template<class ItemType>

void ReheapDown(ItemType elements[], int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;
    leftChild = 2*root +1;
    rightChild = 2*root +2;

    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (elements[leftChild] <= elements[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
    }
    if (elements[root]< elements[maxChild])
    {
        swap(elements[root],elements[maxChild]);
        ReheapDown(elements, maxChild,bottom);
    }
}


template <class ItemType>
void HeapSort(ItemType values[], int numValues)
{
    int index;

    //convert the array of values into a heap
    for (index = numValues/2 -1; index>=0; index--)
    {
        ReheapDown(values, index, numValues-1);
    }
    
    //sort the array
    for (index = numValues -1; index >=1; index--)
    {
        swap(values[0],values[index]);
        ReheapDown(values,0, index-1);
    }
}