#ifndef DYNARRAY_H
#define DYNARRAY_H

class Dynarray{
private:
    int *pa;//points to the array
    int length;
    int nextIndex;

public:
    Dynarray();
    ~Dynarray();
    int & operator[](int index);
    void add(int val);
    int size();
};



#endif