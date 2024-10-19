// LED Traffic Light Simulation
// This program simulates a traffic light system with a pedestrian crossing button.

const int redLightPin = 19;    // Red LED connected to GPIO 23
const int yellowLightPin = 12; // Yellow LED connected to GPIO 22
const int greenLightPin = 21;  // Green LED connected to GPIO 21
const int buttonPin = 14;      // Pedestrian crossing button connected to GPIO 19

bool buttonPressed = false;    // To track if the button was pressed

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);

  // Initialize the button pin as input
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor

  // Start with the red light on
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
}

void loop() {
  // Check if the pedestrian button is pressed
  if (digitalRead(buttonPin) == LOW) {
    buttonPressed = true;
  }

  // Traffic light sequence
  redLight();   // Red for 5 seconds
  greenLight(); // Green for 5 seconds
  yellowLight(); // Yellow for 2 seconds

  // If the button is pressed, stop at the red light for pedestrian crossing
  if (buttonPressed) {
    redLight(); // Red stays on for pedestrians
    buttonPressed = false; // Reset the button press state
  }
}

void redLight() {
  digitalWrite(redLightPin, HIGH);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  delay(5000); // Stay at red for 5 seconds
}

void yellowLight() {
  digitalWrite(redLightPin, LOW);
  digitalWrite(yellowLightPin, HIGH);
  digitalWrite(greenLightPin, LOW);
  delay(2000); // Stay at yellow for 2 seconds
}

void greenLight() {
  digitalWrite(redLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(greenLightPin, HIGH);
  delay(5000); // Stay at green for 5 seconds
}
