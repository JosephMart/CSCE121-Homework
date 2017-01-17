# Homework 3&4: Bulls & Cows

### Program
This homework will be done over two weeks. The parts below will be labeled with HW3 or HW4 indicating when it is due. HW3 will be due the first week, and HW4 will be added to HW3 to create the final program.

Bulls and Cows is a guessing game where you try to guess a 'n' digit code. (Note: each number in the code must be distinct) When a number is guessed and a digit is in the correct location, then that is a bull. When a digit is in the number, but in the incorrect location, then that is a cow. So if a four digit code is 2894, and the user guesses 4698. Then that is "1 bull and 2 cows" because '9' is in the correct location and '4' and '8' are in the code but are currently in the wrong location. The guessing continues until the code is guessed in the correct order... "4 bulls"!

### Requirements
#### Program Flow
1. *HW3*: Get the number of digits to guess as input.
  * Only accept inputs of 0, 3, 4, or 5.
  * Repeat until a valid choice is input.
2. *HW3*: If 0 is input as digits to guess:
  1. ask for code and get as a single integer.
  2. ask for number of digits to guess.
    * This will allow TAs to enter a code to make testing easier.
    * Since this is for testing purposes, you do not have to check these for correct input.
    * Else randomly create a valid code.
    * number of digits matching the number of digits to guess. *Note: 0 (zero) is valid for the leftmost digit. However, it will look like it has less digits if output as an integer. For example: 0471 will look like 471.*
    * each digit is distinct/unique.
3. *HW3*: Ouput the code to be guessed. (This is purely to help with auto-grading, but would not be part of a real game program.)
4. *HW4*: Get guess as a single integer.
  * If more digits than the number in the code, get number again.
  * If not enough digits, assume the missing digits to the left are zero. 
    
    *For example: For a 3 digit code, 35 is the same as 035 where zero is the first digit. For a 4 digit code, 35 is the same as 0035.*
  * If any digits are repeated, get number again.
  
#### Coding Requirements
  * The code and guess must each be stored in a vector of ints.
  * Follow formatting as demonstrated in the "Sample Runs" below.
