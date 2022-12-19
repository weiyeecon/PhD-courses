#include "Stack_Type.h"
#include <iostream>

//Static stack version, the size is fixed. 
StackType::StackType(){
    top = -1;
}

bool StackType::isFull() const{
    return (top == MAX_ITEMS -1);
}

bool StackType::isEmpty() const{
    return (top == -1);
}

void StackType::Push(int newItem){
    if (isFull()) throw FullStack();
    top++;
    items[top] = newItem;
}

void StackType::Pop(){
    if (isEmpty()) throw EmptyStack();
    top--;
}

int StackType::Top(){
    if (isEmpty()) throw EmptyStack();
    return items[top];
}