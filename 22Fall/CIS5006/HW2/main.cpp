#include <UnsortedType.h>
#include <DateList.h>
#include <cassert>



int main(){
    UnsortedType ut(9);
    ut.isFull();
    ut[3];
    ut.size();
    ItemType it1;
    it1.Initialize(2);
    ut.PutItem(it1);





    DateList DT;
    assert(DT.isFull()==true);
    Date *d1= new Date (2022,9,30);
    if(DT.SearchItem(2022,9,30)){
        DT.PutItem(d1);
    }else{
        throw std::invalid_argument("Please type different date");
    }
    DT.DeleteItem(2022,9,30);
    DT.CompareDate(2018,8,20);
    DT.PrintList();
    DT.EmptyList();





    return 0;
}