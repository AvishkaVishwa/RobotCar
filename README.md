

# 🤖 Sumo Robot – ESP32 Upgrade Edition

> ⚡ A major upgrade to my original Arduino-based Sumo Robot — now redesigned with an ESP32 DevKit, advanced dual motor drivers, ultrasonic + IR sensors, and a custom 2-layer PCB. Built for performance, precision, and reliability in competition environments.

---

## 🚀 What’s New in the ESP32 Upgrade?

| Previous Version (Arduino)             | 🚀 **This Version (ESP32)**                       |
|----------------------------------------|--------------------------------------------------|
| Arduino Uno                            | ESP32 DevKit (38-pin)                            |
| L298N Motor Driver                     | Dual TB6612FNG Motor Drivers                     |
| Breadboard wiring                      | Custom 2-layer PCB designed in KiCad             |
| 2 IR sensors + 1 ultrasonic            | 3 IR sensors + 2 ultrasonic sensors              |
| Arduino IDE                            | ESP-IDF + FreeRTOS (modular C code)              |
| No PWM speed control                   | Hardware PWM-based motor and servo control       |

---

## 🛠️ Hardware Overview

### 📍 ESP32 GPIO Pin Mapping

| Feature             | GPIOs                            | Description                      |
|---------------------|-----------------------------------|----------------------------------|
| **Motor Driver 1**  | AIN1: 13, AIN2: 14                | Left Motor Direction             |
|                     | BIN1: 12, BIN2: 27                |                                  |
|                     | PWMA: 26, PWMB: 25                | Left Motor Speed (PWM)           |
| **Motor Driver 2**  | AIN1: 33, AIN2: 32                | Right Motor Direction            |
|                     | BIN1: 19, BIN2: 18                |                                  |
|                     | PWMA: 23, PWMB: 22                | Right Motor Speed (PWM)          |
| **Motor Enable**    | STBY: 15                          | Must be HIGH to enable motors    |
| **IR Sensors**      | Left: 34, Center: 35, Right: 39   | Ring edge detection (input only) |
| **Ultrasonic 1**    | TRIG: 5, ECHO: 36                 | Front detection                  |
| **Ultrasonic 2**    | TRIG: 4, ECHO: 21                 | Side detection                   |
| **Servo Motors**    | SERVO1: 2, SERVO2: 17             | Optional PWM-controlled outputs  |

---

## 🖼️ PCB Design – Custom & Optimized

I designed a compact 2-layer PCB using **KiCad**, integrating:
- Dual TB6612FNG motor drivers
- LM2596 buck converter (12V → 5V)
- Decoupling capacitors and reverse polarity protection
- Labelled headers for sensors, servos, and motors

### PCB Gallery

#### 📘 Schematic View
![Schematic](/assets/pcb_schematic.png)

#### 📐 2D Top View
![Top Layout](/assets/pcb_layout_top.png)

#### 🧵 Routed View
![Tracks](/assets/pcb_layout_tracks.png)

#### 🧱 3D Render
![3D Render](/assets/pcb_3d_view.png)

---

## ⚙️ Software Architecture

Built with the **ESP-IDF framework** and **FreeRTOS**, the robot uses modular C code for sensor management and control logic.

### Main Features
- `motor_control.c` – Direction and PWM speed control for motors
- `sensor_module.c` – IR and ultrasonic sensor readings
- `servo_control.c` – Servo angle control
- `main.c` – Core behavior: search, push, evade

### Logic Flow
1. Wait 5 seconds after startup (Sumo rule)
2. Use ultrasonic sensors to detect opponent
3. Attack by charging forward
4. Avoid white line using IR sensors
5. Realign and retry

---

## 🔧 Setup Instructions

### 🔄 Clone & Flash
git clone https://github.com/AvishkaVishwa/Robot-Competetion-Sumo-Robot-method.git
cd robot-project
idf.py build
idf.py -p /dev/ttyUSB0 flash
idf.py monitor
````

### Requirements

* ESP32 DevKit (38-pin)
* ESP-IDF toolchain installed
* 12V battery (e.g., LiFePO4)
* Micro-USB cable

---

## 📸 Robot in Action

> ![Photo 1](/assets/photo_2024-12-13_21-54-50.jpg)
> ![Photo 2](/assets/photo_2024-12-13_21-54-52.jpg)

---

## 📚 What I Learned

This upgrade reflects my growth in:

* 📐 **PCB Design**: From breadboard to 2-layer custom PCB
* 🧠 **Embedded C Programming**: Using ESP-IDF, FreeRTOS, and modular architecture
* 🔌 **Hardware Interfaces**: Motor drivers, ultrasonic, and IR sensors
* ⚙️ **System Integration**: Reliable real-time robotic behavior

> 🔧 I’ve moved from prototyping with Arduino to building robust systems using professional tools.

---

## 🕹️ Original Arduino Version

Want to see where it started?
Check out the [original Arduino-based version](https://github.com/AvishkaVishwa/Robot-Competetion-Sumo-Robot-method).

---

## 🤝 Contributions & Ideas

Suggestions and contributions are welcome! Possible future improvements:

* PID-based motor speed control
* AI strategy for adaptive behavior
* Bluetooth remote override
* OLED display for debug/status

---


```

