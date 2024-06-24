# Autonomous-Robot-Car
The Picker 

Robot for Detecting and Removing Boxes from a Designated Area

The goal is to build a robot that can detect, pick up, and remove boxes from a 2m² area surrounded by black tape. The robot should use a combination of sensors and a camera to identify boxes, navigate the area, and efficiently remove the boxes one by one.

Key Components:
  -Microcontroller:
      -ESP32 Board: Acts as the main controller, handling navigation, sensor integration, and communication with the ESP32-CAM.
      -ESP32-CAM Module: Captures images and performs basic image processing to detect boxes.
 -Sensors:
     -IR Sensors: Mounted on the chassis to detect the black tape boundary.
     -Ultrasonic (UV) Sensor: Mounted on a servo motor to scan for boxes.
 -Actuators:
     -Servo Motor with Plates: Mechanism to lift and secure boxes using two plates controlled by a single servo motor.
 -Power Supply:
     -Li-Po Battery: Provides power to the microcontroller, sensors, and actuators. 
 -Communication:
     -WiFi: Used for communication between the ESP32-CAM and the ESP32 board for image processing.
 
     
 
      
    
