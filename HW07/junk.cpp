#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
  std::vector<int> v;


  for (int i = 0; i < 9; i++) {
    v.push_back(i);
  }
  int test = max(v);
  cout << test << endl;
  
  return 0;
}
