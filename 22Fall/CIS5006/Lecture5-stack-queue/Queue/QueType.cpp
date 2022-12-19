#include "QueType.h"


QueType::QueType(){
    maxQue = 501;
    front = maxQue - 1;
    rear = maxQue -1;
    items = new int[maxQue];
}

QueType::QueType(int max){
    maxQue = max + 1; //notice: here is max+1
    front = maxQue -1;
    rear = maxQue -1;
    items = new int[maxQue];
}

void QueType::MakeEmpty(){
    front = maxQue -1;
    rear = maxQue -1;
}

bool QueType::isEmpty()const{
    return (front == rear);
}

bool QueType::isFull() const{
    return ((rear+1)%maxQue == front);
}

void QueType::Enqueue(int newItem){
    if (isFull()) throw FullQueue();
    rear = (rear+1)%maxQue;
    items[rear] = newItem;//update rear, then assign list rear to a new item.
}

void QueType::Dequeue(int &item){
    if (isEmpty()) throw EmptyQueue();
    front = (front+1)%maxQue;
    item = items[front];
}//Note: update front first, then assign it(not list, but reference item) to new front. 

