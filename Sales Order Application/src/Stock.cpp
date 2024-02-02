#include "Stock.h"

Stock::Stock()
{
    stocklist=new Product[100];
    Scounter=0;
}

Stock::~Stock()
{
    delete[] stocklist;
}
double Stock::getPrice(int Pid)
{
    for(int i=0; i<Scounter; i++)
    {
        if(Pid==stocklist[i].getP_ID())
        {
            return stocklist[i].getPrice();
            break;
        }
    }
}

int Stock::getS_Quantity(int Pid)
{
    for(int i=0; i<Scounter; i++)
    {
        if(Pid==stocklist[i].getP_ID())
        {
            return stocklist[i].getQuantity();
            break;
        }
    }
}

void Stock::updateS_Quantity(int Pid,int sq)
{
    for(int i=0; i<Scounter; i++)
    {
        if(Pid==stocklist[i].getP_ID())
        {
            stocklist[i].setQuantity(sq);
            break;
        }
    }
}
void Stock::printStock()
{
    cout<<std::left<<"     ";
    cout<<setw(13)<<"ID"
        <<setw(15)<<"Number"
        <<setw(15)<<"Name"
        <<setw(15)<<"Type"
        <<setw(15)<<"Price"
        <<setw(15)<<"Quantity"<<endl;
    for(auto i=0; i<Scounter; i++)
    {
        cout<<"["<<(i+1)<<"]  "
            <<stocklist[i]<<endl;
    }
    cout<<endl;
}

void Stock::addtoStock(ProductList& ps)
{
    Product pp;
    ps.printProducts();
    cout<<"Choose a Product by ID to store in the Stock: ";
    int Pid;
    cin>>Pid;

    if(ps.isfound(Pid))
    {
        int index= ps.isfound(Pid);
        pp=ps.findProduct(index);
        cout<<"Enter Quantity to store: ";
        int q;
        cin>>q;
        stocklist[Scounter]=pp;
        stocklist[Scounter++].setQuantity(q);
        cout<<"Successfully Added\n\n";
    }
    else
    {
        cout<<"ID is not Exist\n";
    }
}
void Stock::updateStock()
{
    int edited;
    cout<<"Enter Product ID to Edit: ";
    cin>>edited;
    bool check= false;
    for(auto i=0; i<Scounter; i++)
    {
        if(edited==stocklist[i].getP_ID())
        {
            stocklist[i].editQuantity();
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
void Stock::deleteStock()
{
    int deleted;
    cout<<"Enter Product ID to Delete: ";
    cin>>deleted;
    bool check= false;
    for(auto i=0; i<Scounter; i++)
    {
        if(deleted==stocklist[i].getP_ID())
        {
            if(i==Scounter-1)
            {
                Scounter--;
            }
            else
            {
                stocklist[i]=stocklist[Scounter-1];
                Scounter--;
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

int Stock::isS_found(int Pid)
{

    for(int i=0; i<Scounter; i++)
    {
        if(Pid==stocklist[i].getP_ID())
        {
            return i+1;
            break;
        }
    }
    return 0;
}
Product Stock::findS_Product(int index)
{
    return stocklist[index-1];
}
