#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    bool gameContinue = true;
    bool again;
    int codeLength;
    int digit;
    int i = 0;
    int j = 0;
    int guess;
    vector<int> guessVector;
    vector<int> codeVector;
    srand(time(0));
    // Ask user for how digits in code
    cout << "Enter number of digits in code (3, 4, or 5): " << endl;
    cin >> codeLength;
    // Check if input is acceptable
    again = (codeLength == 0 || codeLength == 3 || codeLength == 4 ||
      codeLength == 5) ? false:true;

    while (cin.fail() || again) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "Enter number of digits in code (3, 4, or 5): " << endl;
      cin >> codeLength;
      again = (codeLength == 0 || codeLength == 3 || codeLength == 4 ||
        codeLength == 5) ? false:true;
    }
    // if = 0, ask user for code, else, generate random code
    if(codeLength == 0) {
        int trueDigits;
        codeLength = 0;
        // Get code from user
        cout << "Enter code:" << endl;
        cin >> digit;
        cout << "Enter number of digits in code:"  << endl;
        cin >> trueDigits;

        // Convert int into Array
        while (digit) {
            codeVector.insert(codeVector.begin(),digit % 10);
            digit /= 10;
            ++codeLength;
        }
        // Add extra zeros if need be
        for(i = 1; i <= trueDigits-codeLength;++i) {
            codeVector.insert(codeVector.begin(),0);
        }
        // For later use in guesses
        codeLength = trueDigits;

        // Output inputed number to guess
        cout << "Number to guess:";
        for(i = 0; i<=codeVector.size()-1;++i){
            cout << codeVector.at(i);
        }
    } else {
        // Generate random code of codeLength
        for( i = 0;i < codeLength;++i) {
            codeVector.push_back(rand()%10);
            for( j = 0; j < i; ++j) {
                while(codeVector.at(i) == codeVector.at(j)) {
                    codeVector.at(i) = (rand()%10);
                    j=0;
                }
            }
        }
        /*
        // TEMP to test Bulls and Cows
        cout << "Number to guess: ";
        for(i = 0; i<=codeVector.size()-1;++i){
            cout << codeVector.at(i);
        }*/
    }
    // Continue into guessing portion
    while(gameContinue){
        int bulls = 0;
        int cows = 0;
        int guessCount = 0;
        bool badInput = true;
        bool repeat = false;
        guessVector.clear();

        // Check if it is acceptable input
        while (cin.fail() || badInput) {
          badInput = false;
          repeat = false;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cout << endl << "Enter guess:" << endl;
          cin >> guess;
          // Convert guess into guess Vector
          while (guess) {
              guessVector.insert(guessVector.begin(),guess % 10);
              guess /= 10;
              ++guessCount;
          }
          // Add zero if needed
          if (guessVector.size() < codeVector.size()) {
              guessVector.insert(guessVector.begin(),0);
          }

          //check if no repeats
          for( i = 0;i < guessVector.size();++i) {
              for( j = 0; j < i; ++j) {
                  if(guessVector.at(i) == guessVector.at(j) && i != j) {
                      repeat = true;
                  }
              }
          }
          if (repeat || badInput || guessVector.size() < codeVector.size()) {
            guessVector.clear();
            std::cout << "Each number must be different.";
            badInput = true;
          } else if (guessVector.size() > codeVector.size()) {
            std::cout << "You can only enter " << codeVector.size() << " digits.";
            badInput = true;
            guessVector.clear();
          }
        }
        // Compare guessVector to codeVector
        for(i = 0;i < guessVector.size(); ++i) {
            for( j = 0;j < codeVector.size(); ++j) {
                if(guessVector.at(i) == codeVector.at(j)) {
                    if(i == j) {
                        ++bulls;
                    } else {
                        ++cows;
                    }
                }
            }
        }
        cout << bulls << " bulls";
        if (bulls == codeVector.size()) {
            cout << " - ";
            for ( i = 0; i < codeVector.size(); i++) {
              cout << codeVector.at(i);
            }
            cout << "  is Correct!";
            gameContinue = false;
        } else {
            cout << endl;
            cout << cows << " cows";
        }
    }
    return 0;
    }
