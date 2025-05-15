int echoPin = 18;
int triggerPin = 5;

#define SOUND_SPEED 0.034

int duration;
int distanceCm;

void setup() {
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
}

void loop() {
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCm = duration * SOUND_SPEED/2;
  if (distanceCm < 10) {
    Serial.println("Hay alguien");
  }

  Serial.println(distanceCm);
  delay(1000);
}
