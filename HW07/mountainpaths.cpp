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
  int color_b, int start_row, int start_col = 0);

void pathNorth(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
  vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
  int color_b, int start_row, int start_col);

void pathSouth(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
  vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
  int color_b, int start_row, int start_col);

void pathEast(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
  vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
  int color_b, int start_row, int start_col);

void pathWest(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
  vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
  int color_b, int start_row, int start_col);

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

  // Color for Red
  int color_r = 252;
  int color_g = 25;
  int color_b = 63;
  int pathLength = 0;
  int pathMin = colorPath(data, red, green, blue, color_r, color_g, color_b, 0);
  int greenRow = 0;

  // Change all shortests paths to red
  for (int i = 0; i < data.size(); i++) {
    pathLength = colorPath(data, red, green, blue, color_r, color_g, color_b, i);
    if (pathLength < pathMin) {
      greenRow = i;
      pathMin = pathLength;
    }
  }

  // Set shortest path to Green
  colorPath(data, red, green, blue, 31, 253, 13, greenRow);

  // handle the extra input
  int start_row, start_col;

  // This line tries to read two more integers from cin, and assigns false to has_extra_input if the read fails
  // bool has_extra_input = (cin >> start_row >> start_col);
  cin >> start_row >> start_col;

  // if (has_extra_input) {
  //   colorPath(data, red, green, blue, 19, 254, 253, start_row, start_col);
  // }
  colorPath(data, red, green, blue, 19, 254, 253, start_row, start_col);

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
  cout << "Number of rows: " << '\n';
  cin >> rows;

  cout << "Number of Columns: " << '\n';
  cin >> columns;

  cout << "File Name: " << '\n';
  cin >> fileName;

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
  int color_b, int start_row, int start_col) {

    int j = 0;
    int i = start_row;
    int diff0 = 0;
    int diff1 = 0;
    int diff2 = 0;
    int minNum;
    int distance = 0;

    if (start_col != 0) {
      pathNorth(heightMap, r, g, b, color_r, color_g, color_b, start_row, start_col);
      pathSouth(heightMap, r, g, b, color_r, color_g, color_b, start_row, start_col);
      pathEast(heightMap, r, g, b, color_r, color_g, color_b, start_row, start_col);
      pathWest(heightMap, r, g, b, color_r, color_g, color_b, start_row, start_col);
    } else {
      r.at(start_row).at(0) = color_r;
      g.at(start_row).at(0) = color_g;
      b.at(start_row).at(0) = color_b;

      while (j < heightMap[0].size()-1) {
        if (i <= 0) {
          diff1 = abs(heightMap.at(0).at(j) - heightMap.at(0).at(j+1));
          diff2 = abs(heightMap.at(0).at(j) - heightMap.at(1).at(j+1));
          diff0 = max(diff1,diff2) +   1;
        } else if (i >= heightMap.size()-1) {
          // Check column values of row and row - 1
          diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j+1));
          diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i).at(j+1));
          diff2 = max(diff0, diff1) + 1;
        } else {
          diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j+1));
          diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i).at(j+1));
          diff2 = abs(heightMap.at(i).at(j)- heightMap.at(i+1).at(j+1));
        }

        minNum = min(diff0, min(diff1, diff2));

        if ((minNum == diff0) && (diff0 != diff1) && (diff0 != diff2)) {
          --i;
        } else if ( ((minNum == diff2) && (diff1 != diff2)) || (diff0 == diff2 && (diff2 < diff1))) {
          ++i;
        }

        distance += minNum;
        r.at(i).at(j+1) = color_r;
        g.at(i).at(j+1) = color_g;
        b.at(i).at(j+1) = color_b;
        ++j;
      }
    }
    return distance;
  }

  void pathNorth(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
    vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
    int color_b, int start_row, int start_col) {

      int j = start_col;
      int i = start_row;
      int diff0 = 0;
      int diff1 = 0;
      int diff2 = 0;
      int minNum;
      r.at(start_row).at(start_col) = color_r;
      g.at(start_row).at(start_col) = color_g;
      b.at(start_row).at(start_col) = color_b;

      while (i > 0 ) {
          diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j-1));
          diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j));
          diff2 = abs(heightMap.at(i).at(j)- heightMap.at(i-1).at(j+1));

        minNum = min(diff0, min(diff1, diff2));

        if ((minNum == diff0) && (diff0 != diff1) && (diff0 != diff2)) {
          --j;
        } else if ( ((minNum == diff2) && (diff1 != diff2)) || (diff0 == diff2 && (diff2 < diff1))) {
          ++j;
        }

        --i;
        r.at(i).at(j) = color_r;
        g.at(i).at(j) = color_g;
        b.at(i).at(j) = color_b;
      }
    }

    void pathSouth(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
      vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
      int color_b, int start_row, int start_col) {

        int j = start_col;
        int i = start_row;
        int diff0 = 0;
        int diff1 = 0;
        int diff2 = 0;
        int minNum;
        r.at(start_row).at(start_col) = color_r;
        g.at(start_row).at(start_col) = color_g;
        b.at(start_row).at(start_col) = color_b;

        while (i < heightMap.size()-1 ) {
            diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i+1).at(j-1));
            diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i+1).at(j));
            diff2 = abs(heightMap.at(i).at(j)- heightMap.at(i+1).at(j+1));

          minNum = min(diff0, min(diff1, diff2));

          if ((minNum == diff0) && (diff0 != diff1) && (diff0 != diff2)) {
            --j;
          } else if ( ((minNum == diff2) && (diff1 != diff2)) || (diff0 == diff2 && (diff2 < diff1))) {
            ++j;
          }

          ++i;
          r.at(i).at(j) = color_r;
          g.at(i).at(j) = color_g;
          b.at(i).at(j) = color_b;
        }
      }

    void pathEast(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
      vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
      int color_b, int start_row, int start_col) {

        int j = start_col;
        int i = start_row;
        int diff0 = 0;
        int diff1 = 0;
        int diff2 = 0;
        int minNum;
        r.at(start_row).at(start_col) = color_r;
        g.at(start_row).at(start_col) = color_g;
        b.at(start_row).at(start_col) = color_b;

        while (j < heightMap.at(0).size() ) {
            diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j+1));
            diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i).at(j+1));
            diff2 = abs(heightMap.at(i).at(j)- heightMap.at(i+1).at(j+1));

          minNum = min(diff0, min(diff1, diff2));

          if ((minNum == diff0) && (diff0 != diff1) && (diff0 != diff2)) {
            --i;
          } else if ( ((minNum == diff2) && (diff1 != diff2)) || (diff0 == diff2 && (diff2 < diff1))) {
            ++i;
          }

          ++j;
          r.at(i).at(j) = color_r;
          g.at(i).at(j) = color_g;
          b.at(i).at(j) = color_b;
        }
      }

      void pathWest(const vector<vector<int>>& heightMap, vector<vector<int>>& r,
        vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
        int color_b, int start_row, int start_col) {

          int j = start_col;
          int i = start_row;
          int diff0 = 0;
          int diff1 = 0;
          int diff2 = 0;
          int minNum;
          r.at(start_row).at(start_col) = color_r;
          g.at(start_row).at(start_col) = color_g;
          b.at(start_row).at(start_col) = color_b;

          while (j > 0 ) {
              diff0 = abs(heightMap.at(i).at(j) - heightMap.at(i-1).at(j-1));
              diff1 = abs(heightMap.at(i).at(j) - heightMap.at(i).at(j-1));
              diff2 = abs(heightMap.at(i).at(j)- heightMap.at(i+1).at(j-1));

            minNum = min(diff0, min(diff1, diff2));

            if ((minNum == diff0) && (diff0 != diff1) && (diff0 != diff2)) {
              --i;
            } else if ( ((minNum == diff2) && (diff1 != diff2)) || (diff0 == diff2 && (diff2 < diff1))) {
              ++i;
            }

            --j;
            r.at(i).at(j) = color_r;
            g.at(i).at(j) = color_g;
            b.at(i).at(j) = color_b;
          }
        }
