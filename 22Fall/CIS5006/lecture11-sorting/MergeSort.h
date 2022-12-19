int const SIZE;
template <typename ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
    ItemType tempArray(SIZE);
    int index = leftFirst;
    int saveFirst = leftFirst;

    while((leftFirst <= leftLast) && (rightFirst <= rightLast))//index
    {
        if (values[leftFirst]< values[rightFirst])
        {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }

    while(leftFirst <= leftLast)
    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }

    while (rightFirst <= rightLast)
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }

    for (index = saveFirst; index <= rightLast;index++)
    {
        values[index] = tempArray[index];
    }
    
}



template<typename ItemType>
void MergeSort(ItemType values[], int first, int last)
{
    if (first < last)
    {
        int middle = first+(last-first)/2;
        MergeSort(values,first,middle);
        MergeSort(values, middle+1, last);
        Merge(values, first, middle,middle+1, last);
    }
}