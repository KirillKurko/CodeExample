#include "Basket.hpp"

using namespace std;

Basket::Basket() {
    amountOfProducts = 0;
    totalPrice = 0;
}

Basket::Basket(const Basket& b) {
    amountOfProducts = b.amountOfProducts;
    totalPrice = b.totalPrice;
    for (auto it = b.products.begin(); it != b.products.end(); ++it)
        products.insert(*it);
}

void Basket::add(int amount, Product pr) {
    products.insert({amount, pr});
    amountOfProducts += amount;
    totalPrice += amount * pr.getPrice();
    
}

void Basket::remove(int position) {
    auto it = products.begin();
    while (position--) it++;
    amountOfProducts -= it->first;
    totalPrice -= it->first * it->second.getPrice();
    products.erase(it);
}

void Basket::show() {
    if (products.empty())
        cout << "\nКорзина пуста\n";
    else {
        int i = 1;
        for (auto it = products.begin(); it != products.end(); ++it) {
            cout << "\nТовар " <<  i << "\n";
            it->second.show();
            cout << "Количество данных товаров в корзине: " << it->first << "\n";
        }
        cout << "\nОбщее количество товаров в корзине: " << amountOfProducts << endl
        << "Общая стоимость товаров в корзине: " << totalPrice << "\n";
    }
}

double Basket::getTotalPrice() {
    return totalPrice;
}
