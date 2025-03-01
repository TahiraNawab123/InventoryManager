#include<iostream>
#include"Inventory.h"

using namespace std;

void initializeInventory(Inventory &Inv, int size){
   	Inv.CurrentCount = 0;   
    Inv.size = size;   
    Inv.product = new Product[size];  
  }

void setSupplierData(Supplier & supplier, string SupplierName, string contactNum){
       supplier.SupplierName = SupplierName; 
       supplier.ContactNumber = contactNum;   
  }

void setProductData(Product &product, Supplier supplier, string productName, float productPrice){
      product.ProductName = productName;   
      product.ProductPrice = productPrice;  
      product.supplier = supplier;    
  }

int addProductToInventory(Inventory &inv, Product product) {
    if (inv.CurrentCount == inv.size) {       
        return 1; 
    }
    inv.product[inv.CurrentCount] = product; 
    inv.CurrentCount++;  
    return 0;    
}

Supplier* searchProductByName(Inventory &inv, string productName) {
    for (int i = 0; i < inv.CurrentCount; i++) {
        if (inv.product[i].ProductName == productName) {
            return &inv.product[i].supplier; 
        }
    }
    return nullptr;
}


void displayProduct(Product &product) {
    cout << "Product Name: " << product.ProductName << endl;   
    cout << "Product Price: $" << product.ProductPrice << endl;  
    cout << "Supplier Name: " << product.supplier.SupplierName << endl;  
    cout << "Contact Number: " << product.supplier.ContactNumber << endl;  
}


void displayInventory(Inventory &inv) {
    if (inv.CurrentCount == 0) {
        cout << "Inventory is empty!" << endl;
        return;
    }
    for (int i = 0; i < inv.CurrentCount; i++) {
        cout<<"Product " <<i + 1 << ":"<<endl;
        displayProduct(inv.product[i]);
        cout<<"======================================"<<endl;
    }
}