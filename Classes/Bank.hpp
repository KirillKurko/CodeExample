#ifndef Bank_hpp
#define Bank_hpp

#include "Basket.hpp"
#include <map>

class Bank {
private:
    std::map<int, double> bankAccounts;
public:
    Bank() {};
    Bank(const Bank& b);
    void addAccount(int accountNumber, double amountOfMoney);
    bool pay(int accountNumber, Basket& basket);
};

#endif
