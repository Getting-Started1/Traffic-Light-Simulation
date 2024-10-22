// LED Traffic Light Simulation
// This program simulates a traffic light system with a pedestrian crossing button.

const int redLightPin = 12;   // Red LED connected to GPIO 12
const int yellowLightPin = 14; // Yellow LED connected to GPIO 14
const int greenLightPin = 34;  // Green LED connected to GPIO 34
const int buttonPin = 19;      // Pedestrian crossing button connected to GPIO 19

bool pedestrianCrossing = false;  // Flag to track if the pedestrian button has been pressed

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);

  // Set the button pin as INPUT
  pinMode(buttonPin, INPUT);

  // Start with red light on
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
}

void loop() {
  // Check if the pedestrian button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    pedestrianCrossing = true;  // Set flag for pedestrian crossing
  }

  // Normal traffic light sequence if no pedestrian crossing
  if (!pedestrianCrossing) {
    // Red light for 5 seconds
    digitalWrite(redLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
    delay(5000);  // 5 seconds

    // Green light for 3 seconds
    digitalWrite(redLightPin, LOW);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, HIGH);
    delay(3000);  // 3 seconds

    // Yellow light for 2 seconds
    digitalWrite(redLightPin, LOW);
    digitalWrite(yellowLightPin, HIGH);
    digitalWrite(greenLightPin, LOW);
    delay(2000);  // 2 seconds

  } else {
    // Pedestrian crossing sequence
    pedestrianCrossing = false;  // Reset pedestrian crossing flag

    // Stop traffic with red light for pedestrian to cross
    digitalWrite(redLightPin, HIGH);
    digitalWrite(yellowLightPin, LOW);
    digitalWrite(greenLightPin, LOW);
    delay(7000);  // Hold red for 7 seconds to allow crossing

    // Resume normal traffic light sequence after pedestrian crossing
  }
}
