This is a fork of https://gitlab.com/fwojcik/smhasher3, forked on 12-08-2024.
Its only purpose is to add https://github.com/orlp/foldhash to see if it passes
the test suite. What follows is the output of `foldhash::quality` in the
benchmark on an Apple M2 laptop.

```
-------------------------------------------------------------------------------
--- Testing FoldHashQuality "FoldHashQuality"

[[[ Sanity Tests ]]]

Verification value LE 0x2376275A ...... SKIP (unverifiable)
Running sanity check 1       .......... PASS
Running sanity check 2       .......... PASS
Running append zeroes test   .......... PASS
Running prepend zeroes test  .......... PASS
Running thread-safety test 1 .......... PASS
Running thread-safety test 2 .......... PASS

[[[ Speed Tests ]]]

Small key speed test - [1, 31]-byte keys
   1-byte keys -    12.31 cycles/hash
   2-byte keys -    12.30 cycles/hash
   3-byte keys -    12.30 cycles/hash
   4-byte keys -    11.51 cycles/hash
   5-byte keys -    11.51 cycles/hash
   6-byte keys -    11.51 cycles/hash
   7-byte keys -    11.51 cycles/hash
   8-byte keys -    11.28 cycles/hash
   9-byte keys -    11.29 cycles/hash
  10-byte keys -    11.28 cycles/hash
  11-byte keys -    11.29 cycles/hash
  12-byte keys -    11.01 cycles/hash
  13-byte keys -    11.01 cycles/hash
  14-byte keys -    11.01 cycles/hash
  15-byte keys -    11.01 cycles/hash
  16-byte keys -    11.01 cycles/hash
  17-byte keys -    12.74 cycles/hash
  18-byte keys -    12.74 cycles/hash
  19-byte keys -    12.74 cycles/hash
  20-byte keys -    12.36 cycles/hash
  21-byte keys -    12.35 cycles/hash
  22-byte keys -    12.36 cycles/hash
  23-byte keys -    12.36 cycles/hash
  24-byte keys -    12.36 cycles/hash
  25-byte keys -    12.36 cycles/hash
  26-byte keys -    12.36 cycles/hash
  27-byte keys -    12.36 cycles/hash
  28-byte keys -    12.35 cycles/hash
  29-byte keys -    12.36 cycles/hash
  30-byte keys -    12.36 cycles/hash
  31-byte keys -    12.36 cycles/hash
Average        -    11.92 cycles/hash
 rnd-byte keys -    11.93 cycles/hash

Bulk speed test - 262144-byte keys
Alignment   7 - 23.81 bytes/cycle - 77.62 GiB/sec @ 3.5 ghz
Alignment   6 - 23.68 bytes/cycle - 77.18 GiB/sec @ 3.5 ghz
Alignment   5 - 23.81 bytes/cycle - 77.62 GiB/sec @ 3.5 ghz
Alignment   4 - 23.68 bytes/cycle - 77.18 GiB/sec @ 3.5 ghz
Alignment   3 - 23.68 bytes/cycle - 77.18 GiB/sec @ 3.5 ghz
Alignment   2 - 23.54 bytes/cycle - 76.73 GiB/sec @ 3.5 ghz
Alignment   1 - 23.68 bytes/cycle - 77.18 GiB/sec @ 3.5 ghz
Alignment   0 - 23.27 bytes/cycle - 75.86 GiB/sec @ 3.5 ghz
Average       - 23.64 bytes/cycle - 77.07 GiB/sec @ 3.5 ghz
Alignment rnd - 23.01 bytes/cycle - 75.01 GiB/sec @ 3.5 ghz

Bulk speed test - [262017, 262144]-byte keys
Alignment   7 - 22.83 bytes/cycle - 74.42 GiB/sec @ 3.5 ghz
Alignment   6 - 23.39 bytes/cycle - 76.24 GiB/sec @ 3.5 ghz
Alignment   5 - 23.40 bytes/cycle - 76.27 GiB/sec @ 3.5 ghz
Alignment   4 - 23.42 bytes/cycle - 76.34 GiB/sec @ 3.5 ghz
Alignment   3 - 23.37 bytes/cycle - 76.17 GiB/sec @ 3.5 ghz
Alignment   2 - 22.83 bytes/cycle - 74.43 GiB/sec @ 3.5 ghz
Alignment   1 - 23.43 bytes/cycle - 76.37 GiB/sec @ 3.5 ghz
Alignment   0 - 23.49 bytes/cycle - 76.58 GiB/sec @ 3.5 ghz
Average       - 23.27 bytes/cycle - 75.85 GiB/sec @ 3.5 ghz
Alignment rnd - 22.71 bytes/cycle - 74.04 GiB/sec @ 3.5 ghz

[[[ 'Hashmap' Speed Tests ]]]

std::unordered_map
Init std HashMapTest:     92.882 cycles/op (792291 inserts, 1% deletions)
Running std HashMapTest:  75.616 cycles/op (0.9 stdv)

greg7mdp/parallel-hashmap
Init fast HashMapTest:    51.224 cycles/op (792291 inserts, 1% deletions)
Running fast HashMapTest: 63.204 cycles/op (4.6 stdv)

[[[ Avalanche Tests ]]]

Testing   3-byte keys, 300000 reps..................max is 0.629% at bit   13 -> out  44 (^ 0)
Testing   4-byte keys, 300000 reps..................max is 0.688% at bit   18 -> out  54 (^ 1)
Testing   5-byte keys, 300000 reps..................max is 0.723% at bit   29 -> out  13 (^ 2)
Testing   6-byte keys, 300000 reps..................max is 0.678% at bit   26 -> out   6 (^ 1)
Testing   7-byte keys, 300000 reps..................max is 0.667% at bit   14 -> out  20 (^ 0)
Testing   8-byte keys, 300000 reps..................max is 0.719% at bit   11 -> out  10 (^ 1)
Testing   9-byte keys, 300000 reps..................max is 0.779% at bit   55 -> out   9 (^ 3)
Testing  10-byte keys, 300000 reps..................max is 0.628% at bit   40 -> out  50 (^ 0)
Testing  12-byte keys, 300000 reps..................max is 0.653% at bit   83 -> out  24 (^ 0)
Testing  16-byte keys, 300000 reps..................max is 0.784% at bit   25 -> out  14 (^ 2)
Testing  20-byte keys, 300000 reps..................max is 0.671% at bit  156 -> out  20 (^ 0)
Testing  64-byte keys, 300000 reps..................max is 0.805% at bit  267 -> out  43 (^ 1)
Testing 128-byte keys, 300000 reps..................max is 0.776% at bit   17 -> out  33 (^ 0)


[[[ BIC 'Bit Independence Criteria' Tests ]]]

Testing    3-byte keys, 1200000 reps............max 0.0041 at bit   12 -> out (  0, 42)  (^ 1)
Testing    8-byte keys, 1200000 reps............max 0.0046 at bit    9 -> out ( 34, 40)  (^ 4)
Testing   11-byte keys, 1200000 reps............max 0.0043 at bit   25 -> out (  6, 56)  (^ 1)
Testing   15-byte keys, 1200000 reps............max 0.0041 at bit  101 -> out ( 21, 23)  (^ 0)


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 204800 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        4.9, actual          5  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected        4.9, actual          4  (0.819x) (^ 0)
Testing all collisions (high  27-bit) - Expected      156.2, actual        161  (1.031x) (^ 1)
Testing all collisions (low   27-bit) - Expected      156.2, actual        168  (1.076x) (^ 2)
Testing all collisions (high 16..30 bits) - Worst is 29 bits: 42/39             (1.075x) (^ 0)
Testing all collisions (low  16..30 bits) - Worst is 26 bits: 337/312           (1.080x) (^ 0)
Testing distribution   (any   8..15 bits) - Worst bias is 10 bits at bit  54:    0.655x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        4.9, actual          4  (0.819x) (^ 0)
Testing all collisions (low   32-bit) - Expected        4.9, actual          4  (0.819x) (^ 0)
Testing all collisions (high  27-bit) - Expected      156.2, actual        159  (1.018x) (^ 1)
Testing all collisions (low   27-bit) - Expected      156.2, actual        147  (0.941x) (^ 0)
Testing all collisions (high 16..30 bits) - Worst is 28 bits: 90/78             (1.152x) (^ 0)
Testing all collisions (low  16..30 bits) - Worst is 25 bits: 666/624           (1.068x) (^ 0)
Testing distribution   (any   8..15 bits) - Worst bias is  8 bits at bit  45:    0.675x  (^ 0)


[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 4 cycles of 3 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        106  (0.911x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        109  (0.936x) (^ 0)
Testing all collisions (high 16..35 bits) - Worst is 35 bits: 18/15             (1.237x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 21 bits: 204912/204642     (1.001x) (^ 0)

Keyset 'Cyclic' - 4 cycles of 4 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        117  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected      116.4, actual        112  (0.962x) (^ 0)
Testing all collisions (high 16..35 bits) - Worst is 27 bits: 3852/3716         (1.037x) (^ 2)
Testing all collisions (low  16..35 bits) - Worst is 27 bits: 3774/3716         (1.016x) (^ 0)

Keyset 'Cyclic' - 4 cycles of 5 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        104  (0.893x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        122  (1.048x) (^ 1)
Testing all collisions (high 16..35 bits) - Worst is 23 bits: 57586/57305       (1.005x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 31 bits: 242/233           (1.040x) (^ 0)

Keyset 'Cyclic' - 4 cycles of 8 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        107  (0.919x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        114  (0.979x) (^ 0)
Testing all collisions (high 16..35 bits) - Worst is 34 bits: 34/29             (1.168x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 21 bits: 204893/204642     (1.001x) (^ 0)

Keyset 'Cyclic' - 8 cycles of 3 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        109  (0.936x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        130  (1.117x) (^ 3)
Testing all collisions (high 16..35 bits) - Worst is 20 bits: 355651/355464     (1.001x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 33 bits: 70/58             (1.203x) (^ 0)

Keyset 'Cyclic' - 8 cycles of 4 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        146  (1.254x) (^ 7)
Testing all collisions (low   32-bit) - Expected      116.4, actual        117  (1.000x) (^ 1)
Testing all collisions (high 16..35 bits) - Worst is 32 bits: 146/116           (1.254x) (^ 3)
Testing all collisions (low  16..35 bits) - Worst is 22 bits: 110465/110274     (1.002x) (^ 0)

Keyset 'Cyclic' - 8 cycles of 5 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        120  (1.031x) (^ 1)
Testing all collisions (low   32-bit) - Expected      116.4, actual        133  (1.143x) (^ 3)
Testing all collisions (high 16..35 bits) - Worst is 20 bits: 355862/355464     (1.001x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 32 bits: 133/116           (1.143x) (^ 0)

Keyset 'Cyclic' - 8 cycles of 8 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        120  (1.031x) (^ 1)
Testing all collisions (low   32-bit) - Expected      116.4, actual        118  (1.014x) (^ 1)
Testing all collisions (high 16..35 bits) - Worst is 30 bits: 506/466           (1.087x) (^ 1)
Testing all collisions (low  16..35 bits) - Worst is 29 bits: 1005/931          (1.080x) (^ 2)

Keyset 'Cyclic' - 12 cycles of 3 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        123  (1.057x) (^ 1)
Testing all collisions (low   32-bit) - Expected      116.4, actual        124  (1.065x) (^ 1)
Testing all collisions (high 16..35 bits) - Worst is 32 bits: 123/116           (1.057x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 34 bits: 37/29             (1.271x) (^ 0)

Keyset 'Cyclic' - 12 cycles of 4 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        107  (0.919x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        123  (1.057x) (^ 1)
Testing all collisions (high 16..35 bits) - Worst is 20 bits: 356048/355464     (1.002x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 27 bits: 3786/3716         (1.019x) (^ 0)

Keyset 'Cyclic' - 12 cycles of 5 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        104  (0.893x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        115  (0.988x) (^ 0)
Testing all collisions (high 16..35 bits) - Worst is 23 bits: 57532/57305       (1.004x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 27 bits: 3745/3716         (1.008x) (^ 0)

Keyset 'Cyclic' - 12 cycles of 8 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        104  (0.893x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        100  (0.859x) (^ 0)
Testing all collisions (high 16..35 bits) - Worst is 30 bits: 498/466           (1.070x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 20 bits: 356110/355464     (1.002x) (^ 0)

Keyset 'Cyclic' - 16 cycles of 3 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        117  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected      116.4, actual        110  (0.945x) (^ 0)
Testing all collisions (high 16..35 bits) - Worst is 30 bits: 487/466           (1.046x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 28 bits: 1925/1860         (1.035x) (^ 0)

Keyset 'Cyclic' - 16 cycles of 4 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        105  (0.902x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        120  (1.031x) (^ 1)
Testing all collisions (high 16..35 bits) - Worst is 27 bits: 3787/3716         (1.019x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 28 bits: 1922/1860         (1.033x) (^ 0)

Keyset 'Cyclic' - 16 cycles of 5 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        118  (1.014x) (^ 1)
Testing all collisions (low   32-bit) - Expected      116.4, actual        119  (1.022x) (^ 1)
Testing all collisions (high 16..35 bits) - Worst is 33 bits: 65/58             (1.117x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 35 bits: 23/15             (1.581x) (^ 1)

Keyset 'Cyclic' - 16 cycles of 8 bytes - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        117  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected      116.4, actual        127  (1.091x) (^ 2)
Testing all collisions (high 16..35 bits) - Worst is 22 bits: 110822/110274     (1.005x) (^ 0)
Testing all collisions (low  16..35 bits) - Worst is 33 bits: 71/58             (1.220x) (^ 0)


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 2-byte keys with up to 6 bits set - 14893 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  20-bit) - Expected      105.3, actual        122  (1.159x) (^ 4)
Testing all collisions (low   20-bit) - Expected      105.3, actual         98  (0.931x) (^ 0)
Testing all collisions (high 10..23 bits) - Worst is 20 bits: 122/105           (1.159x) (^ 0)
Testing all collisions (low  10..23 bits) - Worst is 15 bits: 2996/2925         (1.024x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  20-bit) - Expected      105.3, actual        101  (0.960x) (^ 0)
Testing all collisions (low   20-bit) - Expected      105.3, actual        110  (1.045x) (^ 1)
Testing all collisions (high 10..23 bits) - Worst is 19 bits: 212/210           (1.012x) (^ 0)
Testing all collisions (low  10..23 bits) - Worst is 21 bits: 61/53             (1.156x) (^ 0)

Keyset 'Sparse' - 3-byte keys with up to 4 bits set - 12951 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  19-bit) - Expected      158.6, actual        152  (0.958x) (^ 0)
Testing all collisions (low   19-bit) - Expected      158.6, actual        170  (1.072x) (^ 2)
Testing all collisions (high 10..22 bits) - Worst is 22 bits: 24/20             (1.202x) (^ 0)
Testing all collisions (low  10..22 bits) - Worst is 17 bits: 649/619           (1.048x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  19-bit) - Expected      158.6, actual        177  (1.116x) (^ 3)
Testing all collisions (low   19-bit) - Expected      158.6, actual        183  (1.154x) (^ 4)
Testing all collisions (high 10..22 bits) - Worst is 18 bits: 345/315           (1.096x) (^ 1)
Testing all collisions (low  10..22 bits) - Worst is 15 bits: 2343/2253         (1.040x) (^ 1)

Keyset 'Sparse' - 4-byte keys with up to 4 bits set - 41449 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.2, actual          2  (10.00x) (^ 4)
Testing all collisions (low   32-bit) - Expected        0.2, actual          0  (0.000x) (^ 0)
Testing all collisions (high  23-bit) - Expected      102.2, actual        121  (1.184x) (^ 4)
Testing all collisions (low   23-bit) - Expected      102.2, actual        102  (1.000x) (^ 0)
Testing all collisions (high 12..26 bits) - Worst is 20 bits: 898/809           (1.111x) (^ 5)
Testing all collisions (low  12..26 bits) - Worst is 18 bits: 3205/3111         (1.030x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.2, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.2, actual          0  (0.000x) (^ 0)
Testing all collisions (high  23-bit) - Expected      102.2, actual        112  (1.096x) (^ 2)
Testing all collisions (low   23-bit) - Expected      102.2, actual        108  (1.056x) (^ 1)
Testing all collisions (high 12..26 bits) - Worst is 21 bits: 459/407           (1.128x) (^ 3)
Testing all collisions (low  12..26 bits) - Worst is 21 bits: 445/407           (1.094x) (^ 1)

Keyset 'Sparse' - 5-byte keys with up to 4 bits set - 102091 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        1.2, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        1.2, actual          0  (0.000x) (^ 0)
Testing all collisions (high  25-bit) - Expected      155.1, actual        167  (1.076x) (^ 2)
Testing all collisions (low   25-bit) - Expected      155.1, actual        141  (0.909x) (^ 0)
Testing all collisions (high 13..28 bits) - Worst is 28 bits: 27/19             (1.391x) (^ 0)
Testing all collisions (low  13..28 bits) - Worst is 28 bits: 22/19             (1.133x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        1.2, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        1.2, actual          0  (0.000x) (^ 0)
Testing all collisions (high  25-bit) - Expected      155.1, actual        152  (0.980x) (^ 0)
Testing all collisions (low   25-bit) - Expected      155.1, actual        150  (0.967x) (^ 0)
Testing all collisions (high 13..28 bits) - Worst is 27 bits: 47/39             (1.211x) (^ 0)
Testing all collisions (low  13..28 bits) - Worst is 20 bits: 4919/4812         (1.022x) (^ 0)

Keyset 'Sparse' - 6-byte keys with up to 3 bits set - 18473 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  20-bit) - Expected      161.8, actual        171  (1.057x) (^ 2)
Testing all collisions (low   20-bit) - Expected      161.8, actual        153  (0.946x) (^ 0)
Testing all collisions (high 11..24 bits) - Worst is 16 bits: 2429/2375         (1.023x) (^ 0)
Testing all collisions (low  11..24 bits) - Worst is 22 bits: 42/41             (1.034x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  20-bit) - Expected      161.8, actual        169  (1.045x) (^ 1)
Testing all collisions (low   20-bit) - Expected      161.8, actual        156  (0.964x) (^ 0)
Testing all collisions (high 11..24 bits) - Worst is 23 bits: 25/20             (1.230x) (^ 0)
Testing all collisions (low  11..24 bits) - Worst is 18 bits: 637/636           (1.002x) (^ 0)

Keyset 'Sparse' - 7-byte keys with up to 3 bits set - 29317 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.1, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.1, actual          0  (0.000x) (^ 0)
Testing all collisions (high  22-bit) - Expected      102.2, actual         94  (0.920x) (^ 0)
Testing all collisions (low   22-bit) - Expected      102.2, actual        101  (0.988x) (^ 0)
Testing all collisions (high 11..25 bits) - Worst is 16 bits: 5709/5680         (1.005x) (^ 0)
Testing all collisions (low  11..25 bits) - Worst is 18 bits: 1600/1580         (1.013x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.1, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.1, actual          0  (0.000x) (^ 0)
Testing all collisions (high  22-bit) - Expected      102.2, actual        102  (1.000x) (^ 0)
Testing all collisions (low   22-bit) - Expected      102.2, actual         92  (0.900x) (^ 0)
Testing all collisions (high 11..25 bits) - Worst is 25 bits: 19/13             (1.484x) (^ 0)
Testing all collisions (low  11..25 bits) - Worst is 24 bits: 31/26             (1.211x) (^ 0)

Keyset 'Sparse' - 8-byte keys with up to 3 bits set - 43745 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.2, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.2, actual          0  (0.000x) (^ 0)
Testing all collisions (high  23-bit) - Expected      113.9, actual        119  (1.045x) (^ 1)
Testing all collisions (low   23-bit) - Expected      113.9, actual        111  (0.975x) (^ 0)
Testing all collisions (high 12..26 bits) - Worst is 16 bits: 11959/11828       (1.011x) (^ 0)
Testing all collisions (low  12..26 bits) - Worst is 18 bits: 3486/3455         (1.009x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.2, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        0.2, actual          0  (0.000x) (^ 0)
Testing all collisions (high  23-bit) - Expected      113.9, actual        113  (0.992x) (^ 0)
Testing all collisions (low   23-bit) - Expected      113.9, actual        106  (0.931x) (^ 0)
Testing all collisions (high 12..26 bits) - Worst is 20 bits: 954/900           (1.060x) (^ 1)
Testing all collisions (low  12..26 bits) - Worst is 26 bits: 17/14             (1.193x) (^ 0)

Keyset 'Sparse' - 9-byte keys with up to 3 bits set - 62269 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.5, actual          1  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected        0.5, actual          2  (4.431x) (^ 3)
Testing all collisions (high  24-bit) - Expected      115.4, actual        119  (1.031x) (^ 1)
Testing all collisions (low   24-bit) - Expected      115.4, actual        113  (0.979x) (^ 0)
Testing all collisions (high 12..27 bits) - Worst is 20 bits: 1872/1813         (1.033x) (^ 0)
Testing all collisions (low  12..27 bits) - Worst is 20 bits: 1819/1813         (1.003x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.5, actual          1  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected        0.5, actual          0  (0.000x) (^ 0)
Testing all collisions (high  24-bit) - Expected      115.4, actual        132  (1.144x) (^ 3)
Testing all collisions (low   24-bit) - Expected      115.4, actual         92  (0.797x) (^ 0)
Testing all collisions (high 12..27 bits) - Worst is 25 bits: 70/58             (1.212x) (^ 0)
Testing all collisions (low  12..27 bits) - Worst is 17 bits: 12738/12702       (1.003x) (^ 0)

Keyset 'Sparse' - 10-byte keys with up to 3 bits set - 85401 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.8, actual          1  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected        0.8, actual          0  (0.000x) (^ 0)
Testing all collisions (high  25-bit) - Expected      108.6, actual        126  (1.160x) (^ 4)
Testing all collisions (low   25-bit) - Expected      108.6, actual         99  (0.912x) (^ 0)
Testing all collisions (high 13..28 bits) - Worst is 26 bits: 68/54             (1.252x) (^ 0)
Testing all collisions (low  13..28 bits) - Worst is 28 bits: 15/14             (1.104x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.8, actual          3  (3.533x) (^ 3)
Testing all collisions (low   32-bit) - Expected        0.8, actual          1  (1.000x) (^ 1)
Testing all collisions (high  25-bit) - Expected      108.6, actual        100  (0.921x) (^ 0)
Testing all collisions (low   25-bit) - Expected      108.6, actual         99  (0.912x) (^ 0)
Testing all collisions (high 13..28 bits) - Worst is 20 bits: 3510/3385         (1.037x) (^ 2)
Testing all collisions (low  13..28 bits) - Worst is 16 bits: 37720/37670       (1.001x) (^ 0)

Keyset 'Sparse' - 12-byte keys with up to 3 bits set - 147537 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        2.5, actual          2  (0.789x) (^ 0)
Testing all collisions (low   32-bit) - Expected        2.5, actual          4  (1.579x) (^ 1)
Testing all collisions (high  26-bit) - Expected      162.1, actual        157  (0.969x) (^ 0)
Testing all collisions (low   26-bit) - Expected      162.1, actual        173  (1.068x) (^ 2)
Testing all collisions (high 13..30 bits) - Worst is 29 bits: 23/20             (1.135x) (^ 0)
Testing all collisions (low  13..30 bits) - Worst is 24 bits: 678/647           (1.048x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        2.5, actual          0  (0.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected        2.5, actual          3  (1.000x) (^ 1)
Testing all collisions (high  26-bit) - Expected      162.1, actual        152  (0.938x) (^ 0)
Testing all collisions (low   26-bit) - Expected      162.1, actual        170  (1.049x) (^ 1)
Testing all collisions (high 13..30 bits) - Worst is 20 bits: 10016/9909        (1.011x) (^ 0)
Testing all collisions (low  13..30 bits) - Worst is 26 bits: 170/162           (1.049x) (^ 0)

Keyset 'Sparse' - 14-byte keys with up to 3 bits set - 234249 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        6.4, actual          5  (0.783x) (^ 0)
Testing all collisions (low   32-bit) - Expected        6.4, actual          5  (0.783x) (^ 0)
Testing all collisions (high  28-bit) - Expected      102.2, actual        104  (1.018x) (^ 1)
Testing all collisions (low   28-bit) - Expected      102.2, actual        107  (1.047x) (^ 1)
Testing all collisions (high 14..31 bits) - Worst is 26 bits: 440/408           (1.077x) (^ 0)
Testing all collisions (low  14..31 bits) - Worst is 27 bits: 213/204           (1.043x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        6.4, actual          9  (1.409x) (^ 2)
Testing all collisions (low   32-bit) - Expected        6.4, actual          6  (1.000x) (^ 0)
Testing all collisions (high  28-bit) - Expected      102.2, actual        107  (1.047x) (^ 1)
Testing all collisions (low   28-bit) - Expected      102.2, actual         97  (0.949x) (^ 0)
Testing all collisions (high 14..31 bits) - Worst is 31 bits: 19/13             (1.487x) (^ 0)
Testing all collisions (low  14..31 bits) - Worst is 19 bits: 45419/45335       (1.002x) (^ 0)

Keyset 'Sparse' - 2-byte keys with up to 10 bits set - 58651 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.4, actual          1  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected        0.4, actual          0  (0.000x) (^ 0)
Testing all collisions (high  24-bit) - Expected      102.4, actual        105  (1.025x) (^ 1)
Testing all collisions (low   24-bit) - Expected      102.4, actual         95  (0.928x) (^ 0)
Testing all collisions (high 12..27 bits) - Worst is 19 bits: 3224/3162         (1.020x) (^ 0)
Testing all collisions (low  12..27 bits) - Worst is 17 bits: 11463/11366       (1.009x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        0.4, actual          1  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected        0.4, actual          0  (0.000x) (^ 0)
Testing all collisions (high  24-bit) - Expected      102.4, actual         96  (0.938x) (^ 0)
Testing all collisions (low   24-bit) - Expected      102.4, actual        108  (1.055x) (^ 1)
Testing all collisions (high 12..27 bits) - Worst is 26 bits: 30/26             (1.171x) (^ 0)
Testing all collisions (low  12..27 bits) - Worst is 27 bits: 21/13             (1.639x) (^ 1)

Keyset 'Sparse' - 3-byte keys with up to 20 bits set - 16774891 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        136  (1.063x) (^ 1)
Testing all collisions (low   40-bit) - Expected      128.0, actual        135  (1.055x) (^ 1)
Testing all collisions (high  32-bit) - Expected    32716.3, actual      32591  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32716.3, actual      32572  (0.996x) (^ 0)
Testing all collisions (high 20..43 bits) - Worst is 36 bits: 2124/2047         (1.037x) (^ 0)
Testing all collisions (low  20..43 bits) - Worst is 41 bits: 84/64             (1.313x) (^ 2)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        146  (1.141x) (^ 3)
Testing all collisions (low   40-bit) - Expected      128.0, actual        127  (0.992x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32716.3, actual      32704  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32716.3, actual      32551  (0.995x) (^ 0)
Testing all collisions (high 20..43 bits) - Worst is 39 bits: 296/256           (1.157x) (^ 2)
Testing all collisions (low  20..43 bits) - Worst is 43 bits: 22/16             (1.375x) (^ 0)

Keyset 'Sparse' - 4-byte keys with up to 9 bits set - 43081973 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  43-bit) - Expected      105.5, actual        102  (0.967x) (^ 0)
Testing all collisions (low   43-bit) - Expected      105.5, actual         79  (0.749x) (^ 0)
Testing all collisions (high  32-bit) - Expected   215352.7, actual     214673  (0.997x) (^ 0)
Testing all collisions (low   32-bit) - Expected   215352.7, actual     214805  (0.997x) (^ 0)
Testing all collisions (high 21..46 bits) - Worst is 26 bits: 11290361/11289412 (1.000x) (^ 0)
Testing all collisions (low  21..46 bits) - Worst is 29 bits: 1683664/1683262   (1.000x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  43-bit) - Expected      105.5, actual         97  (0.919x) (^ 0)
Testing all collisions (low   43-bit) - Expected      105.5, actual        105  (0.995x) (^ 0)
Testing all collisions (high  32-bit) - Expected   215352.7, actual     215524  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected   215352.7, actual     215887  (1.002x) (^ 2)
Testing all collisions (high 21..46 bits) - Worst is 38 bits: 3533/3376         (1.047x) (^ 3)
Testing all collisions (low  21..46 bits) - Worst is 26 bits: 11293598/11289412 (1.000x) (^ 0)

Keyset 'Sparse' - 9-byte keys with up to 5 bits set - 15082603 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      103.4, actual        101  (0.976x) (^ 0)
Testing all collisions (low   40-bit) - Expected      103.4, actual        109  (1.054x) (^ 1)
Testing all collisions (high  32-bit) - Expected    26451.8, actual      26296  (0.994x) (^ 0)
Testing all collisions (low   32-bit) - Expected    26451.8, actual      26497  (1.002x) (^ 1)
Testing all collisions (high 20..43 bits) - Worst is 24 bits: 5135179/5133365   (1.000x) (^ 0)
Testing all collisions (low  20..43 bits) - Worst is 33 bits: 13394/13234       (1.012x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      103.4, actual        100  (0.967x) (^ 0)
Testing all collisions (low   40-bit) - Expected      103.4, actual         88  (0.851x) (^ 0)
Testing all collisions (high  32-bit) - Expected    26451.8, actual      26475  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected    26451.8, actual      26274  (0.993x) (^ 0)
Testing all collisions (high 20..43 bits) - Worst is 27 bits: 817597/816576     (1.001x) (^ 0)
Testing all collisions (low  20..43 bits) - Worst is 27 bits: 816874/816576     (1.000x) (^ 0)

Keyset 'Sparse' - 14-byte keys with up to 4 bits set - 6445069 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      151.1, actual        129  (0.854x) (^ 0)
Testing all collisions (low   37-bit) - Expected      151.1, actual        152  (1.006x) (^ 1)
Testing all collisions (high  32-bit) - Expected     4833.3, actual       4764  (0.986x) (^ 0)
Testing all collisions (low   32-bit) - Expected     4833.3, actual       4864  (1.006x) (^ 1)
Testing all collisions (high 18..40 bits) - Worst is 25 bits: 581825/581180     (1.001x) (^ 0)
Testing all collisions (low  18..40 bits) - Worst is 28 bits: 77515/76757       (1.010x) (^ 3)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      151.1, actual        163  (1.079x) (^ 2)
Testing all collisions (low   37-bit) - Expected      151.1, actual        132  (0.874x) (^ 0)
Testing all collisions (high  32-bit) - Expected     4833.3, actual       4809  (0.995x) (^ 0)
Testing all collisions (low   32-bit) - Expected     4833.3, actual       4853  (1.004x) (^ 1)
Testing all collisions (high 18..40 bits) - Worst is 37 bits: 163/151           (1.079x) (^ 0)
Testing all collisions (low  18..40 bits) - Worst is 28 bits: 77439/76757       (1.009x) (^ 2)

Keyset 'Sparse' - 16-byte keys with up to 4 bits set - 11017633 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  39-bit) - Expected      110.4, actual        120  (1.087x) (^ 2)
Testing all collisions (low   39-bit) - Expected      110.4, actual        111  (1.005x) (^ 1)
Testing all collisions (high  32-bit) - Expected    14119.4, actual      14224  (1.007x) (^ 2)
Testing all collisions (low   32-bit) - Expected    14119.4, actual      14051  (0.995x) (^ 0)
Testing all collisions (high 19..42 bits) - Worst is 30 bits: 56752/56333       (1.007x) (^ 0)
Testing all collisions (low  19..42 bits) - Worst is 38 bits: 245/221           (1.110x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  39-bit) - Expected      110.4, actual         86  (0.779x) (^ 0)
Testing all collisions (low   39-bit) - Expected      110.4, actual        102  (0.924x) (^ 0)
Testing all collisions (high  32-bit) - Expected    14119.4, actual      14239  (1.008x) (^ 2)
Testing all collisions (low   32-bit) - Expected    14119.4, actual      14072  (0.997x) (^ 0)
Testing all collisions (high 19..42 bits) - Worst is 35 bits: 1848/1766         (1.046x) (^ 1)
Testing all collisions (low  19..42 bits) - Worst is 35 bits: 1798/1766         (1.018x) (^ 0)

Keyset 'Sparse' - 32-byte keys with up to 3 bits set - 2796417 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      113.8, actual        121  (1.063x) (^ 1)
Testing all collisions (low   35-bit) - Expected      113.8, actual        146  (1.283x) (^ 8)
Testing all collisions (high  32-bit) - Expected      910.2, actual        945  (1.038x) (^ 2)
Testing all collisions (low   32-bit) - Expected      910.2, actual        923  (1.014x) (^ 1)
Testing all collisions (high 17..38 bits) - Worst is 32 bits: 945/910           (1.038x) (^ 0)
Testing all collisions (low  17..38 bits) - Worst is 35 bits: 146/114           (1.283x) (^ 4)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      113.8, actual        124  (1.090x) (^ 2)
Testing all collisions (low   35-bit) - Expected      113.8, actual         88  (0.773x) (^ 0)
Testing all collisions (high  32-bit) - Expected      910.2, actual        945  (1.038x) (^ 2)
Testing all collisions (low   32-bit) - Expected      910.2, actual        873  (0.959x) (^ 0)
Testing all collisions (high 17..38 bits) - Worst is 28 bits: 14805/14515       (1.020x) (^ 2)
Testing all collisions (low  17..38 bits) - Worst is 24 bits: 221606/220626     (1.004x) (^ 1)

Keyset 'Sparse' - 48-byte keys with up to 3 bits set - 9437505 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      162.0, actual        165  (1.018x) (^ 1)
Testing all collisions (low   38-bit) - Expected      162.0, actual        166  (1.025x) (^ 1)
Testing all collisions (high  32-bit) - Expected    10361.1, actual      10553  (1.019x) (^ 5)
Testing all collisions (low   32-bit) - Expected    10361.1, actual      10324  (0.996x) (^ 0)
Testing all collisions (high 19..42 bits) - Worst is 32 bits: 10553/10361       (1.019x) (^ 0)
Testing all collisions (low  19..42 bits) - Worst is 29 bits: 83048/82466       (1.007x) (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      162.0, actual        171  (1.055x) (^ 1)
Testing all collisions (low   38-bit) - Expected      162.0, actual        158  (0.975x) (^ 0)
Testing all collisions (high  32-bit) - Expected    10361.1, actual      10206  (0.985x) (^ 0)
Testing all collisions (low   32-bit) - Expected    10361.1, actual      10454  (1.009x) (^ 2)
Testing all collisions (high 19..42 bits) - Worst is 40 bits: 49/41             (1.210x) (^ 0)
Testing all collisions (low  19..42 bits) - Worst is 28 bits: 164899/163972     (1.006x) (^ 2)

Keyset 'Sparse' - 64-byte keys with up to 3 bits set - 22370049 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  41-bit) - Expected      113.8, actual        127  (1.116x) (^ 3)
Testing all collisions (low   41-bit) - Expected      113.8, actual        115  (1.011x) (^ 1)
Testing all collisions (high  32-bit) - Expected    58155.4, actual      58463  (1.005x) (^ 3)
Testing all collisions (low   32-bit) - Expected    58155.4, actual      57990  (0.997x) (^ 0)
Testing all collisions (high 20..44 bits) - Worst is 32 bits: 58463/58155       (1.005x) (^ 0)
Testing all collisions (low  20..44 bits) - Worst is 40 bits: 239/228           (1.050x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  41-bit) - Expected      113.8, actual        114  (1.000x) (^ 1)
Testing all collisions (low   41-bit) - Expected      113.8, actual        124  (1.090x) (^ 2)
Testing all collisions (high  32-bit) - Expected    58155.4, actual      58160  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected    58155.4, actual      57808  (0.994x) (^ 0)
Testing all collisions (high 20..44 bits) - Worst is 27 bits: 1767327/1764813   (1.001x) (^ 0)
Testing all collisions (low  20..44 bits) - Worst is 39 bits: 508/455           (1.116x) (^ 2)

Keyset 'Sparse' - 96-byte keys with up to 3 bits set - 75498113 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  44-bit) - Expected      162.0, actual        183  (1.130x) (^ 4)
Testing all collisions (low   44-bit) - Expected      162.0, actual        156  (0.963x) (^ 0)
Testing all collisions (high  32-bit) - Expected   659692.2, actual     659258  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected   659692.2, actual     659911  (1.000x) (^ 1)
Testing all collisions (high 22..48 bits) - Worst is 45 bits: 99/81             (1.222x) (^ 0)
Testing all collisions (low  22..48 bits) - Worst is 42 bits: 691/648           (1.066x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  44-bit) - Expected      162.0, actual        141  (0.870x) (^ 0)
Testing all collisions (low   44-bit) - Expected      162.0, actual        173  (1.068x) (^ 2)
Testing all collisions (high  32-bit) - Expected   659692.2, actual     659597  (1.000x) (^ 0)
Testing all collisions (low   32-bit) - Expected   659692.2, actual     660137  (1.001x) (^ 1)
Testing all collisions (high 22..48 bits) - Worst is 34 bits: 165960/165648     (1.002x) (^ 0)
Testing all collisions (low  22..48 bits) - Worst is 36 bits: 41741/41458       (1.007x) (^ 0)

Keyset 'Sparse' - 128-byte keys with up to 2 bits set - 524801 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected       32.1, actual         29  (0.905x) (^ 0)
Testing all collisions (low   32-bit) - Expected       32.1, actual         34  (1.060x) (^ 1)
Testing all collisions (high  30-bit) - Expected      128.2, actual        124  (0.967x) (^ 0)
Testing all collisions (low   30-bit) - Expected      128.2, actual        136  (1.061x) (^ 1)
Testing all collisions (high 15..33 bits) - Worst is 20 bits: 112178/111907     (1.002x) (^ 0)
Testing all collisions (low  15..33 bits) - Worst is 29 bits: 293/256           (1.143x) (^ 2)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected       32.1, actual         37  (1.154x) (^ 2)
Testing all collisions (low   32-bit) - Expected       32.1, actual         23  (0.717x) (^ 0)
Testing all collisions (high  30-bit) - Expected      128.2, actual        134  (1.045x) (^ 1)
Testing all collisions (low   30-bit) - Expected      128.2, actual        135  (1.053x) (^ 1)
Testing all collisions (high 15..33 bits) - Worst is 26 bits: 2084/2047         (1.018x) (^ 0)
Testing all collisions (low  15..33 bits) - Worst is 29 bits: 285/256           (1.111x) (^ 0)

Keyset 'Sparse' - 256-byte keys with up to 2 bits set - 2098177 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      128.1, actual        140  (1.093x) (^ 2)
Testing all collisions (low   34-bit) - Expected      128.1, actual        122  (0.952x) (^ 0)
Testing all collisions (high  32-bit) - Expected      512.4, actual        518  (1.011x) (^ 1)
Testing all collisions (low   32-bit) - Expected      512.4, actual        499  (0.974x) (^ 0)
Testing all collisions (high 17..37 bits) - Worst is 36 bits: 45/32             (1.405x) (^ 1)
Testing all collisions (low  17..37 bits) - Worst is 37 bits: 19/16             (1.186x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      128.1, actual        140  (1.093x) (^ 2)
Testing all collisions (low   34-bit) - Expected      128.1, actual        135  (1.054x) (^ 1)
Testing all collisions (high  32-bit) - Expected      512.4, actual        491  (0.958x) (^ 0)
Testing all collisions (low   32-bit) - Expected      512.4, actual        512  (1.000x) (^ 0)
Testing all collisions (high 17..37 bits) - Worst is 36 bits: 42/32             (1.311x) (^ 0)
Testing all collisions (low  17..37 bits) - Worst is 30 bits: 2093/2049         (1.022x) (^ 0)

Keyset 'Sparse' - 512-byte keys with up to 2 bits set - 8390657 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      128.1, actual        127  (0.992x) (^ 0)
Testing all collisions (low   38-bit) - Expected      128.1, actual        118  (0.921x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8190.7, actual       8229  (1.005x) (^ 1)
Testing all collisions (low   32-bit) - Expected     8190.7, actual       8108  (0.990x) (^ 0)
Testing all collisions (high 19..41 bits) - Worst is 36 bits: 524/512           (1.023x) (^ 0)
Testing all collisions (low  19..41 bits) - Worst is 26 bits: 504384/503349     (1.002x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      128.1, actual        136  (1.062x) (^ 1)
Testing all collisions (low   38-bit) - Expected      128.1, actual        137  (1.070x) (^ 2)
Testing all collisions (high  32-bit) - Expected     8190.7, actual       8246  (1.007x) (^ 1)
Testing all collisions (low   32-bit) - Expected     8190.7, actual       8285  (1.012x) (^ 2)
Testing all collisions (high 19..41 bits) - Worst is 25 bits: 968364/966847     (1.002x) (^ 0)
Testing all collisions (low  19..41 bits) - Worst is 41 bits: 28/16             (1.749x) (^ 3)

Keyset 'Sparse' - 1024-byte keys with up to 2 bits set - 33558529 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  42-bit) - Expected      128.0, actual        135  (1.054x) (^ 1)
Testing all collisions (low   42-bit) - Expected      128.0, actual        115  (0.898x) (^ 0)
Testing all collisions (high  32-bit) - Expected   130763.2, actual     131224  (1.004x) (^ 3)
Testing all collisions (low   32-bit) - Expected   130763.2, actual     130897  (1.001x) (^ 1)
Testing all collisions (high 21..45 bits) - Worst is 43 bits: 78/64             (1.218x) (^ 0)
Testing all collisions (low  21..45 bits) - Worst is 36 bits: 8237/8193         (1.005x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  42-bit) - Expected      128.0, actual        143  (1.117x) (^ 3)
Testing all collisions (low   42-bit) - Expected      128.0, actual        125  (0.976x) (^ 0)
Testing all collisions (high  32-bit) - Expected   130763.2, actual     130540  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected   130763.2, actual     131305  (1.004x) (^ 3)
Testing all collisions (high 21..45 bits) - Worst is 41 bits: 280/256           (1.093x) (^ 0)
Testing all collisions (low  21..45 bits) - Worst is 29 bits: 1029762/1027316   (1.002x) (^ 2)

Keyset 'Sparse' - 1280-byte keys with up to 2 bits set - 52433921 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  43-bit) - Expected      156.3, actual        160  (1.024x) (^ 1)
Testing all collisions (low   43-bit) - Expected      156.3, actual        149  (0.953x) (^ 0)
Testing all collisions (high  32-bit) - Expected   318764.0, actual     319599  (1.003x) (^ 3)
Testing all collisions (low   32-bit) - Expected   318764.0, actual     319646  (1.003x) (^ 4)
Testing all collisions (high 21..46 bits) - Worst is 37 bits: 10160/10001       (1.016x) (^ 0)
Testing all collisions (low  21..46 bits) - Worst is 32 bits: 319646/318764     (1.003x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  43-bit) - Expected      156.3, actual        149  (0.953x) (^ 0)
Testing all collisions (low   43-bit) - Expected      156.3, actual        160  (1.024x) (^ 1)
Testing all collisions (high  32-bit) - Expected   318764.0, actual     318516  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected   318764.0, actual     318646  (1.000x) (^ 0)
Testing all collisions (high 21..46 bits) - Worst is 34 bits: 80472/79934       (1.007x) (^ 0)
Testing all collisions (low  21..46 bits) - Worst is 35 bits: 40348/39987       (1.009x) (^ 0)


[[[ Keyset 'Permutation' Tests ]]]

Keyset 'Combination 4-bytes [3 low bits; LE]' - up to 7 blocks from a set of 8 - 2396744 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        159  (0.951x) (^ 0)
Testing all collisions (low   34-bit) - Expected      167.2, actual        138  (0.825x) (^ 0)
Testing all collisions (high  32-bit) - Expected      668.6, actual        677  (1.013x) (^ 1)
Testing all collisions (low   32-bit) - Expected      668.6, actual        687  (1.028x) (^ 2)
Testing all collisions (high 19..38 bits) - Worst is 22 bits: 571733/571040     (1.001x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 28 bits: 10821/10668       (1.014x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 14 bits at bit  12:    0.538x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        168  (1.005x) (^ 1)
Testing all collisions (low   34-bit) - Expected      167.2, actual        171  (1.023x) (^ 1)
Testing all collisions (high  32-bit) - Expected      668.6, actual        674  (1.008x) (^ 1)
Testing all collisions (low   32-bit) - Expected      668.6, actual        662  (0.990x) (^ 0)
Testing all collisions (high 19..38 bits) - Worst is 36 bits: 47/42             (1.125x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 38 bits: 14/10             (1.340x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is  8 bits at bit  42:    0.855x  (^ 2)

Keyset 'Combination 4-bytes [3 low bits; BE]' - up to 7 blocks from a set of 8 - 2396744 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        143  (0.855x) (^ 0)
Testing all collisions (low   34-bit) - Expected      167.2, actual        173  (1.035x) (^ 1)
Testing all collisions (high  32-bit) - Expected      668.6, actual        650  (0.972x) (^ 0)
Testing all collisions (low   32-bit) - Expected      668.6, actual        651  (0.974x) (^ 0)
Testing all collisions (high 19..38 bits) - Worst is 23 bits: 312962/311985     (1.003x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 27 bits: 21466/21273       (1.009x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 17 bits at bit   2:    0.501x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        167  (1.000x) (^ 0)
Testing all collisions (low   34-bit) - Expected      167.2, actual        165  (0.987x) (^ 0)
Testing all collisions (high  32-bit) - Expected      668.6, actual        641  (0.959x) (^ 0)
Testing all collisions (low   32-bit) - Expected      668.6, actual        652  (0.975x) (^ 0)
Testing all collisions (high 19..38 bits) - Worst is 26 bits: 42666/42294       (1.009x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 26 bits: 42485/42294       (1.005x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 12 bits at bit  56:    0.633x  (^ 1)

Keyset 'Combination 4-bytes [3 high bits; LE]' - up to 7 blocks from a set of 8 - 2396744 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        179  (1.071x) (^ 2)
Testing all collisions (low   34-bit) - Expected      167.2, actual        164  (0.981x) (^ 0)
Testing all collisions (high  32-bit) - Expected      668.6, actual        649  (0.971x) (^ 0)
Testing all collisions (low   32-bit) - Expected      668.6, actual        663  (0.992x) (^ 0)
Testing all collisions (high 19..38 bits) - Worst is 34 bits: 179/167           (1.071x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 31 bits: 1370/1337         (1.025x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 12 bits at bit  51:    0.603x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        171  (1.023x) (^ 1)
Testing all collisions (low   34-bit) - Expected      167.2, actual        175  (1.047x) (^ 1)
Testing all collisions (high  32-bit) - Expected      668.6, actual        683  (1.022x) (^ 1)
Testing all collisions (low   32-bit) - Expected      668.6, actual        703  (1.051x) (^ 3)
Testing all collisions (high 19..38 bits) - Worst is 35 bits: 96/84             (1.148x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 32 bits: 703/669           (1.051x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 15 bits at bit  48:    0.528x  (^ 0)

Keyset 'Combination 4-bytes [3 high bits; BE]' - up to 7 blocks from a set of 8 - 2396744 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        180  (1.077x) (^ 2)
Testing all collisions (low   34-bit) - Expected      167.2, actual        161  (0.963x) (^ 0)
Testing all collisions (high  32-bit) - Expected      668.6, actual        695  (1.039x) (^ 2)
Testing all collisions (low   32-bit) - Expected      668.6, actual        682  (1.020x) (^ 1)
Testing all collisions (high 19..38 bits) - Worst is 33 bits: 368/334           (1.101x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 24 bits: 163795/163327     (1.003x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is  9 bits at bit  49:    0.696x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      167.2, actual        162  (0.969x) (^ 0)
Testing all collisions (low   34-bit) - Expected      167.2, actual        161  (0.963x) (^ 0)
Testing all collisions (high  32-bit) - Expected      668.6, actual        670  (1.002x) (^ 1)
Testing all collisions (low   32-bit) - Expected      668.6, actual        649  (0.971x) (^ 0)
Testing all collisions (high 19..38 bits) - Worst is 31 bits: 1360/1337         (1.017x) (^ 0)
Testing all collisions (low  19..38 bits) - Worst is 38 bits: 13/10             (1.244x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 15 bits at bit  15:    0.533x  (^ 0)

Keyset 'Combination 4-bytes [3 high+low bits; LE]' - up to 6 blocks from a set of 15 - 12204240 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  39-bit) - Expected      135.5, actual        107  (0.790x) (^ 0)
Testing all collisions (low   39-bit) - Expected      135.5, actual        122  (0.901x) (^ 0)
Testing all collisions (high  32-bit) - Expected    17322.9, actual      17175  (0.991x) (^ 0)
Testing all collisions (low   32-bit) - Expected    17322.9, actual      17223  (0.994x) (^ 0)
Testing all collisions (high 22..42 bits) - Worst is 25 bits: 1973676/1973141   (1.000x) (^ 0)
Testing all collisions (low  22..42 bits) - Worst is 26 bits: 1047938/1045396   (1.002x) (^ 2)
Testing distribution   (any   8..21 bits) - Worst bias is 13 bits at bit  12:    0.590x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  39-bit) - Expected      135.5, actual        148  (1.093x) (^ 2)
Testing all collisions (low   39-bit) - Expected      135.5, actual        127  (0.938x) (^ 0)
Testing all collisions (high  32-bit) - Expected    17322.9, actual      17565  (1.014x) (^ 4)
Testing all collisions (low   32-bit) - Expected    17322.9, actual      17184  (0.992x) (^ 0)
Testing all collisions (high 22..42 bits) - Worst is 31 bits: 34979/34613       (1.011x) (^ 1)
Testing all collisions (low  22..42 bits) - Worst is 24 bits: 3535750/3532925   (1.001x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is  8 bits at bit  31:    0.733x  (^ 0)

Keyset 'Combination 4-bytes [3 high+low bits; BE]' - up to 6 blocks from a set of 15 - 12204240 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  39-bit) - Expected      135.5, actual        135  (1.000x) (^ 0)
Testing all collisions (low   39-bit) - Expected      135.5, actual        128  (0.945x) (^ 0)
Testing all collisions (high  32-bit) - Expected    17322.9, actual      17453  (1.008x) (^ 2)
Testing all collisions (low   32-bit) - Expected    17322.9, actual      17284  (0.998x) (^ 0)
Testing all collisions (high 22..42 bits) - Worst is 27 bits: 539511/538416     (1.002x) (^ 0)
Testing all collisions (low  22..42 bits) - Worst is 30 bits: 69642/69095       (1.008x) (^ 1)
Testing distribution   (any   8..21 bits) - Worst bias is 16 bits at bit   1:    0.591x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  39-bit) - Expected      135.5, actual        131  (0.967x) (^ 0)
Testing all collisions (low   39-bit) - Expected      135.5, actual        127  (0.938x) (^ 0)
Testing all collisions (high  32-bit) - Expected    17322.9, actual      17580  (1.015x) (^ 5)
Testing all collisions (low   32-bit) - Expected    17322.9, actual      17425  (1.006x) (^ 2)
Testing all collisions (high 22..42 bits) - Worst is 31 bits: 34981/34613       (1.011x) (^ 1)
Testing all collisions (low  22..42 bits) - Worst is 28 bits: 274205/273272     (1.003x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 10 bits at bit  51:    0.809x  (^ 2)

Keyset 'Combination 4-bytes [0, low bit; LE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        132  (1.031x) (^ 1)
Testing all collisions (low   40-bit) - Expected      128.0, actual        119  (0.930x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32700  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32717  (1.000x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 39 bits: 279/256           (1.090x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 33 bits: 16537/16373       (1.010x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 20 bits at bit  50:    0.435x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        125  (0.977x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        119  (0.930x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32830  (1.003x) (^ 1)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32517  (0.994x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 37 bits: 1097/1024         (1.071x) (^ 2)
Testing all collisions (low  22..43 bits) - Worst is 28 bits: 514315/513534     (1.002x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 18 bits at bit  47:    0.571x  (^ 2)

Keyset 'Combination 4-bytes [0, low bit; BE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        129  (1.008x) (^ 1)
Testing all collisions (low   40-bit) - Expected      128.0, actual        126  (0.984x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32387  (0.990x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32601  (0.996x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 42 bits: 35/32             (1.094x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 36 bits: 2089/2048         (1.020x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 20 bits at bit  52:    0.488x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        126  (0.984x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        125  (0.977x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32840  (1.004x) (^ 1)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32449  (0.992x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 42 bits: 40/32             (1.250x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 43 bits: 16/16             (1.000x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 12 bits at bit  54:    0.576x  (^ 0)

Keyset 'Combination 4-bytes [0, high bit; LE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        143  (1.117x) (^ 3)
Testing all collisions (low   40-bit) - Expected      128.0, actual        133  (1.039x) (^ 1)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32859  (1.004x) (^ 2)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      33002  (1.008x) (^ 3)
Testing all collisions (high 22..43 bits) - Worst is 39 bits: 293/256           (1.145x) (^ 2)
Testing all collisions (low  22..43 bits) - Worst is 32 bits: 33002/32725       (1.008x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 19 bits at bit  19:    0.536x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        145  (1.133x) (^ 3)
Testing all collisions (low   40-bit) - Expected      128.0, actual         97  (0.758x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      33014  (1.009x) (^ 4)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32643  (0.997x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 29 bits: 260314/259434     (1.003x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 25 bits: 3576969/3574575   (1.001x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 10 bits at bit  51:    0.760x  (^ 1)

Keyset 'Combination 4-bytes [0, high bit; BE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        119  (0.930x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        152  (1.188x) (^ 5)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32819  (1.003x) (^ 1)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32560  (0.995x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 32 bits: 32819/32725       (1.003x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 38 bits: 573/512           (1.119x) (^ 3)
Testing distribution   (any   8..21 bits) - Worst bias is 20 bits at bit  34:    0.439x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        137  (1.070x) (^ 2)
Testing all collisions (low   40-bit) - Expected      128.0, actual        141  (1.102x) (^ 2)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32780  (1.002x) (^ 1)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32954  (1.007x) (^ 3)
Testing all collisions (high 22..43 bits) - Worst is 28 bits: 514892/513534     (1.003x) (^ 1)
Testing all collisions (low  22..43 bits) - Worst is 42 bits: 42/32             (1.313x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 21 bits at bit  12:    0.451x  (^ 0)

Keyset 'Combination 8-bytes [0, low bit; LE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        136  (1.063x) (^ 1)
Testing all collisions (low   40-bit) - Expected      128.0, actual        122  (0.953x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32666  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32754  (1.001x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 40 bits: 136/128           (1.063x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 27 bits: 1008669/1006217   (1.002x) (^ 2)
Testing distribution   (any   8..21 bits) - Worst bias is 15 bits at bit  13:    0.440x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        150  (1.172x) (^ 4)
Testing all collisions (low   40-bit) - Expected      128.0, actual        127  (0.992x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32685  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32465  (0.992x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 36 bits: 2167/2048         (1.058x) (^ 3)
Testing all collisions (low  22..43 bits) - Worst is 42 bits: 37/32             (1.156x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 19 bits at bit  25:    0.384x  (^ 0)

Keyset 'Combination 8-bytes [0, low bit; BE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        111  (0.867x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        113  (0.883x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32869  (1.004x) (^ 2)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32671  (0.998x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 32 bits: 32869/32725       (1.004x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 41 bits: 66/64             (1.031x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 21 bits at bit  19:    0.505x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        156  (1.219x) (^ 6)
Testing all collisions (low   40-bit) - Expected      128.0, actual        119  (0.930x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      33055  (1.010x) (^ 4)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32624  (0.997x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 40 bits: 156/128           (1.219x) (^ 2)
Testing all collisions (low  22..43 bits) - Worst is 23 bits: 9524390/9523881   (1.000x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 15 bits at bit  31:    0.570x  (^ 0)

Keyset 'Combination 8-bytes [0, high bit; LE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        125  (0.977x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        123  (0.961x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32556  (0.995x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32481  (0.993x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 36 bits: 2087/2048         (1.019x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 38 bits: 530/512           (1.035x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 18 bits at bit  26:    0.803x  (^10)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        123  (0.961x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        130  (1.016x) (^ 1)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32913  (1.006x) (^ 2)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32679  (0.999x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 29 bits: 260637/259434     (1.005x) (^ 2)
Testing all collisions (low  22..43 bits) - Worst is 28 bits: 514313/513534     (1.002x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 12 bits at bit  31:    0.680x  (^ 1)

Keyset 'Combination 8-bytes [0, high bit; BE]' - up to 23 blocks from a set of 2 - 16777214 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        130  (1.016x) (^ 1)
Testing all collisions (low   40-bit) - Expected      128.0, actual        117  (0.914x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32996  (1.008x) (^ 3)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32686  (0.999x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 28 bits: 514902/513534     (1.003x) (^ 1)
Testing all collisions (low  22..43 bits) - Worst is 31 bits: 65815/65366       (1.007x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 14 bits at bit  32:    0.620x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        121  (0.945x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        126  (0.984x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32336  (0.988x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32909  (1.006x) (^ 2)
Testing all collisions (high 22..43 bits) - Worst is 27 bits: 1007262/1006217   (1.001x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 31 bits: 65922/65366       (1.009x) (^ 1)
Testing distribution   (any   8..21 bits) - Worst bias is 16 bits at bit  11:    0.572x  (^ 1)


[[[ Keyset 'Text' Tests ]]]

Keyset 'Dict' - dictionary words - 528194 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected       32.5, actual         36  (1.108x) (^ 1)
Testing all collisions (low   32-bit) - Expected       32.5, actual         41  (1.262x) (^ 3)
Testing all collisions (high  30-bit) - Expected      129.9, actual        140  (1.078x) (^ 2)
Testing all collisions (low   30-bit) - Expected      129.9, actual        121  (0.932x) (^ 0)
Testing all collisions (high 17..33 bits) - Worst is 29 bits: 294/260           (1.132x) (^ 1)
Testing all collisions (low  17..33 bits) - Worst is 32 bits: 41/32             (1.262x) (^ 0)
Testing distribution   (any   8..16 bits) - Worst bias is  9 bits at bit  53:    0.551x  (^ 0)

Keyset 'TextNum' - numbers in text form without commas - 10000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      181.9, actual        189  (1.039x) (^ 1)
Testing all collisions (low   38-bit) - Expected      181.9, actual        183  (1.006x) (^ 1)
Testing all collisions (high  32-bit) - Expected    11632.5, actual      11607  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected    11632.5, actual      11611  (0.998x) (^ 0)
Testing all collisions (high 21..42 bits) - Worst is 34 bits: 2949/2910         (1.013x) (^ 0)
Testing all collisions (low  21..42 bits) - Worst is 24 bits: 2467629/2466790   (1.000x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 14 bits at bit  28:    0.716x  (^ 4)

Keyset 'TextNum' - numbers in text form with commas - 10000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      181.9, actual        189  (1.039x) (^ 1)
Testing all collisions (low   38-bit) - Expected      181.9, actual        172  (0.946x) (^ 0)
Testing all collisions (high  32-bit) - Expected    11632.5, actual      11588  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected    11632.5, actual      11697  (1.006x) (^ 1)
Testing all collisions (high 21..42 bits) - Worst is 28 bits: 184732/183973     (1.004x) (^ 0)
Testing all collisions (low  21..42 bits) - Worst is 26 bits: 710421/709389     (1.001x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 20 bits at bit  20:    0.427x  (^ 0)

Keyset 'Text' - keys of form "FXXXXB" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        112  (0.992x) (^ 0)
Testing all collisions (low   40-bit) - Expected      112.8, actual        116  (1.028x) (^ 1)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28660  (0.993x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28497  (0.988x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 38 bits: 479/451           (1.061x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 38 bits: 477/451           (1.057x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 21 bits at bit  27:    0.550x  (^ 2)

Keyset 'Text' - keys of form "FBXXXX" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        117  (1.037x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual        123  (1.090x) (^ 2)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28813  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      29049  (1.007x) (^ 2)
Testing all collisions (high 22..43 bits) - Worst is 38 bits: 498/451           (1.103x) (^ 1)
Testing all collisions (low  22..43 bits) - Worst is 39 bits: 262/226           (1.161x) (^ 2)
Testing distribution   (any   8..21 bits) - Worst bias is 13 bits at bit  61:    0.711x  (^ 3)

Keyset 'Text' - keys of form "XXXXFB" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual         97  (0.860x) (^ 0)
Testing all collisions (low   40-bit) - Expected      112.8, actual        116  (1.028x) (^ 1)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28993  (1.005x) (^ 2)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28888  (1.001x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 34 bits: 7435/7220         (1.030x) (^ 3)
Testing all collisions (low  22..43 bits) - Worst is 31 bits: 57847/57637       (1.004x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 13 bits at bit  36:    0.557x  (^ 0)

Keyset 'Text' - keys of form "FooXXXXBar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        106  (0.939x) (^ 0)
Testing all collisions (low   40-bit) - Expected      112.8, actual        122  (1.081x) (^ 2)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28760  (0.997x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28891  (1.001x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 29 bits: 229516/228869     (1.003x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 39 bits: 244/226           (1.081x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 18 bits at bit  40:    0.534x  (^ 1)

Keyset 'Text' - keys of form "FooBarXXXX" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        116  (1.028x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual        119  (1.055x) (^ 1)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28901  (1.002x) (^ 1)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28705  (0.995x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 30 bits: 115601/114993     (1.005x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 28 bits: 455004/453315     (1.004x) (^ 2)
Testing distribution   (any   8..21 bits) - Worst bias is 14 bits at bit  33:    0.789x  (^ 6)

Keyset 'Text' - keys of form "XXXXFooBar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        105  (0.930x) (^ 0)
Testing all collisions (low   40-bit) - Expected      112.8, actual        121  (1.072x) (^ 2)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28515  (0.988x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28793  (0.998x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 36 bits: 1827/1805         (1.012x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 42 bits: 39/28             (1.382x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is  8 bits at bit   0:    0.998x  (^ 5)

Keyset 'Text' - keys of form "FooooXXXXBaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        109  (0.966x) (^ 0)
Testing all collisions (low   40-bit) - Expected      112.8, actual         98  (0.868x) (^ 0)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      29024  (1.006x) (^ 2)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28928  (1.003x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 27 bits: 890776/889322     (1.002x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 27 bits: 890942/889322     (1.002x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 21 bits at bit  21:    0.445x  (^ 0)

Keyset 'Text' - keys of form "FooooBaaarXXXX" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        120  (1.063x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual        103  (0.913x) (^ 0)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28798  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28682  (0.994x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 39 bits: 258/226           (1.143x) (^ 1)
Testing all collisions (low  22..43 bits) - Worst is 29 bits: 229222/228869     (1.002x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is  8 bits at bit  46:    0.700x  (^ 0)

Keyset 'Text' - keys of form "XXXXFooooBaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        117  (1.037x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual         96  (0.851x) (^ 0)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      29041  (1.006x) (^ 2)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      29097  (1.008x) (^ 3)
Testing all collisions (high 22..43 bits) - Worst is 32 bits: 29041/28854       (1.006x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 33 bits: 14649/14436       (1.015x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 16 bits at bit  28:    0.496x  (^ 0)

Keyset 'Text' - keys of form "FooooooXXXXBaaaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        129  (1.143x) (^ 3)
Testing all collisions (low   40-bit) - Expected      112.8, actual        120  (1.063x) (^ 1)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28987  (1.005x) (^ 2)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28938  (1.003x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 38 bits: 485/451           (1.074x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 31 bits: 57979/57637       (1.006x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 20 bits at bit  60:    0.550x  (^ 2)

Keyset 'Text' - keys of form "FooooooBaaaaarXXXX" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        134  (1.187x) (^ 5)
Testing all collisions (low   40-bit) - Expected      112.8, actual        101  (0.895x) (^ 0)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28947  (1.003x) (^ 1)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28954  (1.003x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 40 bits: 134/113           (1.187x) (^ 1)
Testing all collisions (low  22..43 bits) - Worst is 25 bits: 3183080/3181142   (1.001x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 19 bits at bit  63:    0.628x  (^ 4)

Keyset 'Text' - keys of form "XXXXFooooooBaaaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        131  (1.161x) (^ 4)
Testing all collisions (low   40-bit) - Expected      112.8, actual        101  (0.895x) (^ 0)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28752  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28697  (0.995x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 39 bits: 253/226           (1.121x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 25 bits: 3182501/3181142   (1.000x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 19 bits at bit  10:    0.567x  (^ 2)

Keyset 'Text' - keys of form "FooooooooXXXXBaaaaaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        117  (1.037x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual        115  (1.019x) (^ 1)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28734  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28805  (0.998x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 41 bits: 66/56             (1.170x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 37 bits: 934/903           (1.035x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 16 bits at bit  34:    0.548x  (^ 0)

Keyset 'Text' - keys of form "FooooooooBaaaaaaarXXXX" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        104  (0.922x) (^ 0)
Testing all collisions (low   40-bit) - Expected      112.8, actual        116  (1.028x) (^ 1)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28924  (1.002x) (^ 1)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28894  (1.001x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 42 bits: 39/28             (1.382x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 37 bits: 958/903           (1.061x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 19 bits at bit   7:    0.495x  (^ 0)

Keyset 'Text' - keys of form "XXXXFooooooooBaaaaaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        102  (0.904x) (^ 0)
Testing all collisions (low   40-bit) - Expected      112.8, actual        124  (1.099x) (^ 2)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28883  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28839  (0.999x) (^ 0)
Testing all collisions (high 22..43 bits) - Worst is 29 bits: 229447/228869     (1.003x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 33 bits: 14623/14436       (1.013x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 12 bits at bit  17:    0.476x  (^ 0)

Keyset 'Text' - keys of form "FooooooooooXXXXBaaaaaaaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        116  (1.028x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual        101  (0.895x) (^ 0)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28727  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28962  (1.004x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 38 bits: 479/451           (1.061x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 30 bits: 115386/114993     (1.003x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 17 bits at bit   5:    0.468x  (^ 0)

Keyset 'Text' - keys of form "FooooooooooBaaaaaaaaarXXXX" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        113  (1.000x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual        127  (1.125x) (^ 3)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28833  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      28931  (1.003x) (^ 1)
Testing all collisions (high 22..43 bits) - Worst is 31 bits: 58137/57637       (1.009x) (^ 1)
Testing all collisions (low  22..43 bits) - Worst is 41 bits: 70/56             (1.241x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 15 bits at bit  38:    0.450x  (^ 0)

Keyset 'Text' - keys of form "XXXXFooooooooooBaaaaaaaaar" - 15752961 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      112.8, actual        117  (1.037x) (^ 1)
Testing all collisions (low   40-bit) - Expected      112.8, actual        102  (0.904x) (^ 0)
Testing all collisions (high  32-bit) - Expected    28853.8, actual      28745  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected    28853.8, actual      29009  (1.005x) (^ 2)
Testing all collisions (high 22..43 bits) - Worst is 34 bits: 7333/7220         (1.016x) (^ 0)
Testing all collisions (low  22..43 bits) - Worst is 33 bits: 14590/14436       (1.011x) (^ 0)
Testing distribution   (any   8..21 bits) - Worst bias is 12 bits at bit  51:    0.587x  (^ 0)

Keyset 'Words' - 1-4 random chars from alnum charset - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        107  (0.919x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        126  (1.082x) (^ 2)
Testing all collisions (high 18..35 bits) - Worst is 28 bits: 1918/1860         (1.031x) (^ 0)
Testing all collisions (low  18..35 bits) - Worst is 35 bits: 19/15             (1.306x) (^ 0)
Testing distribution   (any   8..17 bits) - Worst bias is 14 bits at bit  14:    0.534x  (^ 0)

Keyset 'Words' - 5-8 random chars from alnum charset - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        128  (1.100x) (^ 2)
Testing all collisions (low   32-bit) - Expected      116.4, actual        112  (0.962x) (^ 0)
Testing all collisions (high 18..35 bits) - Worst is 31 bits: 256/233           (1.100x) (^ 0)
Testing all collisions (low  18..35 bits) - Worst is 28 bits: 1915/1860         (1.029x) (^ 0)
Testing distribution   (any   8..17 bits) - Worst bias is 13 bits at bit   6:    0.532x  (^ 0)

Keyset 'Words' - 1-16 random chars from alnum charset - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        115  (0.988x) (^ 0)
Testing all collisions (low   32-bit) - Expected      116.4, actual        103  (0.885x) (^ 0)
Testing all collisions (high 18..35 bits) - Worst is 22 bits: 110318/110274     (1.000x) (^ 0)
Testing all collisions (low  18..35 bits) - Worst is 26 bits: 7511/7414         (1.013x) (^ 0)
Testing distribution   (any   8..17 bits) - Worst bias is  8 bits at bit  36:    0.831x  (^ 2)

Keyset 'Words' - 1-32 random chars from alnum charset - 1000000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      116.4, actual        135  (1.160x) (^ 4)
Testing all collisions (low   32-bit) - Expected      116.4, actual        121  (1.039x) (^ 1)
Testing all collisions (high 18..35 bits) - Worst is 26 bits: 7614/7414         (1.027x) (^ 2)
Testing all collisions (low  18..35 bits) - Worst is 24 bits: 29392/29219       (1.006x) (^ 0)
Testing distribution   (any   8..17 bits) - Worst bias is 14 bits at bit  24:    0.483x  (^ 0)

Keyset 'Long' - 1968-2128 random chars from alnum charset - varying first 80 chars - 4960000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        182  (1.017x) (^ 1)
Testing all collisions (low   36-bit) - Expected      179.0, actual        175  (0.978x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2775  (0.969x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2932  (1.024x) (^ 3)
Testing all collisions (high 20..40 bits) - Worst is 22 bits: 2051833/2051226   (1.000x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 33 bits: 1501/1432         (1.048x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  31:    0.523x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        175  (0.978x) (^ 0)
Testing all collisions (low   36-bit) - Expected      179.0, actual        178  (0.994x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2872  (1.003x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2771  (0.968x) (^ 0)
Testing all collisions (high 20..40 bits) - Worst is 31 bits: 5825/5724         (1.018x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 29 bits: 22926/22842       (1.004x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 13 bits at bit   6:    0.484x  (^ 0)

Keyset 'Long' - 1968-2128 random chars from alnum charset - varying last 80 chars - 4960000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        189  (1.056x) (^ 2)
Testing all collisions (low   36-bit) - Expected      179.0, actual        186  (1.039x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2905  (1.015x) (^ 2)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2853  (0.997x) (^ 0)
Testing all collisions (high 20..40 bits) - Worst is 37 bits: 104/89            (1.162x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 28 bits: 45760/45543       (1.005x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 13 bits at bit  31:    0.589x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        191  (1.067x) (^ 2)
Testing all collisions (low   36-bit) - Expected      179.0, actual        189  (1.056x) (^ 2)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2902  (1.014x) (^ 2)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2936  (1.026x) (^ 3)
Testing all collisions (high 20..40 bits) - Worst is 39 bits: 29/22             (1.296x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 29 bits: 23104/22842       (1.011x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 14 bits at bit  60:    0.711x  (^ 3)

Keyset 'Long' - 4016-4176 random chars from alnum charset - varying first 80 chars - 4960000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        180  (1.006x) (^ 1)
Testing all collisions (low   36-bit) - Expected      179.0, actual        191  (1.067x) (^ 2)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2812  (0.982x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2957  (1.033x) (^ 4)
Testing all collisions (high 20..40 bits) - Worst is 34 bits: 771/716           (1.077x) (^ 1)
Testing all collisions (low  20..40 bits) - Worst is 39 bits: 35/22             (1.564x) (^ 2)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit   5:    0.479x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        157  (0.877x) (^ 0)
Testing all collisions (low   36-bit) - Expected      179.0, actual        157  (0.877x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2864  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2877  (1.005x) (^ 1)
Testing all collisions (high 20..40 bits) - Worst is 29 bits: 23095/22842       (1.011x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 24 bits: 667659/665971     (1.003x) (^ 1)
Testing distribution   (any   8..19 bits) - Worst bias is  9 bits at bit  12:    0.666x  (^ 0)

Keyset 'Long' - 4016-4176 random chars from alnum charset - varying last 80 chars - 4960000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        160  (0.894x) (^ 0)
Testing all collisions (low   36-bit) - Expected      179.0, actual        168  (0.939x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2781  (0.971x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2786  (0.973x) (^ 0)
Testing all collisions (high 20..40 bits) - Worst is 26 bits: 179525/178863     (1.004x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 28 bits: 45640/45543       (1.002x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 15 bits at bit  41:    0.604x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        164  (0.916x) (^ 0)
Testing all collisions (low   36-bit) - Expected      179.0, actual        167  (0.933x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2837  (0.991x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2854  (0.997x) (^ 0)
Testing all collisions (high 20..40 bits) - Worst is 25 bits: 350416/349177     (1.004x) (^ 1)
Testing all collisions (low  20..40 bits) - Worst is 21 bits: 3060602/3059852   (1.000x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  8 bits at bit  59:    0.640x  (^ 0)

Keyset 'Long' - 8112-8272 random chars from alnum charset - varying first 80 chars - 4960000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        177  (0.989x) (^ 0)
Testing all collisions (low   36-bit) - Expected      179.0, actual        195  (1.089x) (^ 2)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2859  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2927  (1.022x) (^ 3)
Testing all collisions (high 20..40 bits) - Worst is 30 bits: 11591/11438       (1.013x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 40 bits: 17/11             (1.520x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 13 bits at bit  61:    0.700x  (^ 2)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        194  (1.084x) (^ 2)
Testing all collisions (low   36-bit) - Expected      179.0, actual        156  (0.872x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2876  (1.005x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2860  (0.999x) (^ 0)
Testing all collisions (high 20..40 bits) - Worst is 35 bits: 394/358           (1.101x) (^ 1)
Testing all collisions (low  20..40 bits) - Worst is 40 bits: 20/11             (1.788x) (^ 2)
Testing distribution   (any   8..19 bits) - Worst bias is 17 bits at bit  44:    0.503x  (^ 0)

Keyset 'Long' - 8112-8272 random chars from alnum charset - varying last 80 chars - 4960000 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        159  (0.888x) (^ 0)
Testing all collisions (low   36-bit) - Expected      179.0, actual        198  (1.106x) (^ 3)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2858  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2864  (1.000x) (^ 1)
Testing all collisions (high 20..40 bits) - Worst is 23 bits: 1215780/1215487   (1.000x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 35 bits: 403/358           (1.126x) (^ 2)
Testing distribution   (any   8..19 bits) - Worst bias is 14 bits at bit   7:    0.623x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      179.0, actual        172  (0.961x) (^ 0)
Testing all collisions (low   36-bit) - Expected      179.0, actual        170  (0.950x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2862.9, actual       2900  (1.013x) (^ 2)
Testing all collisions (low   32-bit) - Expected     2862.9, actual       2897  (1.012x) (^ 1)
Testing all collisions (high 20..40 bits) - Worst is 29 bits: 22966/22842       (1.005x) (^ 0)
Testing all collisions (low  20..40 bits) - Worst is 29 bits: 23188/22842       (1.015x) (^ 2)
Testing distribution   (any   8..19 bits) - Worst bias is 17 bits at bit  59:    0.569x  (^ 1)


[[[ Keyset 'TwoBytes' Tests ]]]

Keyset 'TwoBytes' - all [2, 20]-byte keys with 1 or 2 non-zero bytes - 86536545 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  45-bit) - Expected      106.4, actual         89  (0.836x) (^ 0)
Testing all collisions (low   45-bit) - Expected      106.4, actual         94  (0.883x) (^ 0)
Testing all collisions (high  32-bit) - Expected   865959.1, actual     866463  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected   865959.1, actual     865045  (0.999x) (^ 0)
Testing all collisions (high 22..48 bits) - Worst is 36 bits: 54782/54464       (1.006x) (^ 0)
Testing all collisions (low  22..48 bits) - Worst is 36 bits: 54891/54464       (1.008x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  45-bit) - Expected      106.4, actual        113  (1.062x) (^ 1)
Testing all collisions (low   45-bit) - Expected      106.4, actual         91  (0.855x) (^ 0)
Testing all collisions (high  32-bit) - Expected   865959.1, actual     867161  (1.001x) (^ 3)
Testing all collisions (low   32-bit) - Expected   865959.1, actual     865272  (0.999x) (^ 0)
Testing all collisions (high 22..48 bits) - Worst is 32 bits: 867161/865959     (1.001x) (^ 0)
Testing all collisions (low  22..48 bits) - Worst is 38 bits: 13849/13620       (1.017x) (^ 0)

Keyset 'TwoBytes' - all 32-byte keys with 1 or 2 non-zero bytes - 32260560 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          1  (------) (^ 9)
Testing all collisions (high  42-bit) - Expected      118.3, actual        110  (0.930x) (^ 0)
Testing all collisions (low   42-bit) - Expected      118.3, actual        121  (1.023x) (^ 1)
Testing all collisions (high  32-bit) - Expected   120855.7, actual     120680  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected   120855.7, actual     120398  (0.996x) (^ 0)
Testing all collisions (high 21..45 bits) - Worst is 41 bits: 254/237           (1.073x) (^ 0)
Testing all collisions (low  21..45 bits) - Worst is 44 bits: 40/30             (1.352x) (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  42-bit) - Expected      118.3, actual        115  (0.972x) (^ 0)
Testing all collisions (low   42-bit) - Expected      118.3, actual        109  (0.921x) (^ 0)
Testing all collisions (high  32-bit) - Expected   120855.7, actual     121035  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected   120855.7, actual     120755  (0.999x) (^ 0)
Testing all collisions (high 21..45 bits) - Worst is 29 bits: 951980/950142     (1.002x) (^ 0)
Testing all collisions (low  21..45 bits) - Worst is 37 bits: 3833/3786         (1.012x) (^ 0)

Keyset 'TwoBytes' - all 48-byte keys with 1 or 2 non-zero bytes - 73360440 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  44-bit) - Expected      153.0, actual        162  (1.059x) (^ 2)
Testing all collisions (low   44-bit) - Expected      153.0, actual        146  (0.955x) (^ 0)
Testing all collisions (high  32-bit) - Expected   622966.7, actual     623155  (1.000x) (^ 1)
Testing all collisions (low   32-bit) - Expected   622966.7, actual     624023  (1.002x) (^ 3)
Testing all collisions (high 22..47 bits) - Worst is 27 bits: 16848141/16845058 (1.000x) (^ 0)
Testing all collisions (low  22..47 bits) - Worst is 36 bits: 39582/39143       (1.011x) (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  44-bit) - Expected      153.0, actual        143  (0.935x) (^ 0)
Testing all collisions (low   44-bit) - Expected      153.0, actual        151  (0.987x) (^ 0)
Testing all collisions (high  32-bit) - Expected   622966.7, actual     623475  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected   622966.7, actual     622645  (0.999x) (^ 0)
Testing all collisions (high 22..47 bits) - Worst is 29 bits: 4797495/4791445   (1.001x) (^ 3)
Testing all collisions (low  22..47 bits) - Worst is 47 bits: 22/19             (1.151x) (^ 0)

Keyset 'OneByte ' - all 1024-byte keys with 1 non-zero byte  - 261120 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        7.9, actual         10  (1.260x) (^ 1)
Testing all collisions (low   32-bit) - Expected        7.9, actual          8  (1.000x) (^ 1)
Testing all collisions (high  28-bit) - Expected      127.0, actual        110  (0.866x) (^ 0)
Testing all collisions (low   28-bit) - Expected      127.0, actual        125  (0.985x) (^ 0)
Testing all collisions (high 16..31 bits) - Worst is 30 bits: 34/32             (1.071x) (^ 0)
Testing all collisions (low  16..31 bits) - Worst is 19 bits: 55630/55450       (1.003x) (^ 0)
Testing distribution   (any   8..15 bits) - Worst bias is 10 bits at bit  47:    0.542x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected        7.9, actual          9  (1.134x) (^ 1)
Testing all collisions (low   32-bit) - Expected        7.9, actual          9  (1.134x) (^ 1)
Testing all collisions (high  28-bit) - Expected      127.0, actual        130  (1.024x) (^ 1)
Testing all collisions (low   28-bit) - Expected      127.0, actual        137  (1.079x) (^ 2)
Testing all collisions (high 16..31 bits) - Worst is 29 bits: 78/63             (1.229x) (^ 0)
Testing all collisions (low  16..31 bits) - Worst is 22 bits: 8101/7962         (1.017x) (^ 0)
Testing distribution   (any   8..15 bits) - Worst bias is  8 bits at bit  11:    0.790x  (^ 1)

Keyset 'OneByte ' - all 2048-byte keys with 1 non-zero byte  - 522240 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected       31.7, actual         20  (0.630x) (^ 0)
Testing all collisions (low   32-bit) - Expected       31.7, actual         28  (0.882x) (^ 0)
Testing all collisions (high  30-bit) - Expected      127.0, actual        128  (1.008x) (^ 1)
Testing all collisions (low   30-bit) - Expected      127.0, actual        123  (0.969x) (^ 0)
Testing all collisions (high 17..33 bits) - Worst is 23 bits: 16247/15924       (1.020x) (^ 3)
Testing all collisions (low  17..33 bits) - Worst is 21 bits: 60179/59947       (1.004x) (^ 0)
Testing distribution   (any   8..16 bits) - Worst bias is 12 bits at bit  13:    0.622x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected       31.7, actual         41  (1.291x) (^ 3)
Testing all collisions (low   32-bit) - Expected       31.7, actual         23  (0.724x) (^ 0)
Testing all collisions (high  30-bit) - Expected      127.0, actual        131  (1.032x) (^ 1)
Testing all collisions (low   30-bit) - Expected      127.0, actual        112  (0.882x) (^ 0)
Testing all collisions (high 17..33 bits) - Worst is 28 bits: 554/508           (1.091x) (^ 1)
Testing all collisions (low  17..33 bits) - Worst is 24 bits: 8160/8044         (1.014x) (^ 0)
Testing distribution   (any   8..16 bits) - Worst bias is 14 bits at bit   0:    0.607x  (^ 1)

Keyset 'OneByte ' - all 4096-byte keys with 1 non-zero byte  - 1044480 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      127.0, actual        144  (1.134x) (^ 3)
Testing all collisions (low   32-bit) - Expected      127.0, actual        125  (0.984x) (^ 0)
Testing all collisions (high 18..35 bits) - Worst is 30 bits: 545/508           (1.073x) (^ 0)
Testing all collisions (low  18..35 bits) - Worst is 29 bits: 1034/1015         (1.018x) (^ 0)
Testing distribution   (any   8..17 bits) - Worst bias is 17 bits at bit  49:    0.423x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected      127.0, actual        142  (1.118x) (^ 3)
Testing all collisions (low   32-bit) - Expected      127.0, actual        130  (1.024x) (^ 1)
Testing all collisions (high 18..35 bits) - Worst is 33 bits: 82/63             (1.291x) (^ 2)
Testing all collisions (low  18..35 bits) - Worst is 24 bits: 32139/31848       (1.009x) (^ 0)
Testing distribution   (any   8..17 bits) - Worst bias is 17 bits at bit  43:    0.437x  (^ 0)


[[[ Keyset 'PerlinNoise' Tests ]]]

Generating coordinates from   2-byte keys - 16777216 keys
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        122  (0.953x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        118  (0.922x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32612  (0.997x) (^ 0)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32977  (1.008x) (^ 3)
Testing all collisions (high 20..43 bits) - Worst is 26 bits: 1934055/1932788   (1.001x) (^ 0)
Testing all collisions (low  20..43 bits) - Worst is 25 bits: 3578270/3574576   (1.001x) (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        116  (0.906x) (^ 0)
Testing all collisions (low   40-bit) - Expected      128.0, actual        126  (0.984x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32900  (1.005x) (^ 2)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32552  (0.995x) (^ 0)
Testing all collisions (high 20..43 bits) - Worst is 27 bits: 1007623/1006217   (1.001x) (^ 0)
Testing all collisions (low  20..43 bits) - Worst is 24 bits: 6173619/6171993   (1.000x) (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  40-bit) - Expected      128.0, actual        131  (1.023x) (^ 1)
Testing all collisions (low   40-bit) - Expected      128.0, actual        116  (0.906x) (^ 0)
Testing all collisions (high  32-bit) - Expected    32725.4, actual      32945  (1.007x) (^ 3)
Testing all collisions (low   32-bit) - Expected    32725.4, actual      32701  (0.999x) (^ 0)
Testing all collisions (high 20..43 bits) - Worst is 34 bits: 8348/8189         (1.019x) (^ 0)
Testing all collisions (low  20..43 bits) - Worst is 27 bits: 1007854/1006217   (1.002x) (^ 0)


[[[ Keyset 'Bitflip' Tests ]]]

Testing   3-byte keys, 1572864 reps....................  0 failed, worst is key bit  13
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      144.0, actual        155  (1.076x) (^ 2)
Testing all collisions (low   35-bit) - Expected      144.0, actual        146  (1.014x) (^ 1)
Testing all collisions (high  32-bit) - Expected     1151.7, actual       1166  (1.012x) (^ 1)
Testing all collisions (low   32-bit) - Expected     1151.7, actual       1215  (1.055x) (^ 4)
Testing all collisions (high 20..38 bits) - Worst is 28 bits: 18520/18360       (1.009x) (^ 0)
Testing all collisions (low  20..38 bits) - Worst is 32 bits: 1215/1152         (1.055x) (^ 1)
Testing distribution   (any   8..19 bits) - Worst bias is 10 bits at bit  28:    0.888x  (^ 5)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  33-bit) - Expected      144.0, actual        153  (1.063x) (^ 2)
Testing all collisions (low   33-bit) - Expected      144.0, actual        140  (0.972x) (^ 0)
Testing all collisions (high  32-bit) - Expected      288.0, actual        299  (1.038x) (^ 1)
Testing all collisions (low   32-bit) - Expected      288.0, actual        279  (0.969x) (^ 0)
Testing all collisions (high 19..36 bits) - Worst is 23 bits: 139625/138656     (1.007x) (^ 3)
Testing all collisions (low  19..36 bits) - Worst is 29 bits: 2352/2302         (1.022x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 16 bits at bit  56:    0.536x  (^ 0)

Testing   4-byte keys, 1572864 reps....................  0 failed, worst is key bit   6
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      144.0, actual        159  (1.104x) (^ 3)
Testing all collisions (low   35-bit) - Expected      144.0, actual        164  (1.139x) (^ 4)
Testing all collisions (high  32-bit) - Expected     1151.7, actual       1236  (1.073x) (^ 7)
Testing all collisions (low   32-bit) - Expected     1151.7, actual       1192  (1.035x) (^ 3)
Testing all collisions (high 20..38 bits) - Worst is 33 bits: 641/576           (1.113x) (^ 3)
Testing all collisions (low  20..38 bits) - Worst is 34 bits: 332/288           (1.153x) (^ 3)
Testing distribution   (any   8..19 bits) - Worst bias is 18 bits at bit  10:    0.702x  (^ 6)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  33-bit) - Expected      144.0, actual        133  (0.924x) (^ 0)
Testing all collisions (low   33-bit) - Expected      144.0, actual        135  (0.938x) (^ 0)
Testing all collisions (high  32-bit) - Expected      288.0, actual        287  (0.997x) (^ 0)
Testing all collisions (low   32-bit) - Expected      288.0, actual        290  (1.007x) (^ 1)
Testing all collisions (high 19..36 bits) - Worst is 27 bits: 9269/9180         (1.010x) (^ 0)
Testing all collisions (low  19..36 bits) - Worst is 24 bits: 72053/71477       (1.008x) (^ 2)
Testing distribution   (any   8..18 bits) - Worst bias is 10 bits at bit  14:    0.711x  (^ 1)

Testing   8-byte keys, 1572864 reps....................  0 failed, worst is key bit  56
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      144.0, actual        133  (0.924x) (^ 0)
Testing all collisions (low   35-bit) - Expected      144.0, actual        149  (1.035x) (^ 1)
Testing all collisions (high  32-bit) - Expected     1151.7, actual       1247  (1.083x) (^ 8)
Testing all collisions (low   32-bit) - Expected     1151.7, actual       1138  (0.988x) (^ 0)
Testing all collisions (high 20..38 bits) - Worst is 33 bits: 649/576           (1.127x) (^ 5)
Testing all collisions (low  20..38 bits) - Worst is 34 bits: 309/288           (1.073x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit   4:    0.574x  (^ 2)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  33-bit) - Expected      144.0, actual        154  (1.070x) (^ 2)
Testing all collisions (low   33-bit) - Expected      144.0, actual        158  (1.097x) (^ 2)
Testing all collisions (high  32-bit) - Expected      288.0, actual        310  (1.077x) (^ 3)
Testing all collisions (low   32-bit) - Expected      288.0, actual        338  (1.174x) (^ 8)
Testing all collisions (high 19..36 bits) - Worst is 32 bits: 310/288           (1.077x) (^ 0)
Testing all collisions (low  19..36 bits) - Worst is 32 bits: 338/288           (1.174x) (^ 4)
Testing distribution   (any   8..18 bits) - Worst bias is 18 bits at bit  21:    0.519x  (^ 1)


[[[ Seed 'Zeroes' Tests ]]]

Keyset 'SeedZeroes' - up to 1280-byte keys, seeds with up to 2 set bits - 4160 seeds - 5324800 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      103.1, actual         86  (0.834x) (^ 0)
Testing all collisions (low   37-bit) - Expected      103.1, actual         97  (0.940x) (^ 0)
Testing all collisions (high  32-bit) - Expected     3299.4, actual       3305  (1.002x) (^ 1)
Testing all collisions (low   32-bit) - Expected     3299.4, actual       3346  (1.014x) (^ 2)
Testing all collisions (high 21..40 bits) - Worst is 30 bits: 13277/13181       (1.007x) (^ 0)
Testing all collisions (low  21..40 bits) - Worst is 29 bits: 26461/26319       (1.005x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is  9 bits at bit  57:    0.773x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      103.1, actual         97  (0.940x) (^ 0)
Testing all collisions (low   37-bit) - Expected      103.1, actual         79  (0.766x) (^ 0)
Testing all collisions (high  32-bit) - Expected     3299.4, actual       3242  (0.983x) (^ 0)
Testing all collisions (low   32-bit) - Expected     3299.4, actual       3359  (1.018x) (^ 2)
Testing all collisions (high 21..40 bits) - Worst is 23 bits: 1383822/1382655   (1.001x) (^ 0)
Testing all collisions (low  21..40 bits) - Worst is 30 bits: 13468/13181       (1.022x) (^ 3)
Testing distribution   (any   8..20 bits) - Worst bias is 19 bits at bit  15:    0.475x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      103.1, actual        105  (1.018x) (^ 1)
Testing all collisions (low   37-bit) - Expected      103.1, actual         98  (0.950x) (^ 0)
Testing all collisions (high  32-bit) - Expected     3299.4, actual       3311  (1.004x) (^ 1)
Testing all collisions (low   32-bit) - Expected     3299.4, actual       3351  (1.016x) (^ 2)
Testing all collisions (high 21..40 bits) - Worst is 33 bits: 1707/1650         (1.035x) (^ 0)
Testing all collisions (low  21..40 bits) - Worst is 31 bits: 6749/6596         (1.023x) (^ 1)
Testing distribution   (any   8..20 bits) - Worst bias is  9 bits at bit   3:    0.737x  (^ 0)

Keyset 'SeedZeroes' - up to 8448-byte keys, seeds with up to 2 set bits - 4160 seeds - 35143680 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  42-bit) - Expected      140.4, actual        147  (1.047x) (^ 1)
Testing all collisions (low   42-bit) - Expected      140.4, actual        152  (1.083x) (^ 2)
Testing all collisions (high  32-bit) - Expected   143390.7, actual     144011  (1.004x) (^ 4)
Testing all collisions (low   32-bit) - Expected   143390.7, actual     143529  (1.001x) (^ 1)
Testing all collisions (high 23..45 bits) - Worst is 34 bits: 36263/35921       (1.010x) (^ 0)
Testing all collisions (low  23..45 bits) - Worst is 36 bits: 9104/8985         (1.013x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is 16 bits at bit  29:    0.574x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  42-bit) - Expected      140.4, actual        148  (1.054x) (^ 1)
Testing all collisions (low   42-bit) - Expected      140.4, actual        136  (0.969x) (^ 0)
Testing all collisions (high  32-bit) - Expected   143390.7, actual     143254  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected   143390.7, actual     143311  (0.999x) (^ 0)
Testing all collisions (high 23..45 bits) - Worst is 35 bits: 18259/17967       (1.016x) (^ 1)
Testing all collisions (low  23..45 bits) - Worst is 38 bits: 2317/2246         (1.031x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is  8 bits at bit  34:    0.672x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  42-bit) - Expected      140.4, actual        125  (0.890x) (^ 0)
Testing all collisions (low   42-bit) - Expected      140.4, actual        138  (0.983x) (^ 0)
Testing all collisions (high  32-bit) - Expected   143390.7, actual     144003  (1.004x) (^ 4)
Testing all collisions (low   32-bit) - Expected   143390.7, actual     143251  (0.999x) (^ 0)
Testing all collisions (high 23..45 bits) - Worst is 32 bits: 144003/143391     (1.004x) (^ 0)
Testing all collisions (low  23..45 bits) - Worst is 45 bits: 23/18             (1.310x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is 21 bits at bit  40:    0.510x  (^ 1)


[[[ Keyset 'SeedSparse' Tests ]]]

Keyset 'SeedSparse' -   2-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        121  (0.965x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        120  (0.957x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8080  (1.007x) (^ 1)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7977  (0.994x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 34 bits: 2089/2006         (1.041x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 27 bits: 251903/251644     (1.001x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 19 bits at bit  36:    0.417x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        122  (0.973x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        122  (0.973x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7952  (0.991x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7974  (0.994x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 29 bits: 64126/63885       (1.004x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 36 bits: 528/502           (1.053x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is  9 bits at bit  41:    0.721x  (^ 0)

Keyset 'SeedSparse' -   3-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        127  (1.013x) (^ 1)
Testing all collisions (low   38-bit) - Expected      125.4, actual        150  (1.196x) (^ 5)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7946  (0.991x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7988  (0.996x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 39 bits: 78/63             (1.244x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 38 bits: 150/125           (1.196x) (^ 1)
Testing distribution   (any   8..20 bits) - Worst bias is 19 bits at bit  55:    0.449x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        128  (1.021x) (^ 1)
Testing all collisions (low   38-bit) - Expected      125.4, actual        149  (1.188x) (^ 5)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8078  (1.007x) (^ 1)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8127  (1.013x) (^ 3)
Testing all collisions (high 21..41 bits) - Worst is 31 bits: 16150/16033       (1.007x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 37 bits: 285/251           (1.136x) (^ 1)
Testing distribution   (any   8..20 bits) - Worst bias is 19 bits at bit  15:    0.464x  (^ 0)

Keyset 'SeedSparse' -   6-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        129  (1.029x) (^ 1)
Testing all collisions (low   38-bit) - Expected      125.4, actual        116  (0.925x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7982  (0.995x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7941  (0.990x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 40 bits: 40/31             (1.276x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 23 bits: 3032983/3032441   (1.000x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 13 bits at bit  58:    0.731x  (^ 3)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        135  (1.076x) (^ 2)
Testing all collisions (low   38-bit) - Expected      125.4, actual        116  (0.925x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8117  (1.012x) (^ 2)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8083  (1.008x) (^ 2)
Testing all collisions (high 21..41 bits) - Worst is 30 bits: 32396/32025       (1.012x) (^ 1)
Testing all collisions (low  21..41 bits) - Worst is 30 bits: 32318/32025       (1.009x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 10 bits at bit  25:    0.629x  (^ 0)

Keyset 'SeedSparse' -  15-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        131  (1.045x) (^ 1)
Testing all collisions (low   38-bit) - Expected      125.4, actual        131  (1.045x) (^ 1)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7945  (0.990x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7970  (0.994x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 36 bits: 535/502           (1.066x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 25 bits: 948277/947681     (1.001x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 14 bits at bit   8:    0.624x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        140  (1.116x) (^ 3)
Testing all collisions (low   38-bit) - Expected      125.4, actual        103  (0.821x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8057  (1.004x) (^ 1)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8084  (1.008x) (^ 2)
Testing all collisions (high 21..41 bits) - Worst is 36 bits: 542/502           (1.080x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 28 bits: 127761/127116     (1.005x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 10 bits at bit  15:    0.685x  (^ 0)

Keyset 'SeedSparse' -  18-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        132  (1.052x) (^ 1)
Testing all collisions (low   38-bit) - Expected      125.4, actual        109  (0.869x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8143  (1.015x) (^ 3)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7981  (0.995x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 33 bits: 4121/4012         (1.027x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 28 bits: 127529/127116     (1.003x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 13 bits at bit  40:    0.547x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        138  (1.100x) (^ 2)
Testing all collisions (low   38-bit) - Expected      125.4, actual        102  (0.813x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8052  (1.004x) (^ 1)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8008  (0.998x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 30 bits: 32386/32025       (1.011x) (^ 1)
Testing all collisions (low  21..41 bits) - Worst is 34 bits: 2028/2006         (1.011x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 20 bits at bit  48:    0.434x  (^ 0)

Keyset 'SeedSparse' -  31-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        121  (0.965x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        135  (1.076x) (^ 2)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7891  (0.984x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8003  (0.998x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 24 bits: 1755775/1753983   (1.001x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 26 bits: 494489/493171     (1.003x) (^ 1)
Testing distribution   (any   8..20 bits) - Worst bias is 20 bits at bit  50:    0.584x  (^ 3)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        120  (0.957x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        117  (0.933x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8123  (1.013x) (^ 2)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8028  (1.001x) (^ 1)
Testing all collisions (high 21..41 bits) - Worst is 28 bits: 128130/127116     (1.008x) (^ 4)
Testing all collisions (low  21..41 bits) - Worst is 29 bits: 64344/63885       (1.007x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 19 bits at bit  53:    0.396x  (^ 0)

Keyset 'SeedSparse' -  52-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        142  (1.132x) (^ 3)
Testing all collisions (low   38-bit) - Expected      125.4, actual        146  (1.164x) (^ 4)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7953  (0.991x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7980  (0.995x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 38 bits: 142/125           (1.132x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 38 bits: 146/125           (1.164x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 13 bits at bit  53:    0.679x  (^ 2)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        121  (0.965x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        123  (0.981x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7792  (0.971x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7917  (0.987x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 41 bits: 20/16             (1.276x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 26 bits: 493950/493171     (1.002x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is  8 bits at bit  32:    0.628x  (^ 0)

Keyset 'SeedSparse' -  80-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        146  (1.164x) (^ 4)
Testing all collisions (low   38-bit) - Expected      125.4, actual        123  (0.981x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7981  (0.995x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8010  (0.999x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 38 bits: 146/125           (1.164x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 29 bits: 64348/63885       (1.007x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 17 bits at bit  11:    0.444x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        114  (0.909x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        123  (0.981x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8008  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7994  (0.997x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 23 bits: 3033887/3032441   (1.000x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 41 bits: 18/16             (1.148x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 17 bits at bit  43:    0.502x  (^ 0)

Keyset 'SeedSparse' - 200-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        116  (0.925x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        120  (0.957x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8100  (1.010x) (^ 2)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8138  (1.014x) (^ 3)
Testing all collisions (high 21..41 bits) - Worst is 32 bits: 8100/8022         (1.010x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 30 bits: 32259/32025       (1.007x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 11 bits at bit  61:    0.809x  (^ 4)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        139  (1.108x) (^ 2)
Testing all collisions (low   38-bit) - Expected      125.4, actual        141  (1.124x) (^ 3)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8046  (1.003x) (^ 1)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       7874  (0.982x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 39 bits: 76/63             (1.212x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 36 bits: 578/502           (1.152x) (^ 6)
Testing distribution   (any   8..20 bits) - Worst bias is 11 bits at bit  40:    0.476x  (^ 0)

Keyset 'SeedSparse' - 1025-byte keys - seeds with up to  5 bits set - 8303633 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        128  (1.021x) (^ 1)
Testing all collisions (low   38-bit) - Expected      125.4, actual        125  (1.000x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       8184  (1.020x) (^ 4)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8018  (1.000x) (^ 0)
Testing all collisions (high 21..41 bits) - Worst is 32 bits: 8184/8022         (1.020x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 40 bits: 39/31             (1.244x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 20 bits at bit  54:    0.424x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      125.4, actual        114  (0.909x) (^ 0)
Testing all collisions (low   38-bit) - Expected      125.4, actual        121  (0.965x) (^ 0)
Testing all collisions (high  32-bit) - Expected     8021.7, actual       7976  (0.994x) (^ 0)
Testing all collisions (low   32-bit) - Expected     8021.7, actual       8235  (1.027x) (^ 6)
Testing all collisions (high 21..41 bits) - Worst is 40 bits: 37/31             (1.180x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 25 bits: 950335/947681     (1.003x) (^ 3)
Testing distribution   (any   8..20 bits) - Worst bias is 16 bits at bit   5:    0.514x  (^ 0)


[[[ Seed BlockLength Tests ]]]

Seeds have up to 2 bits set, 4-byte blocks have up to 2 bits set

Keyset 'SeedBlockLen' -  8-byte keys with block at offsets [0..4, by 4s] - 2196480 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      140.4, actual        134  (0.954x) (^ 0)
Testing all collisions (low   34-bit) - Expected      140.4, actual        138  (0.983x) (^ 0)
Testing all collisions (high  32-bit) - Expected      561.6, actual        561  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected      561.6, actual        527  (0.938x) (^ 0)
Testing all collisions (high 19..37 bits) - Worst is 27 bits: 18306/17875       (1.024x) (^ 6)
Testing all collisions (low  19..37 bits) - Worst is 26 bits: 35772/35557       (1.006x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 18 bits at bit  49:    0.445x  (^ 0)

Keyset 'SeedBlockLen' -  9-byte keys with block at offsets [0..4, by 4s] - 2196480 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      140.4, actual        123  (0.876x) (^ 0)
Testing all collisions (low   34-bit) - Expected      140.4, actual        139  (0.990x) (^ 0)
Testing all collisions (high  32-bit) - Expected      561.6, actual        530  (0.944x) (^ 0)
Testing all collisions (low   32-bit) - Expected      561.6, actual        564  (1.004x) (^ 1)
Testing all collisions (high 19..37 bits) - Worst is 24 bits: 138093/137707     (1.003x) (^ 0)
Testing all collisions (low  19..37 bits) - Worst is 31 bits: 1136/1123         (1.012x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 15 bits at bit  19:    0.457x  (^ 0)

Keyset 'SeedBlockLen' - 10-byte keys with block at offsets [0..4, by 4s] - 2196480 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      140.4, actual        135  (0.961x) (^ 0)
Testing all collisions (low   34-bit) - Expected      140.4, actual        154  (1.097x) (^ 2)
Testing all collisions (high  32-bit) - Expected      561.6, actual        524  (0.933x) (^ 0)
Testing all collisions (low   32-bit) - Expected      561.6, actual        631  (1.124x) (^ 8)
Testing all collisions (high 19..37 bits) - Worst is 21 bits: 835572/835138     (1.001x) (^ 0)
Testing all collisions (low  19..37 bits) - Worst is 32 bits: 631/562           (1.124x) (^ 4)
Testing distribution   (any   8..18 bits) - Worst bias is 18 bits at bit  15:    0.486x  (^ 0)

Keyset 'SeedBlockLen' - 11-byte keys with block at offsets [0..4, by 4s] - 2196480 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  34-bit) - Expected      140.4, actual        154  (1.097x) (^ 2)
Testing all collisions (low   34-bit) - Expected      140.4, actual        161  (1.147x) (^ 4)
Testing all collisions (high  32-bit) - Expected      561.6, actual        563  (1.003x) (^ 1)
Testing all collisions (low   32-bit) - Expected      561.6, actual        619  (1.102x) (^ 6)
Testing all collisions (high 19..37 bits) - Worst is 35 bits: 83/70             (1.182x) (^ 0)
Testing all collisions (low  19..37 bits) - Worst is 30 bits: 2368/2245         (1.055x) (^ 3)
Testing distribution   (any   8..18 bits) - Worst bias is 15 bits at bit  62:    0.499x  (^ 0)

Keyset 'SeedBlockLen' - 12-byte keys with block at offsets [0..8, by 4s] - 3294720 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      158.0, actual        165  (1.045x) (^ 1)
Testing all collisions (low   35-bit) - Expected      158.0, actual        170  (1.076x) (^ 2)
Testing all collisions (high  32-bit) - Expected     1263.4, actual       1239  (0.981x) (^ 0)
Testing all collisions (low   32-bit) - Expected     1263.4, actual       1262  (0.999x) (^ 0)
Testing all collisions (high 20..38 bits) - Worst is 35 bits: 165/158           (1.045x) (^ 0)
Testing all collisions (low  20..38 bits) - Worst is 36 bits: 95/79             (1.203x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 18 bits at bit  41:    0.511x  (^ 0)

Keyset 'SeedBlockLen' - 13-byte keys with block at offsets [0..8, by 4s] - 3294720 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      158.0, actual        185  (1.171x) (^ 5)
Testing all collisions (low   35-bit) - Expected      158.0, actual        128  (0.810x) (^ 0)
Testing all collisions (high  32-bit) - Expected     1263.4, actual       1290  (1.021x) (^ 2)
Testing all collisions (low   32-bit) - Expected     1263.4, actual       1252  (0.991x) (^ 0)
Testing all collisions (high 20..38 bits) - Worst is 35 bits: 185/158           (1.171x) (^ 1)
Testing all collisions (low  20..38 bits) - Worst is 23 bits: 570973/570016     (1.002x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  40:    0.589x  (^ 3)

Keyset 'SeedBlockLen' - 14-byte keys with block at offsets [0..8, by 4s] - 3294720 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      158.0, actual        144  (0.912x) (^ 0)
Testing all collisions (low   35-bit) - Expected      158.0, actual        135  (0.855x) (^ 0)
Testing all collisions (high  32-bit) - Expected     1263.4, actual       1293  (1.023x) (^ 2)
Testing all collisions (low   32-bit) - Expected     1263.4, actual       1259  (0.997x) (^ 0)
Testing all collisions (high 20..38 bits) - Worst is 30 bits: 5177/5050         (1.025x) (^ 0)
Testing all collisions (low  20..38 bits) - Worst is 30 bits: 5115/5050         (1.013x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 16 bits at bit  36:    0.537x  (^ 0)

Keyset 'SeedBlockLen' - 15-byte keys with block at offsets [0..8, by 4s] - 3294720 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      158.0, actual        141  (0.893x) (^ 0)
Testing all collisions (low   35-bit) - Expected      158.0, actual        158  (1.000x) (^ 1)
Testing all collisions (high  32-bit) - Expected     1263.4, actual       1206  (0.955x) (^ 0)
Testing all collisions (low   32-bit) - Expected     1263.4, actual       1230  (0.974x) (^ 0)
Testing all collisions (high 20..38 bits) - Worst is 21 bits: 1633748/1633415   (1.000x) (^ 0)
Testing all collisions (low  20..38 bits) - Worst is 24 bits: 303979/303333     (1.002x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  31:    0.419x  (^ 0)

Keyset 'SeedBlockLen' - 16-byte keys with block at offsets [0..12, by 4s] - 4392960 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      140.4, actual        129  (0.919x) (^ 0)
Testing all collisions (low   36-bit) - Expected      140.4, actual        128  (0.912x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2245.8, actual       2208  (0.983x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2245.8, actual       2269  (1.010x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 26 bits: 141819/140695     (1.008x) (^ 5)
Testing all collisions (low  20..39 bits) - Worst is 24 bits: 528638/528052     (1.001x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 14 bits at bit  37:    0.639x  (^ 2)

Keyset 'SeedBlockLen' - 17-byte keys with block at offsets [0..12, by 4s] - 4392960 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      140.4, actual        125  (0.890x) (^ 0)
Testing all collisions (low   36-bit) - Expected      140.4, actual        141  (1.004x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2245.8, actual       2218  (0.988x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2245.8, actual       2298  (1.023x) (^ 2)
Testing all collisions (high 20..39 bits) - Worst is 21 bits: 2554229/2553975   (1.000x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 24 bits: 529096/528052     (1.002x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 18 bits at bit   3:    0.387x  (^ 0)

Keyset 'SeedBlockLen' - 18-byte keys with block at offsets [0..12, by 4s] - 4392960 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      140.4, actual        149  (1.061x) (^ 2)
Testing all collisions (low   36-bit) - Expected      140.4, actual        139  (0.990x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2245.8, actual       2212  (0.985x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2245.8, actual       2206  (0.982x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 37 bits: 84/70             (1.196x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 27 bits: 71501/71113       (1.005x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  8 bits at bit  43:    0.838x  (^ 1)

Keyset 'SeedBlockLen' - 19-byte keys with block at offsets [0..12, by 4s] - 4392960 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      140.4, actual        149  (1.061x) (^ 2)
Testing all collisions (low   36-bit) - Expected      140.4, actual        159  (1.132x) (^ 3)
Testing all collisions (high  32-bit) - Expected     2245.8, actual       2304  (1.026x) (^ 3)
Testing all collisions (low   32-bit) - Expected     2245.8, actual       2235  (0.995x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 38 bits: 48/35             (1.367x) (^ 1)
Testing all collisions (low  20..39 bits) - Worst is 36 bits: 159/140           (1.132x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 16 bits at bit  55:    0.478x  (^ 0)

Keyset 'SeedBlockLen' - 20-byte keys with block at offsets [0..16, by 4s] - 5491200 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      109.7, actual        119  (1.085x) (^ 2)
Testing all collisions (low   37-bit) - Expected      109.7, actual        105  (0.957x) (^ 0)
Testing all collisions (high  32-bit) - Expected     3508.8, actual       3553  (1.013x) (^ 2)
Testing all collisions (low   32-bit) - Expected     3508.8, actual       3600  (1.026x) (^ 3)
Testing all collisions (high 21..40 bits) - Worst is 40 bits: 23/14             (1.677x) (^ 1)
Testing all collisions (low  21..40 bits) - Worst is 33 bits: 1867/1755         (1.064x) (^ 3)
Testing distribution   (any   8..20 bits) - Worst bias is 17 bits at bit  25:    0.439x  (^ 0)

Keyset 'SeedBlockLen' - 21-byte keys with block at offsets [0..16, by 4s] - 5491200 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      109.7, actual         97  (0.884x) (^ 0)
Testing all collisions (low   37-bit) - Expected      109.7, actual         93  (0.848x) (^ 0)
Testing all collisions (high  32-bit) - Expected     3508.8, actual       3516  (1.002x) (^ 1)
Testing all collisions (low   32-bit) - Expected     3508.8, actual       3432  (0.978x) (^ 0)
Testing all collisions (high 21..40 bits) - Worst is 31 bits: 7135/7015         (1.017x) (^ 0)
Testing all collisions (low  21..40 bits) - Worst is 21 bits: 3547243/3546970   (1.000x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 12 bits at bit  53:    0.626x  (^ 0)

Keyset 'SeedBlockLen' - 22-byte keys with block at offsets [0..16, by 4s] - 5491200 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      109.7, actual        115  (1.048x) (^ 1)
Testing all collisions (low   37-bit) - Expected      109.7, actual        117  (1.067x) (^ 1)
Testing all collisions (high  32-bit) - Expected     3508.8, actual       3514  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected     3508.8, actual       3577  (1.019x) (^ 2)
Testing all collisions (high 21..40 bits) - Worst is 24 bits: 809700/808120     (1.002x) (^ 0)
Testing all collisions (low  21..40 bits) - Worst is 39 bits: 35/27             (1.276x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is  8 bits at bit  49:    0.833x  (^ 1)

Keyset 'SeedBlockLen' - 23-byte keys with block at offsets [0..16, by 4s] - 5491200 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      109.7, actual        117  (1.067x) (^ 1)
Testing all collisions (low   37-bit) - Expected      109.7, actual        100  (0.912x) (^ 0)
Testing all collisions (high  32-bit) - Expected     3508.8, actual       3494  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected     3508.8, actual       3448  (0.983x) (^ 0)
Testing all collisions (high 21..40 bits) - Worst is 28 bits: 56280/55784       (1.009x) (^ 1)
Testing all collisions (low  21..40 bits) - Worst is 27 bits: 111413/110813     (1.005x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 17 bits at bit  48:    0.625x  (^ 3)

Keyset 'SeedBlockLen' - 24-byte keys with block at offsets [0..20, by 4s] - 6589440 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      158.0, actual        139  (0.880x) (^ 0)
Testing all collisions (low   37-bit) - Expected      158.0, actual        161  (1.019x) (^ 1)
Testing all collisions (high  32-bit) - Expected     5052.3, actual       5043  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected     5052.3, actual       5032  (0.996x) (^ 0)
Testing all collisions (high 21..40 bits) - Worst is 26 bits: 314070/313176     (1.003x) (^ 0)
Testing all collisions (low  21..40 bits) - Worst is 39 bits: 48/39             (1.215x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 10 bits at bit  21:    0.600x  (^ 0)

Keyset 'SeedBlockLen' - 25-byte keys with block at offsets [0..20, by 4s] - 6589440 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      158.0, actual        163  (1.032x) (^ 1)
Testing all collisions (low   37-bit) - Expected      158.0, actual        162  (1.026x) (^ 1)
Testing all collisions (high  32-bit) - Expected     5052.3, actual       5055  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected     5052.3, actual       5087  (1.007x) (^ 1)
Testing all collisions (high 21..40 bits) - Worst is 26 bits: 314430/313176     (1.004x) (^ 2)
Testing all collisions (low  21..40 bits) - Worst is 40 bits: 26/20             (1.317x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 15 bits at bit  32:    0.572x  (^ 0)

Keyset 'SeedBlockLen' - 26-byte keys with block at offsets [0..20, by 4s] - 6589440 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      158.0, actual        158  (1.000x) (^ 1)
Testing all collisions (low   37-bit) - Expected      158.0, actual        152  (0.962x) (^ 0)
Testing all collisions (high  32-bit) - Expected     5052.3, actual       4931  (0.976x) (^ 0)
Testing all collisions (low   32-bit) - Expected     5052.3, actual       4942  (0.978x) (^ 0)
Testing all collisions (high 21..40 bits) - Worst is 39 bits: 47/39             (1.190x) (^ 0)
Testing all collisions (low  21..40 bits) - Worst is 40 bits: 24/20             (1.215x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 16 bits at bit   7:    0.490x  (^ 0)

Keyset 'SeedBlockLen' - 27-byte keys with block at offsets [0..20, by 4s] - 6589440 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  37-bit) - Expected      158.0, actual        149  (0.943x) (^ 0)
Testing all collisions (low   37-bit) - Expected      158.0, actual        165  (1.045x) (^ 1)
Testing all collisions (high  32-bit) - Expected     5052.3, actual       5030  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected     5052.3, actual       5030  (0.996x) (^ 0)
Testing all collisions (high 21..40 bits) - Worst is 26 bits: 314511/313176     (1.004x) (^ 2)
Testing all collisions (low  21..40 bits) - Worst is 35 bits: 670/632           (1.060x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 14 bits at bit  37:    0.593x  (^ 0)

Keyset 'SeedBlockLen' - 28-byte keys with block at offsets [0..24, by 4s] - 7687680 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      107.5, actual        125  (1.163x) (^ 4)
Testing all collisions (low   38-bit) - Expected      107.5, actual        113  (1.051x) (^ 1)
Testing all collisions (high  32-bit) - Expected     6876.1, actual       6905  (1.004x) (^ 1)
Testing all collisions (low   32-bit) - Expected     6876.1, actual       6899  (1.003x) (^ 1)
Testing all collisions (high 21..41 bits) - Worst is 39 bits: 81/54             (1.507x) (^ 7)
Testing all collisions (low  21..41 bits) - Worst is 36 bits: 474/430           (1.102x) (^ 1)
Testing distribution   (any   8..20 bits) - Worst bias is 14 bits at bit  44:    0.496x  (^ 0)

Keyset 'SeedBlockLen' - 29-byte keys with block at offsets [0..24, by 4s] - 7687680 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      107.5, actual         96  (0.893x) (^ 0)
Testing all collisions (low   38-bit) - Expected      107.5, actual        121  (1.126x) (^ 3)
Testing all collisions (high  32-bit) - Expected     6876.1, actual       6883  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected     6876.1, actual       6980  (1.015x) (^ 3)
Testing all collisions (high 21..41 bits) - Worst is 32 bits: 6883/6876         (1.001x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 31 bits: 13919/13744       (1.013x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 14 bits at bit  61:    0.487x  (^ 0)

Keyset 'SeedBlockLen' - 30-byte keys with block at offsets [0..24, by 4s] - 7687680 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      107.5, actual        102  (0.949x) (^ 0)
Testing all collisions (low   38-bit) - Expected      107.5, actual         94  (0.874x) (^ 0)
Testing all collisions (high  32-bit) - Expected     6876.1, actual       7077  (1.029x) (^ 6)
Testing all collisions (low   32-bit) - Expected     6876.1, actual       6964  (1.013x) (^ 2)
Testing all collisions (high 21..41 bits) - Worst is 32 bits: 7077/6876         (1.029x) (^ 2)
Testing all collisions (low  21..41 bits) - Worst is 28 bits: 109473/109040     (1.004x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is  8 bits at bit  37:    0.794x  (^ 1)

Keyset 'SeedBlockLen' - 31-byte keys with block at offsets [0..24, by 4s] - 7687680 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  38-bit) - Expected      107.5, actual         95  (0.884x) (^ 0)
Testing all collisions (low   38-bit) - Expected      107.5, actual        105  (0.977x) (^ 0)
Testing all collisions (high  32-bit) - Expected     6876.1, actual       6781  (0.986x) (^ 0)
Testing all collisions (low   32-bit) - Expected     6876.1, actual       6952  (1.011x) (^ 2)
Testing all collisions (high 21..41 bits) - Worst is 27 bits: 216412/216022     (1.002x) (^ 0)
Testing all collisions (low  21..41 bits) - Worst is 28 bits: 109585/109040     (1.005x) (^ 0)
Testing distribution   (any   8..20 bits) - Worst bias is 10 bits at bit   4:    0.642x  (^ 0)


[[[ Seed BlockOffset Tests ]]]

Seeds have up to 2 bits set, 4-byte blocks have up to 2 bits set

Keyset 'SeedBlockOffset' - [4..31]-byte keys with block at offset 0 - 30750720 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  42-bit) - Expected      107.5, actual        112  (1.042x) (^ 1)
Testing all collisions (low   42-bit) - Expected      107.5, actual        112  (1.042x) (^ 1)
Testing all collisions (high  32-bit) - Expected   109820.9, actual     109675  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected   109820.9, actual     109804  (1.000x) (^ 0)
Testing all collisions (high 23..45 bits) - Worst is 36 bits: 6977/6879         (1.014x) (^ 0)
Testing all collisions (low  23..45 bits) - Worst is 44 bits: 34/27             (1.265x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is 10 bits at bit  35:    0.631x  (^ 0)

Keyset 'SeedBlockOffset' - [5..31]-byte keys with block at offset 1 - 29652480 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  41-bit) - Expected      199.9, actual        211  (1.055x) (^ 2)
Testing all collisions (low   41-bit) - Expected      199.9, actual        199  (0.995x) (^ 0)
Testing all collisions (high  32-bit) - Expected   102125.3, actual     102065  (0.999x) (^ 0)
Testing all collisions (low   32-bit) - Expected   102125.3, actual     102335  (1.002x) (^ 1)
Testing all collisions (high 23..45 bits) - Worst is 27 bits: 3049443/3047070   (1.001x) (^ 0)
Testing all collisions (low  23..45 bits) - Worst is 26 bits: 5686751/5684009   (1.000x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is 14 bits at bit  30:    0.572x  (^ 0)

Keyset 'SeedBlockOffset' - [6..31]-byte keys with block at offset 2 - 28554240 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  41-bit) - Expected      185.4, actual        203  (1.095x) (^ 3)
Testing all collisions (low   41-bit) - Expected      185.4, actual        183  (0.987x) (^ 0)
Testing all collisions (high  32-bit) - Expected    94708.6, actual      94367  (0.996x) (^ 0)
Testing all collisions (low   32-bit) - Expected    94708.6, actual      94057  (0.993x) (^ 0)
Testing all collisions (high 23..45 bits) - Worst is 42 bits: 113/93            (1.219x) (^ 1)
Testing all collisions (low  23..45 bits) - Worst is 44 bits: 35/23             (1.510x) (^ 1)
Testing distribution   (any   8..22 bits) - Worst bias is  8 bits at bit   6:    0.781x  (^ 0)

Keyset 'SeedBlockOffset' - [7..31]-byte keys with block at offset 3 - 27456000 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  41-bit) - Expected      171.4, actual        161  (0.939x) (^ 0)
Testing all collisions (low   41-bit) - Expected      171.4, actual        158  (0.922x) (^ 0)
Testing all collisions (high  32-bit) - Expected    87570.9, actual      87639  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected    87570.9, actual      87147  (0.995x) (^ 0)
Testing all collisions (high 23..45 bits) - Worst is 43 bits: 55/43             (1.284x) (^ 0)
Testing all collisions (low  23..45 bits) - Worst is 26 bits: 4924988/4922880   (1.000x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is 22 bits at bit  23:    0.440x  (^ 0)

Keyset 'SeedBlockOffset' - [8..31]-byte keys with block at offset 4 - 26357760 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  41-bit) - Expected      158.0, actual        159  (1.007x) (^ 1)
Testing all collisions (low   41-bit) - Expected      158.0, actual        147  (0.931x) (^ 0)
Testing all collisions (high  32-bit) - Expected    80712.2, actual      80908  (1.002x) (^ 2)
Testing all collisions (low   32-bit) - Expected    80712.2, actual      80202  (0.994x) (^ 0)
Testing all collisions (high 23..44 bits) - Worst is 40 bits: 352/316           (1.114x) (^ 1)
Testing all collisions (low  23..44 bits) - Worst is 37 bits: 2573/2527         (1.018x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is 14 bits at bit  18:    0.553x  (^ 0)

Keyset 'SeedBlockOffset' - [9..31]-byte keys with block at offset 5 - 25259520 hashes
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  41-bit) - Expected      145.1, actual        128  (0.882x) (^ 0)
Testing all collisions (low   41-bit) - Expected      145.1, actual        139  (0.958x) (^ 0)
Testing all collisions (high  32-bit) - Expected    74132.6, actual      74353  (1.003x) (^ 2)
Testing all collisions (low   32-bit) - Expected    74132.6, actual      73826  (0.996x) (^ 0)
Testing all collisions (high 23..44 bits) - Worst is 35 bits: 9462/9282         (1.019x) (^ 0)
Testing all collisions (low  23..44 bits) - Worst is 37 bits: 2366/2321         (1.019x) (^ 0)
Testing distribution   (any   8..22 bits) - Worst bias is 19 bits at bit  36:    0.516x  (^ 0)


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' -   2-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        131  (1.023x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        106  (0.828x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       1987  (0.971x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2004  (0.979x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 28 bits: 32690/32598       (1.003x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 29 bits: 16504/16341       (1.010x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 10 bits at bit  49:    0.669x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        137  (1.070x) (^ 2)
Testing all collisions (low   36-bit) - Expected      128.0, actual        124  (0.969x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2081  (1.016x) (^ 2)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2045  (0.999x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 34 bits: 542/512           (1.059x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 31 bits: 4139/4093         (1.011x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  8 bits at bit  41:    0.672x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        129  (1.008x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        133  (1.039x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2143  (1.047x) (^ 5)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2001  (0.977x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 32 bits: 2143/2047         (1.047x) (^ 1)
Testing all collisions (low  20..39 bits) - Worst is 37 bits: 70/64             (1.094x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 16 bits at bit  39:    0.529x  (^ 0)

Keyset 'Seed' -   3-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        126  (0.984x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        122  (0.953x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2114  (1.033x) (^ 3)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2042  (0.997x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 32 bits: 2114/2047         (1.033x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 26 bits: 128558/128383     (1.001x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 14 bits at bit  34:    0.536x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        138  (1.078x) (^ 2)
Testing all collisions (low   36-bit) - Expected      128.0, actual        105  (0.820x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2074  (1.013x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2014  (0.984x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 24 bits: 483968/483197     (1.002x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 24 bits: 483689/483197     (1.001x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 15 bits at bit  14:    0.577x  (^ 1)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        124  (0.969x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        118  (0.922x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2081  (1.016x) (^ 2)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2046  (0.999x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 30 bits: 8320/8181         (1.017x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 28 bits: 32790/32598       (1.006x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 10 bits at bit  22:    0.611x  (^ 0)

Keyset 'Seed' -   6-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        120  (0.938x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        110  (0.859x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2035  (0.994x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2053  (1.003x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 39 bits: 17/16             (1.063x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 30 bits: 8239/8181         (1.007x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 15 bits at bit   7:    0.568x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        116  (0.906x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        134  (1.047x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2038  (0.995x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2121  (1.036x) (^ 4)
Testing all collisions (high 20..39 bits) - Worst is 28 bits: 32928/32598       (1.010x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 32 bits: 2121/2047         (1.036x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  63:    0.427x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        110  (0.859x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        135  (1.055x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2044  (0.998x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2090  (1.021x) (^ 2)
Testing all collisions (high 20..39 bits) - Worst is 33 bits: 1068/1024         (1.043x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 33 bits: 1071/1024         (1.046x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  9 bits at bit   7:    0.607x  (^ 0)

Keyset 'Seed' -  15-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        133  (1.039x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        123  (0.961x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2137  (1.044x) (^ 5)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2035  (0.994x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 32 bits: 2137/2047         (1.044x) (^ 1)
Testing all collisions (low  20..39 bits) - Worst is 22 bits: 1543644/1542998   (1.000x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 10 bits at bit  20:    0.550x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        136  (1.063x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        127  (0.992x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2050  (1.001x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2089  (1.020x) (^ 2)
Testing all collisions (high 20..39 bits) - Worst is 39 bits: 28/16             (1.750x) (^ 3)
Testing all collisions (low  20..39 bits) - Worst is 26 bits: 129375/128383     (1.008x) (^ 4)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  61:    0.554x  (^ 2)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        128  (1.000x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        126  (0.984x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2027  (0.990x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2066  (1.009x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 25 bits: 251939/251554     (1.002x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 35 bits: 266/256           (1.039x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 11 bits at bit  39:    0.521x  (^ 0)

Keyset 'Seed' -  18-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        122  (0.953x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        114  (0.891x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2060  (1.006x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2052  (1.002x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 32 bits: 2060/2047         (1.006x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 27 bits: 65226/64859       (1.006x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 10 bits at bit  61:    0.664x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        139  (1.086x) (^ 2)
Testing all collisions (low   36-bit) - Expected      128.0, actual        146  (1.141x) (^ 3)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2015  (0.984x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2011  (0.982x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 36 bits: 139/128           (1.086x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 36 bits: 146/128           (1.141x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 14 bits at bit  56:    0.423x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        119  (0.930x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        150  (1.172x) (^ 4)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2032  (0.993x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2134  (1.042x) (^ 5)
Testing all collisions (high 20..39 bits) - Worst is 22 bits: 1544102/1542998   (1.001x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 34 bits: 557/512           (1.088x) (^ 1)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit   9:    0.598x  (^ 3)

Keyset 'Seed' -  31-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        135  (1.055x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        132  (1.031x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2034  (0.993x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2060  (1.006x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 25 bits: 252147/251554     (1.002x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 33 bits: 1061/1024         (1.036x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 10 bits at bit   2:    0.724x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        126  (0.984x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        116  (0.906x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2002  (0.978x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2045  (0.999x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 25 bits: 252120/251554     (1.002x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 28 bits: 32726/32598       (1.004x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 14 bits at bit  45:    0.516x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        125  (0.977x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        121  (0.945x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2116  (1.034x) (^ 3)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2033  (0.993x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 29 bits: 16698/16341       (1.022x) (^ 4)
Testing all collisions (low  20..39 bits) - Worst is 25 bits: 252131/251554     (1.002x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  9 bits at bit  50:    0.758x  (^ 1)

Keyset 'Seed' -  52-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        110  (0.859x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        132  (1.031x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       1964  (0.959x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2077  (1.014x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 22 bits: 1543217/1542998   (1.000x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 25 bits: 252813/251554     (1.005x) (^ 3)
Testing distribution   (any   8..19 bits) - Worst bias is 12 bits at bit  14:    0.563x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        131  (1.023x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        136  (1.063x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2060  (1.006x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2046  (0.999x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 38 bits: 42/32             (1.313x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 35 bits: 275/256           (1.074x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  8 bits at bit  32:    0.719x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        140  (1.094x) (^ 2)
Testing all collisions (low   36-bit) - Expected      128.0, actual        138  (1.078x) (^ 2)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2065  (1.009x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2069  (1.011x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 35 bits: 288/256           (1.125x) (^ 1)
Testing all collisions (low  20..39 bits) - Worst is 28 bits: 33024/32598       (1.013x) (^ 2)
Testing distribution   (any   8..19 bits) - Worst bias is 11 bits at bit  47:    0.564x  (^ 0)

Keyset 'Seed' -  80-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        116  (0.906x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        136  (1.063x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2075  (1.014x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       1999  (0.976x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 27 bits: 65016/64859       (1.002x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 38 bits: 42/32             (1.313x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 14 bits at bit  31:    0.584x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        135  (1.055x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        121  (0.945x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2061  (1.007x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2081  (1.016x) (^ 2)
Testing all collisions (high 20..39 bits) - Worst is 35 bits: 282/256           (1.102x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 30 bits: 8326/8181         (1.018x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  8 bits at bit   0:    0.699x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        134  (1.047x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        137  (1.070x) (^ 2)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2068  (1.010x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2072  (1.012x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 25 bits: 252510/251554     (1.004x) (^ 1)
Testing all collisions (low  20..39 bits) - Worst is 34 bits: 546/512           (1.066x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 11 bits at bit  58:    0.725x  (^ 2)

Keyset 'Seed' - 200-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        132  (1.031x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        130  (1.016x) (^ 1)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2092  (1.022x) (^ 2)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2022  (0.988x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 32 bits: 2092/2047         (1.022x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 24 bits: 483851/483197     (1.001x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  16:    0.468x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        130  (1.016x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        127  (0.992x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2038  (0.995x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2082  (1.017x) (^ 2)
Testing all collisions (high 20..39 bits) - Worst is 28 bits: 32866/32598       (1.008x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 30 bits: 8359/8181         (1.022x) (^ 1)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  16:    0.581x  (^ 3)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        136  (1.063x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        140  (1.094x) (^ 2)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2016  (0.985x) (^ 0)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2050  (1.001x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 36 bits: 136/128           (1.063x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 33 bits: 1066/1024         (1.041x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 18 bits at bit   0:    0.495x  (^ 0)

Keyset 'Seed' - 1025-byte keys - 4194304 seeds
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        121  (0.945x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        114  (0.891x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2063  (1.008x) (^ 1)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2069  (1.011x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 25 bits: 252764/251554     (1.005x) (^ 2)
Testing all collisions (low  20..39 bits) - Worst is 38 bits: 36/32             (1.125x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is  8 bits at bit  29:    0.591x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        125  (0.977x) (^ 0)
Testing all collisions (low   36-bit) - Expected      128.0, actual        114  (0.891x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2093  (1.022x) (^ 2)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2051  (1.002x) (^ 1)
Testing all collisions (high 20..39 bits) - Worst is 34 bits: 545/512           (1.065x) (^ 0)
Testing all collisions (low  20..39 bits) - Worst is 25 bits: 252513/251554     (1.004x) (^ 1)
Testing distribution   (any   8..19 bits) - Worst bias is 16 bits at bit  30:    0.524x  (^ 0)
---Analyzing additional differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  36-bit) - Expected      128.0, actual        135  (1.055x) (^ 1)
Testing all collisions (low   36-bit) - Expected      128.0, actual        104  (0.813x) (^ 0)
Testing all collisions (high  32-bit) - Expected     2047.3, actual       2147  (1.049x) (^ 6)
Testing all collisions (low   32-bit) - Expected     2047.3, actual       2029  (0.991x) (^ 0)
Testing all collisions (high 20..39 bits) - Worst is 30 bits: 8388/8181         (1.025x) (^ 2)
Testing all collisions (low  20..39 bits) - Worst is 25 bits: 251957/251554     (1.002x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 19 bits at bit  32:    0.566x  (^ 2)


[[[ Seed Avalanche Tests ]]]

Testing   4-byte keys, 300000 reps..................max is 0.711% at bit   36 -> out  18 (^ 1)
Testing   8-byte keys, 300000 reps..................max is 0.647% at bit   10 -> out  10 (^ 0)
Testing  16-byte keys, 300000 reps..................max is 0.626% at bit   46 -> out  55 (^ 0)
Testing  24-byte keys, 300000 reps..................max is 0.757% at bit    4 -> out   0 (^ 2)
Testing  32-byte keys, 300000 reps..................max is 0.673% at bit   42 -> out  51 (^ 0)
Testing  64-byte keys, 300000 reps..................max is 0.698% at bit   21 -> out  21 (^ 1)
Testing 128-byte keys, 300000 reps..................max is 0.659% at bit   25 -> out  30 (^ 0)


[[[ Seed 'Bit Independence Criteria' Tests ]]]

Testing    3-byte keys, 1200000 reps............max 0.0041 at bit   63 -> out (  3, 47)  (^ 0)
Testing    8-byte keys, 1200000 reps............max 0.0041 at bit   31 -> out (  3, 52)  (^ 0)
Testing   11-byte keys, 1200000 reps............max 0.0040 at bit   55 -> out ( 24, 52)  (^ 0)
Testing   15-byte keys, 1200000 reps............max 0.0042 at bit   20 -> out ( 12, 28)  (^ 1)


[[[ Seed Bitflip Tests ]]]

Testing   3-byte keys, 64-bit seeds, 1572864 reps..........  0 failed, worst is seed bit   0
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      144.0, actual        163  (1.132x) (^ 3)
Testing all collisions (low   35-bit) - Expected      144.0, actual        144  (1.000x) (^ 1)
Testing all collisions (high  32-bit) - Expected     1151.7, actual       1201  (1.043x) (^ 3)
Testing all collisions (low   32-bit) - Expected     1151.7, actual       1204  (1.045x) (^ 3)
Testing all collisions (high 20..38 bits) - Worst is 37 bits: 50/36             (1.389x) (^ 1)
Testing all collisions (low  20..38 bits) - Worst is 32 bits: 1204/1152         (1.045x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 11 bits at bit  27:    0.514x  (^ 0)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  33-bit) - Expected      144.0, actual        153  (1.063x) (^ 2)
Testing all collisions (low   33-bit) - Expected      144.0, actual        145  (1.007x) (^ 1)
Testing all collisions (high  32-bit) - Expected      288.0, actual        310  (1.077x) (^ 3)
Testing all collisions (low   32-bit) - Expected      288.0, actual        279  (0.969x) (^ 0)
Testing all collisions (high 19..36 bits) - Worst is 30 bits: 1308/1151         (1.136x) (^14)
Testing all collisions (low  19..36 bits) - Worst is 35 bits: 41/36             (1.139x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 12 bits at bit   6:    0.665x  (^ 1)

Testing   4-byte keys, 64-bit seeds, 1572864 reps..........  0 failed, worst is seed bit  12
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      144.0, actual        160  (1.111x) (^ 3)
Testing all collisions (low   35-bit) - Expected      144.0, actual        155  (1.076x) (^ 2)
Testing all collisions (high  32-bit) - Expected     1151.7, actual       1165  (1.012x) (^ 1)
Testing all collisions (low   32-bit) - Expected     1151.7, actual       1177  (1.022x) (^ 2)
Testing all collisions (high 20..38 bits) - Worst is 33 bits: 612/576           (1.063x) (^ 0)
Testing all collisions (low  20..38 bits) - Worst is 22 bits: 934296/932673     (1.002x) (^ 0)
Testing distribution   (any   8..19 bits) - Worst bias is 12 bits at bit  30:    0.648x  (^ 1)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  33-bit) - Expected      144.0, actual        177  (1.229x) (^ 7)
Testing all collisions (low   33-bit) - Expected      144.0, actual        137  (0.951x) (^ 0)
Testing all collisions (high  32-bit) - Expected      288.0, actual        340  (1.181x) (^ 9)
Testing all collisions (low   32-bit) - Expected      288.0, actual        287  (0.997x) (^ 0)
Testing all collisions (high 19..36 bits) - Worst is 32 bits: 340/288           (1.181x) (^ 5)
Testing all collisions (low  19..36 bits) - Worst is 24 bits: 71943/71477       (1.007x) (^ 0)
Testing distribution   (any   8..18 bits) - Worst bias is 11 bits at bit  42:    0.631x  (^ 0)

Testing   8-byte keys, 64-bit seeds, 1572864 reps..........  0 failed, worst is seed bit  52
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  35-bit) - Expected      144.0, actual        131  (0.910x) (^ 0)
Testing all collisions (low   35-bit) - Expected      144.0, actual        178  (1.236x) (^ 8)
Testing all collisions (high  32-bit) - Expected     1151.7, actual       1120  (0.972x) (^ 0)
Testing all collisions (low   32-bit) - Expected     1151.7, actual       1149  (0.998x) (^ 0)
Testing all collisions (high 20..38 bits) - Worst is 29 bits: 9214/9198         (1.002x) (^ 0)
Testing all collisions (low  20..38 bits) - Worst is 36 bits: 102/72            (1.417x) (^ 6)
Testing distribution   (any   8..19 bits) - Worst bias is  8 bits at bit  49:    0.855x  (^ 2)
---Analyzing differential distribution
Testing all collisions (      64-bit) - Expected        0.0, actual          0  (1.000x) (^ 0)
Testing all collisions (high  33-bit) - Expected      144.0, actual        162  (1.125x) (^ 3)
Testing all collisions (low   33-bit) - Expected      144.0, actual        183  (1.271x) (^ 9)
Testing all collisions (high  32-bit) - Expected      288.0, actual        301  (1.045x) (^ 2)
Testing all collisions (low   32-bit) - Expected      288.0, actual        331  (1.149x) (^ 7)
Testing all collisions (high 19..36 bits) - Worst is 33 bits: 162/144           (1.125x) (^ 0)
Testing all collisions (low  19..36 bits) - Worst is 33 bits: 183/144           (1.271x) (^ 5)
Testing distribution   (any   8..18 bits) - Worst bias is 11 bits at bit   1:    0.699x  (^ 1)


----------------------------------------------------------------------------------------------
-log2(p-value) summary:

          0     1     2     3     4     5     6     7     8     9    10    11    12  
        ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
         4431  1221   644   272   154    85    33    19    11     7     1     1     0

         13    14    15    16    17    18    19    20    21    22    23    24    25+ 
        ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
            1     2     1     0     0     0     0     0     0     0     0     0     0

----------------------------------------------------------------------------------------------
Summary for: FoldHashQuality
Overall result: pass            ( 188 / 188 passed)

----------------------------------------------------------------------------------------------
Verification value is 0x00000001 - Testing took 384.116747 seconds
```