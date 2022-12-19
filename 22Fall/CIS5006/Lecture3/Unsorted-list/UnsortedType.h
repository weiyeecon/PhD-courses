#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

//Fist, define a struct.
struct NodeType;

class UnsortedType
{
private:
    NodeType * ListData;
    int length;
    NodeType * currentPos;
public:
    UnsortedType();

    ~UnsortedType();

    void MakeEmpty();

    bool isFull() const;

    int GetLength() const;

    ItemType GetItem(ItemType & item, bool &found);

    void PutItem(ItemType item);

    void DeleteItem(ItemType item);

    void ResetList();

    ItemType GetNextItem();


};








#endif