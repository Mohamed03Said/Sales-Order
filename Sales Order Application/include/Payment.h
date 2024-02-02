#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <string>
using namespace std;

class Payment
{
public:
    Payment();
    virtual double pay();
    virtual void update();
    virtual void setPayment();
    virtual void getPayment();


protected:
    double amount;

private:

};

#endif // PAYMENT_H
