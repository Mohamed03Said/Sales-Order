#include "Person.h"

Person::Person()
{
    full_name= " ";
    billing_address= " ";
}

int Person::getid()
{
    return id;
}

string Person::getname()
{
    return full_name;
}

void Person::readCustomer(istream& in)
{
    cout<<"Enter Person Name: ";
    cin>>full_name;
    cout<<"Enter Person Billing Address: ";
    cin>>billing_address;
    cout<<"Enter Person ID: ";
    cin>>id;
    cout<<"Enter Person Phone: ";
    cin>>phone;
}

void Person::printCustomer(ostream& out)
{
    cout<<std::left;
    cout<<"    "<<setw(25)<<
    "Person"<<setw(25)<<
    full_name<<setw(25)<<
    billing_address<<setw(25)<<
    id<<setw(25)<<
    phone<<endl;
}

void Person::editCustomer()
{
    int choice=-1;
    while(choice)
    {
        cout<<"[1].Edit Person Name\n";
        cout<<"[2].Edit Person Location\n";
        cout<<"[3].Edit Person ID\n";
        cout<<"[4].Edit Person Phone\n";
        cout<<"[0].Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            cout<<"Enter new Name: ";
            cin>>full_name;
            break;
        case 2:
            cout<<"Enter new Billing Address: ";
            cin>>billing_address;
            break;
        case 3:
            cout<<"Enter new ID: ";
            cin>>id;
            break;
        case 4:
            cout<<"Enter new Phone: ";
            cin>>phone;
            break;
        default:
            cout<<"Enter an Exist choice\n";
        }
    }
}
