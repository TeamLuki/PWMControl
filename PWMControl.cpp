/* Pulse Width Modulation control or just PWMControl
   Written by TheLBall
      I wrote a haiku
      To talk 'bout this library
      Couldn't finish it
   Thank you very much.
*/
#include "PWMControl.h"
#include "Arduino.h"

boolean ison = false;

PWMControl::PWMControl(int pin, int initpwm, int maxPwm)
{
    pinMode(pin,OUTPUT);
    _pin = pin;
    _initpwm = initpwm;
    _pwmrn = _initpwm;
    _maxPwm = maxPwm;
}
void PWMControl::on()
{
    if (ison == false)
    {
        ison = !ison;
        analogWrite(_pin,_pwmrn);
    }
}
void PWMControl::off()
{
    if (ison == true)
    {
        ison = !ison;
        analogWrite(_pin,0);
    }
}
void PWMControl::pwmUp()
{
    if (_pwmrn < _maxPwm)
    {
        _pwmrn = _pwmrn + 10;
        if (ison == true)
        {
            analogWrite(_pin,_pwmrn);
        }
    }
}
void PWMControl::pwmDown()
{
    if (_pwmrn > _initpwm)
    {
        _pwmrn = _pwmrn - 10;
        if (ison == true)
        {
            analogWrite(_pin,_pwmrn);
        }
    }
}
void PWMControl::pwmMax()
{
    _pwmrn = _maxPwm;
    if (ison == true)
    {
        analogWrite(_pin,_pwmrn);
    }
}
void PWMControl::pwmMin()
{
    _pwmrn = _initpwm;
    if (ison == true)
    {
        analogWrite(_pin,_pwmrn);
    }
}