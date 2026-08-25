#ifndef LEDS_H
#define LEDS_H

class LEDs {
public:
    void begin();
    
    void redOn();
    void redOff();

    void yellowOn();
    void yellowOff();
    
    void greenOn();
    void greenOff();

    void allof();

};

#endif