// git repository link
// team members: 

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
   switch(option){
      case 'a': {
         court << "ADD ITEM TO CART" << endl;
         string name, description;
         int price, quantity;
         cout << "Enter the item name:" << endl;
         getline(cin,name);
         cout << "Enter the item description:" << endl;
         getline(cin, description);
         cout << "Enter the item price:" << endl;
         cin >> price;
         cout << "Enter the item quantity:" << endl;
         cin >> quantity;
         cin.ignore();
         ItemPurchase newItem(name, description, price, quantity);
         theCart.AddItem(newItem);
         break;
      }
      case 'd':{
         cout << "REMOVE ITEM FROM CART" << endl;
         string itemName;
         cout << "Enter name of item to remove:" << endl;
         getline(cin,itemName);
         theCart.RemoveItem(itemName);
         break;
      }
      case 'c':{
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
         break;
      }
      case 'i': {
         cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
         theCart.PrintDescriptions();
         break;
      }
      case 'o': {
         cout << "OUTPUT SHOPPING CART" << endl;
         theCart.PrintTotal();
         break;
      }
      case 'q':
         break;
   }
   default:
      cout << "Invalid option."
      
}

int main() {
   /* Type your code here */
   string name;
   string currentDate;

   cout << "Enter customer's name: " << endl;
   cin << name;
   cout << "Enter today's date: " << endl;
   cin << currentDate;
   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << todayDate << endl;

   ShoppingCart myCart(customerName, currentDate);

   char choice;
   do{
      PrintMenu();
      cout << endl;
      cout << "Choose an option:" << endl;
      cin >> choice;
      cin.ignore();
      ExecuteMenu(choice, myCart);
   } while (choice != 'q');
   
   return 0;
}
