#ifndef GPIO_H
#define GPIO_H

#include <Arduino.h>

#define GPIO0 (6*32+0*8+0-8)
#define GPIO1 (6*32+0*8+3-8)
#define GPIO2 (6*32+0*8+4-8)
#define GPIO3 (0*32+0*8+7-0)
#define GPIO4 (0*32+1*8+5-0)


class GPIO {
    private:
        int m_iPin;
        string m_sPath;
        
    public:
        GPIO(void);
        GPIO(int pin);
        
        void setPin(int pin);
        int getPin(void);   
        
        void setPath(int pin);
        string getPath(void);
        
        int setDirection(int dir);
        int getDirection(void);
        
        int setValue(int val);
        int getValue(void);
        
        int exportGPIO(void);
        int unexportGPIO(void);
};

#endif