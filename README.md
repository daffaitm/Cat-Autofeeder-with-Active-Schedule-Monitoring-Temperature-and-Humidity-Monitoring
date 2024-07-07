# Cat-Autofeeder-with-Active-Schedule-Monitoring-Temperature-and-Humidity-Monitoring

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Components](#components)
4. [Wiring Diagram](#wiring-diagram)
5. [Installation](#installation)
6. [Usage](#usage)


## Introduction

This project aims to create an automatic cat feeder that can monitor the feeding schedule, cat activity, room temperature, and humidity. This device is designed to help pet owners manage their pets' feeding times and environment, especially when they are away from home.

## Features

- **Automatic Feeding**: Schedule feeding times via a keypad.
- **Activity Monitoring**: Detect cat movement using a PIR sensor.
- **Temperature and Humidity Monitoring**: Track the environmental conditions with a DHT11 sensor.
- **Real-Time Clock**: Keep accurate time with an RTC DS3231 module.
- **User Interface**: Display information on an LCD 16x2 screen.
- **Buzzer Alert**: Notify feeding times with an audible alert.

## Components

- Arduino Uno
- Keypad 4x4
- Servo Motor (Tower Pro SG90)
- PIR Sensor
- DHT11 Temperature and Humidity Sensor
- RTC DS3231 Real-Time Clock
- LCD 16x2 with I2C Module
- Buzzer
- Push Button
- Jumper Wires
- Breadboard

## Wiring Diagram

Refer to the `wiring_diagram.png` file in the repository for the complete wiring diagram of the project.

## Installation

1. **Install Arduino IDE**
   Download and install the Arduino IDE from [here](https://www.arduino.cc/en/Main/Software).

2. **Load the Code**
   Open the `cat_autofeeder.ino` file in the Arduino IDE and upload it to your Arduino Uno board.

3. **Library Installation**
   Ensure the following libraries are installed in the Arduino IDE:
   - `DS3231`
   - `Servo`
   - `LiquidCrystal_I2C`
   - `Keypad`
   - `DHT`

   You can install these libraries via the Arduino Library Manager. Go to **Sketch** > **Include Library** > **Manage Libraries...** and search for each library name to install.

4. **Wiring Setup**
   Connect the components as per the wiring diagram provided in the repository (`wiring_diagram.png`).

5. **Power Up the Device**
   Once the code is uploaded and the wiring is set up, power up the Arduino Uno using a USB cable or an external power source.

## Usage

1. **Power Up the Device**
   Connect the Arduino Uno to a power source.

2. **Set Feeding Schedule**
   Use the keypad to input the desired feeding times. The current time and date will be displayed on the LCD screen.

3. **Monitor Cat Activity**
   The PIR sensor will detect and log cat movements.

4. **Check Environmental Conditions**
   Temperature and humidity readings will be displayed on the LCD and logged for monitoring.


