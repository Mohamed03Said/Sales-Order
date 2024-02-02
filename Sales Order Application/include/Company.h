#ifndef COMPANY_H
#define COMPANY_H
#include "Customer.h"

class Company: public Customer
{
public:
    Company();
    void readCustomer(istream& in);
    void printCustomer(ostream& out);
    void editCustomer();
    int getid();
    string getname();

protected:

private:
    string location;
    string company_name;
};

#endif // COMPANY_H
