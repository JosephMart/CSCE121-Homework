#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

// Declare functions
vector<vector<int>> loadData(int& rows, int& columns, string& fileName);

int Extrema(int option, vector<vector<int>> v, int rows, int columns);
vector<vector<int>> RGB(vector<vector<int>> v, int rows, int columns, int min,
  int max);

void outputData(vector<vector<int>> r, vector<vector<int>> g,
  vector<vector<int>> b, int rows, int columns, string fileName);

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
  vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
  int color_b, int start_row);



int main() {
  vector<vector<int>> data;
  vector<vector<int>> red;
  vector<vector<int>> green;
  vector<vector<int>> blue;
  int rows;
  int columns;
  string fileName;

  data = loadData(rows, columns, fileName);
  int Max = Extrema(1, data, rows, columns);
  int Min = Extrema(0, data, rows, columns);
  red = RGB(data, rows, columns, Min, Max);
  green = RGB(data, rows, columns, Min, Max);
  blue = RGB(data, rows, columns, Min, Max);

  // Add func to change colors for three different paths
    // First row (row index 0)
    // Middle row (row index numRows/2 - don't forget this is integer division)
    // Last row (row index numRows -1)
  // Colors of path
  int color_r = 252;
  int color_g = 25;
  int color_b = 63;
  int start_row_top = 0;
  int start_row_mid = (rows-1)/2;
  int start_row_bot = rows-1;
  //
  int topD = colorPath(data, red, green, blue, color_r, color_g, color_b, start_row_top);
  int midD = colorPath(data, red, green, blue, color_r, color_g, color_b, start_row_mid);
  int botD = colorPath(data, red, green, blue, color_r, color_g, color_b, start_row_bot);
  outputData(red, green, blue, rows, columns, fileName);

  return 0;
}

vector<vector<int>> loadData(int& rows, int& columns, string& fileName) {
  ifstream inFS;
  vector<vector<int>> data;
  int temp;
  int i = 0; // row
  int j = 0; // column

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

vector<vector<int>> RGB(vector<vector<int>> v, int rows, int columns, int min, int max) {
  vector<vector<int>> colors;
  // Color value = ((float)x-(float)Min)/((float)Max-(float)Min)
  for (int i = 0; i < rows; ++i) {
    vector<int> row;
    for (int j = 0; j < columns; ++j) {
      row.push_back((((float)v.at(i).at(j) - (float)min)/((float)max-(float)min))*255.0);
    }
    colors.push_back(row);
  }
  return colors;
}

void outputData(vector<vector<int>> r, vector<vector<int>> g, vector<vector<int>> b, int rows, int columns, string fileName) {
  ofstream outFS;
  string ext = ".ppm";
  fileName.append(ext);
  outFS.open(fileName);
  if (!outFS.is_open()) {
    std::cout << "File output stream did not open" << '\n';
  }

  // Header info
  outFS << "P3" << endl;
  outFS << columns << " " << rows << endl;
  outFS << 255 << endl;

  // Output values
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      outFS << r.at(i).at(j) << " ";
      outFS << g.at(i).at(j) << " ";
      outFS << b.at(i).at(j) << " ";
    }
    outFS << endl;
  }
  return;
}

// Output distance and change colors
int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
  vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
  int color_b, int start_row) {

    int j = 0;
    int i = start_row;
    int diff0, diff1, diff2 = 0;
    int minNum;
    int distance = 0;

    while (j < heightMap[0].size()-1) {
//      cout << heightMap[0].size() << endl;
      bool unique = false;
      abs(heightMap.at(i).at(j) - heightMap.at(i).at(j+1));
      if (i < 2) {
        // Check column values of 1 and 2
          diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i).at(j+1));
          diff2 = abs(heightMap.at(i).at(j) - heightMap.at(i+1).at(j+1));
          minNum = min(diff1, diff2);

          if (diff2 > diff1) {
            ++i;
          }

      } else if (i == heightMap.size()-1) {
        // Check column values of row and row - 1
        diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j+1));
        diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i).at(j+1));
        minNum = min(diff0, diff1);

        if (diff0 > diff1) {
          --i;
        }
      } else {
        diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j+1));
        diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i).at(j+1));
        diff2 = abs(heightMap.at(i).at(j)- heightMap.at(i+1).at(j+1));
        minNum = min(diff0, min(diff1, diff2));
        // Check if unique

        if (diff0 != diff1 && diff0 != diff1 && diff1 != diff2) {
          unique = true;
        }

        if ((minNum == diff0) && unique) {
          --i;
        } else if ( ( (minNum == diff2) && unique) || (diff0 == diff2)){
          ++i;
        }
      }
      distance += minNum;      
      r.at(i).at(j) = color_r;
      g.at(i).at(j) = color_g;
      b.at(i).at(j) = color_b;
      ++j;
    }
    return distance;
  }
