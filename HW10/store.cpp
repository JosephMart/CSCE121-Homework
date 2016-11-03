/*******************************************************************************
* store.cpp                                                                    *
*******************************************************************************/
#include "store.h"

// Store::Store() : name("Null");
// Store(string name = "null") : name(name);
Store::Store() : storeName("null") {}
Store::Store(string name) : storeName(name) {}

void Store::addProduct(int productID, string productName) {
  Product p = Product(productID, productName);
  listProducts.push_back(p);
}

void Store::addCustomer(int customerID, string customerName) {
  Customer c = Customer(customerName, customerID);
  listCustomers.push_back(c);
}
