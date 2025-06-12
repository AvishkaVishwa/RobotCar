# 🤖 Sumo Robot – ESP32 Upgrade Edition

> ⚡ A complete redesign and performance upgrade of my original ESP32-based 2-wheel robot — now featuring 4-wheel differential drive, dual motor drivers, enhanced sensing, and a **custom-designed 2-layer PCB** for clean, robust competition performance.

---
## 🏅 Awards & Achievements

> 🥈 **2nd Place – University Robotics Competition**  
> My previous 2-wheel ESP32-based robot won **2nd place** in a university competition.  
> 🎯 **Challenge Objective:** Remove the maximum number of boxes from a designated area as fast as possible.  
> 💡 The robot autonomously navigated, detected, and pushed objects while avoiding boundaries.  
>
> This new 4-wheel version builds on that success with:
> - A custom PCB for higher stability and motor control
> - Dual-mode (Autonomous + BLE Manual) operation
> - Improved PD-based line tracking and obstacle avoidance
> - Real-time scanning with servo-driven sensors


## 🔄 Evolution of the Project

| Original Prototype                    | 🚀 **Upgraded Version**                             |
|--------------------------------------|----------------------------------------------------|
| ESP32 on protoboard                  | ESP32 DevKit (38-pin) on custom 2-layer PCB        |
| 2-wheel drive with single TB6612FNG  | 4-wheel drive using dual TB6612FNG drivers         |
| Breadboard wiring                    | Professionally routed and labeled PCB in KiCad     |
| 1 ultrasonic + 2 IR sensors          | 2 ultrasonic + 3 IR sensors                        |
| Basic C firmware                     | Modular, RTOS-based firmware with **ESP-IDF**      |

### 🔧 The Current design 

| Old Design |
|------------|
 ![](/assets/photo_2024-12-13_21-54-50.jpg)
 ![](/assets/photo_2024-12-13_21-54-39.jpg)  

---

## ⚙ Hardware Overview

### 📍 ESP32 GPIO Mapping

| Feature             | GPIOs                            | Description                      |
|---------------------|-----------------------------------|----------------------------------|
| **Motor Driver 1**  | AIN1: 13, AIN2: 14                | Left Front Motor Direction       |
|                     | BIN1: 12, BIN2: 27                | Left Rear Motor Direction        |
|                     | PWMA: 26, PWMB: 25                | Speed Control (PWM)              |
| **Motor Driver 2**  | AIN1: 33, AIN2: 32                | Right Front Motor Direction      |
|                     | BIN1: 19, BIN2: 18                | Right Rear Motor Direction       |
|                     | PWMA: 23, PWMB: 22                | Speed Control (PWM)              |
| **STBY Pin**        | 15                                | Keep HIGH to enable motors       |
| **IR Sensors**      | 34, 35, 39                        | Left, Center, Right (input only) |
| **Ultrasonic**      | TRIG1: 5, ECHO1: 36               | Front sensor                     |
|                     | TRIG2: 4, ECHO2: 21               | Side sensor                      |
| **Servos**          | SERVO1: 2, SERVO2: 17             | Optional (PWM outputs)           |

---

## 📐 PCB Design (KiCad)

This upgrade features a fully custom 2-layer PCB:
- Dual motor driver breakout with decoupling capacitors
- LM2596 buck converter (12V to 5V)
- Pull-up/pull-down resistors for boot-safe ESP32 pins
- Clear silk labels for servo, IR, ultrasonic, and power pins

### PCB Gallery

#### 📘 Schematic View
![Schematic](/assets/1.JPG)

#### 🧵 Routed View
![Tracks](/assets/2.JPG)
![Tracks](/assets/3.JPG)

#### 📐 2D Top View
![Top Layout](/assets/4.JPG)

#### 🧱 3D Render
![3D View](/assets/esp32%20master.png)

---

## ⚙ Software Architecture

Built using **ESP-IDF + FreeRTOS**, the firmware is modular and real-time.

| Module           | Function                                      |
|------------------|-----------------------------------------------|
|    `main.c`      | Set motor direction and PWM speed             |
|                  | Read ultrasonic and IR sensor values          |
|                  | Control servo angles (expandable feature)     |
|                  | Main loop with attack, avoid, search routines |

---

## 🔧 Setup & Flashing

### Prerequisites
- ESP-IDF environment
- ESP32 DevKit (38-pin)
- 12V battery + USB cable

### Flash Instructions

git clone https://github.com/AvishkaVishwa/RobotCar.git
cd robot-project
idf.py build
idf.py -p /dev/ttyUSB0 flash
idf.py monitor

---

## 📹 Videos & Demos

> 🎥 Want to see it in action?
> I’ve recorded videos of both the prototype and the upgraded robot performing edge detection, object pushing, and spiral search.

📌  <video src ="https://github.com/user-attachments/assets/8567fc42-a18b-4fbb-b69a-60d1c5493e56"></video>


📌 Here Is a test of the car with New PCB, I m still doing some modifications to this....😁 here i'm controlling the car with bluetooth using the mobile phone.
    <video src ="https://github.com/user-attachments/assets/c9dc8e6a-7c8a-46cb-9330-15c2b81f15a4"></video>
---

## 📚 What This Project Shows

* Embedded firmware development with **ESP-IDF**
* **Custom PCB design** (routing, power, protection, labeling)
* Real-time autonomous behavior
* Motor control using **PWM & H-bridges**
* Sensor fusion: ultrasonic + IR edge detection
* Full-stack development from electronics to software

---

## 🤝 Contributions Welcome

Feel free to fork or suggest ideas such as:

* PID control integration
* Remote control override via WiFi
* OLED display for system status

---
---
<img src ="assets\photo_2025-06-12_20-35-14.jpg">

## 🎉 Special Thanks to PCBWay

<p align="center">
  <a href="https://www.pcbway.com/" target="_blank">
    <img src="https://github.com/AvishkaVishwa/12V-DC-Motor-Speed-Controller-PCB-Design-using-KiCAD/blob/0191b6e02eeb30e176867d2a93ebec854536829a/Images/pcbwaylogo.jpg" alt="PCBWay" width="200"/>
  </a>
</p>

I would like to give a huge shoutout and sincere thanks to **[PCBWay](https://www.pcbway.com/)** for sponsoring the PCB fabrication of this project!

The **build quality, silkscreen clarity, via precision, and copper finish** exceeded expectations. PCBWay’s service was fast, professional, and extremely helpful throughout the production process.

This project wouldn’t have been possible without their generous support. If you’re looking to manufacture professional-grade PCBs at an affordable price, I highly recommend checking them out.

🔗 [Visit PCBWay →](https://www.pcbway.com/)

---