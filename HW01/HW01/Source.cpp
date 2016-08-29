// Homework 1
// Written by Joseph Martinsen
// August 29th, 2016
// CSCE 121-504
// Dr. John Moore

using namespace std;
#include <iostream>
#include <string>

int main()
{
	string firstName, lastName;
	float birth, feet, inches, avgGrowth;

	cout << "What is your first name: ";
	cin >> firstName;

	cout << "What is your last name: ";
	cin >> lastName;

	cout << "What is your birth year: ";
	cin >> birth;

	cout << "What is your height?\nFeet: ";
	cin >> feet;

	cout << "Inches: ";
	cin >> inches;

	avgGrowth = ((feet * 12) + inches)*2.54 / (2016 - birth);

	cout << "Hello " << firstName << " " << lastName << ". You were " << 2016 - birth
		<< " years old in 2016, and your height is " << ((feet * 12) + inches)*2.54 <<
		" cm. \nThat means you grew an average of " << avgGrowth << " cm per year. (Assuming that you were 51 cm at brith)";


	system("PAUSE");

	return 0;
}
