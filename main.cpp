#include <iostream>
#include <ctime>
#include <clocale>
#include <vector>
#include "Product.hpp"
#include "Department.hpp"
#include "Basket.hpp"
#include "Bank.hpp"

using namespace std;

void showInforamtion(vector<vector<Department>> departments) {
    for (int i = 0; i < departments.size(); ++i)
        for (int j = 0; j < departments[i].size(); ++j)
            departments[i][j].show();
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    vector<vector<Department>> departments;
    vector<Department> temp;
    Department tempDepartment;
    Basket basket;
    Bank bank;
    int selection, selection2 = 0, selection3 = 0, selection3_2, selection_4 = 0;
    
    while (true) {
        cout << "\n1 - Отдел\n2 - Корзина\n3 - Банк\n4 - Завершить работу\n";
        cin >> selection;
        switch (selection) {
            case 1:
                while (selection2 < 5) {
                    cout << "\n1 - Создать отдел\n2 - Добавить отдел"
                    << "\n3 - Редактировать\n4 - Вывести информацию\n5 - Выйти\n";
                    cin >> selection2;
                    switch (selection2) {
                        case 1:
                            int numberOfDepartments;
                            cout << "Введите количество отделов: ";
                            cin >> numberOfDepartments;
                            for (int i = 0; i < numberOfDepartments; ++i) {
                                int numberOfDifferentProducts;
                                cout << "Введите количество видов товаров в данном отделе: ";
                                cin >> numberOfDifferentProducts;
                                for (int j = 0; j < numberOfDifferentProducts; ++j) {
                                    tempDepartment.enter();
                                    temp.push_back(tempDepartment);
                                }
                                departments.push_back(temp);
                                temp.clear();
                            }
                            break;
                        case 2:
                            int numberOfDifferentProducts;
                            cout << "Введите количество видов товаров в новом отделе: ";
                            cin >> numberOfDifferentProducts;
                            for (int i = 0; i < numberOfDifferentProducts; ++i)
                                tempDepartment.enter();
                                temp.push_back(tempDepartment);
                            departments.push_back(temp);
                            temp.clear();
                            break;
                        case 3:
                            int departmentNumber, productNumber;
                            cout << "Введите номер отдела и номер товара для изменения информции: ";
                            cin >> departmentNumber >> productNumber;
                            departments[departmentNumber - 1][productNumber - 1].edit();
                            break;
                        case 4:
                            showInforamtion(departments);
                            break;
                        default:
                            cout << "\nРабота с отделами завершена\n";
                    }
                }
                break;
            case 2:
                while (selection3 < 5) {
                    cout << "\n1 - Добавить товар\n2 - Удалить товар"
                    << "\n3 - Показать содержимое\n4 - Стоимость товаров в коризне\n5 - Выйти\n";
                    cin >> selection3;
                    switch (selection3) {
                        case 1:
                            cout << "\nИмеющиеся товары и их количество\n";
                            showInforamtion(departments);
                            int departmentNumber, productNumber, numberOfProducts;
                            cout << "\nВведите номер отдела, номер товара и количество товаров для добавления: ";
                            cin >> departmentNumber >> productNumber >> numberOfProducts;
                            if (departments[departmentNumber - 1][productNumber - 1].getAmount() == numberOfProducts) {
                                basket.add(numberOfProducts, departments[departmentNumber - 1][productNumber - 1].getProduct());
                                departments[departmentNumber - 1].erase(departments[departmentNumber - 1].begin() + productNumber);
                            }
                            else {
                                basket.add(numberOfProducts, departments[departmentNumber - 1][productNumber - 1].getProduct());
                                departments[departmentNumber - 1][productNumber - 1].changeAmount(numberOfProducts);
                            }
                            break;
                        case 2:
                            basket.show();
                            cout << "Введите номер товара по списку: ";
                            cin >> selection3_2;
                            basket.remove(selection3_2 - 1);
                            break;
                        case 3:
                            basket.show();
                            break;
                        case 4:
                            cout << "Общая стоимость товаров в корзине: " << basket.getTotalPrice() << "\n";
                            break;
                        default:
                            cout << "\nРабота с корзиной заверешена\n";
                    }
                }
                break;
            case 3:
                while (selection_4 < 3) {
                    cout << "\n1 - Добавить счет\n2 - Оплатить\n3 - Выйти\n";
                    cin >> selection_4;
                    switch (selection_4) {
                        case 1:
                            int accountNumber;
                            double amountOfMoney;
                            cout << "Введите номер счета и количество средств: ";
                            cin >> accountNumber >> amountOfMoney;
                            bank.addAccount(accountNumber, amountOfMoney);
                            break;
                        case 2:
                            cout << "Введите номер счета для оплаты: ";
                            cin >> accountNumber;
                            if (bank.pay(accountNumber, basket)) {
                                basket.show();
                                time_t seconds = time(NULL);
                                tm* timeinfo = localtime(&seconds);
                                cout << "\n" << asctime(timeinfo) << "\n";
                            }
                            break;
                        default:
                            cout << "\nРабота с банком завершена\n";
                    }
                }
                break;
            default:
                cout << "\nРабота завершена\n";
                return 0;
        }
    }
}
