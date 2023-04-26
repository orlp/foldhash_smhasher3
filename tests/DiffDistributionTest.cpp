/*
 * SMHasher3
 * Copyright (C) 2021-2023  Frank J. T. Wojcik
 * Copyright (C) 2023       jason
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see
 * <https://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and
 * permission notice:
 *
 *     Copyright (c) 2010-2012 Austin Appleby
 *     Copyright (c) 2019-2021 Reini Urban
 *     Copyright (c) 2019      Yann Collet
 *
 *     Permission is hereby granted, free of charge, to any person
 *     obtaining a copy of this software and associated documentation
 *     files (the "Software"), to deal in the Software without
 *     restriction, including without limitation the rights to use,
 *     copy, modify, merge, publish, distribute, sublicense, and/or
 *     sell copies of the Software, and to permit persons to whom the
 *     Software is furnished to do so, subject to the following
 *     conditions:
 *
 *     The above copyright notice and this permission notice shall be
 *     included in all copies or substantial portions of the Software.
 *
 *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *     HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *     WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *     OTHER DEALINGS IN THE SOFTWARE.
 */
#include "Platform.h"
#include "Hashinfo.h"
#include "TestGlobals.h"
#include "Random.h"
#include "Analyze.h"
#include "Instantiate.h"
#include "VCode.h"

#include "DiffDistributionTest.h"

//-----------------------------------------------------------------------------
// Simpler differential-distribution test - for all 1-bit differentials,
// generate random key pairs and run full distribution/collision tests on the
// hash differentials

template <typename hashtype>
static bool DiffDistTest2( const HashInfo * hinfo, int keybits, const seed_t seed, bool drawDiagram ) {
    const HashFn hash = hinfo->hashFn(g_hashEndian);

    int       keybytes = keybits / 8;
    const int keycount = 512 * 1024 * ((hinfo->bits <= 64) ? 3 : 4);

    std::vector<hashtype> worsthashes;
    int worstlogp   = -1;
    int worstkeybit = -1;
    int fails       =  0;

    std::vector<hashtype> hashes( keycount );
    hashtype h1, h2;

    std::vector<uint8_t> keys( keycount * keybytes );

    Rand r( 857374 + keybytes );

    bool result = true;

    if (!drawDiagram) {
        printf("Testing %3d-byte keys, %d reps", keybytes, keycount);
    }

    for (int keybit = 0; keybit < keybits; keybit++) {
        if (drawDiagram) {
            printf("Testing bit %d / %d - %d keys\n", keybit, keybits, keycount);
        }

        r.substream(keybit);
        RandSeq rs = r.get_seq(SEQ_DIST_2, keybytes);
        rs.write(&keys[0], 0, keycount);

        for (int i = 0; i < keycount; i++) {
            ExtBlob k( &keys[i * keybytes], keybytes );
            hash(k, keybytes, seed, &h1);
            addVCodeInput(k, keybytes);

            k.flipbit(keybit);
            hash(k, keybytes, seed, &h2);
            addVCodeInput(k, keybytes);

            hashes[i] = h1 ^ h2;
        }

        int curlogp = 0;
        bool thisresult = TestHashList(hashes).testDistribution(true).verbose(drawDiagram).drawDiagram(drawDiagram).sumLogp(&curlogp);
        if (drawDiagram) {
            printf("\n");
        } else {
            progressdots(keybit, 0, keybits - 1, 10);
            // Record worst result, but don't let a pass override a failure
            if ((fails == 0) && !thisresult) {
                worstlogp = -1;
            }
            if (((fails == 0) || !thisresult) && (worstlogp < curlogp)) {
                worstlogp   = curlogp;
                worstkeybit = keybit;
                worsthashes = hashes;
            }
            if (!thisresult) {
                fails++;
            }
        }

        addVCodeResult(thisresult);

        result &= thisresult;
    }

    if (!drawDiagram) {
        printf("%3d failed, worst is key bit %3d%s\n", fails, worstkeybit, result ? "" : "                  !!!!!");
        bool ignored = TestHashList(worsthashes).testDistribution(true);
        (void)ignored;
        printf("\n");
    }

    recordTestResult(result, "DiffDist", keybytes);

    return result;
}

//----------------------------------------------------------------------------

template <typename hashtype>
bool DiffDistTest( const HashInfo * hinfo, const bool verbose, const bool extra ) {
    bool result = true;

    printf("[[[ DiffDist 'Differential Distribution' Tests ]]]\n\n");

    const seed_t seed = hinfo->Seed(g_seed);

    result &= DiffDistTest2<hashtype>(hinfo, 24, seed, verbose);
    result &= DiffDistTest2<hashtype>(hinfo, 32, seed, verbose);
    result &= DiffDistTest2<hashtype>(hinfo, 64, seed, verbose);
    if (extra && !hinfo->isVerySlow()) {
        result &= DiffDistTest2<hashtype>(hinfo, 160, seed, verbose);
        result &= DiffDistTest2<hashtype>(hinfo, 256, seed, verbose);
    }
    printf("%s\n", result ? "" : g_failstr);

    return result;
}

INSTANTIATE(DiffDistTest, HASHTYPELIST);

//-----------------------------------------------------------------------------
// An old implementation; currently unused.

#if 0
  #include "SparseKeysetTest.h" // for SparseKeygenRecurse
//-----------------------------------------------------------------------------
// Differential distribution test - for each N-bit input differential, generate
// a large set of differential key pairs, hash them, and test the output
// differentials using our distribution test code.

// This is a very hard test to pass - even if the hash values are well-distributed,
// the differences between hash values may not be. It's also not entirely relevant
// for testing hash functions, but it's still interesting.

// This test is a _lot_ of work, as it's essentially a full keyset test for
// each of a potentially huge number of input differentials. To speed things
// along, we do only a few distribution tests per keyset instead of the full
// grid.

// #TODO - put diagram drawing back on

template <typename keytype, typename hashtype>
void DiffDistTest( HashFn hash, const int diffbits, int trials, double & worst, double & avg ) {
    std::vector<keytype>  keys( trials );
    std::vector<hashtype> A( trials ), B(trials);

    // FIXME seedHash(hash, g_seed);
    for (int i = 0; i < trials; i++) {
        rand_p(&keys[i], keytype::len);

        hash(&keys[i], keytype::len, g_seed, (uint32_t *)&A[i]);
    }

    //----------

    std::vector<keytype> diffs;

    keytype temp( 0 );

    SparseKeygenRecurse<keytype>(0, diffbits, true, temp, diffs);

    //----------

    worst = 0;
    avg   = 0;

    hashtype h2;

    for (size_t j = 0; j < diffs.size(); j++) {
        keytype & d = diffs[j];

        for (int i = 0; i < trials; i++) {
            keytype k2 = keys[i] ^ d;

            hash(&k2, k2.len, g_seed, &h2);

            B[i] = A[i] ^ h2;
        }

        double dworst, davg;

        TestDistributionFast(B, dworst, davg);

        avg  += davg;
        worst = (dworst > worst) ? dworst : worst;
    }

    avg /= double(diffs.size());
}

#endif /* 0 */
