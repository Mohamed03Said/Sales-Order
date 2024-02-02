#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H
#include "Product.h"

class ProductList
{
    public:
        ProductList();
        virtual ~ProductList();
        void addProduct();
        void editProduct();
        void deleteProduct();
        void printProducts();
        Product findProduct(int index);
        int isfound(int Pid);

    protected:

    private:
        Product* productlist;
        static int Pcounter;
};

#endif // PRODUCTLIST_H
