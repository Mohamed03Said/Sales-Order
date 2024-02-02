#ifndef PERSON_H
#define PERSON_H
#include "Customer.h"

class Person: public Customer
{
public:
    Person();
    void readCustomer(istream& in);
    void printCustomer(ostream& out);
    void editCustomer();
    int getid();
    string getname();

protected:

private:
    string billing_address;
    string full_name;
};

#endif // PERSON_H
