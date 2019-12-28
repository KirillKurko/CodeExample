#include <iostream>
#include <cmath>
#include "barcode.hpp"

using namespace std;

void setBarcode(Barcode& barcode) {
    barcode.countryCode = 0;
    barcode.manufacturerCode = 0;
    barcode.productCode = 0;
    barcode.target = 0;
}

void enterBarcode(Barcode& barcode) {
    cout << "Введите код страны: ";
    barcode.countryCode = enterNumber(3);
    cout << "Введите код производителя: ";
    barcode.manufacturerCode = enterNumber(4);
    cout << "Введите код товара: ";
    barcode.productCode = enterNumber(5);
    barcode.target = calculateTarget(barcode.countryCode, barcode.manufacturerCode, barcode.productCode);
}

int enterNumber(int numberOfDigits) {
    
    int number;
    int left = pow(10, numberOfDigits - 1);
    int right = pow(10, numberOfDigits);
    
    cin >> number;
    if (number < left || number >= right) {
        while (number < left || number >= right) {
            cout << "Попытка ввода некорректного значения. Повторите ввод: ";
            cin >> number;
        }
    }
    return number;
}

int calculateTarget(int countryCode, int manufacturerCode, int productCode) {
    
    string number;
    number.append(to_string(countryCode));
    number.append(to_string(manufacturerCode));
    number.append(to_string(productCode));
    
    int oddPositionSum = 0;
    int evenPositionSum = 0;
    
    for (int i = 0; i < 12; ++i) {
        if (i % 2 == 0)
            evenPositionSum += number[i] - '0';
        else
            oddPositionSum += number[i] - '0';
    }
    
    oddPositionSum *= 3;
    oddPositionSum += evenPositionSum;
    oddPositionSum %= 10;
    
    return 10 - oddPositionSum;
}

bool Barcode::operator!=(const Barcode& bc) {
    return (countryCode != bc.countryCode || manufacturerCode != bc.manufacturerCode
            || productCode != bc.productCode);
}

bool Barcode::operator==(const Barcode& bc) {
    return (countryCode == bc.countryCode && manufacturerCode == bc.manufacturerCode
            && productCode == bc.productCode);
}
