/*******************************************************************************
* store.h                                                                      *
*******************************************************************************/
#ifndef STORE_H
#define STORE_H

using namespace std;
#include "product.h"
#include "customer.h"

class Store {
  public:
    Store();
    Store(string name = "null");

    string getName() {return storeName;}

    void setName(string name) {storeName = name;}
    void addProduct(int productID, string productName);
    void addCustomer(int customerID, string customerName);
    void takeShipment(int productID, int quantity, double cost);
    void makePurchase(int customerID, int productID, double quantity);
    void takePayment(int customerID, double amount);
    void listProducts() const;
    void listCustomers() const;

    Product& getProduct(int productID);
    Customer& getCustomer(int customerID);
  private:
    string storeName;
    vector<Product> listOfProducts;
    vector<Customer> listOfCustomers;
};

#endif
