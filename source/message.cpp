/*******************************************************************************
  *                MORSE CODE COMMUNICATORS                                     
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: message.cpp                                       
  * Description: Consists of functions related to sending and receiving signals.
  *****************************************************************************/

#include "message.h"
#include "defs.h"
#include "MicroBit.h"

/*P0 is the software representation of Pin 0 in the microbit*/
MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_DIGITAL);

/** 
  * Name: sendSignal
  * Description: Keeps the pin active (HI) for the required time. 
                 To pass messages via agreed on lengths of signals.
  * Parameters: int signalLength 
                How long the pin should be active for. 
                Standard lengths are defined in source/defs.h
  * Returns: void
  */
void sendSignal(int signalLength){
    P0.setDigitalValue(1);
    uBit.sleep(signalLength);
    P0.setDigitalValue(0);
    uBit.sleep(500);
}

/** 
  * Name: signalReader
  * Description: If the pin is active (HI), the time it is active for, 
                 i.e. the length of the signal is returned.
  * Parameters: none
  * Returns: int deltaTime 
             The length of the signal.
  */
int signalReader(){
    /*initialTime and deltaTime are used to calculate how long the pin was 
      active for.*/
    int initialTime, deltaTime;
    
    /*P0.getDigitalValue() will be true if the pin is actve.*/
    if(P0.getDigitalValue()){
        
        initialTime = uBit.systemTime();
        
        while(P0.getDigitalValue()){
            //Signal being received
        }
        
        /*Calculate how long the pin was active for*/
        deltaTime = uBit.systemTime() - initialTime;
        
        if(deltaTime > 10){
            return deltaTime;
        }
    }
}

/** 
  * Name: rangeChecker
  * Description: Since the lengths of the signal might not be read accurately, 
                 this function allows to check whether the signal is within an 
                 acceptable range.
  * Parameters: int incomingLength - the length of the signal being read by this 
                                     microbit.
                int standard - the length that is expected. 
                               Common standards are defined in source/defs.h
                int range - how widely, from either side of the standard is 
                            acceptable. This value will be added and subtracted 
                            from the standard to give a maximum and minimum, 
                            respectively.
  * Returns: bool - true if the incoming signal is within the acceptable range, 
                    false if not.
  */
bool rangeChecker(int incomingLength, int standard, int range){
    int rangeMax = standard + range;
    int rangeMin = standard - range;
    if(incomingLength < (rangeMax) && (incomingLength > (rangeMin))){
        return true;
    }else{
        return false;
    }
}

/** 
  * Name: sendMorse
  * Description: Sends the appropriate signals for the dots and dashes in the 
                 vector array.
  * Parameters: vector<char>* morse - the (pointer to the) vector array in which 
                                      the dots and dashes are stored.
  * Returns: void
  */
void sendMorse(std::vector<char>* morse){
    
    for (int i = 0; i < morse->size(); i++){
        
        if(morse->at(i) == '.'){
            sendSignal(DOTSIGNAL);
            
        }else if(morse->at(i) == '-'){
            sendSignal(DASHSIGNAL);
            
        }else{
            /*If the character at that spot is not a dot or dash then it must 
              be the symbol for the end of the letter "|" */
            sendSignal(ENDMORSESIGNAL);
            
        }
    }
}
