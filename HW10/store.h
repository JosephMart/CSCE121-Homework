/*******************************************************************************
* store.h                                                                      *
*******************************************************************************/
#ifndef STORE_H
#define STORE_H
#include "customer.h"
#include "product.h"
#include <vector>

class Store {
  public:
    Store();
    Store(string name);
    string getName() { return storeName; }
    void setName( string name ) { storeName = name; }
    void addProduct(int productID, string productName);
    void addCustomer(int customerID, string customerName);
    //Customer getCustomer(int customerID);
    // void listCustomers();
    // void listProducts();
  private:
    string storeName;
    string productName;
    string customerName;
    int productID;
    int customerID;
    vector<Product> productList;
    vector<Customer> customerList;
};

#endif
