#include "query.h"

Query::Query() {}

Query::Query(int location, string avgMode, int year0, int year1)
	: location(location), avgMode(avgMode), year0(year0), year1(year1), tempAvg(1773)
{}

istream& operator>>(istream& is, Query& q) {
	is >> q.location >> q.avgMode >> q.year0 >> q.year1;
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
