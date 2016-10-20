// Required Functions:
//   Function that prints program usage message in case no input strings were found at command line.
//     Name: printUsageInfo
//     Parameter(s): a string representing the name of the executable from the command line.
//   Return: void.
// Recursive function that determines whether a string is a character-unit palindrome.
//   Name: isPalindrome
//   Parameter(s): an input string, a boolean flag that considers case-sensitivity when true, and a boolean flag that does not ignore spaces when true.
// Return: bool.
#include "functions.h"


bool isPalindrome(string word, bool caseS, bool spaceS) {
  int sze = word.size();
  bool pal = false;
  // convert to the same case if !caseS
  if (!caseS) {
    for(int i = 0; word[i] != '\0'; i++){
		  word[i] = tolower(word[i]);
	 }
  }

  // get rid of space if !spaceS
  if (!spaceS) {
    for(int i = 0; i < word.size()-1; i++){
		  if (isspace(word.at(i))) {
		    string temp1 = word.substr(0,i);
        string temp2 = word.substr(i+1, word.size()-1);
        word = temp1 + temp2;
		  }
	  }
  }

  sze = word.size();
  if (word.at(0) == word.at(sze-1)) {
    pal = true;
    if (sze-2 != 0) {
      word = word.substr(1,sze-2);
      pal = isPalindrome(word, caseS, spaceS);
    }
  }
  return pal;
}


void printUsageInfo() {
  cout << "Usage: ./palindrome [-c] [-s] string ..." << endl;
  cout << "   -c: case sensitivity turned on" << endl;
  cout << "   -s: ignoring spaces turned off" << endl;
  return;
}
