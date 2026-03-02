# Wind Turbine Lab Model – DORBINE Project

This repository contains all 3D printable STL files, control scripts, and hardware documentation for the laboratory-scale wind turbine model used in the **DORBINE** project.

The repository includes:

- Original, unmodified STL files from the model creator
- Modified and newly designed STL files developed for our experimental setup
- Control and utility scripts used for turbine operation
- Bill of Materials (BOM) for the turbine hardware
 
<img src="https://github.com/marleo/WindTurbineModel/blob/main/windturbine.jpg" width="450">

---

# Attribution (CC BY-NC-SA 4.0)

This repository includes the original 3D model:

**"Wind Turbine Model 2.3 Meter height"**  
Created by **Julez**  

Source:  
https://makerworld.com/en/models/1091856-wind-turbine-model-2-3-meter-height

The original work is licensed under the  
**Creative Commons Attribution–NonCommercial–ShareAlike 4.0 International (CC BY-NC-SA 4.0)** license:  
https://creativecommons.org/licenses/by-nc-sa/4.0/

## Modifications

Changes made in this repository include:

- Structural modifications to the nacelle housing  
- Spinner redesign  
- Blade adjustments  
- Integration components for motor-driven laboratory operation  

All modifications are clearly separated in the `/modified` directory.

This repository is distributed under the same CC BY-NC-SA 4.0 license where applicable.

## Non-Commercial Use

This repository is intended for research and academic purposes only.  
No commercial use of the original or modified model is permitted under the CC BY-NC-SA 4.0 license.

---
# Repository Structure
 ```
├── original/
│   └── Unmodified STL files from the original creator
├── modified/
│   └── Modified or newly created STL files
├── scripts/
│   └── Monitoring script for RPM measurement
└── README.md
```

`original/` contains all STL files exactly as provided by the original model creator.  
No modifications have been made to these files.

`modified/` contains modified or newly designed components used for the laboratory setup, such as:

- Turbine housing
- Spinner
- Modified blades

`scripts/` contains software used to operate and monitor the turbine system, for example:

- Motor control
- RPM measurement
- Display control

---

# Bill of Materials (BOM)
| Item (from the original creator's BOM) | Quantity |
|------|--|
| Roller Bearing MR-18307-2RS 18x30x7 mm | 3 |
| Roller Bearing 608 2RS 8x22x7 mm | 1 |
| M8 nut | 2 |
| M8 bolt | 2 |

| Item |  Quantity | Description | Notes |
|------|--|------------|-----------|
| Greartisan Electric Reduction Motor | 1 | DC gear motor | Driving the Wind Turbine Model Rotor |
| AZDelivery Arduino Nano (CH340) | 1 | Microcontroller board | Central Controller |
| AZDelivery LJ12A3-4-Z Proximity Sensor | 1 | Inductive sensor | Measure Turbine Model RPM |
| AZDelivery I2C 1602 LCD (HD44780) | 1 | LCD display with I2C interface | Display Wind Turbine RPM |
| XTPower LiPo Battery Pack | 1 | 9-15V 2.1Ah battery | Power Delivery for Wind Turbine Model |
| RUNCCI-YUN Adjustable Reversible Controller | 1 | Speed controller with F/R switch | Allows for bidirectional rotation of the Wind Turbine Model |
| XL4015 DC-DC Buck Converter | 1 | 5A step-down regulator | Ensure the PD does not exceed 5V |
| Various Screws & Nuts | |

---

# Hardware Overview

The laboratory turbine setup includes:

- A **DC motor-driven rotor**
- A **microcontroller-based control system**
- Adjustable **speed control via potentiometer**
- **RPM monitoring displayed on an LCD screen**

This configuration enables controlled turbine rotation for laboratory experiments and testing.

---

# Purpose of Modifications

The original turbine model was adapted to support:

- Laboratory experiments under controlled conditions
- Integration of a stepper motor drive system
- Sensor mounting and RPM monitoring
- Structural reinforcement
- Compatibility with the **DORBINE wind turbine inspection system**

---

# License

Original model:  
**CC BY-NC-SA 4.0**

https://creativecommons.org/licenses/by-nc-sa/4.0/

Modified STL files are distributed under the same license where required.

Scripts may be distributed under a separate software license if specified.
