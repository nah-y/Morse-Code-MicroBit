/*******************************************************************************
  *                MORSE CODE COMMUNICATORS                                     
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: receiver.cpp                                       
  * Description: Consists of the receiver() function, which contains the main 
  *              code for the receiver microbit.
  *****************************************************************************/

#include "MicroBit.h"
#include "morseCharacter.h"
#include "message.h"
#include "defs.h"
#include "receiver.h"

#include <vector>

MicroBitSerial  serialR(USBTX,   USBRX);

/** 
  * Name: receiver
  * Description: This is the main function for the receiver microbit.
  * Parameters: none
  * Returns: void
  */
void receiver() {
    serialR.baud(115200);
    serialR.send("RECEIVER \n\r");
    
    /*Displays sender to confirm the selected role for the microbit*/
    uBit.display.scroll("RECEIVER");
    
    /*Creating variables to be used in the loop*/
    /*morseLetter is a (pointer to a) vector array that stores the incoming
      dots and dashes*/
    std::vector<char>* morseLetter = new vector<char>;
    /*deciphered is a (pointer to a) vector array that stores the deciphered
      dots and dashes*/
    std::vector<char>* deciphered = new vector<char>;
    /*signalLength stores the length of the incoming signals*/
    int signalLength;
    
    
    while(true){
        /*The function signalReader (implemented in message.cpp) returns the 
          length of the signal detected, which is stored in signalLength.*/
        signalLength = signalReader();
        
        /*This block of if statements decide what to do based on the signal 
          length. 
          (More information on rangeChecker can be found in message.cpp 
          where it is implemented)
          (The actual lengths of DOTSIGNAL etc. can be found in defs.h)*/
        if(rangeChecker(signalLength, DOTSIGNAL, 25)){
            /*If a dot is received, save it to the vector array*/
            morseLetter->push_back('.');
            serialR.send("DOT received \n\r");
        }else if(rangeChecker(signalLength, DASHSIGNAL, 25)){
            /*If a dash is received, save it to the vector array*/
            morseLetter->push_back('-');
            serialR.send("DASH received \n\r");
        }else if(rangeChecker(signalLength, ENDMORSESIGNAL, 25)){
            /*If the signal for end of the letter is received, decipher it using
              cipher function (in morseCharacter.cpp).*/
            deciphered = cipher(morseLetter);
            for (int i = 0; i < deciphered->size(); i++) {
                if (deciphered->at(i) == '.') {serialR.send("dot \n\r");}
                else if (deciphered->at(i) == '-') {serialR.send("dash \n\r");}
            }
            /*Find the letter associated with the dots and dashes using the 
            morseToASCII function(implemented in morseCharacter.cpp)*/
            char ASCII = morseToASCII(deciphered);
            /*Clear the screen and display the ASCII character.
              Clear the vector array for the next letter*/
            uBit.display.clear();
            uBit.display.printChar(ASCII);
            morseLetter->clear();
        }
    }    
}
