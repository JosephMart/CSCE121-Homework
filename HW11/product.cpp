/*******************************************************************************
* product.cpp                                                                  *
*******************************************************************************/
#include "product.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Product::Product() : productID(0), productName("Null"), description("Null"),
  inventory(0), numSold(0), totalPaid(0) {}

Product::Product(int productID, string productName) : productID(productID),
  productName(productName) {}

double Product::getPrice() const {
  if ((inventory + numSold) == 0 ) {
    return 0;
  } else {
    return (totalPaid / (static_cast<double>(inventory + numSold))) * 1.25;
  }
}

void Product::addShipment(int shipmentQuantity, double shipmentCost) {
  if (shipmentQuantity >= 0 && shipmentCost >= 0) {
    inventory += shipmentQuantity;
    totalPaid += shipmentCost;
  } else {
    throw runtime_error("");
  }
}

void Product::reduceInventory( int quantity ) {
    if(quantity < inventory && quantity > 0 ) {
    	inventory -= quantity;
      numSold += quantity;
    } else {
        throw runtime_error("");
    }
}


std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << "Product ID: " << p.productID << std::endl;
    os << "Prodcut Name: " <<  p.productName << std::endl;    
    return os;
}
