/*******************************************************************************
  *                MORSE CODE COMMUNICATORS                                     
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: defs.h                                     
  * Description: Contains the constant values for signal lengths and button
  *              presses.
  *****************************************************************************/

#ifndef DEFS_H
#define DEFS_H

#include "MicroBit.h"
 /*Allows uBit to be used across all the files*/
 extern MicroBit uBit;
 
 /*Signal length for dot*/
 #define DOTSIGNAL 250
 /*Signal length for dash*/
 #define DASHSIGNAL 500
 /*Signal length to indicate the end of the letter*/
 #define ENDMORSESIGNAL 800

 /*Time to press button A to enter a dot*/
 #define DOTPRESS 150
 /*Time to press button A to enter a dash*/
 #define DASHPRESS 350

#endif
