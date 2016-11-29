#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
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

struct Query {
	Query();
	Query(int location, string avgMode, int year0, int year1);

	// bool operator<(const Query& d) const;

	int location;
	string avgMode;
	int year0;
	int year1;
	double tempAvg;
};

istream& operator>>(istream& is, Query& q);
ostream& operator<<(ostream& os, const Query& q);

#endif
