#include "Stack_Type.h"
#include <iostream>

StackType::StackType(){
    top = -1;
    maxStack = 500;
    items = new int[maxStack];
}

StackType::StackType(int max){
    top = -1;
    maxStack = max;
    items = new int[maxStack];
}

bool StackType::isEmpty() const{
    return (top == -1);
}

bool StackType::isFull() const{
    return (top == maxStack-1);
}

void StackType::Push(int newItem){
    if (isFull()) throw FullStack();
    top ++;
    items[top] = newItem;
}

void StackType::Pop(){
    if (isEmpty()) throw EmptyStack();
    top --;
}

int StackType::Top(){
    if (isEmpty()) throw EmptyStack();
    return items[top];
}

//Don't forget destructor in dynamic array
StackType::~StackType(){
    delete [] items;
}