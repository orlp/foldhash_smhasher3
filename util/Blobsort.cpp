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
 */
#include "Platform.h"
#include "Timing.h"
#include "TestGlobals.h"
#include "Blobsort.h"
#include "Instantiate.h"
#include "Random.h"

#include <type_traits>

//-----------------------------------------------------------------------------
// Blob sorting routine unit tests

static const size_t SORT_TESTS = 20;
static const char * teststr[SORT_TESTS] = {
    "Consecutive numbers, sorted",
    "Consecutive numbers, almost sorted",
    "Consecutive numbers, scrambled",
    "Consecutive numbers, reverse sorted",
    "Random numbers, sorted",
    "Random numbers, almost sorted",
    "Random numbers, scrambled",
    "Random numbers, reverse sorted",
    "Random numbers, many duplicates",
    "Random numbers, many duplicates, scrambled",
    "Random number,  all duplicates",
    "Random numbers, all zero in LSB",
    "Random numbers, all zero in MSB",
    "Random numbers, all zero in LSB+1",
    "Random numbers, all zero in MSB+1",
    "Random numbers, each byte has some missing values",
    "All zeroes",
    "All ones",
    "All set bits",
    "All 0xAAAA.... and 0x5555.... values",
};

template <typename blobtype, uint32_t TEST_SIZE>
static void blobfill( std::vector<blobtype> & blobs, size_t testnum, size_t iternum ) {
    if (testnum >= SORT_TESTS) { return; }

    Rand r( {testnum, iternum} );

    switch (testnum) {
    case  0: // Consecutive numbers, sorted
    case  1: // Consecutive numbers, sorted almost
    case  2: // Consecutive numbers, scrambled
    {
        for (uint32_t n = 0; n < TEST_SIZE; n++) {
            blobs[n] = n;
        }
        break;
    }
    case  3: // Consecutive numbers, sorted backwards
    {
        for (uint32_t n = 0; n < TEST_SIZE; n++) {
            blobs[n] = TEST_SIZE - 1 - n;
        }
        break;
    }
    case  4: // Random numbers, sorted
    case  5: // Random numbers, sorted almost
    case  6: // Random numbers, scrambled
    case  7: // Random numbers, sorted backwards
    case 11: // All zero bytes in LSB position
    case 12: // All zero bytes in MSB position
    case 13: // All zero bytes in LSB+1 position
    case 14: // All zero bytes in MSB-1 position
    case 15: // Random numbers, except each position has some missing bytes
    {
        r.rand_n(&blobs[0], blobtype::len * TEST_SIZE);
        break;
    }
    case  8: // Many duplicates
    case  9: // Many duplicates, scrambled
    {
        uint32_t x = 0;
        do {
            r.rand_n(&blobs[x], blobtype::len);
            uint32_t count = 1 + r.rand_range(TEST_SIZE - 1 - x);
            for (uint32_t i = 1; i < count; i++) {
                blobs[x + i] = blobs[x];
            }
            x += count;
        } while (x < TEST_SIZE);
        break;
    }
    case 10: // All duplicates
    {
        r.rand_n(&blobs[0], blobtype::len);
        for (uint32_t i = 1; i < TEST_SIZE; i++) {
            blobs[i] = blobs[0];
        }
        break;
    }
    case 16: // All zeroes
    {
        memset((void *)&blobs[0], 0, TEST_SIZE * sizeof(blobtype));
        break;
    }
    case 17: // All ones
    {
        for (uint32_t i = 0; i < TEST_SIZE; i++) {
            blobs[i] = 1;
        }
        break;
    }
    case 18: // All Fs
    {
        memset((void *)&blobs[0], 0xFF, TEST_SIZE * blobtype::len);
        break;
    }
    case 19: // All 0xAAA and 0x555
    {
        uint64_t rndnum = 0;
        for (uint32_t i = 0; i < TEST_SIZE; i++) {
            if (unlikely(i % 64 == 0)) {
                rndnum = r.rand_u64();
            }
            memset((void *)&blobs[i], rndnum & 1 ? 0xAA : 0x55, blobtype::len);
            rndnum >>= 1;
        }
        break;
    }
    default: unreachable(); break;
    }

    switch (testnum) {
    // Sorted backwards
    case  7:
    {
        std::sort(blobs.rbegin(), blobs.rend());
        break;
    }
    // Sorted
    case  4:
    case  5:
    {
        std::sort(blobs.begin(), blobs.end());
        if (testnum == 4) { break; }
    }
    // 5 is fallthrough to...
    // "Almost sorted" == mix up a few entries
    case  1:
    {
        for (uint32_t n = 0; n < TEST_SIZE / 1000; n++) {
            std::swap(blobs[r.rand_range(TEST_SIZE)], blobs[r.rand_range(TEST_SIZE)]);
        }
        break;
    }
    // "Scrambled" == shuffle all the entries
    case  2:
    case  9:
    {
        for (uint32_t n = TEST_SIZE - 1; n > 0; n--) {
            std::swap(blobs[n], blobs[r.rand_range(n + 1)]);
        }
        break;
    }
    // Zero out bytes in some position
    case 11:
    case 12:
    case 13:
    case 14:
    {
        uint32_t offset = (testnum == 11) ? 0 :
                                            ((testnum == 12) ? (sizeof(blobtype) - 1) :
                                                               ((testnum == 13) ? 1 : (sizeof(blobtype) - 2)));
        for (uint32_t n = 0; n < TEST_SIZE; n++) {
            blobs[n][offset] = 0;
        }
        break;
    }
    // Exclude a byte value from each position
    case 15:
    {
        uint8_t excludes[blobtype::len];
        r.rand_n(excludes, sizeof(excludes));
        for (uint32_t n = 0; n < TEST_SIZE; n++) {
            for (uint32_t i = 0; i < blobtype::len; i++) {
                if (blobs[n][i] == excludes[i]) {
                    blobs[n][i] = ~excludes[i];
                }
            }
        }
        break;
    }
    default: break;
    }
}

template <typename blobtype>
static bool blobverify( std::vector<blobtype> & blobs, std::vector<blobtype> & orig ) {
    bool passed     = true;
    const size_t sz = blobs.size();

    for (size_t nb = 1; nb < sz; nb++) {
        if (!((blobs[nb - 1] < blobs[nb]) ||
                (blobs[nb - 1] == blobs[nb]))) {
            passed = false;
        }
        if (blobs[nb] < blobs[nb - 1]) {
            passed = false;
        }
    }

    std::sort(orig.begin(), orig.end());

    for (size_t nb = 0; nb < sz; nb++) {
        if (blobs[nb] != orig[nb]) {
            passed = false;
        }
    }

    return passed;
}

template <typename blobtype>
static bool blobverify( std::vector<blobtype> & blobs, std::vector<blobtype> & orig, std::vector<hidx_t> & idxs ) {
    bool passed     = true;
    const size_t sz = blobs.size();

    for (size_t nb = 0; nb < sz; nb++) {
        if (blobs[nb] != orig[idxs[nb]]) {
            passed = false;
        }
    }

    passed &= blobverify(blobs, orig);

    return passed;
}

//-----------------------------------------------------------------------------

static const uint32_t BASELINE_TEST_ITER = 4000000;
double baseline_timing[6][9] = {
    { 37.0,  34.3, 44.8, 41.8,  8.1,  34.3,  8.4, 42.8 },
    { 76.3,  76.2, 85.1, 83.9, 11.7,  76.3, 11.6, 84.2 },
    { 22.2, 136.0, 25.0, 35.4, 13.1, 136.1, 13.1, 41.1 },
    { 23.1, 144.5, 27.7, 39.0, 15.2, 144.6, 15.2, 43.9 },
    { 26.2, 201.9, 33.8, 30.1, 16.9, 202.0, 16.9, 48.5 },
    { 29.4, 194.7, 30.9, 32.8, 18.0, 194.9, 18.0, 49.5 },
};
// Converts number of 32-bit words in the hash to the row of
// baseline_timing. Row 0 is 32-bits, row 1 is 64, etc.
const static int baseline_idx1[] = {
    -1, +0, +1, -1, +2, +3, -1, +4, +5
};
// Converts test number to the columns of baseline_timing. Column 0 is
// "Random numbers, sorted", column 1 is "Random numbers, scrambled", etc.
const static int baseline_idx2[SORT_TESTS] = {
    -1, -1, -1, -1, +0, -1, +1, -1, +2, +3,
    +4, -1, -1, -1, -1, +5, +6, -1, -1, +7
};

template <uint32_t TEST_SIZE, uint32_t TEST_ITER, typename blobtype, bool track_idxs>
bool test_blobsort_type_idx( void ) {
    std::vector<blobtype> blobs( TEST_SIZE ), orig( TEST_SIZE );
    std::vector<hidx_t> idxs;
    std::vector<size_t> testnums;
    uint64_t timetotal = 0;
    double   basesum   = 0.0;
    bool     passed    = true;

    if (TEST_ITER > 1) {
        testnums = { 4, 6, 8, 9, 10, 15, 16, 19 };
    } else {
        for (size_t i = 0; i < SORT_TESTS; i++) {
            testnums.push_back(i);
        }
    }

    for (size_t i: testnums) {
        bool     thispassed = true;
        uint64_t mintime    = UINT64_C(-1);
        if (TEST_ITER > 1) {
            printf("%3lu bits, test %2zd [%-50s]", blobtype::bitlen, i, teststr[i]);
        }
        for (size_t j = 0; j < TEST_ITER; j++) {
            blobfill<blobtype, TEST_SIZE>(blobs, i, j);
            orig = blobs;

            uint64_t timeBegin = monotonic_clock();
            if (track_idxs) {
                blobsort(blobs.begin(), blobs.end(), idxs);
            } else {
                blobsort(blobs.begin(), blobs.end());
            }
            uint64_t timeEnd   = monotonic_clock();

            uint64_t timesum   = timeEnd - timeBegin;
            if (mintime > timesum) {
                mintime = timesum;
            }
            if (track_idxs) {
                thispassed &= blobverify(blobs, orig, idxs);
                idxs.clear();
            } else {
                thispassed &= blobverify(blobs, orig);
            }
            if (TEST_ITER > 1) {
                progressdots(j, 0, TEST_ITER - 1, 16);
            }
        }
        if (TEST_ITER > 1) {
            double thistime = (double)mintime / (double)(NSEC_PER_SEC / 1000);
            if ((TEST_ITER != BASELINE_TEST_ITER) || (baseline_idx1[blobtype::len / 4] < 0) || (baseline_idx2[i] < 0)) {
                printf("\t %7.1f ms               %s\n", thistime, thispassed ? "ok" : "NO");
            } else {
                double basetime = baseline_timing[baseline_idx1[blobtype::len / 4]][baseline_idx2[i]];
                double delta    = thistime - basetime;
                if ((delta >= -0.05) && (delta <= 0.05)) {
                    delta = 0.0;
                }
                basesum += basetime;
                printf("\t %7.1f ms ( %+6.1f ms ) %s\n", thistime, delta, thispassed ? "ok" : "NO");
            }
        }
        timetotal += mintime;
        passed &= thispassed;
    }

    if (TEST_ITER > 1) {
        double thistime = (double)timetotal / (double)(NSEC_PER_SEC / 1000);
        double delta    = thistime - basesum;
        if ((delta >= -0.05) && (delta <= 0.05)) {
            delta = 0.0;
        }
        printf("%3lu bits, %-60s                \t%8.1f ms ( %+6.1f ms )\n\n",
                blobtype::bitlen, "SUM TOTAL", thistime, delta);
    }

    return passed;
}

template <uint32_t TEST_SIZE, uint32_t TEST_ITER, typename blobtype>
bool test_blobsort_type( void ) {
    bool passed = true;

    passed &= test_blobsort_type_idx<TEST_SIZE, TEST_ITER, blobtype, false>();
    passed &= test_blobsort_type_idx<TEST_SIZE, TEST_ITER, blobtype, true>();

    return passed;
}

//-----------------------------------------------------------------------------
// Instantiator for test_blobsort_type()
//
// All this does is create a std::vector<> full of function pointers to the various
// instantiations of test_blobsort_type<>. Then SortBenchmark() can just iterate over
// those function pointers, calling each one in turn.

typedef bool (* SortTestFn)( void );

template <uint32_t TEST_SIZE, uint32_t TEST_ITER, typename... T>
std::vector<SortTestFn> PACKEXPANDER() {
    return { &test_blobsort_type<TEST_SIZE, TEST_ITER, T>... };
}

auto SortTestFns  = PACKEXPANDER<   16000,  1, HASHTYPELIST>();
auto SortBenchFns = PACKEXPANDER< 4000000,100, HASHTYPELIST>();

void BlobsortTest( void ) {
    bool result = true;

    for (SortTestFn testFn: SortTestFns) {
        result &= testFn();
    }
    if (!result) {
        printf("Blobsort self-test failed! Cannot continue\n");
        exit(1);
    }
    printf("Blobsort self-test passed.\n");
    return;
}

void BlobsortBenchmark( void ) {
    bool result = true;

    for (SortTestFn testFn: SortBenchFns) {
        result &= testFn();
    }
    if (!result) {
        printf("Blobsort self-test failed! Cannot continue\n");
        exit(1);
    }
    return;
}
