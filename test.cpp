
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "board.h"
TEST_CASE("Test mod_2")
{
  complex a(3,4);
  CHECK(a.mod_2() == 25);
};

TEST_CASE("test coordinate_change")
{
  complex a(-2, -1.13);
  CHECK(E(coordinate_change(0,100),a)); //this tests that the origin is properly translated
  CHECK(E(coordinate_change(12,10), 
};
