#ifndef ORDER_H
#define ORDER_H
#include <ctime>
#include "OrderItem.h"
#include "Customers.h"
enum class OrderStatus {NEW,HOLD,PAID,CANCELED};

class Order
{
public:
    Order();
    ~Order();
    OrderStatus ords;
    void createOrder(Stock& sto, Customers& cust);
    friend ostream& operator<<(ostream& out, Order& order);
    friend istream& operator>>(istream& in, Order& order);
    void editOrder();
    void updateStatus();
    int getOid();
    void printOrder();
    double gettotOPrice();
    double long getO_Profit();

protected:

private:
    Customer* customr;
    OrderItem* itemslist;
    int Icounter;
    int Oid;
    int number;
    time_t now = time(0);
    char* date = ctime(&now);
    double total;
    double long Oprofit;
};

#endif // ORDER_H
