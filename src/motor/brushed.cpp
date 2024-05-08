#include "brushed.h"

// TB6612FNG has maximum PWM switching frequency of 100kHz.
#define DEFAULT_LEDC_FREQ 5000

Motor::Motor(int pins[3], int channel, int resolution)
{
  IN1 = pins[0];
  IN2 = pins[1];
  PWM = pins[2];
  _channel = channel;
  _resolution = resolution;

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(PWM, OUTPUT);
  pinMode(STBY, OUTPUT);

  ledcAttachPin(PWM, _channel);
  ledcSetup(_channel, DEFAULT_LEDC_FREQ, _resolution);
}

void Motor::drive(int speed) {

  if(speed > 1000)
      speed = 1000;

  if(speed < -1000)
      speed = -1000; 

  speed = map(speed,-1000,1000,-1023,1023);

  if(speed > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else if(speed < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }


  ledcWrite(_channel, abs(speed));
}