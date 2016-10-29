/*******************************************************************************
* customer.cpp                                                                 *
*******************************************************************************/
// #include "product.h"
#include "customer.h"

Customer::Customer() : customerName("Null"), customerID(0), credit("false"),
  balance(0) {}

Customer::Customer ( string name, int ID, bool cred) :
  customerName(name), customerID(ID), credit(cred) {}
