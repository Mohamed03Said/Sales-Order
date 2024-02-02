#include "Customer.h"

Customer::Customer()
{
    id =0;
    phone =" ";
}

ostream& operator<<(ostream& out, Customer& customer)
{
	 customer.printCustomer(out);
	return out;
}

istream& operator>>(istream& in, Customer& customer)
{
    customer.readCustomer(in);
	return in;
}

void Customer::editCustomer(){}
int Customer::getid(){}
string Customer::getname(){}
void Customer::readCustomer(istream& in){}
void Customer::printCustomer(ostream& out){}
