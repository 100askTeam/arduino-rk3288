#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <Arduino.h>

#define KEY1 (105)
#define KEY2 (106)


#define KEYBOARD_EVENT_PATH   "/dev/input/event2"

class KEYBOARD  {
    private:
        string m_sPath;
        int m_iFileEvent;
        
    public: 
        int code;
        int value;
    
    public:
        KEYBOARD();
        virtual int readKey(void);
        ~KEYBOARD(void);
};


#endif 


