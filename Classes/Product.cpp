#include "Product.hpp"

Product::Product() {
    group = 0;
    type = 0;
    country = "";
    setBarcode(barcode);
    price = 0.0;
}

Product::Product(int g, int t, std::string c, Barcode b, double p) {
    group = g;
    type = t;
    country = c;
    barcode = b;
    price = p;
}

void Product::show() {
    std::cout << "\nГруппа - " << group << std::endl
    << "Тип - " << type << std::endl
    << "Страна - " << country << std::endl
    << barcode.countryCode << barcode.manufacturerCode << " "
    << barcode.productCode << barcode.target << std::endl
    << "Цена - " << price << "\n";
}

void Product::enter() {
    std::cout << "\nВведите группу товара: ";
    std::cin >> group;
    std::cout << "Введите тип товара: ";
    std::cin >> type;
    std::cout << "Введите страну происхождения товара: ";
    std::cin >> country;
    enterBarcode(barcode);
    std::cout << "Введите цену товара: ";
    std::cin >> price;
    std::cout << "\n";
}

void Product::edit() {
    int selection;
    while (true) {
        std::cout << "\n1 - Группа\n2 - Тип\n3 - Страна\n4 - Штрих-код\n5 - Цена\n6 - Завершить редактирование\n";
        std::cin >> selection;
        switch (selection) {
            case 1:
                std::cout << "Введите новое значение группы товара: ";
                std::cin >> group;
                break;
            case 2:
                std::cout << "Введите новое значение типа товара: ";
                std::cin >> type;
                break;
            case 3:
                std::cout << "Введите новое значение страны товара: ";
                std::cin >> country;
                break;
            case 4:
                std::cout << "Введите новое значение штрих-кода товара:\n";
                enterBarcode(barcode);
                break;
            case 5:
                std::cout << "Введите новое значение цены товара: ";
                std::cin >> price;
                break;
            default:
                return;
        }
    }
}

double Product::getPrice() {
    return price;
}

bool Product::operator==(const Product& pr) {
    return (group != pr.group || type != pr.type || country != pr.country
            || barcode != pr.barcode || price != pr.price) ? false : true;
}

Product Product::operator=(const Product& pr) {
    group = pr.group;
    type = pr.type;
    country = pr.country;
    barcode = pr.barcode;
    price = pr.price;
    return *this;
}
