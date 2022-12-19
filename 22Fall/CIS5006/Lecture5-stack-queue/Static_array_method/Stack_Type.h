#ifndef STACK_TYPE_H
#define STACK_TYPE_H

//Static version stack

 class FullStack{};

 class EmptyStack{};

 class StackType{
    public:

        StackType();
        bool isFull() const;
        bool isEmpty() const;
        void Push(int item);
        void Pop();
        int Top();
    
    private:
        int top;

        int items[MAX_ITEMS];//fix me. MAX_ITEMS undefined.


 };



#endif