/*******************************************************************************
* product.cpp                                                                  *
*******************************************************************************/
#include "product.h"

Product::Product() : productID(0), productName("Null"), description("Null"),
  inventory(0), numSold(0), totalPaid(0) {}

Product::Product(int productID, string productName) : productID(productID),
  productName(productName) {}
