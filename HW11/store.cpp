/*******************************************************************************
* store.cpp                                                                    *
*******************************************************************************/
#include "store.h"
#include <stdexcept>

Store::Store() : storeName("null") {}
Store::Store(string name) : storeName(name) {}

void Store::addProduct(int productID, string productName) {
  for (int i = 0; i < listProducts.size(); i++) {
    if (listProducts.at(i).getName() == productName || listProducts.at(i).getID() == productID ) {
      throw runtime_error("");
    }
  }
  Product p = Product(productID, productName);
  listProducts.push_back(p);
}

void Store::addCustomer(int customerID, string customerName) {
  for (int i = 0; i < listCustomers.size(); i++) {
    if (listCustomers.at(i).getName() == customerName || listCustomers.at(i).getID() == customerID ) {
      throw runtime_error("");
    }
  }
  Customer c = Customer(customerName, customerID);
  listCustomers.push_back(c);
}
