#ifndef _I2C_H
#define _I2C_H

#include <Arduino.h>

#define I2C0  "/dev/i2c-4"
#define I2C1  "/dev/i2c-4"

#define I2CX  "/dev/i2c-0" //for rtc

#define AT24C256  0x50
#define HYM8563   0x51


class I2C {
private:
    static int m_iUseCount;
    string m_sPath;
    static int m_iFile;
    
    
public:
    unsigned int m_iDevAddr;
    
    I2C();
    I2C(string bus, unsigned int dev);
    virtual unsigned char readRegister(unsigned int registerAddress);
    virtual unsigned char readRegister(unsigned int registerAddress, int count, unsigned char* buf);
    virtual int writeRegister(unsigned int registerAddress, unsigned char value);
    virtual int writeRegister(unsigned int registerAddress, int count, unsigned char* buf);
    virtual ~I2C();
};


#endif 

