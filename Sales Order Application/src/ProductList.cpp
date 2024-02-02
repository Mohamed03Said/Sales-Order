#include "ProductList.h"

int ProductList::Pcounter=0;
ProductList::ProductList()
{
    productlist=new Product[100];
}

ProductList::~ProductList()
{
    delete[] productlist;
}

void ProductList::addProduct()
{
    int num;
    cout<<"Enter Number of Products you want to Add: ";
    cin>>num;
    while(num--)
    {
        cout<<"Enter the Product "<<(Pcounter+1)<<endl;
        cin>>productlist[Pcounter++];
        cout<<endl;
    }
    cout<<endl;
}

void ProductList::editProduct()
{
    int edited;
    cout<<"Enter Product ID to Edit: ";
    cin>>edited;
    bool check= false;
    for(auto i=0; i<Pcounter; i++)
    {
        if(edited==productlist[i].getP_ID())
        {
            productlist[i].updateProduct();
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
void ProductList::deleteProduct()
{
    int deleted;
    cout<<"Enter Product ID to Delete: ";
    cin>>deleted;
    bool check= false;
    for(auto i=0; i<Pcounter; i++)
    {
        if(deleted==productlist[i].getP_ID())
        {
            if(i==Pcounter-1)
            {
                Pcounter--;
            }
            else
            {
                productlist[i]=productlist[Pcounter-1];
                Pcounter--;
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

void ProductList::printProducts()
{
    cout<<std::left<<"     ";
    cout<<setw(13)<<"ID"
        <<setw(15)<<"Number"
        <<setw(15)<<"Name"
        <<setw(15)<<"Type"
        <<setw(15)<<"Price"
        <<endl;
    for(auto i=0; i<Pcounter; i++)
    {
        cout<<"["<<(i+1)<<"]  ";
        productlist[i].printP();
        cout<<endl;
    }
}

int ProductList::isfound(int Pid)
{

    for(int i=0; i<Pcounter; i++)
    {
        if(Pid==productlist[i].getP_ID())
        {
            return (i+1);
            break;
        }
    }
    return 0;
}

Product ProductList::findProduct(int index)
{
    return productlist[index-1];
}
