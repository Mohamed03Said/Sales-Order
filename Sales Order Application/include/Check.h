#ifndef CHECK_H
#define CHECK_H
#include "Payment.h"

class Check: public Payment
{
public:
    Check();
    void update();
    double pay();
    void getPayment();
    void setPayment();
    string name;
    string Bid;

protected:

private:
};

#endif // CHECK_H
