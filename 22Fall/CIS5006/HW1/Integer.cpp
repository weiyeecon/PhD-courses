//I still take Integer.cpp (the first version) on the blackboard as my reference. I mainly add and modify my codes based on it. 

#include "Integer.h"
#include <iostream>
using namespace std;

Integer::Integer() : digit(0)//no error dected, just initialization
{
}
Integer::Integer(int dig) //No error
{
    digit = dig;
}
void Integer::input()//no error
{
    cin >> digit;
}
void Integer::output() const//no error
{
    cout << digit;
}
int Integer::getdig(){ // just set up an getter function
    return digit;
}
Integer Integer::operator+(const Integer in)
{
    (*this).digit = (*this).digit + in.digit;
    return (*this);
}
bool Integer::operator==(const Integer in)//Shows error on operator. why can't set up bool when the return type is bool?
{
    if ((*this).digit == in.digit){
        return true;
    }else{
        return false;
    }
}
bool Integer::operator!=(const Integer in)//Show error, same reason as before
{
    if ((*this).digit!= in.digit){
        return true;
    }else{
        return false;
    }
}
bool Integer::operator>=(const Integer in)//Show error. Same reason
{
    if ((*this).digit >= in.digit){
        return true;
    }else{
        return false;
    }
}
bool Integer::operator<=(const Integer in)//Show error same reason.
{
    if ((*this).digit <= in.digit){
        return true;
    }else{
        return false;
    }
}
bool Integer::isZero()// Not sure
{
    if ((*this).digit == 0){
        return true;
    }else {
        return false;
    }
}
Integer Integer::operator++()
{
    (*this).digit++;
    return (*this);
}
Integer Integer::operator--()
{
    (*this).digit--;
    return (*this);
}
Integer Integer::operator*(const Integer in)
{
    (*this).digit = (*this).digit * in.digit;
    return (*this);
}
Integer Integer::operator/(const Integer in)
{
    (*this).digit = (*this).digit/ in.digit;
    return (*this);
}

int main(){
    Integer i1, i2;
    // Begin overloading test.
    i1.input();
    i1.output();
    Integer i3;
    i3= i1 + i2;
    i1 ++;
    i2 --;
    if (i1 == i2){
        cout << " It's perfectly true." << endl;
    }else {
        cout << " Unfortunately, it's false."
    }
    if (i1 <= i2){
        cout << "It's comprable. i1 is less or equal to i2." << endl; 
    } else{
        cout << " Not, i1 is larger."
    }
    if (i1 != i2){
        cout << " i1 is not equal to i2." << endl;
    }
    Integer i5;
    i5 = i1 * i2;
    
}