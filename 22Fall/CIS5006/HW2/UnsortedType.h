#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

class UnsortedType{
public:
    UnsortedType();
    UnsortedType(int size);
    //desctuctor is used to deallocate the memory after we execute; And it's only 
    //way to destroy the object.
    ~UnsortedType();
    bool isFull() const;
    ItemType & operator[](int index);
    void PutItem(ItemType item);
    int size();

private:
    int length;
    ItemType *pa;//Define a pointer to allocate memory in the cpp file
    int nextIndex;


};




#endif