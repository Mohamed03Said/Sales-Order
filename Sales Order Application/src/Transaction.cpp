#include "Transaction.h"

Transaction::Transaction()
{
    tid=0;
    transaction_date=__DATE__;
    pay = new Payment*[1];

    ordr = new Order();
}
Transaction::~Transaction()
{
    delete pay;
    delete[] pay;
    delete[] ordr;
}

void Transaction::do_transaction(OrderList& ordl)
{
    cout<<"Enter Transaction ID: ";
    cin>>tid;
    cout<<"Enter Order ID: ";
    int ido;
    cin>>ido;

    if(ordl.isO_found(ido))
    {
        int index= ordl.isO_found(ido);
        ordr = ordl.findOrder(index);
        cout<<"Choose Payment Method...\n";
        cout<<"[1].Credit\t\t[2].Cash\t\t[3].Check\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            pay[0] = new Credit();
            pay[0]->setPayment();
            cout<<"\nSuccessfully Done...\n";
            break;
        case 2:
            pay[0] = new Cash();
            pay[0]->setPayment();
            cout<<"\nSuccessfully Done...\n";
            break;
        case 3:
            pay[0] = new Check();
            pay[0]->setPayment();
            cout<<"\nSuccessfully Done...\n";
            break;
        default:
            cout<<"This is not an Exist Choice...\n";
            break;
        }
    }
    else
        cout<<"This ID is not Found\n";
}
void Transaction::edtitransaction()
{
    cout<<"Enter new Payment Method....\n";
    cout<<"[1].Credit\t\t[2].Cash\t\t[3].Check\n";
    int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            pay[0] = new Credit();
            pay[0]->setPayment();
            break;
        case 2:
            pay[0] = new Cash();
            pay[0]->setPayment();
            break;
        case 3:
            pay[0] = new Check();
            pay[0]->setPayment();
            break;
        default:
            cout<<"This is not an Exist Choice...\n";
            break;
        }
}
void Transaction::printtransaction()
{
    cout<<"\nTransaction Date: "<<transaction_date<<endl;

    cout<<"\nOrder Details: \n\n";
        cout<<std::left<<"    ";
        cout<<setw(15)<<"ID"
            <<setw(15)<<"Number"
            <<setw(15)<<"Total Price"
            <<setw(15)<<"Status"
            <<setw(25)<<"    Date"
            <<endl;
        cout<<"    ";
    ordr[0].printOrder();

    cout<<"\nPayment Details:\n";
    pay[0]->getPayment();
}

int Transaction::gettid()
{
    return tid;
}

