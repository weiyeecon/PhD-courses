
template<typename ItemType>
void Swap(ItemType x, ItemType y)
{
    ItemType Temp;
    temp = y;
    y = x;
    x = temp;
}

template<typename ItemType>

void InsertItem(ItemType values[],int startIndex, int endIndex)
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);

    while(moreToSearch && !finished)
    {
        if (values[current] < values[current-1])
        {
            Swap(values[current], values[current-1]);
            current--;
            moreToSearch = (current!= startIndex);
        }
        else
            finished = true;
    }
}


template <typename ItemType>
void InsertionSort(ItemType values[], int numValues)
{
    for (int count = 0; count < numValues; count ++)
      InsertItem(values, 0, count);
}