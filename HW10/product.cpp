/*******************************************************************************
* product.cpp                                                                  *
*******************************************************************************/
#include "product.h"
#include <iostream>
using namespace std;

Product::Product() : productID(0), productName("Null"), description("Null"),
  inventory(0), numSold(0), totalPaid(0) {}

Product::Product(int productID, string productName) : productID(productID),
  productName(productName) {}

double Product::getPrice() const {
  return (totalPaid / (inventory + numSold)) * 1.25;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost) {
  // Add shipmentQuantity to inventory and increase totalPaid by shipmentCost.
  // Do not replace totalPaid, just increase its value. If you get a negative
  // shipmentQuantity or a negative shipmentCost, throw an exception.
  inventory += shipmentQuantity;
  totalPaid += shipmentCost;
}




std::ostream& operator<<(std::ostream& os, const Product& p) {
    std::cout << "Product ID: " << p.productID << std::endl;
    std::cout << "Prodcut Name: " <<  p.productName << std::endl;
    std::cout << "Inventory: " << p.inventory << std::endl;
    std::cout << "Number Sold: " << p.numSold << std::endl;
    std::cout << "Price: " << p.getPrice() << std::endl;
    std::cout << "Description: " << p.description << std::endl;
}
