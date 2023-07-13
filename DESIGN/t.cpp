#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "P_2_CPP.h"
#include<iostream>

TEST_CASE("Testing num_iter") {
    CHECK(num_iter(0, 0, 500) == 500);
    
    // Testing a value of c that makes the series diverge quickly
    CHECK(num_iter(0, std::complex<double>(2, 2), 500) == 1);

    // Testing a value of c that makes the series diverge, but not immediately
    CHECK(num_iter(0, std::complex<double>(1, 0), 500) == 2);
}
