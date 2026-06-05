# Grading Rubric — Pointers and Pass-by-Reference

Total: **100 points**. Run `make grade` for the full suite, or the individual
targets below for partial credit.

## Correctness — 50 pts (auto-graded via Catch2)

| Test target | Tag | Tests what | Pts |
|-------------|-----|------------|----:|
| `make test_1` | `[s1]` | Warm-up program runs without crashing | 4 |
| `make test_2` | `[s2]` | Pointer dereference & reference alias modify originals | 6 |
| `make test_3_1` | `[swap_ptr]` | `swapByPointer` swaps via `*a`/`*b` | 8 |
| `make test_3_2` | `[swap_ref]` | `swapByReference` swaps via references | 8 |
| `make test_3_3` | `[inc]` | `incrementByReference` adds 1 in place | 4 |
| `make test_3_4` | `[sum]` | `sumAndCount` returns sum + sets out-count | 10 |
| `make test_4_1` | `[temp]` | `normalizeTemperature` rounds & kills noise | 5 |
| `make test_4_2` | `[clamp]` | `clampToRange` clamps into bounds | 5 |
|  |  | **Correctness subtotal** | **50** |

Partial credit within a function = (assertions passed / assertions in that
test case) × the points above.

## Code Quality — 20 pts
- Clear, consistent naming and indentation (8)
- Correct use of `*` / `&` (no unnecessary copies, no leaks) (7)
- Readable logic, no dead/commented-out clutter (5)

## Completion — 20 pts
- All `// TODO:` markers attempted (12)
- File compiles cleanly with `g++ -Wall` (8)

## Challenge — 10 pts
- Section 4 logic correct and handles edge cases (boundary values, near-zero
  noise) (10)

## Notes for the Grader
- Sanity-check the reference solution first: `make grade-teacher`
  (expects **28 assertions in 8 test cases, all passing**).
- Students submit **only** `MainProgram.cpp`; the grader `#include`s it via the
  `#define main student_main` trick, so their `main()` does not collide with
  Catch2's.
- If a submission fails to compile, award Completion compile points = 0 and run
  remaining sections that still build where possible.
