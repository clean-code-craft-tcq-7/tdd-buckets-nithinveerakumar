#include "A2Dconverter.h"
#include <cmath>
using namespace std;
int AnalogToDigitalConverter(int *analog, int length)
{
    int dec_value = 0;
    int base = 1;
    int i=length-1;
    for(i;i>=0;i--)
    {
        dec_value+=analog[i]*base;
        base=base*2;
    }
    return dec_value;
}

bool validateReading_12bit(int reading)
{
    if(reading<0 || reading >4094)
    {
        return false;
    }
    return true;
}

bool validateReading_10bit(int reading)
{
    if(reading<0 || reading >1022)
    {
        return false;
    }
    return true;
}


int digitalToAmps_12bit(float digital)
{
    if(validateReading_12bit(digital))
        return round(10*(digital/4094));
    else
        return 0;
}

int digitalToAmps_10bit(float digital)
{
    if(validateReading_10bit(digital))

        return round((digital/34.067)-15);
    else
        return 0;
}

int getValidAmpsFromInputBits(int* bits,int length)
{
    int decimal_value = AnalogToDigitalConverter(bits,length);
    
    if(length == 12){
        return digitalToAmps_12bit(decimal_value);
    } else if ( length == 10) {
        return digitalToAmps_12bit(decimal_value);
    }
    cout<<"Converter not support this input"<<endl;
    return 0;
    


}