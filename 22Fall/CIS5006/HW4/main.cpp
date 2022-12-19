#include "TreeType.h"



int main(){

        TreeType newTree1, newTree2;
        bool found = false;
        //denote some chars.
        ItemType a = 'a', b='b',c='c',d='d',e='e',f='f',g='g';


        //Before test isfull, delete nodes. let's put item in to tree first.
               newTree1.PutItem(a);
               newTree1.PutItem(g);
               newTree1.PutItem(c);
               newTree1.PutItem(d);

               newTree2.PutItem(e);
               newTree2.PutItem(f);
               newTree2.PutItem(b);

         std::cout <<"Test the tree1 first:"  << newTree1.IsBST()<<std::endl;
         std::cout << "Test the second tree:" << newTree2.IsBST()<<std::endl;
         std::cout << "First tree full or not"<<newTree1.isFull()<<std::endl;
         std::cout << "Second tree empty or not"<< newTree2.isEmpty()<<std::endl;
         std::cout <<"first tree length:" << newTree1.GetLength() << std::endl;

        
         std::cout << "The leaf nodes for the fisrt tree" << newTree1.GetNodes() << std::endl;

         newTree1.DeleteSmallest();
         std::cout << "Lenght after delete" << newTree1.GetLength() << std::endl;
         newTree1.DeleteRoot();
         std::cout << "Length after deleting the root" << newTree1.GetLength() << std::endl;
         newTree1.MakeEmpty();
         std::cout << "Test empty of tree1" << newTree1.isEmpty() << std::endl;

        std::cout << "Get e from tree2" << newTree2.GetItem(e,found) << std::endl;
        

        






    return 0;
}