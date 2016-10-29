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

// void processPayment(double amount);
// Add amount to balance. If amount is negative, throw an exception.
// void processPurchase(double amount, Product product);
// If the customer has credit: subtract amount from balance. Recall that balance
// can be negative if credit is true.
// If the customer does not have credit: if the balance is greater than or equal
// to the amount then subtract amount from balance. Otherwise throw an exception.
// Recall, balance is not allowed to be negative if credit is false.
// Regardless of credit, if the purchase occurs, then add product to
// productsPurchased if it is not already there. If amount is negative, throw an exception.
// void listProductsPurchased(ostream& os);
// Output information about each product purchased. While, not reflected in the
// UML, to allow for different output streams to function with it, we will pass
// in an ostream to use for the output. You should utilize the output operator
 // for product class in this function.
// Output Operators <<
//
// Create overloaded output operators for the Product and Customer classes. Recall, these are helpers for those classes. So the function declaration should go in the header (.h) file for the corresponding class. The function definition should go in the cpp file of the corresponding class.

#endif
