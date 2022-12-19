#include "heap.h"
#include "PQType.h"

template<class ItemType>
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
