/*
 * Jonathan Uy
 * Professor Kounavelis
 * 1/31/17
 * Implementation file for class "Product" 
 */

Product::Product()
{
    anchor = NULL;
    end = NULL;
    numOfProducts = 0;
    total = 0.0;
}

int Product::getCurrentSize()
{

return numOfProducts;
}

bool Product::isEmpty()
{
    bool empty = false;

    if(numOfProducts == 0)
	empty = true;

return empty;
}

void Product::add(string product, double price)
{
    struct productType *node;

    if(anchor == NULL)
    {
	anchor = new productType;

	anchor->product = product;
	anchor->price = price;
	anchor->link = NULL;

	end = anchor;

	numOfProducts++;
    }

    else
    {
	node = new productType;
	
	node->product = product;
	node->price = price;
	node->link = NULL;

	end->link = node;
	end = node;

	numOfProducts++;
    }

    total += price;
}

bool Product::remove(string product)
{
    bool remove = false;

    struct productType *removePtr, *prevPtr;//two pointers needed for relink

    removePtr = prevPtr = anchor;//start with anchor

    if(anchor == NULL)
    {
	remove = false;
    }

    else
    {
	while(removePtr != end)
        {
	    prevPtr = removePtr;//sets temp to removePtr before increment
	    removePtr = removePtr->link;//move to next node
	
            if(removePtr->product == product)
	    {
		prevPtr->link = removePtr->link;//previous node link = current node link

		numOfProducts--;
		total -= removePtr->price;

		remove = true;
		break;  
	    }
        }

	prevPtr = removePtr;//sets temp to removePtr before increment
	removePtr = removePtr->link;//move to next node
	
	if(removePtr->product == product)//checks if remove is end
        {   
	    end = prevPtr;//end = node before removal
      
            numOfProducts--;
            total -= removePtr->price;
            remove = true;
        }
    }  
return remove;
}

int Product::getFreq(string product)
{
    struct productType *findPtr;

    findPtr = anchor;

    while(findPtr != end)
    {
	if(findPtr->product == product)
	{
	    count++;
	}
	
	findPtr = findPtr->link;
    }

return count; 
}

bool Product::contains(string product)
{
    bool find = false;

    struct productType *findPtr;

    findPtr = anchor;

    if(anchor == NULL)
    {
	find = false;
    }

    else
    {
        while(findPtr != end)
        {
	    if(findPtr->product == product)
	    {
	        find = true;
	        break;
            }
	
	    findPtr = findPtr->link;//cycles through list, stops before end
        }

        if(findPtr->product == product)//checks end
        {
	    find = true;
        }
    }
return find;
}

void Product::display()
{
    struct productType *displayPtr;

    displayPtr = anchor;

    if(anchor == NULL)
    {
    }

    else
    {
        while(displayPtr != end)//cuts off end
        {
	     cout << "Product: " << displayPtr->product <<endl;
             cout << "Price: " <<  displayPtr->price << endl << endl;
        
             displayPtr = displayPtr->link;
        }

        if(displayPtr == end)//display end
        {
	     cout << "Product: " << displayPtr->product <<endl;
             cout << "Price: " <<  displayPtr->price << endl << endl;    
        }
    }

    cout << endl << endl;
    cout << "Total number of Products: " << getCurrentSize() <<endl;
    cout << "Total Price: " << total <<endl;
}
