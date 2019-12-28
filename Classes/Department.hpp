#ifndef Department_hpp
#define Department_hpp

#include "Product.hpp"

class Department : public Product {
protected:
    int amount;
    std::string departmentName;
public:
    Department();
    Department(int amount, std::string dn, int g, int t, std::string c, Barcode b, double p);
    void show();
    void enter();
    void edit();
    Product getProduct();
    int getAmount();
    void changeAmount(int amountToReduce);
};

#endif
