#include "Platform.h"
#include "Hashlib.h"

extern "C" {
      uint64_t foldhash_fast_wrapper(const uint8_t*, const size_t, const uint64_t);
      uint64_t foldhash_quality_wrapper(const uint8_t*, const size_t, const uint64_t);
}

template <bool bswap>
static void foldhash_fast( const void * in, const size_t len, const seed_t seed, void * out ) {
    uint64_t h = foldhash_fast_wrapper((const uint8_t*) in, len, (uint64_t) seed);
    PUT_U64<bswap>(h, (uint8_t*) out, 0);
}

template <bool bswap>
static void foldhash_quality( const void * in, const size_t len, const seed_t seed, void * out ) {
    uint64_t h = foldhash_quality_wrapper((const uint8_t*) in, len, (uint64_t) seed);
    PUT_U64<bswap>(h, (uint8_t*) out, 0);
}

//------------------------------------------------------------
REGISTER_FAMILY(FoldHash,
   $.src_url    = "https://github.com/orlp/foldhash/",
   $.src_status = HashFamilyInfo::SRC_ACTIVE
 );

REGISTER_HASH(FoldHashFast,
      $.desc            = "FoldHashFast",
      $.hash_flags      = 0,
      $.impl_flags      = 0,
      $.bits            = 64,
      $.verification_LE = 0x0,
      $.verification_BE = 0x0,
      $.hashfn_native   = foldhash_fast<false>,
      $.hashfn_bswap    = foldhash_fast<true>
);

REGISTER_HASH(FoldHashQuality,
      $.desc            = "FoldHashQuality",
      $.hash_flags      = 0,
      $.impl_flags      = 0,
      $.bits            = 64,
      $.verification_LE = 0x0,
      $.verification_BE = 0x0,
      $.hashfn_native   = foldhash_quality<false>,
      $.hashfn_bswap    = foldhash_quality<true>
);
