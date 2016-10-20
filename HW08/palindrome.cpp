#include "functions.h"

int main(int argc, char const *argv[]) {

  if (false) {
    printUsageInfo();
  } else {

    bool spaceS = false;
    bool caseS = false;
    int start;
    // Check if there is a flag
    string flagTest = argv[1];
    if (flagTest.at(0) == '-') {
      start = 2;
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
      } else {
        start = 1;
    }

    string word;
    // Convert command argument into one string
    while (start < argc) {
      word.append(argv[start]);
      word.append(" ");
      ++start;
    }
    word.erase(word.size()-1);


    bool pal = isPalindrome(word, caseS, spaceS);
    std::cout << pal << std::endl;
    if (pal) {
      cout << word << " is a palindrome" << endl;
    } else {
      cout << word << " is not a palindrome" << endl;
    }

  }
  return 0;
}
