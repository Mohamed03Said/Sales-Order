#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;


class Product
{
public:
    Product();
    void updateProduct();
    friend istream& operator>>(istream& in,Product& product);
    friend ostream& operator<<(ostream& out,Product& product);
    void printP();
    void setQuantity(int q);
    int getQuantity();
    double getPrice();
    int getP_ID();
    string getName();
    string getNumber();
    int getType();
    void editQuantity();

protected:

private:
    int id;
    string number;
    string name;
    double price;
    int type;
    unsigned int quantity;
};

#endif // PRODUCT_H
