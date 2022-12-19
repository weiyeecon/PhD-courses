#include <iostream>
#include "DateList.h"

//Note: I use dummyhead techniques in the link list. It's a little bit tedious, but it's helpful when I want to return link list head.

struct Date{
    int Year;
    int Month;
    int Day;
    Date * next;
    Date(int year, int month, int day): Year(year), Month(month),Day(day),next(NULL){}//initialize the struct
};

DateList::DateList(){
    length =0;
    ListDate = NULL;
}

bool DateList::isFull() const{
    // This function follows the file professor provides on blackboard.
    Date * location;
    try{
        location = new Date(2022,10,01);
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}

void DateList::PutItem(Date * newDate){
    newDate = new Date(2022,10,3);
    Date * dummyHead = new Date(0,0,0);
    dummyHead->next = ListDate;
    newDate->next = ListDate;
    newDate = dummyHead->next;
    delete dummyHead;
    length ++;
}

//compareDate is a little tedious, but since the professor didn't say it must return bool. I return int for the convience of comparing 3 scenarios.
//2 means more recent, -2 means older days, 1 means same day. if link list is nullptr, return -1, quit the loop.
int DateList::CompareDate(int year, int month, int day){

    Date *dummyhead = new Date(0,0,0);
    dummyhead->next = ListDate;
    Date * curr = dummyhead;
    while(curr->next != nullptr){
        if (curr->next->Year > year){
            return 2;//2 means more recent;
        }else if (curr->next->Year <year){
            return -2; // -2 means older days.
        }else{
            if (curr->next->month < month){
                return -2;
            } else if (curr->next->month > month){
                return 2;
            } else{//month equal, compare days.
                if (curr->next->Day < day){
                    return -2;
                }else if (curr->next->Day> day){
                    return 2;
                }else {
                    return 1;//means same day same month, and same year. completely same.
                }
            }
        }
    }
    return -1;

}

void DateList::DeleteItem(int year, int month, int day){
    Date *dummyhead = new Date(0,0,0);
    dummyhead->next = ListDate;
    Date *curr = dummyhead;
    Date *temp;
    while(curr->next != nullptr){
        if(curr->next->Day == day &&curr->next->Month == month && curr->next->Year == year){
            temp=curr->next;
            curr->next = curr->next->next;
            delete temp;
            length--;
        }
        curr = curr->next;
    }
    return dummyhead->next;
}

bool DateList::SearchItem(int year, int month, int day){
    Date * dateTarget = new Date(year,month,day);
    while(ListDate != nullptr){
        if (ListDate->Year == dateTarget->Year && ListDate->Month == dateTarget->Month && ListDate->Day == dateTarget->Day){
            return true;
        }
        ListDate = ListDate->next;
    }
    return false;
}



void DateList::EmptyList(){
    Date * temp;
    while(ListDate != NULL){
        temp = ListDate;
        ListDate = ListDate->next;
        delete temp;
    }
    length = 0;
}

void DateList::PrintList(){
    Date * dummyHead = new Date(0,0,0);
    Date * curr = dummyHead;
    curr->next = ListDate;
    while(curr->next != NULL){
        std::cout << curr->Month <<"/" << curr->Day << "/" << curr->Year << std::endl;
        curr = curr-> next;
    }
}

DateList::~Datelist(){
    Date *temp;
    while(ListDate != nullptr){
        temp = ListDate;
        ListDate = ListDate->next;
        delete temp;
    }
}