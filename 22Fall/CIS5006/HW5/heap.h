#ifndef HEAP_H
#define HEAP_H

template <class ItemType>
struct HeapType{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);
    ItemType *elements;
    int numElements;
};

template <class ItemType>
void swap(ItemType &one, ItemType &two);
#endif