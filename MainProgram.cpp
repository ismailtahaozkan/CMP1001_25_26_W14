/******************************************************************************
 * LAB: Pointers and Pass-by-Reference
 * COURSE: CMP1001 - Introduction to Programming (C++)
 * DURATION: 60 minutes
 *
 * DESCRIPTION:
 *   In this lab you will learn how memory addresses work, how to use pointers
 *   to read and modify variables indirectly, and how pass-by-reference lets a
 *   function change the caller's variables. You will also see why pointers and
 *   references matter for real programs (e.g. swapping, in-place updates).
 *
 * INSTRUCTIONS:
 *   - Everything stays in THIS single file (MainProgram.cpp).
 *   - Do NOT add header files or split into multiple files.
 *   - Read each section's comments, then complete every // TODO: marker.
 *   - The file already compiles. Keep it compiling as you work.
 *   - Test as you go: compile and run after finishing each section.
 *
 * COMPILE & RUN:
 *   g++ MainProgram.cpp -o lab
 *   ./lab
 ******************************************************************************/

#include <iostream>
using namespace std;

/* ===========================================================================
 * FUNCTION PROTOTYPES
 * The functions are defined below main(). Do not change these signatures;
 * the grader relies on them exactly as written.
 * ======================================================================== */
void swapByPointer(int* a, int* b);
void swapByReference(int& a, int& b);
void incrementByReference(int& n);
int  sumAndCount(const int arr[], int size, int& outCount);
void normalizeTemperature(double& celsius);
void clampToRange(int& value, int low, int high);

/* ===========================================================================
 * MAIN
 * The sections below run small demonstrations. As you implement the
 * functions and TODOs, the printed output should become correct.
 * ======================================================================== */
int main() {
    cout << "=== Pointers and Pass-by-Reference Lab ===\n\n";

    /* -----------------------------------------------------------------------
     * SECTION 1 - WARM-UP  (5-10 min)
     * Goal: recall variables, cout/cin, simple arithmetic.
     * --------------------------------------------------------------------- */
    cout << "--- Section 1: Warm-up ---\n";

    // TODO 1a: Declare an int variable called 'score' and set it to 75.
    //          Then print it as:  Score: 75

    // TODO 1b: Declare two int variables 'x' and 'y' with values 8 and 3.
    //          Print their sum and their difference, each on its own line:
    //          Sum: 11
    //          Diff: 5

    cout << "\n";

    /* -----------------------------------------------------------------------
     * SECTION 2 - CORE CONCEPTS  (10-15 min)
     * Short idea:
     *   &var   -> the ADDRESS of var (where it lives in memory).
     *   int* p -> a POINTER: a variable that stores an address.
     *   *p     -> DEREFERENCE: the value stored at that address.
     *
     * Example (already complete - read it carefully):
     * --------------------------------------------------------------------- */
    cout << "--- Section 2: Core Concepts ---\n";

    int value = 42;
    int* ptr = &value;          // ptr now points to value
    cout << "value      = " << value  << "\n";   // 42
    cout << "*ptr       = " << *ptr   << "\n";   // 42 (same thing, via pointer)
    *ptr = 100;                 // change value THROUGH the pointer
    cout << "value now  = " << value  << "\n";   // 100

    // TODO 2a: Declare an int 'apples' = 10 and an int pointer 'pApples'
    //          that points to apples. Using the POINTER only (not 'apples'
    //          directly), add 5 to apples. Then print:  apples = 15

    // TODO 2b: A reference is an alias. Declare int 'gold' = 50 and an
    //          int reference 'alias' bound to gold. Change gold to 99 THROUGH
    //          'alias'. Then print:  gold = 99

    cout << "\n";

    /* -----------------------------------------------------------------------
     * SECTION 3 - GUIDED EXERCISES  (25-30 min)
     * Implement the functions at the bottom of the file, then the calls
     * below will produce correct output.
     * --------------------------------------------------------------------- */
    cout << "--- Section 3: Guided Exercises ---\n";

    // Exercise 3.1 - swap using POINTERS
    int p = 1, q = 2;
    swapByPointer(&p, &q);
    cout << "After swapByPointer:   p=" << p << " q=" << q << "\n"; // p=2 q=1

    // Exercise 3.2 - swap using REFERENCES
    int r = 7, s = 9;
    swapByReference(r, s);
    cout << "After swapByReference: r=" << r << " s=" << s << "\n"; // r=9 s=7

    // Exercise 3.3 - modify in place via reference
    int counter = 4;
    incrementByReference(counter);
    incrementByReference(counter);
    cout << "Counter after 2 increments: " << counter << "\n";     // 6

    // Exercise 3.4 - return a value AND fill an out-parameter by reference
    int data[] = {10, 20, 30, 40};
    int howMany = 0;
    int total = sumAndCount(data, 4, howMany);
    cout << "Sum=" << total << " Count=" << howMany << "\n";        // Sum=100 Count=4

    cout << "\n";

    /* -----------------------------------------------------------------------
     * SECTION 4 - CHALLENGE  (10 min)
     * Slightly open-ended, system-like tasks.
     * --------------------------------------------------------------------- */
    cout << "--- Section 4: Challenge ---\n";

    // Challenge 4.1 - normalize a temperature reading in place.
    // A sensor sometimes reports tiny negative values like -0.0 or noise.
    // normalizeTemperature should round to 1 decimal place and convert any
    // value with magnitude < 0.05 to exactly 0.0 (kill the noise).
    double t1 = -0.03, t2 = 36.66;
    normalizeTemperature(t1);
    normalizeTemperature(t2);
    cout << "Normalized: t1=" << t1 << " t2=" << t2 << "\n";        // t1=0 t2=36.7

    // Challenge 4.2 - clamp a value into [low, high] in place.
    // Used everywhere in systems: volume, brightness, sensor limits.
    int vol = 130;
    clampToRange(vol, 0, 100);
    cout << "Clamped volume: " << vol << "\n";                      // 100

    int bright = -20;
    clampToRange(bright, 0, 255);
    cout << "Clamped brightness: " << bright << "\n";               // 0

    cout << "\n=== End of Lab ===\n";
    return 0;
}

/* ===========================================================================
 * FUNCTION DEFINITIONS
 * Implement each function below. Replace the TODO bodies.
 * ======================================================================== */

// Exercise 3.1
// Swap the two ints that a and b POINT TO (use dereferencing *a, *b).
void swapByPointer(int* a, int* b) {
    // TODO 3.1: swap the values pointed to by a and b
}

// Exercise 3.2
// Swap the two ints that a and b REFER TO (a and b are aliases).
void swapByReference(int& a, int& b) {
    // TODO 3.2: swap a and b
}

// Exercise 3.3
// Add 1 to the variable that n refers to.
void incrementByReference(int& n) {
    // TODO 3.3: increment n by 1
}

// Exercise 3.4
// Return the sum of all elements in arr (which has 'size' elements).
// ALSO set outCount (by reference) to how many elements were summed.
int sumAndCount(const int arr[], int size, int& outCount) {
    // TODO 3.4a: set outCount to size
    // TODO 3.4b: compute and return the sum of arr[0..size-1]
    return 0; // replace this
}

// Challenge 4.1
// Modify 'celsius' in place: round to 1 decimal, and if the magnitude is
// less than 0.05 set it to exactly 0.0.
// Hint: rounding to 1 decimal -> round(celsius * 10.0) / 10.0
void normalizeTemperature(double& celsius) {
    // TODO 4.1: implement in place (no return value)
}

// Challenge 4.2
// Modify 'value' in place so it stays within [low, high]:
//   if value < low  -> value = low
//   if value > high -> value = high
void clampToRange(int& value, int low, int high) {
    // TODO 4.2: clamp value into [low, high]
}
