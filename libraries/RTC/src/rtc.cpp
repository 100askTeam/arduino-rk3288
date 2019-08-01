
#include "rtc.h"

RTC::RTC(int num)
{
    if (num == I2C_RTC)
        I2C(I2C0, HYM8563);
    
    this->m_iDevAddr = HYM8563; //bug
    
    this->hym8563Init();
}


void RTC::hym8563Init(void)
{
    unsigned char rtc_vl;
#if 0
    readRegister(0x02, 1, &rtc_vl);
    if (rtc_vl & (0x01<<7))
    {
        //默认时间 2000/1/1
        this->year = 2000;
        this->month = 1;
        this->day = 1;
        this->week = 6;
        this->hour = 0;
        this->minute = 0;
        this->second = 0;

        this->setTime();
        printf("Set the default time:2000-01-01 00:00:00, you may have to readjust the clock\n");
    }
#endif
}


Time RTC::readTime()
{
    Time t;
    unsigned char rtc_data[7];

    readRegister(0x02, 7, rtc_data);
    
    //printf("readTime: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n", 
        //rtc_data[0], rtc_data[1], rtc_data[2], rtc_data[3], rtc_data[4], rtc_data[5], rtc_data[6]);
    
    this->second = (rtc_data[0] & 0xF) + ((rtc_data[0] & 0x70)>>4)*10;
    this->minute = (rtc_data[1] & 0xF) + ((rtc_data[1] & 0x70)>>4)*10;
    this->hour   = (rtc_data[2] & 0xF) + ((rtc_data[2] & 0x30)>>4)*10;
    this->day    = (rtc_data[3] & 0xF) + ((rtc_data[3] & 0x30)>>4)*10;
    this->week   = (rtc_data[4] & 0x7);
    this->month  = (rtc_data[5] & 0xF) + ((rtc_data[5] & 0x10)>>4)*10;
    this->year   = (rtc_data[6] & 0xF) + ((rtc_data[6] & 0xF0)>>4)*10 + 2000;

    t.second = this->second;
    t.minute = this->minute;
    t.hour   = this->hour;  
    t.week   = this->week;  
    t.day    = this->day;   
    t.month  = this->month; 
    t.year   = this->year;  
    
    return t;
}

int RTC::setTime(Time t)
{
    unsigned int ctrl;
    unsigned char rtc_data[7];
    memset(rtc_data, 0, 7*sizeof(unsigned char));
    
    this->second = t.second;
    this->minute = t.minute;
    this->hour   = t.hour;
    this->week   = t.week;
    this->day    = t.day;
    this->month  = t.month; 
    this->year   = t.year;  

    if(this->second > 59)
        goto err;
    else
        rtc_data[0] = (this->second/10)<<4 | (this->second%10);
    
    if(this->minute > 59)
        goto err;
    else
        rtc_data[1] = (this->minute/10)<<4 | (this->minute%10);
    
    if (this->hour>23)
        goto err;   
    else
        rtc_data[2] = (this->hour/10)<<4 | (this->hour%10);     
       
    if(this->day > 31)
        goto err;
    else
        rtc_data[3] = (this->day/10)<<4 | (this->day%10);
    
    if(this->week>6)
        goto err;
    else
        rtc_data[4] = this->week;
    
    if(this->month > 12 || this->month==0)
        goto err;
    else
        rtc_data[5] = (this->month/10)<<4 | (this->month%10);
    
    if((this->year-2000) > 99)
        goto err;
    else
        rtc_data[6] = ((this->year-2000)/10)<<4 | ((this->year-2000)%10);
    
    writeRegister(0x02, 7, rtc_data);
    
    return 0;

err:
    printf("setTime err.\n\r");
    return 1;       

}

void RTC::timePrintf()
{
    readTime();

    printf("Time: %d-%02d-%02d %02d:%02d:%02d [%s]\n", this->year, this->month,this->day,this->hour,this->minute,this->second, this->week_string[this->week]);
}


RTC::~RTC()
{
    
}