#ifndef barcode_hpp
#define barcode_hpp

struct Barcode {
    int countryCode;
    int manufacturerCode;
    int productCode;
    int target;
    
    bool operator!= (const Barcode& bc);
    bool operator== (const Barcode& bc);
};

int enterNumber(int numberOfDigits);
void setBarcode(Barcode& barcode);
void enterBarcode(Barcode& barcode);
int calculateTarget(int countryCode, int manufacturerCode, int productCode);

#endif 
