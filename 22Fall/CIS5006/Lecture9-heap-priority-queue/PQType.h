//Definition of class PQType, which represents the priority queue ADT
class FullPQ{};
class EmptyPQ{};
#include "heap.h"
template <class ItemType>

class PQType
{
public:
    PQType();
    ~PQType();

    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;

    void Enqueue(ItemType newItem);
    void Dequeue(ItemType &item);

private:
    int length;
    HeapType<ItemType> items;
    int maxItems;
};


//Implementing the class;
template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[max];
    length = 0;
}

template <class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    length = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete [] items.elements;
}

template <class ItemType>
void PQType<ItemType>::Dequeue(ItemType &item)
{
    if (length ==0)
        throw EmptyPQ();
    else
    {
        item = items.elements[0];
        items.elements[0] = items.elements[length -1];
        length--;
        items.ReheapDown(0,length-1);
    }
}

template <class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
{
    if (length == maxItems)
        throw FullPQ();
    else
    {
        legnth ++;
        items.elements[length-1] = newItem;
        items.RehapUP(0,length-1);
    }
}

template<class ItemType>
bool PQType<ItemType>::IsFull() const
{
    return length == maxItems;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
{
    return length == 0;
}