#ifndef ORDERITEM_H
#define ORDERITEM_H
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Stock.h"
using namespace std;

class OrderItem
{
public:
    OrderItem();
    void addItem(Stock& st);
    double gettotPriceSale();
    double long getProfit();
    double getO_quantity();
    void printItem();
    OrderItem operator++();
    OrderItem operator--();
    OrderItem operator+=(int n);
    OrderItem operator-=(int n);

protected:

private:
    Product* produc;
    double sales_price;
    double O_quantity;
    double long profit;
};

#endif // ORDERITEM_H
