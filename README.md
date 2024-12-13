# Sumo Robot

This project contains the code for a sumo robot built for a competition. The robot uses motor control, ultrasonic sensor, and IR sensor configurations to detect and push objects out of the ring while avoiding lines.

## Hardware Setup

https://github.com/user-attachments/assets/4bb56c18-8b56-4d90-b98e-7fa41129c853


### Motor Control Pins
- STBY_PIN: 33
- AIN1_PIN: 25
- AIN2_PIN: 26
- PWMA_PIN: 27
- BIN1_PIN: 14
- BIN2_PIN: 13
- PWMB_PIN: 12

### Ultrasonic Sensor Pins
- TRIG_PIN: 18 (Trigger pin)
- ECHO_PIN: 32 (Echo pin)

### Sensor Pins
- Left IR Sensor: 35
- Right IR Sensor: 34

### Constants
- LINE_THRESHOLD: 500 (IR sensor threshold)
- DISTANCE_THRESHOLD: 40 (Ultrasonic sensor threshold in cm)
- PUSH_SPEED: 255 (Maximum speed for pushing)
- SEARCH_SPEED: 200 (Speed while searching)
- BACKUP_TIME: 700 (Time to back up when hitting line)
- SPIRAL_INCREMENT: 200 (Duration increment for spiral search)

## Software Setup

### Prerequisites
- Arduino IDE
- Arduino board compatible with the pin configurations

### Installation
1. Clone the repository: `git clone https://github.com/AvishkaVishwa/Robot-Competetion-Sumo-Robot-method.git`
2. Open the project in Arduino IDE.
3. Upload the code to your Arduino board.

### Code Explanation

#### `setup()`
- Initializes serial communication.
- Sets motor control and sensor pins as outputs/inputs.
- Enables the motor driver.
- Initializes the timer for spiral search.

#### `measureDistance()`
- Measures the distance using the ultrasonic sensor.

#### `loop()`
- Reads sensor values and performs actions based on conditions.
- Implements line detection, box pushing, and spiral search logic.

#### Motor Control Functions
- `BACKWARD(int Speed)`: Moves the robot backward.
- `FORWARD(int Speed)`: Moves the robot forward.
- `ROTATE(int Speed)`: Rotates the robot.
- `Stop()`: Stops the robot.

## Usage
1. Place the robot in the competition ring.
2. Turn on the robot.
3. The robot will start by delaying for 5 seconds as per sumo rules.
4. The robot will then search for objects using a spiral pattern and push detected objects while avoiding lines.

## Contribution
Feel free to fork the repository and submit pull requests for any improvements or bug fixes.

## License
This project is licensed under the MIT License.# Sumo Robot
