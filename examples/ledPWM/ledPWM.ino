#include <PWMControl.h>
PWMControl led(10,1,101);
void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available())
  {
    String str = Serial.readStringUntil('\n');
    if (str == "on")
    {
      led.on();
    }
    if (str == "off")
    {
      led.off();
    }
    if (str == "up")
    {
      led.pwmUp();
    }
    if (str == "down")
    {
      led.pwmDown();
    }
    if (str == "max")
    {
      led.pwmMax();
    }
    if (str == "min")
    {
      led.pwmMin();
    }
  }

}
