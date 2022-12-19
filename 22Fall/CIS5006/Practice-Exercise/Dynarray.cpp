#include <iostream>
#include "Dynarray.h"

using namespace std;

Dynarray::Dynarray(){
    length = 10;
    nextIndex = 0;
    pa = new int [10];
    for (int i = 0; i< 10; i++){
        pa[i] = 0;
    }
    //need to initialize pointer?
    //we want to extend the array at the end, this is 
    //why we use dynamic array.
    delete[] pa;
}


int & Dynarray::operator[](int index){
// still struggling.
    int * paNew;
    if (index > length){
        paNew = new int[index +10];//create a new dynamic array.
        for (int i = 0; i <nextIndex; i++){
            paNew[i]=pa[i]
        }

        for (int j = nextIndex; j<index+10;j++){
            paNew[j]=0;
        }

        delete[] pa;
        pa = paNew;
    }
    return *(pa+index);// or return pa[index]

}

void Dynarray::add(int val){}{
    //how to access the element of the dynamic array?
    //if know, use it to add val
    int *paNEW;
    if (nextIndex == length){
        length = length +10;
        paNew = new int[length];
        for (int i = 0; i< nextIndex; i++){
            paNEW[i] = pa[i];
        }
        for (int j = nextIndex; j < length; j++){
            paNEW[j] = 0;
        }
        delete [] pa;
        pa = paNEW;
        pa[nextIndex+1]= val;
    }
    nextIndex++;
}