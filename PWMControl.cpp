/* Pulse Width Modulation control or just PWMControl
   Written by TheLBall
   Comments by TheLBall but from 2019
      I wrote a haiku
      To talk 'bout this library
      Couldn't finish it
   Thank you very much.
*/
#include "PWMControl.h"
#include "Arduino.h"
//One of the goals was to help beginners program??? I really don't know.
boolean ison = false;
//Ok, here's the init code. This initializes the variables used for the library, storing given variables in their respective places.
PWMControl::PWMControl(int pin, int initpwm, int maxPwm)
{
    pinMode(pin,OUTPUT);
    _pin = pin;
    _initpwm = initpwm;
    _pwmrn = _initpwm;
    _maxPwm = maxPwm;
}
//Why are these seperate commands? Combining them takes 0 work to do!
//This specifically tells the Arduino to send the requested PWM value to the output.
void PWMControl::on()
{
    if (ison == false)
    {
        ison = !ison;
        analogWrite(_pin,_pwmrn);
    }
}
//Now THIS one tells the Arduino to set the output to 0. This turns off what's on the recieving end.
void PWMControl::off()
{
    if (ison == true)
    {
        ison = !ison;
        analogWrite(_pin,0);
    }
}
//The PWM value is stored in an integer. This code adds 10 to the variable and refreshes the output if it's "on".
void PWMControl::pwmUp()
{
    if (_pwmrn < _maxPwm)
    {
        _pwmrn = _pwmrn + 10;
       //Note to self, why isn't this if statement a function? That could've save precious keypresses.
        if (ison == true)
        {
            analogWrite(_pin,_pwmrn);
        }
    }
}
//This code subtracts 10 from the variable and refreshes the output if necessary.
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
//This sets the variable to the maximum as defined by the user. It also refreshes the output if necessary.
void PWMControl::pwmMax()
{
    _pwmrn = _maxPwm;
   //WHY WASN'T THIS A SEPERATE FUNCTION??? IT'S USED MULTIPLE TIMES???? -TheLBall
    if (ison == true)
    {
        analogWrite(_pin,_pwmrn);
    }
}
//This sets the variable to the minimum value as set by the user, then refreshes output if necessary. Yes, I know it's technicaly the initial value, sosumi.
void PWMControl::pwmMin()
{
    _pwmrn = _initpwm;
    if (ison == true)
    {
        analogWrite(_pin,_pwmrn);
    }
}
//If you've made it here, congrats. I don't think I'll be working on this anymore, so feel free to contribute!
