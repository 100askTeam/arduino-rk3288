#ifndef GPIO_H
#define GPIO_H

#include <Arduino.h>

#define GPIO0 (0*32+0*8+7-0)
#define GPIO1 (0*32+1*8+5-0)
#define GPIO2 (7*32+0*8+3-8)
#define GPIO3 (6*32+0*8+4-8)
#define GPIO4 (6*32+1*8+0-8)

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