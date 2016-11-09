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
    Customer ( string name = "Null", int ID = 0, bool cred = false);

    string getName() const { return customerName; }
    void setName( string name ) { customerName = name; }
    int getID() const { return customerID; }
    bool getCredit() const { return credit; }
    void setCredit( bool credit ) { this->credit = credit; }
    double getBalance() const { return balance; }
    void listProductsPurchased(ostream& os);
    void processPayment(double amount);
    void processPurchase(double amount, Product& product);
    friend std::ostream& operator<<(std::ostream& os, const Customer& c);
  private:
    string customerName;
    int customerID;
    int customers = 0;
    bool credit;
    double balance = 0.0;
    vector<Product> productsPurchased;
};
#endif
