#include <iostream>
#include "heap.h"


template <class ItemType>
void swap(ItemType &one, ItemType &two)
{
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}

template <class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
    int parent;
    if (bottom > root)
    {
        parent = (bottom - 1)/2;
        if (elements[parent] < elements[bottom])
        {
            swap(elements[parent],elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}

template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = 2 * root + 1;
    rightChild = 2*root +2;
    if(leftChild == bottom)
        maxChild = leftChild;
    else
    {
        if (elements[leftChild] <= elements[rightChild])
            maxChild = rightChild;
        else    
            maxChild = leftChild;
    }
    if(elements[root] < elements[maxChild])
    {
        swap(elements[root],elements[maxChild]);
        ReheapDown(maxChild,bottom);
    }
}

//test. The reason Why I test in heap.cpp and PQType.cpp is that when i 
// use main.cpp, it always shows main can not be template. But when I 
//test seperately, it shows no error.
int main()
{   
    int MaxIndex = 8;
    HeapType<int> heaps;
    heaps.elements = new int[MaxIndex];
    int arr[] = {10, 4, 7, 3,5,6, 8,9};
    for (int i = 0; i < MaxIndex; i++)
    {
        heaps.elements[i] = arr[i];
    }
    heaps.ReheapDown(0,7);
    heaps.ReheapUp(0,7);

    return 0;
}