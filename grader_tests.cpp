/******************************************************************************
 * GRADER: Pointers and Pass-by-Reference
 * COURSE: CMP1001
 *
 * HOW IT WORKS:
 *   We rename the student's main() to student_main via a #define, then #include
 *   the student's .cpp directly so we can call the functions they implemented.
 *   This keeps everything single-file on the student side while letting Catch2
 *   test the individual functions.
 *
 * The TARGET macro lets the Makefile choose which solution file to grade:
 *   -DTARGET_FILE="MainProgram.cpp"          (student submission)
 *   -DTARGET_FILE="MainProgram_teacher.cpp"  (reference / sanity check)
 *
 * Each TEST_CASE carries a tag like [s1], [s2], ... so individual tests can be
 * run for partial credit (make test_1, make test_2, ...).
 ******************************************************************************/

#include "catch_amalgamated.hpp"

// Redirect the student's main so it does not collide with Catch2's main.
#define main student_main
  #ifndef TARGET_FILE
  #define TARGET_FILE "MainProgram.cpp"
  #endif
  #include TARGET_FILE
#undef main

#include <cmath>

/* ---- Section 1: Warm-up (smoke test: student_main runs cleanly) ---- */
TEST_CASE("S1 warm-up program runs", "[s1]") {
    REQUIRE_NOTHROW(student_main());
}

/* ---- Section 2: Core concepts (pointer & reference mechanics) ---- */
TEST_CASE("S2 pointer dereference modifies original", "[s2]") {
    int v = 10;
    int* p = &v;
    *p += 5;
    REQUIRE(v == 15);

    int g = 50;
    int& a = g;
    a = 99;
    REQUIRE(g == 99);
}

/* ---- Section 3.1: swapByPointer ---- */
TEST_CASE("S3.1 swapByPointer swaps values", "[s3][swap_ptr]") {
    int a = 1, b = 2;
    swapByPointer(&a, &b);
    REQUIRE(a == 2);
    REQUIRE(b == 1);

    int x = -5, y = 40;
    swapByPointer(&x, &y);
    REQUIRE(x == 40);
    REQUIRE(y == -5);
}

/* ---- Section 3.2: swapByReference ---- */
TEST_CASE("S3.2 swapByReference swaps values", "[s3][swap_ref]") {
    int a = 7, b = 9;
    swapByReference(a, b);
    REQUIRE(a == 9);
    REQUIRE(b == 7);

    int x = 100, y = 0;
    swapByReference(x, y);
    REQUIRE(x == 0);
    REQUIRE(y == 100);
}

/* ---- Section 3.3: incrementByReference ---- */
TEST_CASE("S3.3 incrementByReference adds one each call", "[s3][inc]") {
    int n = 4;
    incrementByReference(n);
    REQUIRE(n == 5);
    incrementByReference(n);
    REQUIRE(n == 6);

    int z = -1;
    incrementByReference(z);
    REQUIRE(z == 0);
}

/* ---- Section 3.4: sumAndCount (return value + out-parameter) ---- */
TEST_CASE("S3.4 sumAndCount returns sum and sets count", "[s3][sum]") {
    int data[] = {10, 20, 30, 40};
    int count = 0;
    int total = sumAndCount(data, 4, count);
    REQUIRE(total == 100);
    REQUIRE(count == 4);

    int one[] = {99};
    int c2 = -1;
    REQUIRE(sumAndCount(one, 1, c2) == 99);
    REQUIRE(c2 == 1);

    int empty[] = {0};
    int c3 = -1;
    REQUIRE(sumAndCount(empty, 0, c3) == 0);
    REQUIRE(c3 == 0);
}

/* ---- Section 4.1: normalizeTemperature ---- */
TEST_CASE("S4.1 normalizeTemperature rounds and kills noise", "[s4][temp]") {
    double t1 = -0.03;
    normalizeTemperature(t1);
    REQUIRE(t1 == Catch::Approx(0.0));

    double t2 = 36.66;
    normalizeTemperature(t2);
    REQUIRE(t2 == Catch::Approx(36.7));

    double t3 = 0.04;
    normalizeTemperature(t3);
    REQUIRE(t3 == Catch::Approx(0.0));

    double t4 = 21.34;
    normalizeTemperature(t4);
    REQUIRE(t4 == Catch::Approx(21.3));
}

/* ---- Section 4.2: clampToRange ---- */
TEST_CASE("S4.2 clampToRange clamps into bounds", "[s4][clamp]") {
    int hi = 130;
    clampToRange(hi, 0, 100);
    REQUIRE(hi == 100);

    int lo = -20;
    clampToRange(lo, 0, 255);
    REQUIRE(lo == 0);

    int mid = 60;
    clampToRange(mid, 0, 100);
    REQUIRE(mid == 60);

    int edge = 100;
    clampToRange(edge, 0, 100);
    REQUIRE(edge == 100);
}
