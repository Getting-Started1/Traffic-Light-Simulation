int redLED = 25;
int yellowLED = 26;
int greenLED = 27;
int button = 33;
bool pedestrianRequest = false;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), pedestrianCrossing, FALLING);
}

void loop() {
  if (pedestrianRequest) {
    // Red light for pedestrian crossing
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(5000); // 5 seconds for pedestrian crossing
    pedestrianRequest = false;
  }
 
  // Normal Traffic Light Sequence
  digitalWrite(redLED, HIGH);
  delay(5000); // 3 seconds for green light

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(2000); // 2 seconds for yellow light

  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(3000); // 5 seconds for red light

  digitalWrite(greenLED, LOW);
}

void pedestrianCrossing() {
  pedestrianRequest = true;
}
