#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ShoppingCart.h"

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
