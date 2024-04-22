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

void ShoppingCart::ModifyItem(const ItemToPurchase& newItem){
  bool found = false;
  for(int i = 0; i < cartItems.size(); ++i){
    if(cartitems[i].GetDescription() == newItem.GetDescription());
      if(newItem.GetDescription() == != "none) {
        cartItems[i].SetDescription(newItem.GetDescription());
      }
        found = true;
        break;
      }
    }
    if(!found) {
      cout << "Item not found in cart. Nothing has been modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() const {
  int totalQuantity = 0;
  for(const ItemToPurchase& item : cartItems) {
    totalQuantity += item.GetQuantity();
  }
  return totalQuantity;
}

int ShoppingCart::GetCostOfCart() const {
  int totalCost = 0;
  for(const ItemToPurchase& item : cartItems){
    item.PrintItemCost();
  }
  return totalCost;
}

void ShoppingCart::PrintTotal() const {
  cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
  cout << "Number of Items: " << GetNumItemsInCart() <<  endl;

  if(cartItems.empty()){
    cout << "SHOPPING CART IS EMPTY" << endl;
  } else {
    for(const ItemToPurchase& item : cartItems){
      item.PrintItemCost();
    }
  }
  cout << endl << "Total: $" << GetCostOfCart() << endl;
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
