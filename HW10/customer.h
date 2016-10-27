/*******************************************************************************
* customer.h                                                                   *
*******************************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std;
#include "product.h"
#include <vector>

class Customer {
  public:
    Customer ();
    Customer ( string name, int ID, bool cred);
    string getName() { return customerName; }
    void setName( string name ) { customerName = name; }
    int getID() { return customerID; }
    bool getCredit() { return credit; }
    void setCredit( bool credit ) { this->credit = credit; }
    double getBalance() { return balance; }
    // + listProductsPurchased()
    // + processPayment(amount)
    // + processPurchase(amount, product)
  private:
    string customerName = "Null";
    int customerID = 0;
    bool credit = "false";
    double balance = 0.0;
    // - productsPurchased : list of Product
    vector<Product> productsPurchased;
};

#endif
