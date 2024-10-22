#include <Servo.h>

// Pin definitions for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Servo for rotating the ultrasonic sensor
Servo radarServo;        // Servo for rotating the entire crane top
Servo armServo;          // Servo for moving the arm
const int radarServoPin = 6;
const int armServoPin = 5;

// Variables for distance measurement
long duration;
int distance;

// Variables for joystick inputs
const int joyXPin = A0;   // Joystick horizontal (X-axis)
const int joyYPin = A1;   // Joystick vertical (Y-axis)
const int joyButtonPin = 2;  // Joystick button

int angleX = 0;   // Servo angle for X-axis (rotation)
int angleY = 90;  // Servo angle for Y-axis (arm movement)

// Function to get distance from ultrasonic sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(9600);

  // Set up ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach the radar and arm servos to their respective pins
  radarServo.attach(radarServoPin);
  armServo.attach(armServoPin);

  // Set up joystick input pins
  pinMode(joyButtonPin, INPUT_PULLUP);  // Joystick button with pull-up resistor
}

void loop() {
  // Read the joystick inputs
  int joyXValue = analogRead(joyXPin);
  int joyYValue = analogRead(joyYPin);
  int joyButtonState = digitalRead(joyButtonPin);

  // Map the joystick input to servo angles (adjust sensitivity as needed)
  angleX = map(joyXValue, 0, 1023, 0, 180);  // Horizontal joystick controls radar rotation
  angleY = map(joyYValue, 0, 1023, 0, 180);  // Vertical joystick controls arm movement

  // Move the radar servo (rotation of the crane) and the arm servo
  radarServo.write(angleX);
  armServo.write(angleY);

  // Get the distance from the ultrasonic sensor
  int dist = getDistance();

  // Send data to serial for Processing visualization
  Serial.print(angleX);
  Serial.print(",");
  Serial.print(angleY);
  Serial.print(",");
  Serial.println(dist);

  // Add a small delay for smooth movements
  delay(1000);
}
