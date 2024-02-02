#ifndef CREDIT_H
#define CREDIT_H
#include "Payment.h"

class Credit: public Payment
{
public:
    Credit();
    void update();
    double pay();
    void getPayment();
    void setPayment();
    string number;
    string expire_date;
    string type;

protected:

private:
};

#endif // CREDIT_H
