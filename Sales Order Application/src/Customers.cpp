#include "Customers.h"
int Customers::Ccounter =0;

Customers::Customers()
{
    customerlist= new Customer* [100];
}

Customers::~Customers()
{
    for(auto i=0; i<Ccounter; i++)
    {
        delete customerlist[i];
    }

    delete []customerlist;
}

void Customers::addCustomer()
{
    int choice=-1;
    while(choice)
    {
        cout<<"[1].Add Company\n";
        cout<<"[2].Add Person\n";
        cout<<"[0].Exist\n";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            customerlist[Ccounter] = new Company;
            cin>>*customerlist[Ccounter++];
            break;
        case 2:
            customerlist[Ccounter] = new Person;
            cin>>*customerlist[Ccounter++];
            break;
        default:
            cout<<"Enter an Exist Choice\n";
        }
        cout<<endl;
    }
}

void Customers::editCustomer()
{
    int edited;
    cout<<"Enter Customer ID to Edit: ";
    cin>>edited;
    bool check= false;
    for(auto i=0; i<Ccounter; i++)
    {
        if(edited==customerlist[i]->getid())
        {
            customerlist[i]->editCustomer();
            check= true;
            cout<<"Successfully Edited\n";
            break;
        }
    }
    if(!check)
    {
        cout<<"This ID not Exist\n";
    }
    cout<<endl;
}

void Customers::deleteCustoemr()
{
    int deleted;
    cout<<"Enter Customer ID to Delete: ";
    cin>>deleted;
    bool check= false;
    for(auto i=0; i<Ccounter; i++)
    {
        if(deleted==customerlist[i]->getid())
        {
            if(i==Ccounter-1)
            {
                Ccounter--;
            }
            else
            {
                customerlist[i]=customerlist[Ccounter-1];
                Ccounter--;
            }
            check=true;
            cout<<"Successfully Deleted\n";
            break;
        }
    }
    if(!check)
    {
        cout<<"This ID not Exist\n";
    }
    cout<<endl;
}

void Customers::printCustomers()
{

    cout<<std::left;
    cout<<setw(30)<<
        "     Customer Type"<<setw(25)<<
        "Name"<<setw(25)<<
        " Address"<<setw(25)<<
        "  ID"<<setw(25)<<
        "Phone"<<endl;
    for(auto i=0; i<Ccounter; i++)
    {
        cout<<"["<<(i+1)<<"]";
        cout<<*customerlist[i];

    }
    cout<<endl;
}

int Customers::isC_found(int cid)
{
    for(int i=0; i<Ccounter; i++)
    {
        if(cid==customerlist[i]->getid())
        {
            return i+1;
            break;
        }
    }
    return 0;
}
Customer* Customers::findS_Customer(int index)
{
    return customerlist[index-1];
}
