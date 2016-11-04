/*******************************************************************************
* customer.cpp                                                                 *
*******************************************************************************/
// #include "product.h"
#include "customer.h"
#include <iostream>
using namespace std;

Customer::Customer() : customerName("Null"), customerID(0), credit("false"),
  balance(0) {}

Customer::Customer ( string name, int ID, bool cred) :
  customerName(name), customerID(ID), credit(cred) { ++customers;}

void Customer::processPurchase ( double amount, Product product) {
  if (credit) {
    balance -= amount;
  } else {
    if (balance > amount) {
      balance -= amount;
    } else {
      throw "Error";
    }
  }
  productsPurchased.push_back(product);
}

void Customer::processPayment( double amount ) {
  if (amount < 0) {
    throw "Amount is Negative";
  } else {
    balance += amount;
  }
}

void Customer::listProductsPurchased(ostream& os) {
  os << "Products bought by " << customerName << "(" << customerID << "):" << std::endl << endl;
  for (int i = 0; i <= customers; i++) {
    os << productsPurchased.at(i);
    os << std::endl;
  }
}

std::ostream& operator<<(std::ostream& os, const Customer& c) {
    os << "Customer Name: " << c.customerName << endl;
    os << "Customer ID: " << c.customerID << "\n";
    os << "Credit: " << c.credit << endl;
    os << "Balance: " << c.balance << endl;
    return os;
}
