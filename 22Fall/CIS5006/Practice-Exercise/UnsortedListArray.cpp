#include <iostream>
#include "UnsortedListArray.h"

using namespace std;

int UnsortedListArray::findElement(int arr[],int n,int key){
    int i;
    for (i = 0; i<n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}

int UnsortedListArray::insertUnsorted(int arr[],int n, int key, int capacity){
        if (n > capacity){
            return n;
        } else{
            arr[n+1]= key;
            return n+1;
        }


}

int UnsortedListArray::deleteElement(int arr[],int n, int key){
    int pos = findElement(arr, n, key);
    if (pos == -1){
        cout << "Element not found";
        return n;
    }

    //delete element
    int i;
    for (i = pos; i< n-1; i++){
        arr[i]=arr[i+1];
    }
    return n-1;
}