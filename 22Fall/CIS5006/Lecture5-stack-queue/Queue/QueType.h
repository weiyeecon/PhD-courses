#ifndef QUETYPE_H
#define QUETYPE_H

class FullQueue{};

class EmptyQueue{};

class QueType{
public:
    QueType();

    QueType(int max);

    ~QueType();

    void MakeEmpty();

    bool isEmpty() const;

    bool isFull() const;

    void Enqueue(int newItem);

    void Dequeue(int & item);//Note: for dequeue, we pass by reference.

private:
    int front;
    int rear;
    int * items;//Dynamic array method here. so use pointer.
    int maxQue;




};



#endif