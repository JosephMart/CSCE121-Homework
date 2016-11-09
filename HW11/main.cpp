#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include "store.h"
#include "customer.h"
#include "product.h"
using namespace std;

int main(int argc, char const *argv[]) {
	Store store = Store("Old Army Shop");

	// Check initializatin of store and set name
	std::cout << "Store Name: " << store.getName() <<std::endl;
	store.setName("Old Army Store");
	std::cout << "Store Name*: " << store.getName() <<std::endl;

	// Add Prodcuts and Customers
	store.addCustomer(123, "Joseph");
	store.addCustomer(456, "Michelle");
	store.addCustomer(789, "Marie");
	store.addProduct(111, "Basketball(s)");
	store.addProduct(222, "Volleyball(s)");
	store.addProduct(333, "Steak(s)");

	std::cout << "List of Products" << std::endl;
	store.listProducts();
	std::cout << "List of Customers" << std::endl;
	store.listCustomers();
	return 0;
}
