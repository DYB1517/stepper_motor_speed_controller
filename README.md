# Stepper Motor Speed Controller

A stepper motor speed and direction controller based on Arduino Uno and an L298 motor driver. The project implements manual speed adjustment and rotation direction control using push buttons.

## Features

- **Variable speed control** — adjust motor speed by changing the delay between coil commutation steps.
- **Forward and reverse rotation** — change the motor rotation direction.
- **Push-button control** — speed adjustment and direction switching using two buttons.
- **Internal pull-up resistors** — button inputs are configured using `INPUT_PULLUP`.

## Hardware

| Component | Description |
|---|---|
| Arduino Uno | Main controller |
| L298 motor driver | Controls the stepper motor windings |
| Stepper motor | Bipolar stepper motor |
| 2 push buttons | Speed adjustment and direction control |

## How It Works

The motor is controlled through a sequence of coil commutation steps. The controller switches the driver outputs in a predefined order to rotate the stepper motor.

The rotation speed is controlled by changing the delay between successive commutation steps. A smaller delay increases the stepping frequency, while a larger delay decreases it.

Push buttons are used to adjust the motor speed and change the rotation direction. The button inputs use the Arduino's internal pull-up resistors, configured through `INPUT_PULLUP`.

## Repository Structure

```text
stepper_motor_speed_controller/
├── src/
│   └── stepper_motor_speed_controller.ino
├── docs/
│   ├── coursework.docx
│   └── presentation.pptx
└── .gitignore
```

## Source Code

The Arduino sketch is available in [`src/`](src/stepper_motor_speed_controller.ino).

## Documentation

The coursework report and presentation are available in [`docs/`](docs/).

## Technologies

- Arduino
- C++
- Arduino Uno
- L298 motor driver
- Stepper motor control
