#include <iostream>
#include "store.h"

int main() {
  Product p(123, "Volleyballs");
  Product p2(456, "Basketballs");
  Customer c("Joseph", 123, true);

  p.addShipment( 10, 12.5);
  c.processPurchase(2, p);
  c.processPurchase(4, p2);
  c.listProductsPurchased(cout);
}
