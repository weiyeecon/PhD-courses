#include "UnsortedType.h"

struct NodeType{
    ItemType info;
    NodeType * next;
};// linked list。一个value- 用info表示; 一个指针: 用next.

UnsortedType::UnsortedType(){
    length = 0;
    ListData = NULL;
    //currentPos = -1;
}

bool UnsortedType::isFull() const{
    NodeType * location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

int UnsortedType::GetLength() const{
    return length;
}

void UnsortedType::MakeEmpty(){
    //Post: List is empty; and all items have been deallocated.
    NodeType * tempPtr;

    while(ListData != NULL){
        tempPtr = ListData;
        ListData = ListData->next;
        delete tempPtr;
    }
    /*
    如果当前的NodeType指针不为空，说明有数据，所以用temp来代表当前数据，当前数据
    的下一个assign 给当前。最后再进行解指针。
    */
    length = 0;
}

ItemType UnsortedType::GetItem(ItemType& item, bool& found){
    bool moreToSearch;
    NodeType * location;
    
    location = ListData;
    found = false;
    moreToSearch = (location!=NULL);

    while(moreToSearch && !found){
        switch(item.ComparedTo(location->info)){
            case LESS:
            case GREATER:
                location = location->next;
                moreToSearch = (location!=NULL);
                break;
            case EQUAL:
                found = true;
                item = location ->info;
                break;
        }
    }
    return item;
}
/*GetItem的逻辑是先初始化找不到和moretosearch; ！found 和moretosearch同时正确，
则用本node的info和虚参中的info比较（函数已经被定义好了再ItemType),如果大，在本list中
继续寻找，如果找到了，就看看本list中的数据是什么，最后返回数据。
*/

void UnsortedType::DeleteItem(ItemType item){
    NodeType *location = ListData;
    NodeType * tempLocation;
    if (item.ComparedTo(location->info) == EQUAL){
        tempLocation = location;
        ListData = ListData->next;
    } else{
        while (item.ComparedTo(location->info)!= EQUAL){
            location = location->next;
            tempLocation = location->next;//not sure why,待看代码随想录
            location->next = (location->next)->next;//not sure.
        }
    }
    delete tempLocation;
    length--;
}

void UnsortedType::ResetList(){
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem(){
    ItemType item; 
    if(currentPos == NULL){
        currentPos = ListData;
    }else{
        currentPos = currentPos->next;
    }
    item = currentPos->info;
    return item;
}

UnsortedType::~UnsortedType(){
    NodeType * tempPtr;
    while(ListData != NULL){
        tempPtr = ListData;
        ListData = ListData->next;
        delete tempPtr;
    }
}