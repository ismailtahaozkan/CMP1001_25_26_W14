## ===========================================================================
## Makefile - Pointers and Pass-by-Reference Lab
## CMP1001
##
## Common targets:
##   make            build the student program (lab)
##   make run        build and run the student program
##   make grade      build grader against student file, run ALL tests
##   make grade-teacher  run grader against the teacher solution (sanity check)
##
## Per-section / partial-credit targets (run one group of tests):
##   make test_1     Section 1  warm-up      [s1]
##   make test_2     Section 2  core concepts [s2]
##   make test_3     Section 3  ALL guided   [s3]
##   make test_4     Section 4  ALL challenge [s4]
##
## Finer-grained single-exercise targets:
##   make test_3_1   swapByPointer        [swap_ptr]
##   make test_3_2   swapByReference      [swap_ref]
##   make test_3_3   incrementByReference [inc]
##   make test_3_4   sumAndCount          [sum]
##   make test_4_1   normalizeTemperature [temp]
##   make test_4_2   clampToRange         [clamp]
##
##   make clean      remove build artifacts
## ===========================================================================

CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall

CATCH_SRC := catch_amalgamated.cpp
STUDENT   := MainProgram.cpp
TEACHER   := MainProgram_teacher.cpp
GRADER    := grader_tests.cpp

.PHONY: all run grade grade-teacher clean \
        test_1 test_2 test_3 test_4 \
        test_3_1 test_3_2 test_3_3 test_3_4 test_4_1 test_4_2

## ---- Build / run the student program itself ----
all: lab

lab: $(STUDENT)
	$(CXX) $(CXXFLAGS) $(STUDENT) -o lab

run: lab
	./lab

## ---- Build the grader (against the student submission) ----
grader: $(GRADER) $(CATCH_SRC) $(STUDENT)
	$(CXX) $(CXXFLAGS) -DTARGET_FILE='"$(STUDENT)"' $(GRADER) $(CATCH_SRC) -o grader

## ---- Build the grader against the teacher solution ----
grader_teacher: $(GRADER) $(CATCH_SRC) $(TEACHER)
	$(CXX) $(CXXFLAGS) -DTARGET_FILE='"$(TEACHER)"' $(GRADER) $(CATCH_SRC) -o grader_teacher

## ---- Run everything ----
grade: grader
	./grader

grade-teacher: grader_teacher
	./grader_teacher

## ---- Section-level partial-credit targets ----
test_1: grader
	./grader "[s1]"

test_2: grader
	./grader "[s2]"

test_3: grader
	./grader "[s3]"

test_4: grader
	./grader "[s4]"

## ---- Single-exercise targets ----
test_3_1: grader
	./grader "[swap_ptr]"

test_3_2: grader
	./grader "[swap_ref]"

test_3_3: grader
	./grader "[inc]"

test_3_4: grader
	./grader "[sum]"

test_4_1: grader
	./grader "[temp]"

test_4_2: grader
	./grader "[clamp]"

clean:
	rm -f lab grader grader_teacher
