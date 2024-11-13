# Índice

- 1.[ Introduction](#introducción)
    -
- 2.[ Components](#components)
    -
    - [Materials List](#materials-list)
    - [Arduino mega](#arduino-mega)
    - [Servo motor MG90S](#servo-motor-mg90s)
    - [Puente H (L293D)](#puente-h-l293d)
    - [Pixy2 cam](#pixy2-cam)
    - [Distance sensor (ToF) VL53L0X)](#distance-sensor-tof-vl53l0x)
    - [Ultrasonic sensor (HC-S04)](#ultrasonic-sensor-hc-s04)
    - [Battery and charger](#battery-and-charger)
    - [Motor GA37-520](#motor-ga37-520)
    - [LM2596 HW-411 Step down](#lm2596-hw-411-step-down.)
  

- 3.[ Floors of the robot](#pisos-del-robot)
    -
    - [Floors 1 and 2](#piso-1-y-2)
        - [Front axel](#tren-delantero)
        - [Back axel](#tren-trasero)

    - [Floor 3]()
        
- 4.[ 3D desing](models/README.md#3d-desing)
    -
    - [Parts list](models/README.md#parts-list)
    - [Printing settings and recommendations](models/README.md#printing-settings-and-recommendations)
    - [STL files](models/stl/)
    - [Files ready to print](models/ready%20to%20print/)

- 5.[ Circuit diagram](schemes/README.md#circuit-diagram)<!--[Carpeta de Fuentes](../) asi se puede hacer un enlace con una carpeta -->
    -

- 6.[ Codes](src/)
    -
    - [Open challenge](src/Open%20challenge.ino)
    - [Close challenge](src/Close%challenge.ino)

- 7.[Flowcharts](src/README.md#flowcharts)
    -
    - [Open challenge](src/README.md#open-challenge)
    - [Close challenge](src/README.md#close-challenge)
    
- 8.[Vehicle photos](v-photos/)

<!---------------------------------------------espanol-------------------------------------------------------- -->

# Introduction 

# Components

## Materials List

| **Pieces**                              | **Quantity** |
|-----------------------------------------|--------------|
| Arduino Mega                            | 1            |
| Pixy2 Cam                               | 1            |
| Ultrasonic Sensor (HC-SR04)             | 2            |
| LM7805                                  | 1            |
| Bridge H L298D                          | 1            |
| Pull-up Button                          | 1            |
| Motor GA37-520 of 320rpm                | 1            |
| Puente H (L298N)                        | 1            |
| Servo Motor MG90S                       | 1            |
| NI-MH Battery 12V 3000mAh               | 1            |
| Condensator 10μF 50V                    | 1            |
| LM2596 HW-411 Step Down                 | 1            |
| Ceramic Capacitor 10nF (104) 50V        | 2            |
| Switch button                           | 1            |

## Arduino mega

[![A000067-00-front-934x700.jpg](https://i.postimg.cc/Tw4CcFkv/A000067-00-front-934x700.jpg)](https://postimg.cc/2bnQkcR0)

| | | | |
| --- | --- | --- | --- |
| **Microcontroller** | ATmega2560 | **Operating Voltage**    | 5V       |
| **Input Voltage**   | 7-12V      | **Digital I/O Pins**     | 54 (15 provide PWM output)    |
| **Analog Input Pins**   | 16     | **Flash Memory**         | 256 KB            |
| **SRAM**                | 8 KB   | **EEPROM**               | 4 KB              |

A unique controller, the Arduino Mega, was chosen to
manage all the robot`s functions. This model is distinguished
by its great prosecution capability inside the Arduino family,
letting it sort out complete code and manage a wide range of
components thanks to its large quantity of digital pins,
analogic, and PWM.

## Servo motor MG90S
[![mg90s-micro-servomotor-kompatibel-mit-arduino-154289-2.png](https://i.postimg.cc/LsdqjTkQ/mg90s-micro-servomotor-kompatibel-mit-arduino-154289-2.png)](https://postimg.cc/4Y5NgpSp) [![1-2-4-5-10-20pcs-MG90-S-Micro-Servo-Motor-Metal-Gear-Analog-RC-Servomotor-180-jpg.jpg](https://i.postimg.cc/05tbVxdw/1-2-4-5-10-20pcs-MG90-S-Micro-Servo-Motor-Metal-Gear-Analog-RC-Servomotor-180-jpg.jpg)](https://postimg.cc/SjMSKBPS)

| | | | |
| --- | --- | --- | --- |
| **Weight**    | 13.4g  | **Operating speed**  | 0.1 s/60 degree, 0.08 s/60 degree (6V) 
| **Dimension** | 22.5 x 12 x 35.5 mm        | **Operating voltage**| 4.8 V - 6.0 V    |
| **Stall torque**  | 1.8 kgf·cm (4.8V), 2.2 kgf·cm (6V) | **Dead band width**   | 5 μs |

It uses the servomotor MG90S in the turn system to get
precise turns. This model is smaller, lighter, and offers higher
torque than the SG90, which allows it to move the wheels with
the necessary strength for shunting, mainly in obstacle
evasion.

## Puente H (L293D)

## Pixy2 cam
[![pixy-v21-camera-sensor.jpg](https://i.postimg.cc/N04gL7dH/pixy-v21-camera-sensor.jpg)](https://postimg.cc/Jysw2JVr)

| | | | |
| --- | --- | --- | --- |
| **Procesador**                  | NXP LPC4330, 204 MHz, dual core | **Imagen sensor**              | Aptina MT9M114, 1296×976       |
| **Field of view horizontaL**        | 60°                          | **Field of view vertical**            | 40°                             |
| **Operating current**                     | 140 mA                       | **Operating voltage**                  | USB (5V) o 6V a 10V            |
| **RAM**                         | 264Kb                        | **Flash**                         | 2Mb                             |
| **Buses**                       | UART serial, SPI, I2C, USB, digital, analog | **Light**               | 20 lumens approx                |

The camera is capable of detecting seven colors
simultaneously. It is equipped with an internal processor,
which lets us explore just the necessary information for the
Arduino or other controllers due to the variety of connections
that allow it. Moreover, it counts with an obturation speed of

60 fps, an excellent gap, and white adjustable LED lights;
thus, the continuous movement and the lower light don’t
represent a huge problem.

## Distance sensor (ToF) VL53L0X
[![vl53l0x.png](https://i.postimg.cc/C1gmrb0m/vl53l0x.png)](https://postimg.cc/jWMHLwL7) [![vl53l0x-1.png](https://i.postimg.cc/Tw3WPPJT/vl53l0x-1.png)](https://postimg.cc/JySh6MFF)

| | | | |
| --- | --- | --- | --- |
|**Operating voltagen**| 3V - 5V DC| **Operating current**| 10mA (40mA máx)|
| **Range**     | 50mm a 1200m   | **Precision**   | ±30mm    |
| **Interface**   | I2C 400kHz       |       |                      |

It uses the VL53L0X distance laser sensor, which is based
on flight time (ToF), and employs an infrared laser to measure
distances with a higher precision. This sensor lets the robot
have a better understanding of its position and allows the
ability to park at the end of the third turning in the game field
by its potential to detect distances at millimeters.

## Ultrasonic sensor (HC-S04)
[![Medidas-de-sensor-ultrasonido-HC-SR04.jpg](https://i.postimg.cc/mgdP54Gq/Medidas-de-sensor-ultrasonido-HC-SR04.jpg)](https://postimg.cc/FYLFY2zg)

| | | | |
| --- | --- | --- | --- |
| **Operating voltage** | 5 V  | **Operating current** | 15mA     |
| **Minimum range**     | 2cm  | **Max. distance**  | 4m   |
| **Measuring angle**   | 15°  | **Output Echo signal**  | 40Hz     |
| **Input Trigger signal**  | Input 10μs TTL | **Pulso Echo** | Output 100-25000 μs TTL |

The ultrasonic sensors are essential in our robot because
let calculate distances by using ultrasonic vibes. These
sensors own a transmitter that sends the vibe and a receiver
to detect the echo of the reflexive vibes which lets us
determine the distance by the time it takes to come back with
a maximum detection of 4 meters, these sensors are ideal for
the game field size, which measures 3m x 3m. thanks to
them, the robot has a higher perception of its position and
anticipate possible coalitions effectively.

## Battery and charger
[![REV-31-1302-12-VSlim-Battery-New-FINAL-87390.jpg](https://i.postimg.cc/L80sVVtF/REV-31-1302-12-VSlim-Battery-New-FINAL-87390.jpg)](https://postimg.cc/pmzxWzcs) [![AA-Ni-Mh-Battery-Charger-noflag-08282.jpg](https://i.postimg.cc/CMHL20GN/AA-Ni-Mh-Battery-Charger-noflag-08282.jpg)](https://postimg.cc/qgqTt9Zh)

| | | | |
| --- | --- | --- | --- |
| **Voltage**  | 12V  | **Capacity**           | 3000mAh  |
| **Weight**   | 567g | **Connector**          | XT30         |
| **Replaceable Fuse** | 20A ATM |             |              |

After an extensive period of using NI-MH Batteries, we
have chosen a 12V battery and 3000 mAh Rev Robotics. This
new battery offers significant advantages.

Firstly, it gives better autonomy, letting the robot work
through longer periods without the charging need. Its 12
voltages are enough to completely provide the energetic
needs of the robot, ensuring a favorable performance.

In addition, the battery includes a versatile charger with
two charging modes; a lower one (0.9 A) and a faster one (1.8
A), allowing flexibility in the time charging. Also, it is allowed
on international trips by airplane because it is made with
nickel which is safe for its transport.

Lastly, it is a prefabricated battery and offers a superior
level of security and efficiency compared to the settings of
individual batteries.

## Motor GA37-520
[![51-J-66l-USg-L.jpg](https://i.postimg.cc/dV0214sb/51-J-66l-USg-L.jpg)](https://postimg.cc/xcWJpGb5) 

| | | | |
| --- | --- | --- | --- |
| **Nominal voltage**  | 12V | **Rated power** | 8,3W    |
| **Rated current**| 1,5A | **Reduction**    | 18.8:1  |
| **No-load speed** | 320rpm | **Rated speed**| 224rpm  |
| **No-load current** | ≥120mA | **Rated current**  | ≥400mA |
| **Rated torque** | 3.1Kg.cm  | **Par nominal**  | 0.67Kg.cm    |

From a robotic kit, we have obtained two motors. Each one
to 12V, they are capable of going at a nominal speed of
250rpm and a 3,5 kg torque. Therefore using just a 12V motor
is enough to give it the speed, control, and attraction needed,
as well as greater management thanks to its encoder which
lets us have better precision in the turns that the robot should
do in the game field.

## LM2596 HW-411 Step down
[![XL6009-Module-Pinout.jpg](https://i.postimg.cc/Vv6fMrJk/XL6009-Module-Pinout.jpg)](https://postimg.cc/LYcFFskc)

| | | | |
| --- | --- | --- | --- |
| **Input**                   | 4.5-40VDC                   | **Output**                   | 1.5-35VDC                     |
| **Rated Current**           | 2A (Surge 3A)               | **Regulation**               | 0.5%                          |

To protect the robot`s electronic components from
possible damages caused by higher voltages that are not
required, for this, we have incorporated a voltage regulator in
our system. This device assures a constant and stable energy
supply, which prevents failures in the components, and also
increases the stability and movement of the robot in its
performance.

# Floors of the robot