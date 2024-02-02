#include "Product.h"

Product::Product()
{
    id=0;
    number=" ";
    name=" ";
    price=0.0;
    type=0;
    quantity=0;
}
int Product::getQuantity()
{
    return quantity;
}
string Product::getNumber()
{
    return number;
}
string Product::getName()
{
    return name;
}
int Product::getType()
{
    return type;
}
double Product::getPrice()
{
    return price;
}
int Product::getP_ID()
{
    return id;
}

void Product::updateProduct()
{
    int choice=-1;
    while(choice)
    {
        cout<<"[1].Edit Product ID\n";
        cout<<"[2].Edit Product Number\n";
        cout<<"[3].Edit Product Name\n";
        cout<<"[4].Edit Product Price\n";
        cout<<"[5].Edit Product Type\n";
        cout<<"[0].Exit\n";
        cin>>choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            cout<<"Enter new ID: ";
            cin>>id;
            break;
        case 2:
            cout<<"Enter new Number: ";
            cin>>number;
            break;
        case 3:
            cout<<"Enter new Name: ";
            cin>>name;
            break;
        case 4:
            cout<<"Enter new Price: ";
            cin>>price;
            break;
        default:
            cout<<"Enter an Exist Choice\n";
        }
    }
    cout<<endl;
}
istream& operator>>(istream& in,Product& product)
{
    cout<<"Enter Product ID: ";
    in>>product.id;
    cout<<"Enter Product Number: ";
    in>>product.number;
    cout<<"Enter Product Name: ";
    in>>product.name;
    cout<<"Enter Product Price: ";
    in>>product.price;
    cout<<"Enter Product Type: ";
    in>>product.type;
    return in;
}
ostream& operator<<(ostream& out,Product& product)
{
out<<std::left;
    out<<setw(15)<<product.id
    <<setw(15)<<product.number
    <<setw(15)<<product.name
    <<setw(15)<<product.type
    <<setw(15)<<product.price
    <<setw(15)<<product.quantity<<endl;
    return out;
}
void Product::printP()
{
    cout<<std::left;
    cout<<setw(15)<<id
    <<setw(15)<<number
    <<setw(15)<<name
    <<setw(15)<<type
    <<setw(15)<<price<<endl;
}
void Product::setQuantity(int q)
{
    quantity+=q;
}
void Product::editQuantity()
{
    cout<<"Enter new Quantity: ";
    cin>>quantity;
}
