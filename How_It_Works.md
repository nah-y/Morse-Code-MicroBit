# How It Works

## Program files
### Source
| File | Description |
|--|--|
| main.cpp | Execution begins in the main() function. |
| sender.cpp | Consists of the sender() function, which contains the main code for the sender Microbit.|
| sender.h | Header file for sender.cpp |
| receiver.cpp | Consists of the receiver() function, which contains the main code for the receiver microbit. |
| receiver.h | Header file for receiver.cpp |
| morseCharacter.cpp | Consists of functions related to enciphering, deciphering and finding the character associated with a particular morse code. |
| morseCharacter.h | Header file for morseCharacter.cpp |
| message.cpp | Consists of functions related to sending and receiving signals. |
| message.h | Header file for message.cpp |
| defs.h | Contains the constant values for signal lengths and button presses. |


## Encryption
The sender Microbit transmits dots and dashes over the wires. But these are not the same dots and dashes that were entered.

**The XOR cipher**
The morse characters are encrypted based on a variant of the XOR cipher.
The XOR cipher works on the concept of the XOR operation. Exclusive or or exclusive disjunction is a logical operation that outputs true only when inputs differ.

| A | B | Out |
|--|--|--|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

In computers, data is encrypted via the XOR cipher by applying the XOR operator to binary data and a key (which is also in binary).

Since morse also uses a binary system (of dots and dashes) the same idea could be applied to our transmissions as well.

| In | Key | Out |
|--|--|--|
| . | . | . |
| . | - | - |
| - | . | - |
| - | - | . |

**Cipher key**
At the beginning of the program the `cipherKey` will be populated with the dots and dashes in `generateCipherKey`.  Edit the cipher key by changing the dots and dashes in `generateCipherKey`. If you enter a symbol other than a dot or dash, the program will still work but the encryption will not be much of an encryption.


**Enciphering and Deciphering**
Enciphering and deciphering are both done with the same `cipher` function, adding to the advantages of using this cipher (since it leads to less code).


## Morse Decoding - A Better Way
Once the dots and dashes have been received and deciphered by the receiver Microbit, they need to be decoded to display the letter or character that they represent.

The most natural way to do this might be to use a `std::map` as a dictionary. With each morse sequence being matched with its character. This might not take so much time in a computer but I still felt there must be a better way. 

In my research into morse I came across an amazing device used by people to decode morse. It's no surprise that it existed, since it would be too slow for a person to go through each letter's morse sequence every time one is received. This device is a binary tree diagram (shown below).

<img src="/images/IOTChallenge2-Morse%20Decoder.png" width="700px"/>

If a dot is entered/ received, move down the left branch, for a dash move down the right branch. It's amazingly simple.

Now I needed a way to represent this in C++ code. Radu Mortison's [morse encoder](https://www.pocketmagic.net/morse-encoder/) had the same approach and I used his string of characters and their index method. But his way of finding the letter was not what I wanted, so I set out to create my own. 

While I experimented with the binary values of the indices (because of the binary nature of morse code) I noticed that when we go down a level in the morse decoder binary tree, a bit is added to the least significant bit or the left side. If a dot is entered, a 0 is added, if a dash is entered, a 1 is added. Using this, I devised the following algorithm:<br>
The ASCII characters are stored in a string and accessed by using an index value.<br>
Given an array of dots and dashes,<br>
If the character at a particular position is a dot, perform a left shift on the index. This adds a zero to the binary value of the index.<br>
If the character is a dash, perform a left shift and OR operation with 1. This adds a 1 to the binary value of the index.<br>
After going through all the morse characters in this way, return the the ASCII character at the index position.<br>


## Finite State Diagram

<img src="/images/IOTChallenge2-FSD.png" width="700px"/>