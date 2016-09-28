#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// Declare functions
vector<vector<int>> loadData(int& rows, int& columns);
int Extrema(int option, vector<vector<int>> v, int rows, int columns);

int main() {
  vector<std::vector<int>> data;
  int rows;
  int columns;
  // Load data
  data = loadData(rows, columns);

  // Find min and Max
  int Max = Extrema(1, data, rows, columns);
  int Min = Extrema(0, data, rows, columns);

  std::cout << "Max: " << Max << '\n';
  std::cout << "Min: " << Min << '\n';



  return 0;
}

vector<vector<int>> loadData(int& rows, int& columns) {
  ifstream inFS;
  vector<vector<int>> data;
  int temp;
  int i = 0; // row
  int j = 0; // column
  string fileName;
  // Get info from user
  std::cout << "Number of rows: " << '\n';
  std::cin >> rows;

  std::cout << "Number of Columns: " << '\n';
  std::cin >> columns;

  std::cout << "File Name: " << '\n';
  std::cin >> fileName;

  // Open and load data
  inFS.open(fileName);
  if (!inFS.is_open()) {
        cout << "Could not open file" << endl;
     }

 for (i = 0; i < rows; ++i) {
     vector<int> row;

   for (j = 0; j < columns; ++j) {
     inFS >> temp;
     row.push_back(temp);
   }
   data.push_back(row);
 }
 /* TESTING - Output data
 int w = 3;
 for (int i = 0; i < rows; ++i) {
     cout << (i+1) << setw(w) << "|";
   for (int j = 0; j < columns; ++j) {
       cout << setw(w);
       cout <<  data.at(i).at(j);
   }
   cout << endl;
 }
 cout << endl;
 */

  // Step 5: close (Do nothing will automatically close when stream variable is destroyed.)
  //inFS.close(fileName);
  return data;
}

int Extrema(int option, vector<vector<int>> v, int rows, int columns) {
  int Extreme = v.at(0).at(0);
  // 1 is Max 0 is Min
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
        if (option == 1 && v.at(i).at(j) > Extreme) {
          Extreme = v.at(i).at(j);
        } else if (option == 0 && v.at(i).at(j) < Extreme) {
          Extreme = v.at(i).at(j);
        }
    }
  }
  return Extreme;
}
