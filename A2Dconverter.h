#include"currentRangeCounter.h"
int AnalogToDigitalConverter(int* analog, int length);
bool validateReading_12bit(int);
bool validateReading_10bit(int);
int digitalToAmps_12bit(float);
int digitalToAmps_10bit(float);
int getValidAmpsFromInputBits(int*,int );