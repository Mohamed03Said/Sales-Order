#ifndef ORDERLIST_H
#define ORDERLIST_H
#include "Order.h"

class OrderList
{
public:
    OrderList();
    virtual ~OrderList();
    void CreateOrders(Stock& sto, Customers& cust);
    void UpdateOrders();
    void DeleteOrders();
    void PrintOrders();
    Order* findOrder(int ido);
    int isO_found(int index);
    void Total_Profits();
protected:

private:
    static int Ocounter;
    Order* orderlist;
};

#endif // ORDERLIST_H
