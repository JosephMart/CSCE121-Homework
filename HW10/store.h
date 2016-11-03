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
  private:
    string storeName;
    vector<Product> listProducts;
    vector<Customer> listCustomers;
};

#endif

// Store();
// Store(string name);
// string getName();
// void setName(string name);
// void addProduct(int productID, string productName);
// Create a new Product and add it to products. If this productID already belongs
// to another product, throw an exception.
// void addCustomer(int customerID, string customerName);
// Create a new Customer and add it to customers. If this customerID already belongs
// to another customer, throw an exception.
