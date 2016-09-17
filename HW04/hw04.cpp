#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {
    int codeLength;
    int digit;
    int i = 0;
    int j = 0;

    srand(time(0));
    // Ask user for how digits in code
    cout << "Enter number of digits in code (3, 4 or 5): ";
    cin >> codeLength;
    vector<int> codeVector;


    // if = 0, ask user for code, else, generate random code
    if(codeLength == 0) {
        // Get code from user
        cout << "Enter code: ";
        cin >> digit;
        codeLength = 0;

        int trueDigits;
        cout << "Enter number of digits in code: ";
        cin >> trueDigits;

        // Convert int into Array
        while (digit) {
            //codeVector.push_back(digit % 10);
            codeVector.insert(codeVector.begin(),digit % 10);
            digit /= 10;
            ++codeLength;
        }

        // Add extra zeros
        for( i = 1; i <= trueDigits-codeLength;++i) {
            codeVector.insert(codeVector.begin(),0);
        }

        codeLength = trueDigits;
        // Output inputed number to guess
        cout << "Number to guess: ";

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

        cout << "Number to guess: ";
        for(i = 0; i<=codeVector.size()-1;++i){
            cout << codeVector.at(i);
        }
    }

    int guess;
    vector<int> guessVector;
    bool gameContinue = true;

    // Time to guess
    while(gameContinue){
        int bulls = 0;
        int cows = 0;
        int guessCount = 0;
        guessVector.clear();

        cout << endl << "Enter guess: ";
        cin >> guess;

        // Convert guess into guess Vector
        while (guess) {
            //codeVector.push_back(digit % 10);
            guessVector.insert(guessVector.begin(),guess % 10);
            guess /= 10;
            ++guessCount;
        }

        // Check if guess was supposed to start with a 0
        if(guessCount < codeVector.size()) {
            guessVector.insert(guessVector.begin(),0);
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
            cout << "  -  Correct!";
            gameContinue = false;
        } else {
            cout << endl;
            cout << cows << " cows";
        }
    }
    return 0;
    }

