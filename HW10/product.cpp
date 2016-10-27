/*******************************************************************************
* product.cpp                                                                  *
*******************************************************************************/
#include "product.h"

Product::Product() : productID(0), productName("Null"), description("Null"),
  inventory(0), numSold(0), totalPaid(0) {}

Product::Product(int productID, string productName) : productID(productID),
  productName(productName) {}


// Product(int productID, string productName);
// string getDescription();
// void setDescription(string description);
// string getName();
// int getID();
// int getNumberSold();
// double getTotalPaid();
// int getInventoryCount();
