#include "TransactionList.h"
int TransactionList::Tcounter=0;

TransactionList::TransactionList()
{
    trans= new Transaction[150];
}

TransactionList::~TransactionList()
{
    delete[] trans;
}

void TransactionList::addTransaction(OrderList& ordl)
{
    trans[Tcounter++].do_transaction(ordl);
}
void TransactionList::editTransaction()
{
    int edited;
    cout<<"Enter Transaction ID to Edit: ";
    cin>>edited;
    bool check= false;
    for(auto i=0; i<Tcounter; i++)
    {
        if(edited==trans[i].gettid())
        {
            trans[i].edtitransaction();
            check= true;
            cout<<"Successfully Edited\n";
            break;
        }
    }
    if(!check)
    {
        cout<<"This ID is not Exist\n";
    }
    cout<<endl;
}

void TransactionList::deleteTransaction()
{
    int deleted;
    cout<<"Enter Transaction ID to Delete: ";
    cin>>deleted;
    bool check= false;
    for(auto i=0; i<Tcounter; i++)
    {
        if(deleted==trans[i].gettid())
        {
            if(i==Tcounter-1)
            {
                Tcounter--;
            }
            else
            {
                trans[i]=trans[Tcounter-1];
                Tcounter--;
            }
            check=true;
            cout<<"Successfully Deleted\n";
            break;
        }
    }
    if(!check)
    {
        cout<<"This ID is not Exist\n";
    }
    cout<<endl;
}

void TransactionList::printTransaction()
{
    for(int i=0;i<Tcounter;i++)
    {
        cout<<"\t-------------------------------------------\n";
        cout<<"Transaction ["<<i+1<<"] :\n";
        trans[i].printtransaction();
        cout<<endl;
    }
}
