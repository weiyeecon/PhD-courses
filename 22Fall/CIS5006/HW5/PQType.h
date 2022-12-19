class FullPQ{};
class EmptyPQ{};
#include "heap.h"
template <class ItemType>

class PQType
{
public:
    PQType(int max);
    ~PQType();
    void MakeEmpty();
    bool isEmpty() const;
    bool isFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType &item);

private:
    int length;
    HeapType<ItemType> items;
    int maxItems;
};
