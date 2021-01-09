/*******************************************************************************
  *                MORSE CODE COMMUNICATORS                                     
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: message.h                                       
  * Description: Consists of functions related to sending and receiving signals.
  *****************************************************************************/

#ifndef MESSAGE_H
#define MESSAGE_H

#include <vector>

 /** 
  * Name: sendSignal
  * Description: Keeps the pin active (HI) for the required time. 
                 To pass messages via agreed on lengths of signals.
  * Parameters: int signalLength 
                How long the pin should be active for. 
                Standard lengths are defined in source/defs.h
  * Returns: void
  */
 void sendSignal(int signalLength);
 
 /** 
  * Name: signalReader
  * Description: If the pin is active (HI), the time it is active for, 
                 i.e. the length of the signal is returned.
  * Parameters: none
  * Returns: int deltaTime 
             The length of the signal.
  */
 int signalReader();
 
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
 bool rangeChecker(int incomingLength, int standard, int range);
 
 /** 
  * Name: sendMorse
  * Description: Sends the appropriate signals for the dots and dashes in the 
                 vector array.
  * Parameters: vector<char>* morse - the (pointer to the) vector array in which 
                                      the dots and dashes are stored.
  * Returns: void
  */
 void sendMorse(std::vector<char>* morse);

#endif
