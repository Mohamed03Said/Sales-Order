#ifndef CASH_H
#define CASH_H
#include "Payment.h"

class Cash: public Payment
{
public:
    Cash();
    void update();
    double pay();
    void getPayment();
    void setPayment();
    double value;
protected:

private:
};

#endif // CASH_H
