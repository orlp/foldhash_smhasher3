/*
 * Copyright (C) 2021-2022  Frank J. T. Wojcik
 * Copyright (C) 2012-2021 Yann Collet
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following disclaimer
 *      in the documentation and/or other materials provided with the
 *      distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#if defined(NEW_HAVE_XOP)
#  if defined(_MSC_VER)
#    include <ammintrin.h>
#  else
#    include <x86intrin.h>
#  endif
#  define HAVE_X64_INTRIN 1
#elif \
    defined(NEW_HAVE_SHA2_X86_64)   ||   \
    defined(DNEW_HAVE_SHA1_X86_64)  ||   \
    defined(NEW_HAVE_AES_X86_64)    ||   \
    defined(NEW_HAVE_CRC32C_X86_64) ||   \
    defined(NEW_HAVE_AVX512_BW)     ||   \
    defined(NEW_HAVE_AVX512_F)      ||   \
    defined(NEW_HAVE_AVX2)          ||   \
    defined(NEW_HAVE_SSE_4_1)       ||   \
    defined(NEW_HAVE_SSSE3)         ||   \
    defined(NEW_HAVE_SSE_2)
#  include <immintrin.h>
#  define HAVE_X64_INTRIN 1
#endif

#if defined(NEW_HAVE_ARM_NEON)
    /* circumvent a clang bug */
#  if defined(__GNUC__) || defined(__clang__)
#    if defined(__ARM_NEON__) || defined(__ARM_NEON) || \
        defined(__aarch64__)  || defined(_M_ARM)     || \
        defined(_M_ARM64)     || defined(_M_ARM64EC)
#           define inline __inline__
#    endif
#  endif
#  include <arm_neon.h>
#  if defined(__GNUC__) || defined(__clang__)
#    if defined(__ARM_NEON__) || defined(__ARM_NEON) || \
        defined(__aarch64__)  || defined(_M_ARM)     || \
        defined(_M_ARM64)     || defined(_M_ARM64EC)
#           undef inline
#    endif
#  endif
#  if defined(NEW_HAVE_ARM_ACLE)
#    include <arm_acle.h>
#  endif
#endif


#if defined(NEW_HAVE_AES_PPC)
/*
 * Annoyingly, these headers _may_ define three macros: `bool`,
 * `vector`, and `pixel`. This is a problem for obvious reasons.
 *
 * These keywords are unnecessary; the spec literally says they are
 * equivalent to `__bool`, `__vector`, and `__pixel` and may be
 * undef'd after including the header.
 *
 * We use pragma push_macro/pop_macro to keep the namespace clean.
 */
#pragma push_macro("bool")
#pragma push_macro("vector")
#pragma push_macro("pixel")
/* silence potential macro redefined warnings */
#undef bool
#undef vector
#undef pixel

#if defined(__s390x__)
#  include <s390intrin.h>
#else
#  include <altivec.h>
#endif

/* Restore the original macro values, if applicable. */
#pragma pop_macro("pixel")
#pragma pop_macro("vector")
#pragma pop_macro("bool")

#if defined(__ibmxl__) || (defined(_AIX) && defined(__xlC__))
typedef  __vector unsigned char vec_t;
#define vec_encrypt(a,b) __vcipher(a,b);
#define vec_encryptlast(a,b) __vcipherlast(a,b);
#define vec_decrypt(a,b) __vncipher(a,b);
#define vec_encryptlast(a,b) __vncipherlast(a,b);
#elif defined(__clang__)
typedef  __vector unsigned long long vec_t;
#define vec_encrypt(a,b) __builtin_altivec_crypto_vcipher(a, b);
#define vec_encryptlast(a,b) __builtin_altivec_crypto_vcipherlast(a, b);
#define vec_decrypt(a,b) __builtin_altivec_crypto_vncipher(a, b);
#define vec_decryptlast(a,b) __builtin_altivec_crypto_vncipherlast(a, b);
#elif defined(__GNUC__)
typedef  __vector unsigned long long vec_t;
#define vec_encrypt(a,b) __builtin_crypto_vcipher(a,b);
#define vec_encryptlast(a,b) __builtin_crypto_vcipherlast(a,b);
#define vec_decrypt(a,b) __builtin_crypto_vncipher(a,b);
#define vec_decryptlast(a,b) __builtin_crypto_vncipherlast(a,b);
#else
#error "PPC AES intrinsic mapping unimplemented"
#endif
#endif

//------------------------------------------------------------
// Vectorized byteswapping

#if defined(NEW_HAVE_ARM_NEON)
static FORCE_INLINE uint64x2_t Vbswap64_u64(const uint64x2_t v) {
    return vreinterpretq_u64_u8(vrev64q_u8(vreinterpretq_u8_u64(v)));
}
static FORCE_INLINE uint32x4_t Vbswap32_u32(const uint32x4_t v) {
    return vreinterpretq_u32_u8(vrev32q_u8(vreinterpretq_u8_u32(v)));
}
#endif

#if defined(NEW_HAVE_AVX512_BW)
static FORCE_INLINE __m512i mm512_bswap64(const __m512i v) {
    const __m512i MASK = _mm512_set_epi64(UINT64_C(0x08090a0b0c0d0e0f),
                                          UINT64_C(0x0001020304050607),
                                          UINT64_C(0x08090a0b0c0d0e0f),
                                          UINT64_C(0x0001020304050607),
                                          UINT64_C(0x08090a0b0c0d0e0f),
                                          UINT64_C(0x0001020304050607),
                                          UINT64_C(0x08090a0b0c0d0e0f),
                                          UINT64_C(0x0001020304050607));
    return _mm512_shuffle_epi8(v, MASK);
}
static FORCE_INLINE __m512i mm512_bswap32(const __m512i v) {
    const __m512i MASK = _mm512_set_epi64(UINT64_C(0x0c0d0e0f08090a0b),
                                          UINT64_C(0x0405060700010203),
                                          UINT64_C(0x0c0d0e0f08090a0b),
                                          UINT64_C(0x0405060700010203),
                                          UINT64_C(0x0c0d0e0f08090a0b),
                                          UINT64_C(0x0405060700010203),
                                          UINT64_C(0x0c0d0e0f08090a0b),
                                          UINT64_C(0x0405060700010203));
    return _mm512_shuffle_epi8(v, MASK);
}
#elif defined(NEW_HAVE_AVX512_F)
static FORCE_INLINE __m512i mm512_bswap64(const __m512i v) {
    // Byteswapping 256 bits at a time, since _mm512_shuffle_epi8()
    // requires AVX512-BW in addition to AVX512-F.
    const __m256i MASK = _mm256_set_epi64x(UINT64_C(0x08090a0b0c0d0e0f),
                                           UINT64_C(0x0001020304050607),
                                           UINT64_C(0x08090a0b0c0d0e0f),
                                           UINT64_C(0x0001020304050607));
    __m256i blk1 = _mm512_extracti64x4_epi64(v, 0);
    __m256i blk2 = _mm512_extracti64x4_epi64(v, 1);
    blk1 = _mm256_shuffle_epi8(blk1, MASK);
    blk2 = _mm256_shuffle_epi8(blk2, MASK);
    v = _mm512_inserti64x4(v, blk1, 0);
    v = _mm512_inserti64x4(v, blk2, 1);
    return v;
}
static FORCE_INLINE __m512i mm512_bswap64(const __m512i v) {
    // Byteswapping 256 bits at a time, since _mm512_shuffle_epi8()
    // requires AVX512-BW in addition to AVX512-F.
    const __m256i MASK = _mm256_set_epi64x(UINT64_C(0x0c0d0e0f08090a0b),
                                           UINT64_C(0x0405060700010203),
                                           UINT64_C(0x0c0d0e0f08090a0b),
                                           UINT64_C(0x0405060700010203));
    __m256i blk1 = _mm512_extracti64x4_epi64(v, 0);
    __m256i blk2 = _mm512_extracti64x4_epi64(v, 1);
    blk1 = _mm256_shuffle_epi8(blk1, MASK);
    blk2 = _mm256_shuffle_epi8(blk2, MASK);
    v = _mm512_inserti64x4(v, blk1, 0);
    v = _mm512_inserti64x4(v, blk2, 1);
    return v;
}
#endif

#if defined(NEW_HAVE_AVX2)
static FORCE_INLINE __m256i mm256_bswap64(const __m256i v) {
    const __m256i MASK = _mm256_set_epi64x(UINT64_C(0x08090a0b0c0d0e0f),
                                           UINT64_C(0x0001020304050607),
                                           UINT64_C(0x08090a0b0c0d0e0f),
                                           UINT64_C(0x0001020304050607));
    return _mm256_shuffle_epi8(v, MASK);
}
static FORCE_INLINE __m256i mm256_bswap32(const __m256i v) {
    const __m256i MASK = _mm256_set_epi64x(UINT64_C(0x0c0d0e0f08090a0b),
                                           UINT64_C(0x0405060700010203),
                                           UINT64_C(0x0c0d0e0f08090a0b),
                                           UINT64_C(0x0405060700010203));
    return _mm256_shuffle_epi8(v, MASK);
}
#endif

#if defined(NEW_HAVE_SSSE3)
static FORCE_INLINE __m128i mm_bswap64(const __m128i v) {
    const __m128i MASK = _mm_set_epi64x(UINT64_C(0x08090a0b0c0d0e0f),
                                        UINT64_C(0x0001020304050607));
    return _mm_shuffle_epi8(v, MASK);
}
static FORCE_INLINE __m128i mm_bswap32(const __m128i v) {
    const __m128i MASK = _mm_set_epi64x(UINT64_C(0x0c0d0e0f08090a0b),
                                        UINT64_C(0x0405060700010203));
    return _mm_shuffle_epi8(v, MASK);
}
#elif defined(NEW_HAVE_SSE_2)
static FORCE_INLINE __m128i mm_bswap64(const __m128i v) {
    // Swap each pair of bytes
    __m128i tmp = _mm_or_si128(_mm_slri_epi16(v, 8),
                               _mm_slli_epi16(v, 8));
    // Swap 16-bit words
    tmp = _mm_shufflelo_epi16(tmp, _MM_SHUFFLE(0, 1, 2, 3));
    tmp = _mm_shufflehi_epi16(tmp, _MM_SHUFFLE(0, 1, 2, 3));
}
static FORCE_INLINE __m128i mm_bswap32(const __m128i v) {
    // Swap each pair of bytes
    __m128i tmp = _mm_or_si128(_mm_slri_epi16(v, 8),
                               _mm_slli_epi16(v, 8));
    // Swap 16-bit words
    tmp = _mm_shufflelo_epi16(tmp, _MM_SHUFFLE(2, 3, 0, 1));
    tmp = _mm_shufflehi_epi16(tmp, _MM_SHUFFLE(2, 3, 0, 1));
}
#endif
