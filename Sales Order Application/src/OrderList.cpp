#include "OrderList.h"

int OrderList::Ocounter=0;
OrderList::OrderList()
{
    orderlist = new Order [100];
}

OrderList::~OrderList()
{
    delete[] orderlist;
}

void OrderList::Total_Profits()
{
    for(int i=0; i<Ocounter; i++)
    {
        cout<<"\nProfit of Order ["<<(i+1)<<"] = "
            <<orderlist[i].getO_Profit()<<endl;
    }
}

void OrderList::CreateOrders(Stock& sto, Customers& cust)
{
    orderlist[Ocounter++].createOrder(sto,cust);
}
void OrderList::UpdateOrders()
{
    int edited;
    cout<<"Enter Order ID to Edit: ";
    cin>>edited;
    bool check= false;
    for(auto i=0; i<Ocounter; i++)
    {
        if(edited==orderlist[i].getOid())
        {
            orderlist[i].editOrder();
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

void OrderList::PrintOrders()
{
    for(auto i=0; i<Ocounter; i++)
    {
        cout<<"\t----------------------------------------------------------------\n";
        cout<<"Order ["<<(i+1)<<"] Details: \n\n";
        cout<<std::left<<"    ";
        cout<<setw(15)<<"ID"
            <<setw(15)<<"Number"
            <<setw(15)<<"Total Price"
            <<setw(15)<<"Status"
            <<setw(25)<<"    Date"
            <<endl;
        cout<<"    ";

        orderlist[i].printOrder();
        cout<<endl;
    }

}

void OrderList::DeleteOrders()
{
    int deleted;
    cout<<"Enter Order ID to Delete: ";
    cin>>deleted;
    bool check= false;
    for(auto i=0; i<Ocounter; i++)
    {
        if(deleted==orderlist[i].getOid())
        {
            if(i==Ocounter-1)
            {
                Ocounter--;
            }
            else
            {
                orderlist[i]=orderlist[Ocounter-1];
                Ocounter--;
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

int OrderList::isO_found(int ido)
{
    for(int i=0; i<Ocounter; i++)
    {
        if(ido==orderlist[i].getOid())
        {
            return i+1;
            break;
        }
    }
    return 0;
}

Order* OrderList::findOrder(int index)
{
    return (orderlist+(index-1));
}
