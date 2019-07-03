#ifndef _ADC_H
#define _ADC_H

#include <Arduino.h>

#define ADC1_PATH  "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define ADC2_PATH  "/sys/bus/iio/devices/iio:device0/in_voltage2_raw"

class ADC {
    private:
        string m_sPath;
        int m_iFile;
        int m_iValue;

    public:
        ADC(int num);
        ~ADC(void);
        
        int getValue(void);
};

#endif