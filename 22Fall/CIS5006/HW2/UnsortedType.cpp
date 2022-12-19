
#include <iostream>
#include "UnsortedType.h"




UnsortedType::UnsortedType(){

    nextIndex = 0;
    pa = new ItemType[10];
    for (int i =0; i<10;i++){
        pa[i].Initialize(0);
    }
    delete [] pa;
}

UnsortedType::UnsortedType(int size){
    length = size;
    pa = new ItemType[length];
    for (int i = 0; i < length; i++){
        pa[i].Initialize(0);
    }
    delete[] pa;
}

int UnsortedType::size(){
    return length;
}

bool UnsortedType::isFull() const{
    if (length == nextIndex){
        return true;
    }
    return false;
}

ItemType & UnsortedType::operator[](int index){
     ItemType *paNew;
    if (index > length){
        paNew = new ItemType[index + 10];
        for (int i = 0; i < nextIndex; i++){
            paNew[i] = pa[i];
        }
        for (int j = nextIndex; j < index+10; j++){
            paNew[j].Initialize(0);
        }
        delete [] pa;
        pa = paNew;
        length = index + 10;
    }
    return *(pa+index);
}

void UnsortedType::PutItem(ItemType item){
    if (nextIndex == length){//may can use if(isfull())
        length = 2* length;
    ItemType * paNew2 = new ItemType[length];
    for (int i = 0; i < nextIndex; i++){
        paNew2[i] = pa[i];
    }
    for (int j =nextIndex; j< length; j++ ){
        paNew2[j].Initialize(0);
    }
    delete [] pa;
    pa = paNew2;
    pa[nextIndex+1] = item;
    }
    else{
        pa[nextIndex] = item;
        nextIndex++;
    }

}

UnsortedType::~UnsortedType(){
    delete [] pa;
}