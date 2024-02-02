#include "Cash.h"

Cash::Cash()
{
    value=0.0;
}

void Cash::update()
{
    cout<<"Enter new Amount: ";
    cin>>amount;
    cout<<"Enter new Value: ";
    cin>>value;
}
double Cash::pay()
{
    return amount;
}
void Cash::getPayment()
{
    cout<<"Payment Method: "<<"Cash";
    cout<<"\tAmount: "<<amount;
    cout<<"\tCash Value: "<<value;
}
void Cash::setPayment()
{
    cout<<"Enter Amount of Payment: ";
    cin>>amount;
    cout<<"Enter Cash Value: ";
    cin>>value;
}
