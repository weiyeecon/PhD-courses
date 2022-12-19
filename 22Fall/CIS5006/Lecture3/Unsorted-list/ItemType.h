#ifndef ITEMTYPE_H
#define ITEMTYPE_H


#include <fstream>

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
private:
    int value;

public:
    ItemType();
    RelationType ComparedTo(ItemType) const;
    void Print(std::ostream&) const;
    void Initialize(int number);
};





#endif