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
	// Initialize Variables
	string firstName, lastName;
	float birth, feet, inches, avgGrowth, userHeight, age;

	// Gather required information from the user
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

	// Calculate info
	userHeight = ((feet * 12) + inches)*2.54;
	age = 2016 - birth;
	avgGrowth = userHeight / age;
	
	// Output info to user
	cout << "Hello " << firstName << " " << lastName << ". You were " << age
		<< " years old in 2016, and your height is " << userHeight <<
		" cm. \nThat means you grew an average of " << avgGrowth << " cm per year. (Assuming that you were 51 cm at brith)";

	// Need to get rid of
	system("PAUSE");

	return 0;
}
