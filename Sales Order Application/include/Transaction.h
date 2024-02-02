#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Orderlist.h"
#include "Cash.h"
#include "Credit.h"
#include "Check.h"

class Transaction
{
public:
    Transaction();
    ~Transaction();
    void do_transaction(OrderList& ordl);
    void edtitransaction();
    void printtransaction();
    int gettid();

protected:

private:
    int tid;
    Payment** pay;
    Order* ordr;
    string transaction_date;
};

#endif // TRANSACTION_H
