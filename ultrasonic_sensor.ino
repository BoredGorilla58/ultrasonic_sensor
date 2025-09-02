int tpin = 9;
int epin = 10;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor starting");
  pinMode(tpin , OUTPUT);
  pinMode(epin , INPUT);

}

void loop() {
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
  Serial.print(distance);
  Serial.println("cm");

  delay(500);

}
