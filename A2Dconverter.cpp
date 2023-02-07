#include "A2Dconverter.h"
#include <cmath>
int AnalogToDigitalConverter(int analog[12], int length)
{
    int dec_value = 0;
    int base = 1;
    int i=length-1;
    for(i=11;i>=0;i--)
    {
        dec_value+=analog[i]*base;
        base=base*2;
    }
    return dec_value;
}

bool validateReading(int reading)
{
    if(reading<0 || reading >4094)
    {
        return false;
    }
    return true;
}

int digitalToAmps(float digital)
{
    return round(10*(digital/4094));
}

int getValidAmpsFromInputBits(int bits[12],int length)
{
    int decimal_value = AnalogToDigitalConverter(bits,length);
    if(validateReading(decimal_value))
    {
        return digitalToAmps(decimal_value);
    }
    return 0;

}