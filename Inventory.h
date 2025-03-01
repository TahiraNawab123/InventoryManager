#ifndef INVENTORY_H
#define INVENTORY_H
#include<iostream>

using namespace std;

struct Supplier{   
  string SupplierName;
  string ContactNumber;
  };


struct Product{  
  string ProductName;
  float ProductPrice;
  Supplier supplier;
  };


struct Inventory{  
  Product* product = nullptr;
  int size;
  int CurrentCount;
  };


void initializeInventory(Inventory &Inv, int size);
void setSupplierData(Supplier & supplier, string SupplierName, string contactNum);
void setProductData(Product &product, Supplier supplier, string productName, float productPrice);
int addProductToInventory(Inventory &inv, Product product);
Supplier* searchProductByName(Inventory &inv, string productName);
void displayProduct(Product &product);
void displayInventory(Inventory &inv);

#endif //INVENTORY_H
