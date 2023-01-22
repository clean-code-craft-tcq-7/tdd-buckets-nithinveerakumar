#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "currentRangeCounter.cpp"

TEST_CASE("Range of current measurements") {
  //cover inferBreach
  REQUIRE(getContRageCount("4,5") == "4-5,2\n");
  REQUIRE(getContRageCount("1,2,4,5") == "1-2,2\n4-5,2\n");

}
