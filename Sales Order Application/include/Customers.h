#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include "Company.h"
#include "Person.h"
#include <fstream>
#include "Customer.h"

class Customers
{
public:
    Customers();
    virtual ~Customers();
    void addCustomer();
    void editCustomer();
    void deleteCustoemr();
    void printCustomers();
    Customer* findS_Customer(int index);
    int isC_found(int cid);

protected:

private:
    Customer** customerlist;
    static int Ccounter;
};

#endif // CUSTOMERS_H
