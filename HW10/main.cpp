/*******************************************************************************
* main.cpp                                                                     *
*******************************************************************************/
#include <iostream>
#include "store.h"

int main() {
  Store s("Aggie Stuff");
  s.addProduct(123, "Aggie hat");
  s.addCustomer(444, "Ole Sarge");
  s.addCustomer(555, "Rev");
  // try {
  //   Customer c1 = s.getCustomer(123);
  //   c1.setCredit(true);
  //   s.makePurchase(444, 123, 4);
  //
  //   Customer c2 = s.getCustomer(123);
  //   c2.makePayment(1500);
  //   c2.makePurchase(555, 123, 5);
  //
  //   s.listCustomers();
  //   s.listProducts();
  // }
  // catch (exception& e) {
  //   cout << e.what() << endl;
  // }
}
