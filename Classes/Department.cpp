#include "Department.hpp"

using namespace std;

Department::Department() {
    departmentName = "Новый отдел";
}

Department::Department(int a, std::string dn, int g, int t, std::string c, Barcode b, double p) {
    amount = a;
    departmentName = dn;
    Product(g, t, c, b, p);
}

void Department::show() {
    cout << "\n" << departmentName << "\n";
    Product::show();
    cout << "\nКоличество данного товара в отделе: " << amount << "\n";
}

void Department::enter() {
    cout << "Введите название отдела: ";
    cin >> departmentName;
    cout << "Введите количество данного товара в отделе: ";
    cin >> amount;
    Product::enter();
}


void Department::edit() {
    int selection;
    while (true) {
        cout << "\n1 - Название отдела\n2 - Количество"
        << "\n3 - Информация о товаре\n4 - Завершить редактирование\n";
        cin >> selection;
        switch (selection) {
            case 1:
                cout << "Введите новое название отдела: ";
                cin >> departmentName;
                break;
            case 2:
                cout << "Введите количество товара: ";
                cin >> amount;
                break;
            case 3:
                Product::edit();
                break;
            default:
                return;
        }
    }
}

Product Department::getProduct() {
    return Product(group, type, country, barcode, price);
}
int Department::getAmount() {
    return amount;
}

void Department::changeAmount(int amountToReduce) {
    amount -= amountToReduce;
}
