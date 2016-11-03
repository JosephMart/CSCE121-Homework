/*******************************************************************************
* store.cpp                                                                    *
*******************************************************************************/
#include "store.h"

Store::Store() : storeName("Null") {}

Store::Store ( string name ) : storeName(name) {}

void addProduct(int productID, string productName) {
  // Create a new Product and add it to products. If this productID already
  // belongs to another product, throw an exception.
  Product p(productID, productName);
  productList.push_back(p);

}

void addCustomer(int customerID, string customerName) {
  // Create a new Customer and add it to customers. If this customerID already
  // belongs to another customer, throw an exception
  Customer c(customerID, customerName, false);
  customerList.push_back(c);

}
