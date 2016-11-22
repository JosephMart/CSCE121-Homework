#include "data.h"

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
