#include "Bank.hpp"

using namespace std;

Bank::Bank(const Bank& b) {
    for (auto it = b.bankAccounts.begin(); it != b.bankAccounts.end(); ++it)
        bankAccounts.insert(*it);
}

void Bank::addAccount(int accountNumber, double amountOfMoney) {
    bankAccounts.insert({accountNumber, amountOfMoney});
}

bool Bank::pay(int accountNumber, Basket& basket) {
    for (auto it = bankAccounts.begin(); it != bankAccounts.end(); ++it) {
        if (it->first == accountNumber) {
            if (it->second < basket.getTotalPrice()) {
                cout << "\nНедостаточно средств\n";
                return false;
            }
            else {
                it->second -= basket.getTotalPrice();
                return true;
            }
        }
    }
    cout << "\nОшибка. Банковский счет с указанным номером не существует\n";
    return false;
}
