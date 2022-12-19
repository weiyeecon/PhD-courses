#ifndef TREETYPE_H
#define TREETYPE_H

#include <string>
#include <fstream>
typedef char ItemType;
struct TreeNode;

class TreeType
{
public:
    TreeType();
    ~TreeType();
    TreeType(const TreeType & originalTree);
    void operator=(const TreeType & originalTree);
    void MakeEmpty();
    bool isEmpty() const;
    bool isFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item, bool & found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void Print(std::ofstream &outFile) const;

private:
    TreeNode * root;
};


#endif