#include<iostream>
#include"Inventory.h"

using namespace std;

int main(){

  Inventory inv;

  initializeInventory(inv, 3); 
  
  Supplier supplier1;
  setSupplierData(supplier1, "Ahmad", "03107300166");  
  
  Product product1;
  setProductData(product1, supplier1, "Apple", 150.50); 

  if (addProductToInventory(inv, product1) == 0){  
        cout << "Product added successfully!" << endl;
        }else
         cout<<"Error in adding the product. Inventory is full!"<<endl;

  // Display inventory
  displayInventory(inv);

  delete[] inv.product; // delete allocated memory

  return 0;
 }