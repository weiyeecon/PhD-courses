#ifndef UNSORTEDLISTARRAY_H
#define UNSORTEDLISTARRAY_H



class UnsortedListArray{
public:
    int findElement(int arr[], int n, int key);
    int insertUnsorted(int arr[],int n, int key, int capacity);
    int deleteElement(int arr[], int n, int key);

private:

    int arr[size];
    int size;

};



#endif