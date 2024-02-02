#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H
#include "Transaction.h"
#include <fstream>

class TransactionList
{
public:
    TransactionList();
    virtual ~TransactionList();
    void addTransaction(OrderList& ordl);
    void editTransaction();
    void deleteTransaction();
    void printTransaction();

protected:

private:
    static int Tcounter;
    Transaction* trans;
};

#endif // TRANSACTIONLIST_H
