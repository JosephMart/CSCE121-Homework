/*******************************************************************************
* product.h                                                                    *
*******************************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;
#include "store.h"

class Product {
  public:
    Product();
    Product(int productID, string productName);
    string getDescription() { return description; }
    void setDescription(string i) { description = i; }
    string getName() { return productName; }
    int getID() { return productID; }
    int getNumberSold() { return numSold; }
    double getTotalPaid() { return totalPaid; }
    int getInventoryCount() { return inventory; }
    double getPrice() { return (totalPaid / (inventory + numSold)) * 1.25;}
    void addShipment( int quantity, double shipmentCost) { totalPaid += shipmentCost;}
    void reduceInventory( int quanity ) { inventory -= quanity; }
  private:
    int productID = 0;
    string productName = "Null";
    string description = "Null";
    int inventory = 0;
    int numSold = 0;
    double totalPaid = 0.0;
};

// void addShipment(int shipmentQuantity, double shipmentCost);
// void reduceInventory(int purchaseQuantity);
// If there is not enough inventory, throw an exception. Otherwise, decrease inventory by purchaseQuantity and increase numSold by purchaseQuantity. If the purchaseQuantity is negative, throw an exception.
// double getPrice();
// This function will calculate the current price based on the average cost per item over time plus a 25% markup.
// price = (totalPaid / (inventory + numSold)) * 1.25.
// Warning: avoid integer division!

#endif
