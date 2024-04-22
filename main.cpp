#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   /* Type your code here */
   cout << "MENU"
   cout << "a - Add item to cart" << endl;
   cout << "b - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   /* Type your code here */
   
}

int main() {
   /* Type your code here */
   string name;
   string todayDate;

   cout << "Enter customer's name: " << endl;
   cin << name;
   cout << "Enter today's date: " << endl;
   cin << todayDate;
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << todayDate << endl;
   
   return 0;
}
