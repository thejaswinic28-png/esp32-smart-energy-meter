# ESP32 Smart Energy Meter

ESP32-based smart energy monitoring system with LCD display and ThingSpeak cloud integration using Wokwi simulation.

---

# Project Overview

This project simulates a smart home energy monitoring system using ESP32, LCD display, and ThingSpeak cloud platform.

A potentiometer is used to simulate varying current consumption values. The ESP32 calculates power consumption and uploads real-time data to ThingSpeak for cloud monitoring and visualization.

---

# Features

- Real-time current monitoring
- Power consumption calculation
- LCD live display
- ThingSpeak cloud integration
- WiFi connectivity using ESP32
- Real-time serial monitoring
- Wokwi simulation support

---

# Components Used

| Component | Quantity |
|---|---|
| ESP32 Dev Module | 1 |
| LCD 16x2 I2C Display | 1 |
| Potentiometer | 1 |
| Jumper Wires | Few |

---

# Circuit Connections

## Potentiometer Connections

| Potentiometer Pin | ESP32 Pin |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SIG | GPIO34 |

---

## LCD I2C Connections

| LCD Pin | ESP32 Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

---

# Working Principle

1. Potentiometer simulates sensor current values.
2. ESP32 reads analog data from GPIO34.
3. Current value is calculated from ADC readings.
4. Power is calculated using:

```math
Power = Voltage × Current
```

5. LCD displays live current and power values.
6. ESP32 uploads data to ThingSpeak every 15 seconds.
7. ThingSpeak generates cloud graphs for monitoring.

---

# ThingSpeak Fields

| Field | Description |
|---|---|
| Field 1 | Current Consumption (A) |
| Field 2 | Power Consumption (W) |

---

# Libraries Used

- WiFi.h
- ThingSpeak.h
- Wire.h
- LiquidCrystal_I2C.h

---

# Wokwi Simulation

This project was fully simulated using Wokwi IoT Simulator.

---

# Simulation Images

## Circuit Diagram

![Circuit Diagram](Simulation%20images/Circuit%20Diagram.png)

---

## LCD and Simulation Output

![Simulation Output](Simulation%20images/Simulation%20Output.png)

---

## Potentiometer Testing

![Potentiometer Testing](Simulation%20images/Simulating%20the%20Circuit%20with%20different%20values.png)

---

## ThingSpeak Dashboard

![ThingSpeak Dashboard](Simulation%20images/thingspeak-dashboard-output.png)

---

# Serial Monitor Output

Example Output:

```text
Connecting to WiFi...
WiFi Connected!

Current: 5 A
Power: 1150 W

Upload Successful
```

---

# Applications

- Smart home energy monitoring
- IoT-based power management
- Energy consumption analytics
- Embedded systems learning
- Cloud-connected monitoring systems

---

# Future Improvements

- Real ACS712 current sensor integration
- Mobile app dashboard
- Blynk integration
- Overload protection system
- Energy billing calculation
- Relay-based appliance control

---

# Author

Thejaswini C

---

# GitHub Repository

ESP32 Smart Energy Meter using ESP32, LCD, ThingSpeak, and Wokwi simulation.
