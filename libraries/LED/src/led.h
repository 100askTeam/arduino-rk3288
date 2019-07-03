#ifndef _LED_H
#define _LED_H

#include "gpio.h"

#define LED1 (8*32+0*8+2 - 8)
//#define LED2 (8*32+0*8+1 - 8)

class LED : public GPIO {
    public:

        LED(int pin);
        ~LED(void);
        
        int on(void);
        int off(void);
};


#endif 


