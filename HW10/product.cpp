/*******************************************************************************
* product.cpp                                                                  *
*******************************************************************************/
#include "product.h"
#include <iostream>
#include <exception>
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
  // Add shipmentQuantity to inventory and increase totalPaid by shipmentCost.
  // Do not replace totalPaid, just increase its value. If you get a negative
  // shipmentQuantity or a negative shipmentCost, throw an exception.
  if (shipmentQuantity < 0) {
    throw "Negative shipment";
  } else {
    inventory += shipmentQuantity;
    totalPaid += shipmentCost;
  }
}

void Product::reduceInventory( int quanity ) {
  if (quanity > inventory || quanity < 0) {
    throw "Not enough inventory";
  } else {
    inventory -= quanity;
  }
}


std::ostream& operator<<(std::ostream& os, const Product& p) {
    os << "Product ID: " << p.productID << std::endl;
    os << "Prodcut Name: " <<  p.productName << std::endl;
    os << "Inventory: " << p.inventory << std::endl;
    os << "Number Sold: " << p.numSold << std::endl;
    os << "Price: " << p.getPrice() << std::endl;
    os  << "Description: " << p.description << std::endl;
    return os;
}
