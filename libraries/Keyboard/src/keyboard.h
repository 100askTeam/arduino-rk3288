#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <Arduino.h>

#define KEY_A (30)

#define KEYBOARD_EVENT_PATH   "/dev/input/event2"

class KEYBOARD  {
    private:
        string m_sPath;
        int m_iFileEvent;
        int m_iCode;
        int m_iValue;
    
    public:
        KEYBOARD();
        virtual int readKey(void);
        virtual int getCode(void);
        virtual int getValue(void);
        ~KEYBOARD(void);
};


#endif 

