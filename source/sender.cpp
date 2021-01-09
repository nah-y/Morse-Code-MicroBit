/*******************************************************************************
  *                MORSE CODE COMMUNICATORS                                     
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: sender.cpp                                       
  * Description: Consists of the sender() function, which contains the main code 
  *              for the sender microbit.
  *****************************************************************************/

#include "MicroBit.h"
#include "morseCharacter.h"
#include "message.h"
#include "defs.h"

#include <vector>

/** 
  * Name: sender
  * Description: This is the main function for the sender microbit.
  * Parameters: none
  * Returns: void
  */
void sender(){
    /*Displays sender to confirm the selected role for the microbit*/
    uBit.display.scroll("SENDER");

    /*Creating variables to be used in the loop*/
    /*morseEntered is true when a button press has been detected*/
    bool morseEntered; 
    /*initialTime and deltaTime are used to calculate how long the button was 
      pressed for */
    int initialTime, deltaTime;
    /*The row number allows each dot or dash to be displayed in its own row */
    int row = 0;
    /*morseLetter is a (pointer to a) vector array that will store the dots and 
      dashes to be sent */
    std::vector<char>* morseLetter = new vector<char>;


    while(true) {
        
        /*Read current system time */
        initialTime = system_timer_current_time();
        /*Loop while button A is pressed */
        while(uBit.buttonA.isPressed()) {
            morseEntered = true;
        }
        /*Calculate how long the button was pressed for, 
          i.e. how long the loop executed for */
        deltaTime = system_timer_current_time() - initialTime;
        
        /*This if condition executes if button A has been pressed. 
        It decides whether it should be stored as a dot or dash*/
        if(morseEntered) {
            if(deltaTime > 1000) {
                /*If the button press is too long then do nothing. */
            }
            /*DASH*/
            else if(deltaTime > DASHPRESS) {
                /*The dash is displayed as three consecutive LEDs lighting 
                  up on its row */
                for(int i = 0; i < 3; i++) {
                    uBit.display.image.setPixelValue(i, row, 255);
                }
                row++;
                /*Store the the dash in the vector array */
                morseLetter->push_back('-');
            }
            /*DOT*/
            else if(deltaTime > DOTPRESS) {
                /*The dot is displayed as one LED lighting up on its row*/
                uBit.display.image.setPixelValue(0, row, 255);
                row++;
                /*Store the the dot in the vector array*/
                morseLetter->push_back('.');
            }
            /*Once the dot press has been identified morseEntered is set 
            to false*/
            morseEntered = false;
        }
        
        /*Button B is pressed to send dots and dashes to the other microbit*/
        if(uBit.buttonB.isPressed()) {
            /*The character | is used to indicate the end of the letter*/
            morseLetter->push_back('|');
            
            /*The vector array is first sent to the function cipher (implemented
              in morseCharacter.cpp) and the result is sent to the function 
              sendMorse (implemented in message.cpp)
             *In essence, the morse letter is enciphered and then sent over
              to the receiver microbit*/
            sendMorse(cipher(morseLetter));
            
            /*The dots and dashes stored in the vector array and the display 
              are cleared for the next letter*/
            morseLetter->clear();
            uBit.display.clear();
            row = 0;
            
            /*The > is displayed to indicate that letter is sent
              and to allow some time between sending letters so the receiver 
              microbit is not overwhelmed*/
            uBit.display.print('>');
            uBit.sleep(1000);
            uBit.display.clear();
        }
        
        /*Since each dot and dash is stored in its own row, the row number 
        functions as the number of characters too.
        The number of characters is limited to 5.
        If a 6th character is attempted a ! will be displayed and you'll have to
        start over again.*/
        if (row > 5) {
            morseLetter->clear();
            uBit.display.clear();
            row = 0;
            uBit.display.printChar('!');
            uBit.sleep(500);
            uBit.display.clear();
        }
    }
}
