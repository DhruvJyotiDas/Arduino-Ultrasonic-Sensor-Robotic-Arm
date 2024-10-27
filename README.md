Crane Structure with Ultrasonic Sensor
This project involves a crane-like structure controlled by a joystick, with an ultrasonic distance sensor on top. The structure allows for rotation and arm movement, which are controlled by two servo motors. The project includes an Arduino script for sensor readings, servo control, and joystick input handling.

Components
1. Arduino Uno
Serves as the main controller, reading inputs from the joystick and ultrasonic sensor and controlling the servos.
2. HC-SR04 Ultrasonic Sensor
Used to measure distance from obstacles. It sends ultrasonic waves and calculates the time taken for the waves to return, allowing for the calculation of the distance to an object.
Pins Used:
TrigPin (Pin 9): Sends an ultrasonic pulse.
EchoPin (Pin 10): Receives the pulse and measures the duration.
3. Servos (2x)
Radar Servo (Pin 6): Controls the rotation of the crane’s top section.
Arm Servo (Pin 5): Moves the arm attached to the crane.
Both servos are controlled based on joystick inputs, allowing smooth and precise movement.
4. Joystick Module
Used to control the movement of the crane’s rotation and arm.
Joystick Horizontal (X-axis) (Pin A0): Controls the radar servo for crane rotation.
Joystick Vertical (Y-axis) (Pin A1): Controls the arm servo for arm movement.
Joystick Button (Pin 2): Reserved for future functionality, with pull-up resistor enabled.
Functionality
The joystick’s horizontal and vertical axes control the servo angles, allowing for movement of the crane’s rotation and arm.
The ultrasonic sensor measures the distance from obstacles, which can be used for obstacle avoidance or mapping.
Data from the joystick and ultrasonic sensor is sent to the serial monitor, which can be visualized through Processing or similar tools.
