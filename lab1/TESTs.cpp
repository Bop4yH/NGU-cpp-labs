#define TEST 50
#ifdef TEST

#include "catch.h"
#include "TritSet.h"
TEST_CASE("CreateSet") {

    size_t size = 100;
    TritSet set(size);
    size_t allocLen = set.capacity();
    REQUIRE(allocLen >= (size * 2 / 8 / sizeof(int)));       // count of allocated blocks
}
TEST_CASE("Operators") {
    SECTION("[]") {
        TritSet set(100);
        size_t allocLen = set.capacity();
        set[1000000] = Unknown;
        REQUIRE(allocLen == set.capacity());       // do not allocate memory

        REQUIRE(set[100000000] == Unknown);        // Unknown trits out of range

        REQUIRE(allocLen == set.capacity());       // do not allocate memory

        set[10000] = True;
        REQUIRE(allocLen < set.capacity());        // allocate memory to store setted trit

        allocLen = set.capacity();

        set[10000] = Unknown;
        REQUIRE(allocLen == set.capacity());       // no memory operations

        set[5000] = False;
        REQUIRE(set[5000] == False);               // set trit
        REQUIRE(allocLen == set.capacity());       // no memory operations


    }

    SECTION("&,|,~") {


        /////////////////////////////////// operations tests start
        TritSet A(30);
        TritSet B(60);
        for (int i = 0; i < 30; i++) {
            B[i + 30] = False;
            if (i % 6 == 0) {
                A[i] = False;
                B[i] = True;
            }
            if (i % 6 == 1) {
                A[i] = Unknown;
                B[i] = True;
            }
            if (i % 6 == 2) {
                A[i] = True;
                B[i] = True;
            }
            if (i % 6 == 3) {
                A[i] = False;
                B[i] = Unknown;
            }
            if (i % 6 == 4) {
                A[i] = False;
                B[i] = False;
            }
            if (i % 6 == 5) {
                A[i] = Unknown;
                B[i] = Unknown;
            }
        }
        TritSet C = (A & B);
        TritSet D = (A | B);
        TritSet E = (~B);
        REQUIRE(C.capacity() == B.capacity());       // memory to store result

        for (int i = 0; i < 60; i++) {

            if (i >= 30) {                        // Unknown , False
                REQUIRE(C[i] == False);            // A&B = false
                REQUIRE(D[i] == Unknown);        // A|B = unknown
                REQUIRE(E[i] == True);            // ~B = true
                continue;
            }
            if (i % 6 == 0) {                    // False , True
                REQUIRE(C[i] == False);            // A&B = false
                REQUIRE(D[i] == True);            // A|B = true
                REQUIRE(E[i] == False);            // ~B = False
            }
            if (i % 6 == 1) {                    // Unknown , True
                REQUIRE(C[i] == Unknown);        // A&B = unknown
                REQUIRE(D[i] == True);            // A|B = true
                REQUIRE(E[i] == False);            // ~B = false
            }
            if (i % 6 == 2) {                    // True , True
                REQUIRE(C[i] == True);            // A&B = true
                REQUIRE(D[i] == True);            // A|B = true
                REQUIRE(E[i] == False);            // ~B = false
            }
            if (i % 6 == 3) {                    // False , Unknown
                REQUIRE(C[i] == False);            // A&B = false
                REQUIRE(D[i] == Unknown);        // A|B = unknown
                REQUIRE(E[i] == Unknown);        // ~B = unknown
            }
            if (i % 6 == 4) {                    // False , False
                REQUIRE(C[i] == False);            // A&B = false
                REQUIRE(D[i] == False);            // A|B = false
                REQUIRE(E[i] == True);            // ~B = true
            }
            if (i % 6 == 5) {                    // Unknown , Unknown
                REQUIRE(C[i] == Unknown);        // A&B = unknown
                REQUIRE(D[i] == Unknown);        // A|B = unknown
                REQUIRE(E[i] == Unknown);        // ~B = unknown
            }
        }
    }
}

TEST_CASE("Methods"){   // cardinality, trim, length  tests
    TritSet A(40);
    for (int i = 0; i < 20; i++)A[i] = True;
    for (int i = 20; i < 35; i++)A[i] = Unknown;
    for (int i = 35; i < 40; i++)A[i] = False;

    SECTION("Cardinality()") {
        REQUIRE(A.cardinality(True) == 20);
        REQUIRE(A.cardinality(False) == 5);
        REQUIRE(A.cardinality(Unknown) == 15);

        std::unordered_map<Trit, int, std::hash<int>> trits_counts = A.cardinality();
        REQUIRE(trits_counts[True] == 20);
        REQUIRE(trits_counts[False] == 5);
        REQUIRE(trits_counts[Unknown] == 15);
    }
    SECTION("Trim()") {
        A.trim(35);
        for (int i = 35; i < 40; i++)
            REQUIRE(A[i] == Unknown);
        REQUIRE(A.length() == 20);
    }
    SECTION("Shrink()"){
        TritSet B(100);
        size_t base_length = B.capacity();
        B[200] = False;
        size_t allocLen = B.capacity();
        B[150] = False;
        B.shrink();
        REQUIRE(allocLen > B.capacity());
        B[50] = True;
        B.shrink();
        REQUIRE(base_length == B.capacity());
    }
}



#endif












