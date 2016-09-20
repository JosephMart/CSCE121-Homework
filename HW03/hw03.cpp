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
        int numberDigits = 0;

        int trueDigits;
        cout << "Enter number of digits in code: ";
        cin >> trueDigits;

        // Convert int into Array
        while (digit) {
            //codeVector.push_back(digit % 10);
            codeVector.insert(codeVector.begin(),digit % 10);
            digit /= 10;
            ++numberDigits;
        }

        // Add extra zeros
        for( i = 1; i <= trueDigits-numberDigits;++i) {
            codeVector.insert(codeVector.begin(),0);
        }

        // Output inputed number to guess
        cout << "Number to guess: ";

        for(i = 0; i<=codeVector.size()-1;++i){
            cout << codeVector.at(i);
        }
    } else {
        // Generate random code of codeLength
        for( i = 0;i < codeLength;++i) {
            codeVector.push_back(rand()%10);
            for(int j = 0; j < i; ++j) {
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
      return 0;
    }

