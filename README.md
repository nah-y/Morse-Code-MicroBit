# Morse Code Communicator [IoT-Challenge-02]
This application allows a microbit to send encrypted Morse code to a microbit that is connected to it.

**Author Information** \
**Name:** Aishath Nahidha \
**Student ID:** S1900136 \
**Program:** Bsc Computer Science (January 2019)
## Installation
Morse Code Communicator was created using the [micro:bit runtime](https://lancaster-university.github.io/microbit-docs/) developed by Lancaster University. 
To run the application on your microbit,

**Using the hex file:** 
1. Connect the microbit to your computer via a USB cable (Micro-USB). The microbit will appear as a drive.
2. Download the [microbit-morse-code-communicator.NRF51_MICROBIT.hex](https://gitlab.uwe.ac.uk/a2-nahidha/iot-challenge-02/-/blob/master/microbit-morse-code-communicator.NRF51_MICROBIT.hex) file.
3. Drop the hex file into the microbit drive. The copy triggers the orange LED on the back of the micro:bit to flash; it will stop flashing when the download is complete.
4. Once the download process is completed, the application will start running on your microbit.

**Using the C++ source code:** \
If you would like to make any changes to the application, the altered source file has to be compiled to create a hex file.<br>
Please read [How It Works](/How_It_Works.md) before changing the code.
1. Decide on a development environment from the micro:bit documentation [Getting Started](https://lancaster-university.github.io/microbit-docs/#getting-started) page.
2. Compile the source code to generate a hex file.
3. Download the hex file and follow the steps from above.

## Usage

**Connect**

Connect the two Microbits by connecting a wire from Pin 0 (below button A) on one device to that of the other. Likewise connect the GND pins of each microbit to each other.

<img src="/images/IMG_0160.jpg" width="400px"/>


**Power**

Connect batteries or connect to a computer via USB to provide a power supply.

**Choose sender**

Both Microbits will display "MORSE" at startup.

Press `A` on the sender Microbit.

Press `B` on the receiver Microbit.

Now the microbits should display "SENDER" and "RECEIVER" according to their roles.

Once the screen clears, the sender microbit can start to input Morse code.

**Enter Morse code**

Short press button `A` = DOT

Long press button `A` = DASH

Each morse character will be displayed on its own line as they are entered.

Press `B` to send the character

Allow around 5 seconds to send the dots and dashes. Once the letter is sent the ">" will appear on the microbit. The receiver Microbit will display the letter that was sent.

**Entering too many characters**

All the letters that are currently supported in this application, which are all the common english letters and numbers (and some symbols) have a maximum of 5 morse characters. As such, if you attempt to enter a sixth character, a "!" will appear on the screen and you will have to enter the characters again (correctly this time).

**Wrong morse sequence/ Unsupported characters**

If the sender attempts to send a morse sequence for which there is no letter (at least in our letter set) then a "#" will appear on the receiver's Microbit.

For the supported characters and how to enter them, refer to the morse decoder image in [How It Works](/How_It_Works.md).

## How It Works
Check out [How It Works](/How_It_Works.md) to read how these were implemented.

## License
[MIT](https://choosealicense.com/licenses/mit/)
