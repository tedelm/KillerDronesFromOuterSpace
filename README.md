# KillerDronesFromOuterSpace
</br>
Have you ever wanted to shot your friends and enemies with Nerf darts launched from a drone? 
</br>
<img src='https://github.com/tedelm/KillerDronesFromOuterSpace/blob/master/IMG/pic1.jpg'>
</br>
</br>

# Make
Needed
- [ ]  Download KillerDroneFromOuterSpace files (Arduino and STL)
- [ ]  Download BLHeli Suite
- [ ]  Print STL files
- [ ]  1 x Nerf Mag.
- [ ]  2 x Blheli_s or Blheli_32 Esc (25-30amp)
- [ ]  2 x Brushless motor, like 2207 (6s 1600kv or 4s 2400kv)
- [ ]  1 x Arduino Nano
- [ ]  1 x SG90 Servo (9g servo)
- [ ]  1 x 5v BUCK/BEC (min 25v stepdown) like LM2596
- [ ]  1 x 4s/6s Lipo
- [ ]  3cm Thin (~1mm) Garden wire (for pulley/servo)


# Flash BLHELI_S ESC´s
Download: <a href='http://www.mediafire.com/file/23jnmpa0kiqry1k/BLHeliSuite16714902.zip/file'>Windows BLHELI_S Suite</a></br>
or browse for your version: <a href='https://www.mediafire.com/folder/dx6kfaasyo24l/BLHeliSuite'>All versions</a></br>
</br>
1. Connect Arduino to Computer</br>
2. Start BLHeli Suite</br>
3. Options -> "Expert Mode"</br>
4. Make Interfaces</br>
5. Select "Port" eg. COM5</br>
6. Click Arduino BLHeli BootLoader</br>
7. After the arduino is flashed with blheli bootloader, disconnect the Arduino from computer.</br>
8. Select "ATMEL / SILABS interface" as described, its usually "SILABS BLHELI Bootloader (USB/COM)"</br>
9. Solder GND and Signal from ESC to Arduino GND and D2 and solder vbat+ and vbat- to ESC</br>
10. Connect Arduino to Computer and start BLHeli Suite, click "Connect"</br>
11. Connect Lipo (VBAT+/VBAT-)</br>
12. Click "Flash BLHeli", select newest FW (Default)</br>
13. Repeat steps 1-12 for both esc´s.</br>
</br>


# Flash BLHELI_32 ESC´s
Download <a href='http://www.mediafire.com/file/as2n6rkbah053zp/BLHeliSuite32_32711.zip/file'>Windows BLHELI_32 Suite</a></br>
or browse for your version: <a href='https://www.mediafire.com/folder/dx6kfaasyo24l/BLHeliSuite'>All versions</a></br>
1. Connect Arduino to Computer</br>
2. Start BLHeli Suite</br>
3. Options -> "Expert Mode"</br>
4. Make Interfaces</br>
5. Select "Port" eg. COM5</br>
6. Click Arduino BLHeli BootLoader</br>
7. After the arduino is flashed with blheli bootloader, disconnect the Arduino from computer.</br>
8. Select "ATMEL / SILABS interface" as described, its usually "SILABS BLHELI Bootloader (USB/COM)"</br>
9. Solder GND and Signal from ESC to Arduino GND and D2 and solder vbat+ and vbat- to ESC</br>
10. Connect Arduino to Computer and start BLHeli Suite, click "Connect"</br>
11. Connect Lipo (VBAT+/VBAT-)</br>
12. Click "Flash BLHeli", select newest FW (Default)</br>
13. Repeat steps 1-12 for both esc´s.</br>
</br>

# Flash Arduino
1. Download and istall Arduino IDE <a href='https://www.arduino.cc/en/main/software'>Link</a></br>
2. Open Arduino IDE and open the sketch "KillerDroneFromOuterSpace.ino" </br>
3. Select correct Arduino under </br>
    Tools->Board = Arduino nano </br>
    Tools->Processor = ATMega328p (Old bootloader)</br>
    Tools->Port = COMx</br>
4. Press "Upload"    </br>

# Connect to Arduino (schematic)
Schematic:</br>
    ESC #1 (signal) -> Arduino pin: D9</br>
    ESC #1 (gnd, for signal) -> Arduino pin GND  </br>
    ESC #2 (signal) -> Arduino pin: D10</br>
    ESC #2 (gnd, for signal) -> Arduino pin GND</br>
    Servo (signal)  -> Arduino pin: D8</br>
    Servo (gnd)  -> 5v BUCK/BEC GND out</br>
    Servo (Vcc/+)  -> 5v BUCK/BEC Vcc/+ out</br>
    RevoltOSD TX4 (Pin Toggle) -> Arduino pin: A7</br>
    5v Buck/BEC (IN GND/VCC) -> VBAT GND/VCC</br>

```code
```