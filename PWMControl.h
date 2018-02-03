/* Pulse Width Modulation control or just PWMControl
   Written by TheLBall
      I wrote a haiku
      To talk 'bout this library
      Couldn't finish it
   Thank you very much.
*/

#include "Arduino.h"

class PWMControl
{
    public:
    PWMControl(int pin, int initpwm, int maxPwm);
    void on();
    void off();
    void pwmUp();
    void pwmDown();
    void pwmMax();
    void pwmMin();
    private:
    int _pin;
    int _initpwm;
    int _pwmrn;
    int _maxPwm;
};