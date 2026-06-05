# Lab: Pointers and Pass-by-Reference

## Course Information
- **Course:** CMP1001 – Introduction to Programming (C++)
- **Lab Duration:** 60 minutes
- **File:** `MainProgram.cpp` (single file – no headers, no splitting)

## Objective
Learn how memory addresses, pointers, and references work, and how
pass-by-reference lets a function modify the caller's variables. By the end you
should be able to read/modify variables indirectly through pointers, use
reference parameters, and apply both to small system-like problems.

## Prerequisites
- Basic C++ syntax: `cout`, `cin`, variables, `if`, `for`
- A working C++ compiler (`g++`) and a terminal
- Comfort with editing and compiling a single `.cpp` file

## What You Will Learn
- The address-of operator `&` and the dereference operator `*`
- Declaring and using pointers (`int* p = &x; *p = ...;`)
- References as aliases (`int& a = x;`)
- Pass-by-pointer vs pass-by-reference in functions
- Modifying data in place (swap, increment, clamp, normalize)
- Using an **out-parameter** (returning extra data through a reference)

## Lab Structure
| Section | Topic | Time |
|--------|-------|------|
| 1 | Warm-up: variables, `cout`, arithmetic | 5–10 min |
| 2 | Core concepts: `&`, `*`, pointers, references | 10–15 min |
| 3 | Guided exercises: swap (ptr/ref), increment, sum+count | 25–30 min |
| 4 | Challenge: normalize temperature, clamp to range | 10 min |

All work happens inside `MainProgram.cpp`. The file already compiles; complete
each `// TODO:` and keep it compiling as you go.

## How to Compile & Run
```bash
g++ MainProgram.cpp -o lab
./lab
```

## How to Test Yourself (Auto-Grader)
A `Makefile` and a Catch2 grader are provided. Run all tests:
```bash
make grade
```
Run a single section or exercise for partial credit:
```bash
make test_1     # Section 1 (warm-up)
make test_2     # Section 2 (core concepts)
make test_3     # Section 3 (all guided exercises)
make test_4     # Section 4 (all challenges)

make test_3_1   # swapByPointer only
make test_3_2   # swapByReference only
make test_3_3   # incrementByReference only
make test_3_4   # sumAndCount only
make test_4_1   # normalizeTemperature only
make test_4_2   # clampToRange only
```
Clean build artifacts with `make clean`.

## Submission Instructions
1. Complete every `// TODO:` in `MainProgram.cpp`.
2. Make sure `make grade` runs without compile errors.
3. Commit and push **only** `MainProgram.cpp` to your GitHub Classroom repo:
   ```bash
   git add MainProgram.cpp
   git commit -m "Complete pointers & references lab"
   git push
   ```
4. Do **not** modify the grader, Makefile, or Catch2 files.

## Grading Criteria
| Criterion | Weight |
|-----------|--------|
| Correctness (tests pass) | 50% |
| Code Quality (naming, readability) | 20% |
| Completion (all TODOs attempted) | 20% |
| Challenge (Section 4) | 10% |

See `GRADING_RUBRIC.md` for the per-test point breakdown.

## Estimated Time Breakdown
- Warm-up: ~7 min
- Core concepts: ~13 min
- Guided exercises: ~28 min
- Challenge: ~10 min
- Buffer / testing: ~2 min

## Tips for Students
- `&x` gives the **address**; `*p` gives the **value** at that address.
- A reference (`int& a = x`) is just another name for `x` — changing `a`
  changes `x`.
- For swap, you need a **temp** variable; don't lose a value by overwriting.
- Test after each section with `make test_2`, `make test_3`, etc. — don't wait
  until the end.
- For the temperature challenge, round with `round(c * 10.0) / 10.0` and
  remember to `#include <cmath>`.
