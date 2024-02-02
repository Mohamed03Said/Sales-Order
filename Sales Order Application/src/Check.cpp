#include "Check.h"

Check::Check()
{
    name=" ";
    Bid= " ";
}

void Check::update()
{
    cout<<"Enter new Amount: ";
    cin>>amount;
    cout<<"Enter new Name: ";
    cin>>name;
    cout<<"Enter new ID: ";
    cin>>Bid;
}
double Check::pay()
{
    return amount;
}
void Check::getPayment()
{
    cout<<"Payment Method: "<<"Check";
    cout<<"\tAmount: "<<amount;
    cout<<"\tName: "<<name;
    cout<<"\tBank ID: "<<Bid;
}
void Check::setPayment()
{
    cout<<"Enter Amount of Payment: ";
    cin>>amount;
    cout<<"Enter check Name: ";
    cin>>name;
    cout<<"Enter Bank ID: ";
    cin>>Bid;
}
