#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"


ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016") {}

ShoppingCart::ShoppingCart(string customerName, string currentDate){
  this->customerName = customerName;
  this->currentDate = currentDate;
  return;
}

string ShoppingCart::GetCustomerName() const{
  return customerName;
}

string ShoppingCart::GetDate() const{
  return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item){
  cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name){
   bool found = false;
   for(int i = 0; i < cartItems.size(); i++){
      if((cartItems.at(i).GetName() == name) && (!found)){
         cartItems.erase(cartItems.begin() + i);
         found = true;
      }
   }
   
   if(!found){
      cout << "Item not found in cart. Nothing removed." << endl << endl;   
   }
   else{
     cout << endl;
   }
   return;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
   bool found = false;
   for(auto& cartItem : cartItems){
      if(cartItem.GetName() == item.GetName()){
         if(item.GetDescription() != "none"){
            cartItem.SetDescription(item.GetDescription());   
         }
         if(item.GetPrice() != 0){
            cartItem.SetPrice(item.GetPrice());
         } if(item.GetQuantity() != 0){
            cartItem.SetQuantity(item.GetQuantity());   
         }
         found = true;
         break;
      }
   }
   if(!found) {
      cout << "Item not found in cart. Nothing modified." << endl; 
   }
}

int ShoppingCart::GetNumItemsInCart() {
  int totalQuantity = 0;
  for(const ItemToPurchase& item : cartItems) {
     totalQuantity += item.GetQuantity();
  }
  return totalQuantity;
}

int ShoppingCart::GetCostOfCart() {
   int price;
   int quantity;
   int totalPrice = 0;
   for(int i = 0; i < cartItems.size(); ++i){
      price = cartItems.at(i).GetPrice();
      quantity = cartItems.at(i).GetQuantity();
      totalPrice += (price * quantity);
   }
   return totalPrice;
}

void ShoppingCart::PrintTotal() {
  string name;
  int price;
  int quantity;
  int totalPrice;
  int total = 0;

  cout << customerName << "'s Shopping Cart - " << GetDate() << endl;
  cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

   if(cartItems.size() == 0){
      cout << "SHOPPING CART IS EMPTY" << endl;
   } else {
      for(int i = 0; i < cartItems.size(); ++i){
         name = cartItems.at(i).GetName();
         price = cartItems.at(i).GetPrice();
         quantity = cartItems.at(i).GetQuantity();
         totalPrice = price * quantity;
         cout << name << " " << quantity << " @ $" << price << " = $" << totalPrice << endl;
      
         total += totalPrice;
      }
   }
   cout << endl << "Total: $" << total << endl;
   return;
}

void ShoppingCart::PrintDescriptions() {
   cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
   cout << endl;
   cout << "Item Descriptions" << endl;
   if(cartItems.empty()){
      cout << "SHOPPING CART IS EMPTY" << endl;
   } else {
      for(int i = 0; i < cartItems.size(); i++){
         cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
      }
   }
   cout << endl;
}
