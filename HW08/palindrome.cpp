#include "functions.h"

int main(int argc, char const *argv[]) {
  // Get program name into a string
  string name = argv[0];

  // If no arguments, print usage
  if (argc < 2) {
      printUsageInfo(name);
  } else {
    // Initialize parameter restriction booleans
    bool spaceS = false;
    bool caseS = false;

    // Check if there is a flag
    string flagTest = argv[1];
    int i = checkFlag(flagTest, caseS, spaceS);

      // Check if is an argument after the parameter
      if (i == 2 && argc == 2 ) {
            printUsageInfo(name);
          } else {
            while (i < argc) {
              // Check if 3rd item is -c or -s
              if (i == 2) {
                string test = argv[i];
                if (test.at(0) == '-') {
                  if (argc < 4){
                    printUsageInfo(name);
                    break;
                  } else {
                    i = 1 + checkFlag(test, caseS, spaceS);
                  }
                }
              }
              // Remove punctuation
              string word = argv[i];
              for (int j = 0; j < word.size(); ++j) {
                  if (ispunct(word.at(j)) || word.at(j) == '?') {
                      word.erase(word.begin()+j);
                  }
                }

              // Run the recursivly checking isPalindrome function
              bool pal = isPalindrome(word, caseS, spaceS);

              // Print results to the user
              if (pal) {
                cout << "\"" << argv[i] << "\" is a palindrome" << endl;
              } else {
                cout << "\"" << argv[i] << "\" is not a palindrome" << endl;
              }
              ++i;
            }
          }
        }
        return 0;
      }
