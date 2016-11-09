/*******************************************************************************
* customer.cpp                                                                 *
*******************************************************************************/
// #include "product.h"
#include "customer.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Customer::Customer() : customerName("Null"), customerID(0), credit("false"),
  balance(0) {}

Customer::Customer ( string name, int ID, bool cred) :
  customerName(name), customerID(ID), credit(cred) { ++customers;}

void Customer::processPurchase ( double amount, Product& product) {
  if (amount < 0 || amount > product.getInventoryCount()){
    throw runtime_error("");
  }
  else {
    if (credit) {
      balance -= amount * product.getPrice();
    } else {
      if (balance >= amount * product.getPrice()) {
        balance -= amount * product.getPrice();
      } else {
        throw runtime_error("");
      }
    }
  }
  product.reduceInventory(amount);
  productsPurchased.push_back(product);
}
void Customer::processPayment( double amount ) {
  if (amount < 0) {
    throw runtime_error("");
  } else {
    balance += amount;
  }
}

void Customer::listProductsPurchased(ostream& os) {
  for (int i = 0; i < productsPurchased.size(); i++) {
    os << productsPurchased.at(i);
    os << std::endl;
  }
}

std::ostream& operator<<(std::ostream& os, const Customer& c) {
    os << "Customer Name: " << c.customerName << "\n";
    os << "Customer ID: " << c.customerID << "\n";
    os << "Credit: " << c.credit << "\n";
    os << "Balance: " << c.balance << "\n";
    return os;
}
