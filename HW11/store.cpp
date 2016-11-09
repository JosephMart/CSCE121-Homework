/*******************************************************************************
* store.cpp                                                                    *
*******************************************************************************/
#include "store.h"
#include <iostream>
#include <stdexcept>

Store::Store() : storeName("null") {}
Store::Store(string name) : storeName(name) {}

void Store::addProduct(int productID, string productName) {
  for (int i = 0; i < listOfProducts.size(); i++) {
    if (listOfProducts.at(i).getName() == productName || listOfProducts.at(i).getID() == productID ) {
      throw runtime_error("");
    }
  }
  Product p = Product(productID, productName);
  listOfProducts.push_back(p);
}

void Store::addCustomer(int customerID, string customerName) {
  for (int i = 0; i < listOfCustomers.size(); i++) {
    if (listOfCustomers.at(i).getName() == customerName || listOfCustomers.at(i).getID() == customerID ) {
      throw runtime_error("");
    }
  }
  Customer c = Customer(customerName, customerID);
  listOfCustomers.push_back(c);
}

Product& Store::getProduct(int productID) {
  for (int i = 0; i < listOfProducts.size(); i++) {
    if (productID == listOfProducts.at(i).getID()) {
      return listOfProducts.at(i);
    }
  }
  throw runtime_error("");
}

Customer& Store::getCustomer(int customerID) {
  for (int i = 0; i < listOfCustomers.size(); i++) {
    if (customerID == listOfCustomers.at(i).getID()) {
      return listOfCustomers.at(i);
    }
  }
  throw runtime_error("");
}

void Store::takeShipment(int productID, int quantity, double cost) {
  getProduct(productID).addShipment(quantity, cost);
}

void Store::makePurchase(int customerID, int productID, double quantity) {
  getCustomer(customerID).processPurchase(quantity, getProduct(productID));
}

void Store::takePayment(int customerID, double amount) {
  getCustomer(customerID).processPayment(amount);
}

void Store::listProducts() const {
  for (int i = 0; i < listOfProducts.size(); i++) {
    cout << listOfProducts.at(i) << endl;
  }
}

void Store::listCustomers() const {
  for (int i = 0; i < listOfCustomers.size(); i++) {
    cout << listOfCustomers.at(i) << endl;
  }
}
