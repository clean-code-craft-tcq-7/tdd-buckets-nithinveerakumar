#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "currentRangeCounter.hpp"

//DDD
map<string,string> TestData = {
  {"4,5","4-5,2\n"},
  {"1,2,4,5","1-2,2\n4-5,2\n"},
  {"","0"},
  {"3,3","3-3,2\n"},
  {"3,3,3,3","3-3,4\n"},
  {"3,0,0,3","0-0,2\n3-3,2\n"}
};

TEST_CASE("Range of current measurements") {
  //cover inferBreach
  for(auto& TestDataItr : TestData)
  {
    REQUIRE(getContinuousRangeCount(TestDataItr.first) == TestDataItr.second);
  }
  
}
