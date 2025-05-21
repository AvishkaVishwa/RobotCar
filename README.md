
````markdown
# 🤖 Sumo Robot – **ESP32 Upgrade Edition** 🚀

> ✅ A major redesign and performance upgrade of my original Arduino-based sumo robot project – now rebuilt with a powerful **ESP32 DevKit**, precision motor drivers, ultrasonic sensing, and a fully custom-designed PCB.

---

## 🛠 What's New in This Upgrade?

| Original Setup (Arduino)              | 🚀 **Upgraded Setup (ESP32)**                        |
|--------------------------------------|-----------------------------------------------------|
| Arduino Uno                          | ESP32 DevKitC (38-pin) with WiFi, Dual Core         |
| Breadboard + jumper wires            | Professionally designed 2-layer custom PCB          |
| Single motor driver (L298N)          | Dual **TB6612FNG** drivers with PWM speed control   |
| Basic IR and ultrasonic sensing      | Enhanced sensor layout with IR ×3, ultrasonic ×2    |
| Arduino IDE                          | **ESP-IDF** with FreeRTOS and structured modules    |
| Manual tuning                        | Modular C code with PID-ready motor control         |

🎯 This project demonstrates a full transition from rapid prototyping to a **professional-grade, embedded robotics platform**.

---

## 🔧 Hardware Architecture

### 💡 Pinout (ESP32 GPIO Mapping)

| Feature                | GPIO Pins       | Description                      |
|------------------------|------------------|----------------------------------|
| **Motor Driver 1**     | AIN1: 13, AIN2: 14<br>BIN1: 12, BIN2: 27<br>PWMA: 26, PWMB: 25 | Left motor control |
| **Motor Driver 2**     | AIN1: 33, AIN2: 32<br>BIN1: 19, BIN2: 18<br>PWMA: 23, PWMB: 22 | Right motor control |
| **STBY Pin**           | 15               | Motor enable (HIGH to activate) |
| **IR Sensors**         | 34, 35, 39       | Left, Center, Right line sensors |
| **Ultrasonic Sensors** | TRIG1: 5, ECHO1: 36<br>TRIG2: 4, ECHO2: 21 | Front + Side sensors |
| **Servo Motors**       | PWM1: 2, PWM2: 17 | For future expansions or arms    |

---

## 📐 Custom PCB Design (KiCad)

Upgraded from a breadboard mess to a **compact, production-ready PCB** design!

### 🖼️ PCB Gallery

| Schematic | 2D Layout | Traces | 3D View |
|----------|-----------|--------|---------|
| ![](/assets/pcb_schematic.png) | ![](/assets/pcb_layout_top.png) | ![](/assets/pcb_layout_tracks.png) | ![](/assets/pcb_3d_view.png) |

🧠 The board integrates:
- LM2596 buck converter for 12V→5V power supply
- Flyback protection, pull-ups, and boot-safe GPIO handling
- Clean silkscreen for motors, sensors, servos, and ESP32 pins

---

## ⚙ Software Architecture

Rebuilt from scratch using **ESP-IDF** with real-time multitasking.

### Features:
- `motor_control.c`: PWM-based speed/direction control for each wheel
- `sensor_module.c`: Accurate ultrasonic and IR data reading
- `servo_control.c`: Independent PWM channels for future mechanisms
- `main.c`: Core decision loop – attack, avoid, rotate, reset

### Task Flow:
1. Wait 5s at start (sumo rule)
2. Spiral scan for opponent
3. Charge if detected
4. Reverse/rotate on IR line detection
5. Loop back to search

---

## 📦 Setup Instructions

### Prerequisites
- ESP-IDF environment installed
- ESP32 DevKit (38-pin)
- 12V LiFePO4 battery or regulated supply

### Flash the Firmware:
```bash
git clone https://github.com/AvishkaVishwa/Robot-Competetion-Sumo-Robot-method.git
cd robot-project
idf.py build
idf.py -p /dev/ttyUSB0 flash
idf.py monitor
````

---

## 🧠 Learning Outcome

This project reflects my transition from beginner-level prototyping to professional embedded systems engineering:

### 💼 Skills Demonstrated:

* Custom **KiCad PCB Design**
* Hardware interfacing with **TB6612FNG**, **IR**, and **Ultrasonic sensors**
* Real-time firmware in **C with ESP-IDF + FreeRTOS**
* GPIO boot configuration for **ESP32 stability**
* Full-stack integration from **electronics to software**

---

## 🔁 Legacy Reference

Want to see where it started?

👉 [Original Arduino-based Sumo Robot](https://github.com/AvishkaVishwa/Robot-Competetion-Sumo-Robot-method)

---

## 📸 Real Robot Preview

> ![](/assets/photo_2024-12-13_21-54-50.jpg)
> ![](/assets/photo_2024-12-13_21-54-52.jpg)

---

## 🤝 Contributions

Feel free to fork, adapt, or expand the logic for:

* PID motion control
* AI-based opponent prediction
* Bluetooth or remote-controlled override

---

## 📜 License
