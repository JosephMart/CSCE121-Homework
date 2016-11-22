#pragma once

#include <iostream>
using namespace std;

struct Data {
	Data();
	Data(int location, int year, int month, double temperature);

	bool operator<(const Data& d) const;

	int location;
	int year;
	int month;
	double temperature;
};

istream& operator>>(istream& is, Data& d);
ostream& operator<<(ostream& os, const Data& d);
