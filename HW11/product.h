/*******************************************************************************
* product.h                                                                    *
*******************************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

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
    double getPrice() const;
    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory( int quantity );
    friend std::ostream& operator<<(std::ostream& os, const Product& p);
  private:
    int productID = 0;
    string productName = " ";
    string description = " ";
    int inventory = 0;
    int numSold = 0;
    double totalPaid = 0.0;
};


#endif
