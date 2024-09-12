#include <Servo.h>
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;
Servo myServo; //Create a servo project

int servoPin = 9;

void setup() {
    myservo.attach(servoPin); // Attach servo to pin 9
    Wire.begin();
    rtc.begin();
    Serial.begin(9600); // Start serial comm for debugging
}

void loop() {
    DateTime now = rtc.now();
    if (now.hour() % 6 == 0 && now.minute() == 0) { // Logic to dispense food every 6 hours
        myservo.write(90); // Rotate servo to dispense food
        delay(1000); // Wait for 1 second
        myservo.write(0); // Return servo to initial position
        delay(60000); // Wait for 1 minute to avoid multiple triggers
    }
}
