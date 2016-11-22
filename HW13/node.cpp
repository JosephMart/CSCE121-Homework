#include "node.h"

ostream& operator<<(ostream& os, const Node& n) {
	os << n.data;
	return os;
}
