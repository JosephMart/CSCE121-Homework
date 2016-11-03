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

void Customer::processPurchase( double amount, Product product) {
  balance -= amount;
  productsPurchased.push_back(product);
}

void Customer::processPayment( double amount ) {
  // void processPayment(double amount);
  // Add amount to balance. If amount is negative, throw an exception
  balance -= amount;
}

void Customer::listProductsPurchased(ostream& os) {
  std::cout << "Products bought by " << customerName << "(" << customerID << "):" << std::endl << endl;
  for (int i = 0; i <= customers; i++) {
    cout << productsPurchased.at(i);
    std::cout << std::endl;
  }
}

std::ostream& operator<<(std::ostream& os, const Customer& c) {
    cout << "Customer ID: " << c.customerID << "\n";
    cout << "Customer Name: " << c.customerName << endl;
    cout << "Credit: " << c.credit << endl;
    std::cout << "Balance: " << c.balance << endl;
}
