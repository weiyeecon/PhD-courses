#include "TreeType.h"
#include <iostream>
#include <vector>

struct TreeNode
{
    ItemType info;
    TreeNode *left;
    TreeNode *right;

};

//Problem1 a
TreeType::TreeType()
{
    root = nullptr;
}

void Destroy(TreeNode *&tree);//hyperfunction, to be used in destructor;

//Problem1 b
TreeType::~TreeType()
{
    Destroy(root);
}

//Define our hyperfunction.
void Destroy(TreeNode *&tree)
{
    if (tree != nullptr)
    {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

//Problem1 c
int countNodes(TreeNode *tree);

int TreeType::GetLength() const
{
    countNodes(root);
}

int countNodes(TreeNode *tree)
{
    if (tree==nullptr)
        return 0;
    else    
        return countNodes(tree->left)+countNodes(tree->right)+1;
}


//Problem1 d
bool TreeType::isEmpty() const
{
    return (root == nullptr);
}


//Problem1 e
bool TreeType::isFull() const
{
    TreeNode *location;
    try
    {
        location = new TreeNode;
        return false;
        delete location;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
    
}


//Problem1 f
void Retrieve(TreeNode *tree, ItemType &item, bool &found);

ItemType TreeType::GetItem(ItemType item, bool& found)
{
    Retrieve(root, item, found);
    return item;
}

void Retrieve(TreeNode *tree, ItemType &item, bool &found)
{
    if(tree == nullptr)
        found = false;
    else if (item < tree->info)
    {
        Retrieve(tree->left, item, found);
    }
    else if (item > tree->info)
    {
        Retrieve(tree->right, item, found);
    } 
    else{
        item = tree->info;
        found = true;
    }
}


//Problem1 g
void PrintTree(TreeNode *tree, std::ofstream &outFile);

void TreeType::Print(std::ofstream &outFile) const
{
    PrintTree(root,outFile);
}

void PrintTree(TreeNode *tree, std::ofstream &outFile)
{
    if (tree != nullptr)
    {
        PrintTree(tree->left,outFile);
        outFile << tree->info;//FIX ME, << not work
        PrintTree(tree->right,outFile);
    }
}


//Problem2
/*Note: This question is LeetCode 98. The discussion section is as my
reference to this question. I use two pointer method to loop the whole 
tree and check whether it's BST.
*/

/*
TreeNode *pre = nullptr;
bool TreeType::IsBST(root) const
{
    if (root == nullptr)
        return true;
    bool left = IsBST(root->left);//check the left subtree is bst or not
    if (pre != nullptr || pre->info >= root->info)
        return false;
    pre = root;// if pre is null , assign the root to the pre. 
    bool right = IsBST(root->right);//check the right subtree is bst or not.
    return left && right;//iff left and right are both bst, it's bst.
}
The above block of codes are two pointer methods.
Now, I will try the method the professor mentioned in class.
*/

//Another method.
bool TreeType::IsBST()const
{   
    TreeNode *tree;
    tree = root;
    if (tree != nullptr)
    {
        if (tree->info < tree->left->info || tree->info > tree->right->info)
        {
            return false;
        }
        IsBST(tree->left);//check left subtree using recursive method
        IsBST(tree->right);
    }
    return true;
}


//Problem3: delete the root of the bst.
void GetPredecessor(TreeNode *tree, ItemType &data );
void Delete(TreeNode *tree, ItemType item);
void DeleteNode (TreeNode *& tree);
void TreeType::DeleteRoot()
{
    DeleteNode(root);
}

void Delete(TreeNode *tree, ItemType item)
{
    if (item < tree->info)
    {
        Delete(tree->left,item);
    }
    else if (item > tree->info)
    {
        Delete(tree->right, item);
    }
    else DeleteNode(tree);
}

void GetPredecessor(TreeNode *tree, ItemType &data){
    while(tree->right != NULL)
        tree = tree->right;
    data = tree->info;
}

void DeleteNode(TreeNode *& tree)
{
    ItemType data;
    TreeNode * tempPtr;
    
    tempPtr = tree;
    if (tree->left = NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right = NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else//Left and right are both not null
    {
        GetPredecessor(tree->left, data);//在tree的做边找最右的node
        tree->info = data;
        Delete(tree->left, data);//Delete predecessor node
    }
}


//Problem4: DeleteSmallest
void TreeType::DeleteSmallest()
{
    if (root->left == nullptr)
    {
        TreeNode *temp;
        temp = root;
        root = root->right;
        delete temp;
    }
    else
    {
        DeleteSmallest(root->left);
    }
}


//Problem5: Getnodes in an array of leaf nodes in BST.

ItemType TreeType::GetNodes()
{
    vector <ItemType> result;
    if (root != nullptr)
    {
        if (root->left == nullptr  && root->right == nullptr)
        {
            result.push_back(root->info);
        }
        else if (root->left != nullptr)
        {
            GetNodes(root->left);
        }
        else if (root->right != nullptr)
        {
            GetNodes(root->right);
        }
    }
    return result;
}

