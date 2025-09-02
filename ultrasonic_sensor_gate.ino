int tpin = 9;
int epin = 10;

long duration;
int distance;
#include <Servo.h>

Servo gate_servo;


void setup() {
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor starting");
  pinMode(tpin , OUTPUT);
  pinMode(epin , INPUT);

  gate_servo.attach(5);

}

void getDistance(){
  // Clearing Trigger
  digitalWrite(tpin, LOW);
  delayMicroseconds(2);

  // Activating Trigger
  digitalWrite(tpin , HIGH);
  delayMicroseconds(10);
  digitalWrite(tpin, LOW);

  // Getting echo
  duration = pulseIn(epin , HIGH);

  // Convert duration to distance
  distance = (duration*0.034)/2;
  Serial.println(distance);
}


bool isOpen = false;
void closeGate(){
    for (int pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    gate_servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
  isOpen = false;
}
void openGate(){
    for (int pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    gate_servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
  isOpen = true;
}


void loop() {
  getDistance();
  if (isOpen) {
    if (distance > 15) { closeGate(); }
  } else {
    if (distance < 15) { openGate(); }
  }
  delay(1000);
}
