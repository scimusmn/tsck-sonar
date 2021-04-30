
//The Kuwait Science Center - 314 Living with Assitive Technology-Sonar
//David Bailey, Science Museum of MN, 8/10/20

#include <NewPing.h>
#include "intervalTmr.h"

#define TRIGGER_PIN 1 // ATtiny pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 3 // ATtiny pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 150 //max distance we want to ping for (in centimeters). Maximum sensor distance is rated at ~500cm.
#define vibeMotor 0

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int distance;
IntervalTmr intTimer1;
IntervalTmr intTimer2;

void setup() {
  pinMode(vibeMotor, OUTPUT);
  intTimer1 = IntervalTmr(vibeMotor, 50, 50); //pin number, on time, off time
  intTimer2 = IntervalTmr(vibeMotor, 75, 125); //pin number, on time, off time
}

void loop() {
  distance = sonar.ping_cm(); //returns cm
  if ( distance > 3 && distance <= 50) { 
    digitalWrite(vibeMotor, HIGH);
  }
  else if (distance > 50 && distance <= 100) { 
    intTimer1.enable();
  }
  else if (distance > 100 && distance <= 150) { 
    intTimer2.enable();
  }
  else if (distance = MAX_DISTANCE || distance <= 3 ) digitalWrite(vibeMotor, LOW);
  delay(20); //neccessary for sensor read stabilization, this affects intTimers slightly
}
