#include "StackType.h"
#include <iostream>

struct NodeType{
    int info;
    NodeType * next;
};

StackType::StackType(){
    topPtr = NULL;// note: in linked list, it's pointer, to null. In static array, set it to -1.
}

void StackType::Push(int newItem){
    if(isFull()) throw FullStack();
    
    NodeType * location;
    location->info = newItem;
    location->next = topPtr;//downwards
    topPtr = location;

}

void StackType::Pop(){
    if (isEmpty()) throw EmptyStack();

    NodeType * temp;
    temp = topPtr;
    topPtr = topPtr->next; //downwards
    delete temp;
}

int StackType::Top(){
    if (isFull()) throw FullStack();
    return topPtr->info;
}

bool StackType::isFull() const{
    NodeType * location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}

bool StackType::isEmpty() const{
    return (topPtr == NULL);
}

StackType::~StackType(){
    NodeType * temp;

    while(topPtr!= NULL){//not empty
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}