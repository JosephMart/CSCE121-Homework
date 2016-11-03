#include <iostream>
#include "product.h"
#include "customer.h"

int main() {
  Product p = Product(777,"Basketballs");
  Product p1 = Product(555,"Volleyballs");
  // cout << p << endl;

  Customer c("Old ag", 123);
  Customer c1("Rev", 456);
  std::cout << c << std::endl;
  std::cout << c1 << std::endl;

  c.processPurchase(50, p);
  c.processPurchase(50, p1);
  c.listProductsPurchased(cout);
}
