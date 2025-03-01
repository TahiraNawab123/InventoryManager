#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Inventory.h"

TEST_CASE("Initialize inventory with valid size") {
    Inventory inv;
    int size = 5;
    initializeInventory(inv, size);

    REQUIRE(inv.size == size);
    REQUIRE(inv.CurrentCount == 0);
    REQUIRE(inv.product != nullptr);
}

TEST_CASE("Add product to inventory") {
    Inventory inv;
    int size = 5;
    initializeInventory(inv, size);

    Supplier supplier;
    setSupplierData(supplier, "ABC Supplies", "123-456-7890");

    Product product;
    setProductData(product, supplier, "Laptop", 999.99);

    int result = addProductToInventory(inv, product);

    REQUIRE(result == 0); // Successfully added
    REQUIRE(inv.CurrentCount == 1);
    REQUIRE(inv.product[0].ProductName == "Laptop");
}

TEST_CASE("Search product by name") {
    Inventory inv;
    int size = 5;
    initializeInventory(inv, size);

    Supplier supplier;
    setSupplierData(supplier, "ABC Supplies", "123-456-7890");

    Product product;
    setProductData(product, supplier, "Laptop", 999.99);

    addProductToInventory(inv, product);

    Supplier* foundSupplier = searchProductByName(inv, "Laptop");

    REQUIRE(foundSupplier != nullptr);
    REQUIRE(foundSupplier->SupplierName == "ABC Supplies");
    REQUIRE(foundSupplier->ContactNumber == "123-456-7890");
}

TEST_CASE("Display inventory with products") {
    Inventory inv;
    int size = 5;
    initializeInventory(inv, size);

    Supplier supplier;
    setSupplierData(supplier, "ABC Supplies", "123-456-7890");

    Product product1, product2;
    setProductData(product1, supplier, "Laptop", 999.99);
    setProductData(product2, supplier, "Smartphone", 599.99);

    addProductToInventory(inv, product1);
    addProductToInventory(inv, product2);

    // Expected to output two products to console, but we won't validate output in the test case
    REQUIRE(inv.CurrentCount == 2);
}
