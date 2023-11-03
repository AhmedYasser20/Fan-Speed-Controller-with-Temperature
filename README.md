# Temperature-Controlled Fan Controller
<div style="text-align:center">
<img src="https://github.com/AhmedYasser20/Fan-Speed-Controller-with-Temperature/assets/93765400/cf08154a-c28c-4899-b8fe-ef6f7855aa7c" alt="Designer" width="300">
</div>


## Table of Contents

- [About the Project](#about-the-project)
  - [System Requirements](#system-requirements)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Drivers](#drivers)

## About the Project

This project is a Temperature-Controlled Fan Controller implemented with an ATmega32 microcontroller. It automatically turns a fan on or off based on the temperature readings from an LM35 temperature sensor. The fan's speed is controlled according to the temperature, and the temperature is displayed on an LCD.

### System Requirements

The project has the following specifications:

1. The microcontroller used is ATmega32 running at 1 MHz.
2. The LM35 temperature sensor provides continuous analog output, which is converted to digital values using the ADC.
3. Temperature calculations are performed by the microcontroller.
4. The temperature is displayed on an LCD.
5. The fan operates based on temperature values:
   - Below 30°C, the fan is turned off.
   - 30-59°C, the fan operates at 25% of its maximum speed.
   - 60-89°C, the fan operates at 50% of its maximum speed.
   - 90-119°C, the fan operates at 75% of its maximum speed.
   - 120°C and above, the fan operates at 100% of its maximum speed.
6. The project follows a layered architecture model.
7. The DC motor's speed is controlled using PWM signals from Timer0.

## Getting Started

### Prerequisites

- You will need an ATmega32 microcontroller, an LM35 temperature sensor, an LCD, and a DC motor for hardware setup.
- You need an AVR development environment such as Atmel Studio or avr-gcc.
- Ensure you have the necessary drivers and libraries for your hardware components.

### Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/AhmedYasser20/Fan-Speed-Controller-with-Temperature
   ```

2. Configure the project in your AVR development environment.

3. Upload the code to your ATmega32 microcontroller.

## Usage

- Connect the LM35 temperature sensor, LCD, and DC motor to the microcontroller as specified in the requirements.
- Power up the system and observe the fan's behavior based on the temperature.
- The LCD will continuously display the current temperature and fan state.

## Project Structure
![image](https://github.com/AhmedYasser20/Fan-Speed-Controller-with-Temperature/assets/93765400/bdd92b59-4c49-461f-84b1-53caadfab15b)

- `main.c`: The main program that controls the temperature-controlled fan.
- `drivers/`: Directory containing various drivers for ADC, GPIO, LCD, Temperature Sensor, and DC Motor.
- `drivers/adc.h`: The ADC driver.
- `drivers/gpio.h`: The GPIO driver.
- `drivers/lcd.h`: The LCD driver.
- `drivers/lm35_sensor.h`: The LM35 temperature sensor driver.
- `drivers/dc_motor.h`: The DC motor driver.
- `drivers/pwm.h`: The PWM driver for Timer0.

## Screen Shot

![image](https://github.com/AhmedYasser20/Fan-Speed-Controller-with-Temperature/assets/93765400/5f13eb8d-a680-4fdb-80ab-628755a1cf1c)


