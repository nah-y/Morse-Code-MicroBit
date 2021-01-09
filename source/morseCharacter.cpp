/*******************************************************************************
  *                MORSE CODE COMMUNICATORS                                     
  * Internet of Things | Challenge 02                    
  * Student Name: Aishath Nahidha                        
  * Student ID: S1900136                                 
  * Created Date: April 2020                             
  *                                                      
  * File: morseCharacter.cpp                                       
  * Description: Consists of functions related to enciphering, deciphering and 
  *              finding the character associated with a particular morse code.
  *****************************************************************************/

#include "MicroBit.h"
#include "morseCharacter.h"
#include "defs.h"

#include <vector>

/*cipherKey is a (pointer to a) vector array that stores the... cipher key*/
std::vector<char>* cipherKey = new vector<char>;

/** 
  * Name: generateCipherKey
  * Description: Stores the cipher key with dots and dashes. Insert either '.' 
                 (dot) or '-' (dash) to change the cipher key.
  * Parameters: none
  * Returns: void
  */
void generateCipherKey(){
    cipherKey->push_back('.');
    cipherKey->push_back('-');
    cipherKey->push_back('-');
    cipherKey->push_back('.');
    cipherKey->push_back('.');
    return;
}

/** 
  * Name: cipher 
  * Description: Enciphers and deciphers the given vector array of morse.
  * Parameters: std::vector<char>* morseInput
                A pointer to a vector array with dots and dashes.
  * Returns: std::vector<char>* morseOutput
             A pointer to a vector array.
  */
std::vector<char>* cipher(std::vector<char>* morseInput){
    
    /*morseOutput is a (pointer to a) a vector array that stores the returning 
      dots and dashes.*/
    std::vector<char>* morseOutput;
    
    
    for (int i = 0; i < morseInput->size(); i++) {
        if(morseInput->at(i) == '|') {
            /*"|" is the symbol for end of the letter*/
            morseOutput->at(i) = '|';
            
        } else if(morseInput->at(i) == cipherKey->at(i)) {
            /*If the input vector array and the cipher key both have the same 
              character at the same spot then insert a dot at that spot in the 
              returning array.*/
            morseOutput->at(i) = '.';
            
        } else {
            /*If the input vector array and the cipher key both have different 
              character at the same spot then insert a dash at that spot in the 
              returning array.*/
            morseOutput->at(i) = '-';
        }
    }
    return morseOutput;
}

/*ASCII holds the characters to be decoded from morse. 
  They are written in a particular order (more information in README).
  # stands for empty spots.*/
const char *ASCII = "##ETIANMSURWDKGOHVF#L#PJBXCYZQ##54#3###2##+####16=/#####7###8#90";

/** 
  * Name: morseToASCII
  * Description: When given a series of dots and dashes in a vector array, the 
                 function finds the corresponding ASCII character from the 
                 variable ASCII above.(More detail about how this is done can be
                 found in the README.)
  * Parameters: std::vector<char>* morse
                A vector array of morse code, i.e. dots "." and dashes "-".
  * Returns: char ASCII[index]
             The character from the variable ASCII that corresponds to the morse
             code given.
  */
char morseToASCII(std::vector<char>* morse){
    /*index stores the position of the character in the variable ASCII*/
    int index = 1;
    
    for(int i = 0; i < morse->size(); i++) {
        if(morse->at(i) == '.') {
            /*Left shift adds a zero to the binary value of index*/
            index = index<<1;
        }else if(morse->at(i) == '-') {
            index = index << 1;
            /*Doing the OR operation with 1 turns the 0 added to the least
              significant bit from the previous statement to a 1*/
            index = index | 1; //Doing the OR operation 
        }
    }
    
    return ASCII[index];
}
