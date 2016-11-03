/*******************************************************************************
* customer.cpp                                                                 *
*******************************************************************************/
// #include "product.h"
#include "customer.h"
using namespace std;
#include <iostream>

Customer::Customer() : customerName("Null"), customerID(0), credit("false"),
  balance(0) {}

Customer::Customer ( string name, int ID, bool cred) :
  customerName(name), customerID(ID), credit(cred) {}

void Customer::processPayment( double amount ) {
  // Add amount to balance.
  this->balance += amount;
  // If amount is negative, throw an exception.
}

void Customer::processPurchase( double amount, Product product) {
  // If the customer has credit: subtract amount from balance. Recall that balance
  // can be negative if credit is true.
  // If the customer does not have credit: if the balance is greater than or equal
  // to the amount then subtract amount from balance. Otherwise throw an exception.
  // Recall, balance is not allowed to be negative if credit is false.
  // Regardless of credit, if the purchase occurs, then add product to
  // productsPurchased if it is not already there. If amount is negative, throw an exception.
  if (credit) {
    balance -= amount;
  } else {
    if (balance >= amount) {
      balance -= amount;
    } else {
      cout << "Not enough monies" << endl;
    }
  }
  productsPurchased.push_back(product);

}

// Create overloaded output operators for the Product and Customer classes.
// Recall, these are helpers for those classes. So the function declaration
// should go in the header (.h) file for the corresponding class. The function
// definition should go in the cpp file of the corresponding class.
void Customer::listProductsPurchased(ostream& os) {

}
