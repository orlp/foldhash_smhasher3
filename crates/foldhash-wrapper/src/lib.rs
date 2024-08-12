use std::hash::BuildHasher;

#[no_mangle]
pub unsafe extern "C" fn foldhash_fast_wrapper(bytes: *const u8, len: usize, seed: u64) -> u64 {
    let sl = std::slice::from_raw_parts(bytes, len);
    let hasher = foldhash::fast::FixedState::with_seed(seed);
    hasher.hash_one(sl)
}

#[no_mangle]
pub unsafe extern "C" fn foldhash_quality_wrapper(bytes: *const u8, len: usize, seed: u64) -> u64 {
    let sl = std::slice::from_raw_parts(bytes, len);
    let hasher = foldhash::quality::FixedState::with_seed(seed);
    hasher.hash_one(sl)
}