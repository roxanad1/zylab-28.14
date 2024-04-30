// git repository link: https://github.com/roxanad1/zylab-28.14.git
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
   switch(option) {
        case 'a': {
            cout << "\n" << "ADD ITEM TO CART" << endl;
            string name, description;
            int price, quantity;
            cout << "Enter the item name:" << endl;
            cin.ignore();
            getline(cin, name);
            cout << "Enter the item description:" << endl;
            getline(cin, description);
            cout << "Enter the item price:" << endl;
            cin >> price;
            cout << "Enter the item quantity:" ;
            cin >> quantity;
            cout << endl << endl;
            cin.ignore();
            ItemToPurchase newItem(name, description, price, quantity);
            theCart.AddItem(newItem);
            PrintMenu();
            break;
        }
        case 'd': {
            cout << "\nREMOVE ITEM FROM CART" << endl;
            string itemName;
            cout << "Enter name of item to remove:";
            // cin.ignore();
            getline(cin, itemName);
            cout << endl;
            theCart.RemoveItem(itemName); 
            // cout << endl;
            PrintMenu();
            break;
        }
        case 'c': {
            cout << "\n" << "CHANGE ITEM QUANTITY" << endl;
            string itemName;
            cout << "Enter the item name:" << endl;
            cin.ignore();
            getline(cin, itemName);
            int newQuantity;
            cout << "Enter the new quantity:" << endl;
            cin >> newQuantity;
            cin.ignore();
            ItemToPurchase newItem(itemName, "", 0, newQuantity);
            theCart.ModifyItem(newItem);
            cout << endl;
            PrintMenu();
            break;
        }
        case 'i': {
            cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            theCart.PrintDescriptions();
            PrintMenu();
            break;
        }
        case 'o': {
            cout << endl << "OUTPUT SHOPPING CART" << endl;
            theCart.PrintTotal();
            cout << endl;
            // PrintMenu();
            break;
        }
        case 'q': {
            break; // Quit the loop
        }
        default: {
            break;
        }
    }
}

int main() {
   /* Type your code here */
   string name;
   string currentDate;

   cout << "Enter customer's name:" << endl;
   getline(cin, name);
   cout << "Enter today's date:" << endl;
   getline(cin, currentDate);
   
   cout << endl;

   cout << "Customer name: " << name << endl;
   cout << "Today's date: " << currentDate << endl;
   
   cout << endl;
   
   ShoppingCart myCart(name, currentDate);

   char choice;
   // cout << endl;
   
   do{
      PrintMenu();
      cout << "Choose an option:";
      cin >> choice;
      cin.ignore();
      ExecuteMenu(choice, myCart);
   } while (choice != 'q');
   
   return 0;
}
