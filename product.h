/*************************
**Jonathan Uy		**
**Professor Kounavelis  **
**1/31/17		**
**product.h		**
*************************/

#ifndef PRODUCT_H
#define PRODUCT_H

struct productType
{
    string product;
    double price;
    struct productType *link;
};

class Product
{
   public:
      Product();
      int  getCurrentSize();
      bool isEmpty();
      void add(string, double);
      bool remove(string);
      int  getFreq(string);
      bool contains(string);
      void display();
      
   private:
      struct productType *anchor;
      struct productType *end;
      int numOfProducts;
      int count;
      double total;

};
#endif
