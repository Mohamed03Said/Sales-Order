#include "Order.h"

Order::Order()
{
    Oid=0;
    number=(rand() % 1000000)+1;
    total=0.0;
    Oprofit=0.0;
    ords= OrderStatus::NEW;
    itemslist = new OrderItem [50];
    customr= new Customer();
    Icounter=0;
}

Order::~Order()
{
    delete[] customr;
    delete[] itemslist;
}

double long Order::getO_Profit()
{

    for(int i=0; i<Icounter; i++)
    {
        Oprofit += itemslist[i].getProfit();
    }
    return Oprofit;
}


void Order::createOrder(Stock& sto, Customers& cust)
{
    cout<<"\nEnter Order ID: ";
    cin>>Oid;

    cout<<"Enter Customer ID: ";
    int cid;
    cin>>cid;
    if(cust.isC_found(cid))
    {
        int index= cust.isC_found(cid);
        customr = cust.findS_Customer(index);
        cout<<"Enter number of Items Customer want to ADD: ";
        int num;
        cin>>num;
        while(num--)
        {
            cout<<"\nAdd Item number "<<(Icounter+1)<<endl;
            itemslist[Icounter].addItem(sto);
            Icounter++;
        }
        cout<<endl;
    }
    else
    {
        cout<<"This ID is not found..\n";
    }
    for(int i=0;i<Icounter;i++)
    {
        if(itemslist[i].getO_quantity()<1)
        {
            itemslist[i]=itemslist[Icounter-1];
            Icounter--;
        }
    }
}

ostream& operator<<(ostream& out, Order& order)
{
    out<<std::left;
    out<<setw(15)<<order.Oid
       <<setw(15)<<order.number
       <<setw(15)<<order.gettotOPrice();
    if(order.ords==OrderStatus::NEW)
        out<<setw(15)<<"NEW";
    else if(order.ords==OrderStatus::HOLD)
        out<<setw(15)<<"HOLD";
    else if(order.ords==OrderStatus::PAID)
        out<<setw(15)<<"PAID";
    else
        out<<setw(15)<<"CANCELED";
    out<<setw(25)<<order.date
       <<endl;
    return out;
}

void Order::printOrder()
{
    cout<<std::left;
    cout<<setw(15)<<Oid
       <<setw(15)<<number
       <<setw(15)<<gettotOPrice();
    if(ords==OrderStatus::NEW)
        cout<<setw(15)<<"NEW";
    else if(ords==OrderStatus::HOLD)
        cout<<setw(15)<<"HOLD";
    else if(ords==OrderStatus::PAID)
        cout<<setw(15)<<"PAID";
    else
        cout<<setw(15)<<"CANCELED";
    cout<<setw(25)<<date
       <<endl;

    cout<<"\nCustomer Name: "<<customr->getname()<<"\tCustomer ID: "<<customr->getid()<<endl;
    cout<<std::left;
    cout<<"\nItems Details....\n\n";
    cout<<setw(19)<<"    ID"
        <<setw(15)<<"Number"
        <<setw(15)<<"Name"
        <<setw(15)<<"Type"
        <<setw(15)<<"Price for 1"
        <<setw(15)<<"Quantity"
        <<endl;
    for(int i=0; i<Icounter; i++)
    {
        cout<<"["<<(i+1)<<"]  ";
        (itemslist + i)->printItem();
    }
}

istream& operator>>(istream& in, Order& order)
{
    cout<<"Enter Order ID: ";
    in>>order.Oid;
    return in;
}
void Order::editOrder()
{
    cout<<"[1].Edit Order ID\t"
        <<"[2].Update Order Status\t";
    int choice;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter new ID: ";
        cin>>Oid;
        break;
    case 2:
        updateStatus();
        break;
    default:
        cout<<"enter an exist choice..\n";
    }
}
void Order::updateStatus()
{
    int status;
    cout<<"[1].NEW\n";
    cout<<"[2].HOLD\n";
    cout<<"[3].PAID\n";
    cout<<"[4].CANCELED\n";
    cin>>status;
    bool isupdated=true;
    switch(status)
    {
    case 1:
        ords= OrderStatus::NEW;
        break;
    case 2:
        ords= OrderStatus::HOLD;
        break;
    case 3:
        ords= OrderStatus::PAID;
        break;
    case 4:
        ords= OrderStatus::CANCELED;
        break;
    default:
        cout<<"This Choice is not an Exist Status\n";
        isupdated=false;
    }

    if(isupdated)
        cout<<"Updated Successfully\n";
}
int Order::getOid()
{
    return Oid;
}

double Order::gettotOPrice()
{
    for(int i=0; i<Icounter; i++)
    {
        total+=itemslist[i].gettotPriceSale();
    }
    return total;
}


