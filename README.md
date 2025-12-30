Industrial Proximity Alert System
A three-stage safety monitoring system designed using an Arduino Uno and an IR Obstacle Avoidance Sensor. This project demonstrates the implementation of a Finite State Machine (FSM) and non-blocking timing logic using the millis() function.

Project Overview
In industrial environments, safety systems must provide clear, tiered feedback based on the proximity of a hazard. This project simulates that by transitioning through three distinct states:

Clear (Safe): No obstruction detected.

Warning (Caution): Obstruction detected for less than 2 seconds.

Danger (Emergency): Obstruction persistent for more than 2 seconds.

Key Engineering Concepts
Non-Blocking I/O: Utilized millis() instead of delay() to ensure the sensor remains responsive while LEDs are blinking.

Pass-by-Reference: Implemented a modular blinkLED() function using C++ references (&) to update global timing variables.

State Logic: Designed logic to track the duration of a digital signal to trigger tiered responses.

Circuit Diagram:

<img width="606" height="448" alt="image" src="https://github.com/user-attachments/assets/61b9ea4e-47aa-4602-919d-fe5682c0358d" />

Hardware Components
Microcontroller: Arduino Uno

Sensor: IR Obstacle Avoidance Module (Active Low)

Visual Output: Green LED (Safe), Yellow LED (Warning - Blinking), Red LED (Danger - Solid)

Resistors: 3x 220 Ohm (for LEDs)

Circuit Diagram
(Note: Replace this placeholder with a photo of your breadboard or a Fritzing schematic)

Logic Flow
Idle: Green LED is HIGH.

Detection: When SensorPin goes LOW, the system enters the Warning state.

Timing: The system calculates currentMillis - prevMillis.

Escalation: If the duration exceeds 2000ms, the system switches from blinking Yellow to solid Red.

How to Use
Clone this repository using the git clone command.

Open the .ino file in the Arduino IDE.

Ensure pins are connected as defined in the code (Green: 13, Yellow: 12, Red: 11, Sensor: 8).

Upload to your Arduino Uno.
