#ifndef TREETYPE_H
#define TREETYPE_H

typedef char ItemType;

struct TreeNode;

class TreeType
{
public:
    TreeType();
    ~TreeType();
    TreeType(const TreeType& originalTree);
    void MakeEmpty();
    bool isEmpty() const;
    bool isFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void Print(std::ofstream& outFile) const;
    bool IsBST()const;
    void DeleteRoot();
    void DeleteSmallest();
    ItemType GetNodes();
private:
    TreeNode* root;

};



#endif