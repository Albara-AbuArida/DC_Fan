# DC Fan 3-Speed Controller (Arduino + L298N)

A small Arduino-based controller that sets a DC fan to three selectable speeds. The current speed (1, 2, 3) is shown on a common-cathode 7-segment display. Demo video included.

## Features
- 3 discrete speeds via PWM (speed 1 / 2 / 3)  
- Current speed displayed on a common-cathode 7-segment display  
- Uses L298N H-bridge to drive the DC fan (motor powered from external adapter)  
- Source code: `test_file.ino` (Arduino)

## Parts / Bill of Materials
- Arduino Uno Rev3  
- L298N H-bridge driver module  
- DC motor (toy 140) 3V-6V  
- Common-cathode 7-segment display  
- Resistors:
  - 10 KΩ for pull down resistors
  - 10 KΩ for 7-segemnt display
- Pushbuttons for speed selection  
- Power adapter for motor 9V/2A  
- Jumper wires, breadboard

## Wiring & Notes
- L298N supply (12V) → external adapter positive.  
- L298N negative (GND) → external adapter GND. Arduino GND must be connected to L298N GND.  
- L298N inputs (IN1, IN2, ENA) → Arduino digital/PWM pins (pin mapping below).  
- 7-segment (common cathode) → cathodes to GND; each segment pin → Arduino digital pin through a resistor.  
- buttons: connect to digital pins with pull-down resistors.

- `Arduino D2`  → off button  
- `Arduino D3`  → speed 1  
- `Arduino D4`  → speed 2  
- `Arduino D5`  → speed 3  
- `Arduino D6`  → 7-segment segment A  
- `Arduino D7`  → 7-segment segment B
- `Arduino D8`  → 7-segment segment C
- `Arduino D10` → 7-segment segment D
- `Arduino D11` → 7-segment segment E
- `Arduino D12` → 7-segment segment F
- `Arduino D13` → 7-segment segment g
- `Arduino D14 (A1)` → L298N IN1
- `Arduino D15 (A0)` → L298N IN2
- `Arduino D9`  → L298N ENA


## Software
- File: `test_file.ino` — Arduino sketch implementing PWM speed control and 7-segment display mapping.  
- No external libraries required.  
- Arduino IDE recommended version: 2.3.4

## How to run
1. Connect motor power to L298N (12V) (external adapter) and ground common with Arduino.  
2. Upload `test_file.ino` to the Arduino.  
3. Power the motor supply.  
4. Use the button to choose speed 1 / 2 / 3. 7-segment displays the active speed.  
5. See demo video: https://drive.google.com/file/d/1oa7phfurA_jUcReGZnMe5DiJC0Q40k1c/view?usp=drive_link

## Demo
- Demo video (17 s): https://drive.google.com/file/d/1oa7phfurA_jUcReGZnMe5DiJC0Q40k1c/view?usp=drive_link

## Troubleshooting
- Motor doesn't spin: check motor adapter voltage and that L298N (12V) is powered. Confirm common ground with Arduino. Verify PWM pin is enabled/active.  
- 7-segment too dim or not lighting: if segment resistors are 10 kΩ, replace them with ~220 Ω. Confirm common-cathode is connected to GND and segment mapping in code matches wiring.  
- L298N overheats: ensure motor current is within L298N limits (2A); add heatsink (if does not exist); consider a MOSFET-based driver for better efficiency.  
- Buttons not responding: verify pull-down wiring and read button state via `Serial.println()` for debugging.

## Next steps / Improvements
- Add soft-start / ramping between speeds to reduce inrush current.  
- Add RPM sensing (tachometer) and closed-loop speed control.  
- Replace L298N with a MOSFET driver for better efficiency if motor current is high.  
- Enclose circuit and add fuses for safety.

## License
MIT — see `LICENSE` file.

## Contact
Author: Albara' AbuArida — abuaridaalbalbara@gamil.com
Repository: [link to GitHub]
