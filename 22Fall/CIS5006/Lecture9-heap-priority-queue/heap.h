template <class ItemType>
void swap(ItemType &one, Item &two);

template <class ItemType>
struct HeapType
{
    void ReheapDown(int root, int bottom);
    void RehapUP(int root, int bottom);
    ItemType *elements;
    int numElements;
};


template <class ItemType>
void swap(ItemType &one, ItemType &two)
{
    Itemtype temp;
    temp = one;
    one = two;
    two = temp;
}

template <class ItemType>
void HeapType<ItemType>::RehapUP(int root, int bottom)
{
    int parent;
    if (bottom > root)//index compare, bottom in general is larger than root
    {
        parent = (bottom - 1)/2;
        if (elements[parent] < elements[bottom])
        {
            swap(elements[parent], elements[bottom]);
            RehapUP(root, parent);
        }
    }
}

template <class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = 2*root +1;
    rightChild = 2*root +2;
    if (leftChild == bottom)
        maxChild = leftChild;
    else
    {
        if (elements[leftChild] <= elements[rightChild])
            maxChild = rightChild;
        else 
            maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
        swap(elements[root], elements[maxChild]);
        ReheapDown(maxChild,bottom);
    }
}