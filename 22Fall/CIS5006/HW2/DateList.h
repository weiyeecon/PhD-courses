#ifndef DATELIST_H
#define DATELIST_H

struct Date;

class DateList{
public:
    DateList();
    ~DateList();
    void PutItem(Date * newDate);
    void DeleteItem(int year, int month, int day);
    bool isFull() const;
    int CompareDate(int year, int month, int day);//fix this
    bool SearchItem(int year, int month, int day);
    void EmptyList();
    void PrintList();
    

private:
    Date * ListDate;
    int length;
};




#endif