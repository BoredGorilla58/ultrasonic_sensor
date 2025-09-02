int tpin = 9;
int epin = 10;

int pins[4] = {3 , 4 , 5 , 6} ;

long duration;
int distance;

void setup(){
  Serial.begin(9600);
  pinMode(tpin, OUTPUT);
  pinMode(epin, INPUT);

  for( int i = 0 ; i < 4 ; i ++){
    pinMode(i, OUTPUT);
  }
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
  getDistance();
  int distance_step = 8;
  for( int i = 0 ; i < 4 ; i ++){
    if ( (distance_step * i) > distance  ) { digitalWrite(pins[3-i],LOW); Serial.println(i); }
    else { digitalWrite(pins[3-i] , HIGH); }
  }
  delay(250);
}
