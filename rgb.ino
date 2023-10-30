/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

const int r = 9;           // the PWM pin the LED is attached to
const int g = 10;
const int b = 11;
int color = 0;   // how bright the LED is
int red = 255;
int green = 0;
int blue = 0;
int v = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // set the brightness of pin 9:
  if(color>765){
    color = 0;
  }
  if(0<=color&&color<255){
      green+=v;
      red-=v;
  }
  if(255<=color&&color<510){
      blue+=v;
      green-=v;
  }
  if(510<=color&&color<765){
      red+=v;
      blue-=v;
  }
  

  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);
  color+=v;
  delay(30);
}   
