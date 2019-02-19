/*************************
**Jonathan Uy		    **
**Professor Kounavelis	**
**1/31/17		        **
**main.cpp		        **
*************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
using namespace std;

#include "product.h"
#include "product.cpp"

Product cart;

int main()
{
   string input, prod, price;

   while (1)
   {
      system("clear");
      cart.display();

      cout << endl << endl;
      cout << "Enter A=Add, R=Remove, C=Contains or Q=quit : ";
      getline(cin,input);

      if (input.length() >= 1)
      {
         if (input.at(0) == 'Q'|| input.at(0) == 'q')
         {
            break;
         }
         else if (input.at(0) == 'A' || input.at(0) == 'a') 
         {
            cout << endl << endl;
            cout << " Enter the Product Name (ADD) : ";
            getline(cin,prod);
            cout << "Enter the Product Price (ADD) : ";
            getline(cin,price);

            cart.add(prod, atof(price.c_str()));
         }
         else if (input.at(0) == 'R' || input.at(0) == 'r')
         {
             if (cart.isEmpty())
             {
                cout << endl << endl << "Sorry. The cart is empty." << endl;
                sleep (3);
             }

             else
             {
                cout << endl << endl;
                cout << " Enter the Product Name (REMOVE) : ";
                getline(cin,prod);

                if (cart.remove(prod) == true)
                {
                   cout << endl << endl 
                        << " ***** Product is being removed from the cart!......" << endl;
 
                   sleep (3);
                }

                else
                {
                   cout << endl << endl 
                        << " ***** The product was NOT found in the cart! ***** " << endl;

                   sleep (3);
                }
             }
         }

         else if (input.at(0) == 'C' || input.at(0) == 'c')
         {
             if (cart.isEmpty())
             {
                cout << endl << endl << "Sorry. The cart is empty." << endl;
                sleep (3);
             }

             else
             {
                cout << endl << endl;
                cout << " Enter the Product Name (CONTAINS) : ";
                getline(cin,prod);

                if (cart.contains(prod))
                {
                 cout << endl << endl 
                     << " ***** Yes. The product is in the cart! ***** " << endl
		     << "You have " << cart.getFreq(prod) << " of " "" << prod << "" " in the cart." <<endl;
                   sleep (3);
                }

                else
                {
                  cout << endl << endl 
                       << " ***** No. The product is not in the cart! ***** " << endl;

                  sleep (3);
                }
             }
         }

         else
         {
            continue;
         }
      }
   }//end while
return 0;
}//end main
