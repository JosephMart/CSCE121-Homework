// Homework 02
// Written by Joseph Martinsen
// CSCE 121-
// Dr. John Moore

using namespace std;
#include <iostream>
#include <string>
#include <cmath>

int main() {
	float a, b, c, dr, x0, x1;

	// Gather info from user
	cout << "Enter a, b, and c on a single line seperated by a space" << endl;
	cin >> a;
	cin >> b;
	cin >> c;


	// Determine if a = 0, if so solve linear equation
	if(a == 0 && b !=0 && c != 0) {
        cout <<  b << "x + " << c << " = 0" << endl;
        x0 = -c/b;
        cout << x0 << endl;
	} else if(b == 0) {
        cout << "Unable to determine root(s)." << endl;
	} else {
        cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
        // Calculate the Discriminate
        dr = pow(b, 2) - 4 * a*c;

        /*
            Determine what type of solution
            Positive = 2 real roots
            0 = There is one real root
            Negative = There are two complex roots
        */
        if (dr == 0) {
            // One real root
            x0 = (-b + sqrt(dr)) / (2 * a);
            cout << "x = " << x0;
        } else if (dr > 0) {
            // 2 real roots
            x0 = (-b - sqrt(dr)) / (2 * a);
            x1 = (-b + sqrt(dr)) / (2 * a);
            cout << "x = " << x0 << endl;
            cout << "x = " << x1 << endl;
        } else if (dr < 0) {
            // 2 complex roots
            float i0;
            x0 = -b / (2 * a);
            i0 = sqrt(-dr)/( 2* a);
            cout << "x = " << x0 << " - " << i0 << "i" << endl;
            cout << "x = " << x0 << " + " << i0 << "i" << endl;
        }
	}

	return 0;
}
