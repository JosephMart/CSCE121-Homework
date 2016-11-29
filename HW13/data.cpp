#include "data.h"
#include <stdexcept>

Data::Data() {}

Data::Data(int location, int year, int month, double temperature)
	: location(location), year(year), month(month), temperature(temperature)
{}

bool Data::operator<(const Data& d) const {
	if (location < d.location) return true;
	else if (location == d.location) {
		if (year < d.year) return true;
		else if (year == d.year) {
			if (month < d.month) return true;
			else if (month == d.month) return temperature < d.temperature;
			else return false;
		}
		else return false;
	}
	else return false;
}

istream& operator>>(istream& is, Data& d) {
	is >> d.location >> d.year >> d.month >> d.temperature;
	return is;
}

ostream& operator<<(ostream& os, const Data& d) {
	os << d.location << ' ' << d.year << ' ' << d.month << ' ' << d.temperature;
	return os;
}

// Query struct

Query::Query() {}

Query::Query(int location, string avgMode, int year0, int year1)
	: location(location), avgMode(avgMode), year0(year0), year1(year1), tempAvg(1773)
{}

istream& operator>>(istream& is, Query& q) {
	is >> q.location >> q.avgMode >> q.year0 >> q.year1;
	if (q.year0 < 1800 || q.year0 > 2016 || q.year1 < 1800 || q.year1 > 2016 || q.location == 0 || q.avgMode == "" || isdigit(q.avgMode[0])) {
		throw runtime_error("Failed to run query" );
	}
	return is;
}

ostream& operator<<(ostream& os, const Query& q) {
	os << q.location << ' ' << q.year0 << ' ' << q.year1 << ' ' << q.avgMode << ' ';

	if (q.tempAvg == 1773 || q.tempAvg != q.tempAvg) {
		os << "unknown";
	} else {
		os << q.tempAvg;
	}


	return os;
}
