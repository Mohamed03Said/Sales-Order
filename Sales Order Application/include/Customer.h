#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Customer
{
public:
    Customer();
    virtual void editCustomer();
    virtual int getid();
    virtual string getname();
    friend ostream& operator<<(ostream& out, Customer& customer);
    friend istream& operator>>(istream& in, Customer& customer);

protected:
    int id;
    string phone;
    virtual void readCustomer(istream& in);
    virtual void printCustomer(ostream& out);

private:

};

#endif // CUSTOMER_H
