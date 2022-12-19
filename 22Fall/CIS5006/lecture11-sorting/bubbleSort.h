
template<typename ItemType>
void Swap(ItemType x, ItemType y)
{
    ItemType Temp;
    temp = y;
    y = x;
    x = temp;
}

template<typename ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex)
{
    for (int index = endIndex; index > startIndex; index--)
    {
        if (values[index]<values[index-1])
            Swap(values[index], values[index-1]);
    }
}


template<typename ItemType>
void BubbleSort(ItemType values[], int numValues)
//The elements in the array values are sorted by index/key
{
    int current = 0;
    while(current < numValues)
    {
        BubbleUp(values, current, numValues-1);
        current++;
    }
}