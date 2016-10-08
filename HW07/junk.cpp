#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;



int printValues(int x, int y=10)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    return 0;
}

int main()
{
    int x = printValues(1); // y will use default parameter of 10
    int y = printValues(3, 4); // y will use user-supplied value 4
    return 0;
}
