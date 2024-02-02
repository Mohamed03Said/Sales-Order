#ifndef STOCK_H
#define STOCK_H
#include "ProductList.h"
class Stock
{
public:
    Stock();
    virtual ~Stock();
    void printStock();
    void addtoStock(ProductList& ps);
    void updateStock();
    void deleteStock();
    double getPrice(int Pid);
    int getS_Quantity(int Pid);
    void updateS_Quantity(int Pid,int sq);
    Product findS_Product(int index);
    int isS_found(int Pid);

protected:

private:
    int id;
    Product* stocklist;
    int Scounter;
};

#endif // STOCK_H
