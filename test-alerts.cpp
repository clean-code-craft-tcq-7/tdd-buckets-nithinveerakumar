#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
//#include "currentRangeCounter.cpp"
//#include "A2Dconverter.cpp"

#include "currentRangeCounter.h"
#include "A2Dconverter.h"

map<string,string> RangeCountTestData = {
  {"4,5","4-5,2\n"},
  {"1,2,4,5","1-2,2\n4-5,2\n"},
  {"","0"},
  {"3,3","3-3,2\n"},
  {"3,3,3,3","3-3,4\n"},
  {"3,0,0,3","0-0,2\n3-3,2\n"}
};

TEST_CASE("Range of current measurements") {
 
  for(auto& TestDataItr : RangeCountTestData)
  {
    REQUIRE(getContinuousRangeCount(TestDataItr.first) == TestDataItr.second);
  }


}


int AnalogInput[][12]={{1,1,1,1,1,0,0,0,1,0,1,1},{1,1,1,1,1,0,0,0,1,0,1,1},{1,1,1,1,1,0,0,0,1,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1},{}};
int DigitalOutput[]={3979,3979,3979,0,4095,0};
TEST_CASE("Test analog to digital converter") {
  int outputCounter = 0;
  for(auto& TestDataItr : AnalogInput)
  {
    int length=sizeof(TestDataItr)/sizeof(TestDataItr[0]);
    REQUIRE(AnalogToDigitalConverter(TestDataItr,length) == DigitalOutput[outputCounter++]);

  }


}

int Digitalinput[]={3979,3979,3979,0,4095,0};
bool validation[]={true,true,true,true,false,true};
TEST_CASE("Test if reading from the converter is valid") {
  for(int i=0;i<(sizeof(Digitalinput)/sizeof(Digitalinput[0]));i++)
  {
    REQUIRE(validateReading(Digitalinput[i]) == validation[i]);

  }
}

int DigitalinputtoAmps[]={1146,0,3979,1};
int Amps[]={3,0,10,0};
TEST_CASE("Test Digital to Amps converter") {
  for(int i=0;i<(sizeof(DigitalinputtoAmps)/sizeof(DigitalinputtoAmps[0]));i++)
  {
    REQUIRE(digitalToAmps(float(DigitalinputtoAmps[i])) == Amps[i]);

  }
}
int BitsInput[][12]={{1,1,1,1,1,0,0,0,1,0,1,1},{1,1,1,1,1,0,0,0,1,0,1,1},{1,1,1,1,1,0,0,0,1,0,1,1},{0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1},{}};
int outputAmps[] = {10,10,10,0,0,0};
TEST_CASE("Test Bits to valid Amps converter") {
  int outputCounter = 0;
   for(auto& TestDataItr : BitsInput)
  {
    int length=sizeof(TestDataItr)/sizeof(TestDataItr[0]);
    REQUIRE(getValidAmpsFromInputBits(TestDataItr,length) == outputAmps[outputCounter++]);

  }
}