int tpin = 9;
int epin = 10;
int green_led = 11;
int red_led = 4;

long duration;
int distance;
int low_distance = 20;

void setup() {
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor starting");
  pinMode(tpin , OUTPUT);
  pinMode(epin , INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);

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


void loop() {
  // Getting Distance
  getDistance();

  // Checking distance is lower than critical low distance
  if (distance < low_distance) {
    // RED ON , GREEN OFF
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led , LOW);
    Serial.println("RED");
  } else {
    //RED OFF , GREEN ON
    digitalWrite(red_led, LOW);
    digitalWrite(green_led , HIGH);
    Serial.println("GREEN");
  }

  delay(250);
}
