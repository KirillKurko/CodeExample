#ifndef Product_hpp
#define Product_hpp

#include <iostream>
#include "barcode.hpp"

class Product {
protected:
    int group;
    int type;
    std::string country;
    Barcode barcode;
    double price;
public:
    Product();
    Product(int g, int t, std::string c, Barcode b, double p);
    void show();
    void enter();
    void edit();
    double getPrice();
    bool operator==(const Product& pr);
    Product operator= (const Product& pr);
    
};

#endif
