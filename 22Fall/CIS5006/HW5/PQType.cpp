#include "PQType.h"
#include<iostream>
using namespace std;

template <class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[max];
    length = 0;
}

template<class Itemtype>
void PQType<Itemtype>::MakeEmpty()
{
    length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete [] items.elements;
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
    if (length == maxItems)
        throw FullPQ();
    else
    {
        length++;
        items.elements[length-1] = newItem;
        items.ReheapUp(0,length-1);
    }
}

template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType &item)
{
    if (length ==0)
        throw EmptyPQ();
    else{
        item = items.elements[0];
        items.elements[0]=items.elements[length -1];
        length--;
        items.ReheapDown(0,length-1);//root, bottom
    }
}

template<class ItemType>
bool PQType<ItemType>::isFull() const
{
    return length == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::isEmpty() const
{
    return length == 0;
}


int main()
{
    PQType<int> pqt(8);
    pqt.Enqueue(10);
    pqt.Enqueue(20);
    pqt.Enqueue(30);
    std::cout<< pqt.isEmpty() << std::endl;
    std::cout<< pqt.isFull() << std::endl;


    pqt.MakeEmpty();
    std::cout<<pqt.isEmpty()<<std::endl;

    return 0;
}

