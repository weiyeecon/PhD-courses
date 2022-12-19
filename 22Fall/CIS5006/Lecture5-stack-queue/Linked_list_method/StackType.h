#ifndef STACKTYPE_H
#define STACKTYPE_H

struct NodeType; //construct a class is also fine.

class FullStack{};

class EmptyStack{};

class StackType{
public:
    StackType();

    ~StackType();

    void Push(int newItem);

    void Pop();

    int Top();

    bool isFull() const;

    bool isEmpty() const;

private:

    NodeType * topPtr;

};





#endif