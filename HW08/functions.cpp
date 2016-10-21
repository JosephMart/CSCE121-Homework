#include "functions.h"

bool isPalindrome(string word, bool caseS, bool spaceS) {
  bool pal = false;
  int sze = word.size();
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

  // Recursivly if the string is a palindrome
  sze = word.size();
  if (word.at(0) == word.at(sze-1)) {
    pal = true;
    if (sze-2 > 0) {
      word = word.substr(1,sze-2);
      pal = isPalindrome(word, caseS, spaceS);
    }
  }
  return pal;
}


void printUsageInfo(const string name) {
  cout << "Usage: " << name << " [-c] [-s] string ..." << endl;
  cout << "   -c: case sensitivity turned on" << endl;
  cout << "   -s: ignoring spaces turned off" << endl;
  return;
}

int checkFlag(string flagTest, bool& caseS, bool& spaceS){
  int i = 1;
  if (flagTest.at(0) == '-') {
    i = 2;
    flagTest = flagTest.substr(1, flagTest.size()-1);

    // Lower flag(s) and compare
    for(int i = 0; flagTest[i] != '\0'; i++){
        flagTest[i] = tolower(flagTest[i]);
        if (flagTest.at(i) == 'c') {
          caseS = true;
        } else if(flagTest.at(i) == 's') {
          spaceS = true;
       }
      }
    }
    return i;
  }
