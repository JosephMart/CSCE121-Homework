/*******************************************************************************
* customer.cpp                                                                 *
*******************************************************************************/
// #include "product.h"
#include "customer.h"

Customer::Customer() : customerName("Null"), customerID(0), credit("false"),
  balance(0) {}

Customer::Customer ( string name, int ID, bool cred) :
  customerName(name), customerID(ID), credit(cred) {}

// Customer(string name, int customerID, bool credit);
// Credit means that the customer's balance is allowed to become negative. If they have credit and they make a purchase with insufficient funds in their balance, the purchase is allowed. Otherwise, they are limited to purchases that can be paid by their balance.
// string getName();
// void setName(string name);
// int getID();
// bool getCredit();
// void setCredit(bool hasCredit)
// double getBalance();
