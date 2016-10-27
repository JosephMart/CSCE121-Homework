#include <iostream>
using namespace std;

#include "product.h"
#include "customer.h"

int main() {
 Product p = Product(777,"A Name");
 cout << "ID: " << p.getID() << endl;
 cout << "ProductName: " << p.getName() << endl;
 cout << "description: " << p.getDescription() << endl;
 p.setDescription("set description");
 cout << "description: " << p.getDescription() << endl;

 cout << endl << endl << endl; // Test Customer CLass

 Customer c = Customer("Joseph", 1234, "true");

 cout << "Name: " << c.getName() << endl;

}
