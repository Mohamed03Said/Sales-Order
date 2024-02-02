#include "OrderItem.h"

OrderItem::OrderItem()
{
    produc= new Product();
    sales_price=0.0;
    O_quantity=0.0;
    profit=0.0;
}
double OrderItem::getO_quantity()
{
    return O_quantity;
}
void OrderItem::addItem(Stock& st)
{
    st.printStock();
    cout<<"Choose a Product by ID to make an Order: ";
    int Pid;
    cin>>Pid;

    if(st.isS_found(Pid))
    {
        cout<<"Enter Quantity you want to add: ";
        cin>>O_quantity;
        if(O_quantity>st.getS_Quantity(Pid))
        {
            cout<<"The Maximum Quantity of this Product is: "
                <<st.getS_Quantity(Pid)<<endl;
            O_quantity=0.0;
        }
        else
        {
            int index= st.isS_found(Pid);
            produc[0] = st.findS_Product(index);
            st.updateS_Quantity(Pid,-O_quantity);

            sales_price = (st.getPrice(Pid) + st.getPrice(Pid)*0.25);
            profit=sales_price-st.getPrice(Pid);
            cout<<"Successfully Added...\n";
        }
    }
    else
    {
        cout<<"ID is not Exist\n";
    }
}

double OrderItem::gettotPriceSale()
{
    return (sales_price * O_quantity);
}

double long OrderItem::getProfit()
{
    return (profit * O_quantity);
}

OrderItem OrderItem::operator++()
{
    O_quantity++ ;
    return* this;
}

OrderItem OrderItem::operator--()
{
    O_quantity-- ;
    return* this;
}
OrderItem OrderItem::operator+=(int n)
{
    O_quantity+=n;
    return* this;
}
OrderItem OrderItem::operator-=(int n)
{
    O_quantity-=n;
    return* this;
}

void OrderItem::printItem()
{
    cout<<std::left;
    cout<<setw(15)<<produc->getP_ID()
        <<setw(15)<<produc->getNumber()
        <<setw(15)<<produc->getName()
        <<setw(15)<<produc->getType()
        <<setw(15)<<sales_price
        <<setw(15)<<O_quantity
        <<endl;
}

