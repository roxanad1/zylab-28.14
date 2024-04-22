#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity = 0){
  itemname = name;
  itemDescription = description;
  itemPrice = price;
  itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name) {
  itemName = name;
}

void ItemToPurchase::SetDescription(string description){
  itemDescription = description;
}

void ItemToPurchase::SetPrice(int price) {
  itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quantity) {
  itemQuantity = quantity;
}

string ItemToPurchase::GetName(){
  return itemName;
}

string ItemToPurchase::GetDescription(){
  return itemDescription;
}

int ItemToPurchase::GetPrice(){
  return itemPrice;
}

int ItemToPurchase::GetQuantity(){
  return itemQuantity;
}

void ItemToPurchase::PrintItemCost(){
  cout << 
}

void ItemToPurchase::PrintItemDescription(){
  cout << 
}
