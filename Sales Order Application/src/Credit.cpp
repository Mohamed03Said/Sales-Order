#include "Credit.h"

Credit::Credit()
{
    number =" ";
    expire_date=" ";
    type= " ";
}

void Credit::update()
{
    cout<<"Enter new amount: ";
    cin>>amount;
    cout<<"Enter new Expire Date: ";
    cin>>expire_date;
}
double Credit::pay()
{
    return amount;
}

void Credit::setPayment()
{
    cout<<"Enter Amount of Payment: ";
    cin>>amount;
    cout<<"Enter Credit Number: ";
    cin>>number;
    cout<<"Enter Expire Date: ";
    cin>>expire_date;
    cout<<"Enter Credit Type: ";
    cin>>type;

}
void Credit::getPayment()
{
    cout<<"Payment Method: "<<"Credit";
    cout<<"\tAmount: "<<amount;
    cout<<"\tNumber: "<<number;
    cout<<"\tExpire Date: "<<expire_date;
    cout<<"\tType: "<<type;
}
