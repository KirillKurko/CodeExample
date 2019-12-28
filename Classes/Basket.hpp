#ifndef Basket_hpp
#define Basket_hpp

#include <unordered_map>
#include "Product.hpp"

class Basket {
protected:
    int amountOfProducts;
    double totalPrice;
    std::unordered_multimap<int, Product> products;
public:
    Basket();
    Basket(const Basket& b);
    void add(int amount, Product pr);
    void remove(int position);
    void show();
    double getTotalPrice();
};

#endif
