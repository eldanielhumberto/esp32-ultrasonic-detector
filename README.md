# ESP32 Ultrasonic Detector

This project uses an ESP32 microcontroller to detect motion and send a notification to a server.

## Features
- Real-time motion detection using ultrasonic distance measurement
- Wi-Fi connectivity for network communication
- Automated HTTP/REST signal transmission to a remote server


## Hardware Required

- ESP32 development board
- HC-SR04 ultrasonic sensor
- Jumper wires
- Breadboard (optional)

## Circuit Diagram

```
HC-SR04    ESP32
-----------------
VCC      -> VIN
GND      -> GND
TRIG     -> GPIO 5
ECHO     -> GPIO 18
```

## Installation

1. Clone this repository.
2. Open `esp32-ultrasonic-detector.ino` in Arduino IDE.
3. Select the correct ESP32 board and port.
4. Upload the code.