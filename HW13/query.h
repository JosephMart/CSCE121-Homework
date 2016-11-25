#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
using namespace std;

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
