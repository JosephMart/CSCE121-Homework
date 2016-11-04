#include <iostream>
#include "store.h"

int main() {
  Product p = Product(777,"Basketballs");
  Product p1 = Product(555,"Volleyballs");
  // cout << p << endl;
  // cout << p1 << endl;
  //
  Customer c("Old ag", 123);
  Customer c1("Rev", 456);
  // std::cout << c << std::endl;
  // std::cout << c1 << std::endl;

  c.processPurchase(50, p);
  c.processPurchase(50, p1);
  c.listProductsPurchased(cout);
  // Store s = Store("Da Store");
  // s.addProduct(123, "Volleyballs");
  // s.addCustomer(111, "Joseph");
  //
  // std::cout << "Store Name: " << s.getName() << std::endl;
}
