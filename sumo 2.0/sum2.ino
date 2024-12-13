// Motor Control Pins for your robot
#define STBY_PIN 33
#define AIN1_PIN 25
#define AIN2_PIN 26
#define PWMA_PIN 27
#define BIN1_PIN 14
#define BIN2_PIN 13
#define PWMB_PIN 12

// Ultrasonic Sensor Pins for your robot
#define TRIG_PIN 18  // Trigger pin
#define ECHO_PIN 32  // Echo pin

// Sensor Pins for your robot
const int leftIRPin = 35;     // Left line detection IR sensor
const int rightIRPin = 34;    // Right line detection IR sensor

// Constants
const int LINE_THRESHOLD = 500;  // Adjust based on your IR sensor readings
const int DISTANCE_THRESHOLD = 40;  // Adjust based on your ultrasonic sensor readings (in cm)
const int PUSH_SPEED = 255;      // Maximum speed for pushing
const int SEARCH_SPEED = 200;    // Speed while searching
const int BACKUP_TIME = 700;     // Time to back up when hitting line

// Spiral search parameters
unsigned long lastDirectionChange = 0;
unsigned long spiralDuration = 100;  // Initial duration for each spiral segment
const unsigned long SPIRAL_INCREMENT = 200;  // How much to increase the duration each spiral
int currentSpiral = 0;  // Keep track of spiral iterations

void setup() {
  Serial.begin(115200);

  // Set motor control pins as outputs
  pinMode(AIN1_PIN, OUTPUT);
  pinMode(AIN2_PIN, OUTPUT);
  pinMode(PWMA_PIN, OUTPUT);
  pinMode(BIN1_PIN, OUTPUT);
  pinMode(BIN2_PIN, OUTPUT);
  pinMode(PWMB_PIN, OUTPUT);
  pinMode(STBY_PIN, OUTPUT);

  // Enable the motor driver
  digitalWrite(STBY_PIN, HIGH);

  // Sensor pins setup
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(leftIRPin, INPUT);
  pinMode(rightIRPin, INPUT);

  delay(5000); // Initial delay as per sumo rules
  lastDirectionChange = millis();  // Initialize the timer
}

long measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2; // Convert to centimeters
  return distance;
}

void loop() {
  // Read sensor values
  long frontDistance = measureDistance();
  int leftValue = analogRead(leftIRPin);
  int rightValue = analogRead(rightIRPin);

  // Reset spiral search if box is found
  if (frontDistance < DISTANCE_THRESHOLD) {
    currentSpiral = 0;
    spiralDuration = 500;
  }

  // Debug output
  Serial.print("Distance: ");
  Serial.print(frontDistance);
  Serial.print(" Left: ");
  Serial.print(leftValue);
  Serial.print(" Right: ");
  Serial.println(rightValue);

  // Check for line detection first
  if (leftValue < LINE_THRESHOLD || rightValue < LINE_THRESHOLD) {
    // Hit the line - back up and turn
    Stop();
    Serial.println("Action: Hit line, backing up and turning");
    BACKWARD(PUSH_SPEED);
    delay(BACKUP_TIME);
    Stop();
    // Turn about 90 degrees
    ROTATE(SEARCH_SPEED);
    delay(500);
    return;
  }

  // Box detection and removal logic
  if (frontDistance < DISTANCE_THRESHOLD) {  // Ultrasonic sensor: closer distance means smaller value
    // Box detected - charge at full speed
    Serial.println("Action: Box detected, moving forward to push");
    FORWARD(PUSH_SPEED);
    // Keep pushing until we hit a line
    while (frontDistance < DISTANCE_THRESHOLD) {
      frontDistance = measureDistance();
      leftValue = analogRead(leftIRPin);
      rightValue = analogRead(rightIRPin);

      // Check if we've hit a line
      if (leftValue < LINE_THRESHOLD || rightValue < LINE_THRESHOLD) {
        // Back up and search for new box
        Stop();
        Serial.println("Action: Hit line while pushing, backing up");
        BACKWARD(PUSH_SPEED);
        delay(BACKUP_TIME);
        break;
      }
      delay(10);
    }
  } else {
    // No box detected - search in spiral pattern
    unsigned long currentTime = millis();
    
    if (currentTime - lastDirectionChange >= spiralDuration) {
      currentSpiral++;
      lastDirectionChange = currentTime;
      
      if (currentSpiral % 2 == 0) {
        // Increase spiral duration every two segments
        spiralDuration += SPIRAL_INCREMENT;
      }
      
      // Alternate between moving forward and rotating
      if (currentSpiral % 2 == 0) {
        Serial.println("Action: Spiral search - moving forward");
        FORWARD(SEARCH_SPEED);
      } else {
        Serial.println("Action: Spiral search - rotating");
        ROTATE(SEARCH_SPEED);
      }
    }
  }
}

// Motor control functions
void BACKWARD(int Speed) {
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, HIGH);
  analogWrite(PWMA_PIN, Speed);

  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, HIGH);
  analogWrite(PWMB_PIN, Speed);
}

void FORWARD(int Speed) {
  digitalWrite(AIN1_PIN, HIGH);
  digitalWrite(AIN2_PIN, LOW);
  analogWrite(PWMA_PIN, Speed);

  digitalWrite(BIN1_PIN, HIGH);
  digitalWrite(BIN2_PIN, LOW);
  analogWrite(PWMB_PIN, Speed);
}

void ROTATE(int Speed) {
  digitalWrite(AIN1_PIN, HIGH);
  digitalWrite(AIN2_PIN, LOW);
  analogWrite(PWMA_PIN, Speed);

  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, HIGH);
  analogWrite(PWMB_PIN, Speed);
}

void Stop() {
  digitalWrite(AIN1_PIN, LOW);
  digitalWrite(AIN2_PIN, LOW);
  analogWrite(PWMA_PIN, 0);

  digitalWrite(BIN1_PIN, LOW);
  digitalWrite(BIN2_PIN, LOW);
  analogWrite(PWMB_PIN, 0);
}