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
