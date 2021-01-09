/*******************************************************************************
  *                MORSE CODE COMMUNICATORS              
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: main.cpp                                       
  * Description: Execution begins in the main() function.
  *****************************************************************************/

#include "MicroBit.h"
#include "morseCharacter.h"
#include "sender.h"
#include "receiver.h"

//Create an instance of the MicroBit class
MicroBit uBit;


/********************************************************
  *                     Main                            *
  *******************************************************/

/** 
  * Name: main
  * Description: The main function, where execution begins.
  * Parameters: none
  * Returns: int
  */
int main()
{
    /*Initialise the micro:bit runtime.*/
    uBit.init();

    uBit.display.scroll("MORSE");
    
    /*Adds dots and dashes to the cipher key.
      Implemented in morseCharacter.cpp*/
    generateCipherKey();
    
    
    bool roleChosen = false;
    /*This loops continuously checks for button presses until either A or B 
      is pressed*/
    while(!roleChosen){
        if(uBit.buttonA.isPressed()){
            roleChosen = true;
            /*If button A is pressed the microbit is chosen as the sender
              Function is implemented in sender.cpp*/
            sender();
            
        }
        if(uBit.buttonB.isPressed()){
            roleChosen = true;
            /*If button B is pressed the microbit is chosen as the receiver
              Function is implemented in receiver.cpp*/
            receiver();
        }
    }

    /*If main exits, there may still be other fibers running or registered 
      event handlers etc.
      Simply release this fiber, which will mean we enter the scheduler. 
      Worse case, we then sit in the idle task forever, in a power efficient 
      sleep.*/
    release_fiber();
}
