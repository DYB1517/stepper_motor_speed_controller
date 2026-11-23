# Stepper Motor Speed Controller

An Arduino-based stepper motor control system with manual speed adjustment and rotation direction switching. The project uses an Arduino Uno and an L298 motor driver.

## Features

- **Speed control** — adjust the motor speed by changing the delay between successive stepping operations.
- **Direction control** — reverse the motor rotation direction using two push buttons.
- **Manual control** — interact with the motor through physical buttons.
- **Four-step control sequence** — sequential switching of motor control signals.
- **Button input handling** — buttons configured using the Arduino internal pull-up resistors.

## Hardware

| Component | Description |
|---|---|
| Arduino Uno | Main controller |
| L298 motor driver | Motor driver module |
| NEMA 17 stepper motor | Controlled motor |
| Push buttons | Speed and direction control |

## How It Works

The Arduino controls the stepper motor by sending a sequence of signals to the L298 motor driver.

The rotation speed is adjusted by changing the `stepDelay` variable, which determines the time interval between successive steps. A smaller delay results in a higher stepping frequency, while a larger delay reduces it.

Two push buttons are used to adjust the speed. Pressing both buttons simultaneously changes the rotation direction.

The button inputs are configured using `INPUT_PULLUP`, and the program includes a time interval to control repeated button activation.

## Repository Structure

```text
stepper-motor-speed-controller/
├── src/
│   └── stepper_motor_speed_controller.ino
├── docs/
│   ├── coursework.docx
│   └── presentation.pptx
└── .gitignore
```

## Source Code

The main Arduino sketch is located in [`src/stepper_motor_speed_controller.ino`](src/stepper_motor_speed_controller.ino).

## Documentation

The original coursework documentation and presentation are available in the [`docs/`](docs/) directory.

## Technologies

- Arduino Uno
- C++
- Arduino IDE
- L298 motor driver
- Stepper motor control
