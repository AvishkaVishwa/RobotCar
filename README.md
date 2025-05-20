Thanks! Based on your upgrade from Arduino to **ESP32 with a custom PCB**, here’s a **revised and modernized `README.md`** for your updated **Sumo Robot project**, reflecting the current ESP32-based design, hardware improvements, and professional formatting:

---

````markdown
# 🔥 Sumo Robot – ESP32 Upgrade Version

This project is the upgraded version of the original Sumo Robot built for competition purposes. The robot now uses an **ESP32 DevKit (38-pin)** with custom PCB, enhanced motor driver support, and refined obstacle detection and edge avoidance capabilities using ultrasonic and IR sensors.

---

## 🧠 Key Features
- Dual-motor differential drive using **TB6612FNG motor drivers**
- **IR sensors** for ring edge (white line) detection
- **Ultrasonic sensors** for opponent detection
- **PWM-based servo motor support**
- Compact and modular **PCB designed in KiCAD**
- Controlled by an **ESP32 DevKit**, programmed using **ESP-IDF**

---

## 🔌 Hardware Setup

### 🔲 ESP32 DevKit Pin Assignments (New PCB)

| Component           | GPIO Pin | Description                |
|---------------------|----------|----------------------------|
| STBY (Shared)       | 15       | Motor driver enable (HIGH) |
| Motor1 AIN1/AIN2    | 13 / 14  | Left motor direction       |
| Motor1 BIN1/BIN2    | 12 / 27  | Left motor direction       |
| Motor1 PWMA/PWMB    | 26 / 25  | Left motor speed (PWM)     |
| Motor2 AIN1/AIN2    | 33 / 32  | Right motor direction      |
| Motor2 BIN1/BIN2    | 19 / 18  | Right motor direction      |
| Motor2 PWMA/PWMB    | 23 / 22  | Right motor speed (PWM)    |
| IR Sensors (L/C/R)  | 34 / 35 / 39 | Edge detection (Input only) |
| Ultrasonic 1        | TRIG: 5 / ECHO: 36 | Front sensor     |
| Ultrasonic 2        | TRIG: 4 / ECHO: 21 | Side sensor       |
| Servo 1 / Servo 2   | 2 / 17   | PWM output for actuators   |

---

## 🧩 PCB Design Overview

- Designed using **KiCAD**
- Contains LM2596-5.0 buck converter for **12V → 5V power supply**
- Includes reverse polarity protection, indicator LEDs, decoupling caps
- Labeled headers for **Motor drivers**, **Sensors**, and **Servos**
- Optimized 2-layer layout with **ground plane** and **short traces**

---

## ⚙️ Software Stack

### 🛠 Development Environment
- **ESP-IDF** (official framework)
- FreeRTOS-based task scheduling
- C code with modular structure for motors, sensors, and logic

### 🧪 Features in Code
- **`motor_init()`**: Initializes motor driver GPIOs
- **`pwm_init()`**: Configures PWM for motors and servos
- **`measure_distance()`**: Ultrasonic distance measurement
- **`app_main()`**: Core logic loop for movement, obstacle detection, edge avoidance

---

## 🚀 Getting Started

### ✅ Prerequisites
- ESP-IDF setup on your machine
- USB cable for ESP32 DevKit
- Flashing tool: `idf.py`

### 🔧 Setup Steps
1. Clone this repo:
   ```bash
   git clone https://github.com/AvishkaVishwa/Robot-Competetion-Sumo-Robot-method.git
````

2. Open the project in ESP-IDF.
3. Build & flash:

   ```bash
   idf.py build
   idf.py -p /dev/ttyUSB0 flash
   ```

---

## 🎮 Usage

1. Power the robot via 12V supply.
2. Upon boot, robot waits 5 seconds (per Sumo rules).
3. Begins spiral search pattern using ultrasonic sensors.
4. Pushes opponent when detected.
5. Backs off and realigns if a white line is detected via IR sensors.

---

## 📸 Images

> ![PCB Front View](/assets/photo_2024-12-13_21-54-50.jpg)
> ![PCB Top View](/assets/photo_2024-12-13_21-54-52.jpg)

---

## 🤝 Contribution

Feel free to fork this repository and submit pull requests for:

* Performance optimizations
* Additional sensor integration
* AI-based strategy logic

---

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.

```

---

Would you like me to push this updated `README.md` to your GitHub repo or help create an **assets folder** with updated schematic/3D model renders for showcasing the new PCB?
```
