#ifndef STACK_TYPE_H
#define STACK_TYPE_H

class FullStack{};

class EmptyStack{};

class StackType{
public:
    StackType();

    StackType(int size);

    ~StackType();

    bool isFull() const;

    bool isEmpty() const;

    void Push(int item);

    void Pop();

    int Top();



private:
    int top;
    int maxStack;
    int *items;//This distinguishes it's dynamic array. dynamic allocation using pointer.



};


#endif