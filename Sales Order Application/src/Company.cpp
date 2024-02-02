#include "Company.h"

Company::Company()
{
    location= " ";
    company_name= " ";
}

int Company::getid()
{
    return id;
}

string Company::getname()
{
    return company_name;
}

void Company::readCustomer(istream& in)
{
    cout<<"Enter Company Name: ";
    cin>>company_name;
    cout<<"Enter Company Location: ";
    cin>>location;
    cout<<"Enter Company ID: ";
    cin>>id;
    cout<<"Enter Company Phone: ";
    cin>>phone;
}

void Company::printCustomer(ostream& out)
{
    cout<<std::left;
    cout<<"    "<<setw(25)<<
    "Company"<<setw(25)<<
    company_name<<setw(25)<<
    location<<setw(25)<<
    id<<setw(25)<<
    phone<<endl;

}

void Company::editCustomer()
{
    int choice=-1;
    while(choice)
    {
        cout<<"[1].Edit Company Name\n";
        cout<<"[2].Edit Company Location\n";
        cout<<"[3].Edit Company ID\n";
        cout<<"[4].Edit Company Phone\n";
        cout<<"[0].Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            cout<<"Enter new Name: ";
            cin>>company_name;
            break;
        case 2:
            cout<<"Enter new Location: ";
            cin>>location;
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
