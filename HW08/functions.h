#ifndef functionsH
#define functionsH

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string word, bool caseS, bool spaceS);

void printUsageInfo(const string name);

int checkFlag(string flagTest, bool& caseS, bool& spaceS);

#endif
