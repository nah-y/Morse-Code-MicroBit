/*******************************************************************************
  *                MORSE CODE COMMUNICATORS                                     
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: morseCharacter.h                                       
  * Description: Consists of functions related to enciphering, deciphering and 
  *              finding the character associated with a particular morse code.
  *****************************************************************************/

#ifndef MORSECHARACTER_H
#define MORSECHARACTER_H

#include <vector>

 /*cipherKey is a (pointer to a) vector array that stores the... cipher key*/
 extern std::vector<char>* cipherKey;
 
 /** 
  * Name: generateCipherKey
  * Description: Stores the cipher key with dots and dashes. Insert either '.' 
                 (dot) or '-' (dash) to change the cipher key.
  * Parameters: none
  * Returns: void
  */
 void generateCipherKey();
 
 /** 
  * Name: cipher 
  * Description: Enciphers and deciphers the given vector array of morse.
  * Parameters: std::vector<char>* morseInput
                A pointer to a vector array with dots and dashes.
  * Returns: std::vector<char>* morseOutput
             A pointer to a vector array.
  */
 std::vector<char>* cipher(std::vector<char>* morseInput);
 
 /** 
  * Name: morseToASCII
  * Description: When given a series of dots and dashes in a vector array, the 
                 function finds the corresponding ASCII character from the 
                 variable ASCII.(More detail about how this is done can be
                 found in the README.)
  * Parameters: std::vector<char>* morse
                A vector array of morse code, i.e. dots "." and dashes "-".
  * Returns: char ASCII[index]
             The character from the variable ASCII that corresponds to the morse
             code given.
  */
 char morseToASCII(std::vector<char>* morse);

#endif
