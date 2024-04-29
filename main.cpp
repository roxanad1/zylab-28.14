// git repository link
// team members: Roxana Dicusara and Tiffany Nguyen

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   /* Type your code here */
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   /* Type your code here */
   if (option == 'a'){
      string name, description;
      int price, quantity;
      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin,name);
      cout << "Enter the item description:" << endl;
      getline(cin, description);
      cout << "Enter the item price:" << endl;
      cin >> price;
      cout << "Enter the item quantity:" << endl;
      cin >> quantity;
      cin.ignore();
      ItemToPurchase newItem(name, description, price, quantity);
      theCart.AddItem(newItem);
   }
   else if (option == 'd'){
      cout << "REMOVE ITEM FROM CART" << endl;
      string itemName;
      cout << "Enter name of item to remove:" << endl;
      getline(cin,itemName);
      theCart.RemoveItem(itemName);
   }
   else if (option == 'c'){
      cout << "CHANGE ITEM QUANTITY" << endl;
      string itemName;
      cout << "Enter the item name:" << endl;
      getline(cin, itemName);

      int newQuantity;
      cout << "Enter the new quantity:" << endl;
      cin >> newQuantity;
      cin.ignore();
      ItemToPurchase newItem(itemName, "", 0, newQuantity);
      theCart.ModifyItem(newItem);
   }
   else if (option == 'i'){
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      theCart.PrintDescriptions();
   }
   else if (option == 'o'){
      cout << "OUTPUT SHOPPING CART" << endl;
      theCart.PrintTotal();
   }
   else if (option == 'q'){

   }
   else{
   }
}

int main() {
   /* Type your code here */
   string name;
   string currentDate;

   cout << "Enter customer's name:" << endl;
   getline(cin, name);
   cout << "Enter today's date:" << endl;
   cout << endl;
   getline(cin, currentDate);
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << currentDate << endl;
   cout << endl;
   
   ShoppingCart myCart(name, currentDate);

   char choice;
   PrintMenu();
   cout << endl;
   do{
      cout << "Choose an option:" << endl;
      cin >> choice;
      cin.ignore();
      ExecuteMenu(choice, myCart);
   } while (choice != 'q');
   
   return 0;
}
