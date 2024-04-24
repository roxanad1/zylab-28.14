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

string ShoppingCart::GetCustomerName(){
  return customerName;
}

string ShoppingCart::GetDate(){
  return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item){
  cartItems = item;
}

void ShoppingCart(string name){
  customerName = name;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
  bool found = false;
  for(int i = 0; i < cartItems.size(); ++i){
    if(cartitems[i].GetDescription() == newItem.GetDescription());
      if(newItem.GetDescription() != "none") {
        cartItems[i].SetDescription(newItem.GetDescription());
      }
    string name = cartItems.at(i).GetName();
    string description = cartItems.at(i).GetDescription();
    int price = cartItems.at(i).GetPrice();
    int quantity = cartItems.at(i).GetQuantity();

    if((!found) && (name = item.GetName())) {
      if((description != "none") && (price != 0) && (quantity != 0)) {
        item.SetName(name);
        item.SetName(description);
        item.SetPrice(price);

        cartItems.at(i) = item;
        found = true;
      }
    }
  }
  if(!found) {
    cout << "Item not found in cart. Nothing modified." << endl;
  }
  return;
}

int ShoppingCart::GetNumItemsInCart() const {
  int totalQuantity = 0;
  for(const ItemToPurchase& item : cartItems) {
    totalQuantity += item.GetQuantity();
  }
  return totalQuantity;
}

int ShoppingCart::GetCostOfCart() const {
  int totalPrice = 0;
  int price;
  int quantity;
  for(int i = 0; i < cartItems.size(); ++i){
    price = cartItems.at(i).GetPrice();
    quantity = cartItems.at(i).GetQuantity();

    sum += (price * quantity);
  }
  return sum;
}

void ShoppingCart::PrintTotal() const {
  string name;
  int price;
  int quantity;
  int totalPrice;
  int total = 0;

  cout << customerName << "'s Shopping Cart - " << GetDate() << endl;
  cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;

  if(cartItems.size() == 0{
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

void ShoppingCart::PrintDescriptions() const {
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
