#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"


ShoppingCart::ShoppingCart(){
}

ShoppingCart::ShoppingCart(string name, string date){
  customerName = name;
  currentDate = date;
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
  customerName = name;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
  bool found = false;
  for(int i = 0; i < cartItems.size(); ++i){
    if(cartItems[i].GetDescription() == item.GetDescription()){
      if(item.GetDescription() != "none") {
        cartItems[i].SetDescription(item.GetDescription());
      }
      string name = cartItems.at(i).GetName();
      string description = cartItems.at(i).GetDescription();
      int price = cartItems.at(i).GetPrice();
      int quantity = cartItems.at(i).GetQuantity();

      if((!found) && (name == item.GetName())) {
        if((description != "none") && (price != 0) && (quantity != 0)) {
          item.SetName(name);
          item.SetName(description);
          item.SetPrice(price);
  
          cartItems.at(i) = item;
          found = true;
        }
      }
    }
  }
  if(!found) {
    cout << "Item not found in cart. Nothing modified." << endl;
  }
  return;
}

int ShoppingCart::GetNumItemsInCart() {
  int totalQuantity = 0;
  for(const ItemToPurchase& item : cartItems) {
    totalQuantity += item.GetQuantity();
  }
  return totalQuantity;
}

int ShoppingCart::GetCostOfCart() {
  int totalPrice = 0;
  int price;
  int quantity;
  int totalPrice;
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
      cout << name << " " << quantity << " @ $" << price << " =  $" << totalPrice << endl;

      total += totalPrice;
    }
  }
  cout << endl << "Total: $" << total << endl;
  return;
}

void ShoppingCart::PrintDescriptions() {
  cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
  cout << "Item Descriptions" << endl;
  if(cartItems.empty()){
    cout << "SHOPPING CART IS EMPTY" << endl;
  } else {
    for(const ItemToPurchase& item : cartItems){
      cout << item.GetDescription() << endl;
      }
    }
}
