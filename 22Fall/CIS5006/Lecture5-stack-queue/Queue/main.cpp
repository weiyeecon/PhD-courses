//Test for the homework question #22
#include "QueType.h"
#include <iostream>


int main(){
        QueType queue;

        int item1 = 1;
        int item2 = 0;
        int item3 = 4;

        queue.Enqueue(item2);
        queue.Enqueue(item1);
        queue.Enqueue(item1 + item2);
        queue.Dequeue(item2);
        queue.Enqueue(item3*item3);
        queue.Enqueue(item2);
        queue.Enqueue(3);
        queue.Dequeue(item1);
        std::cout << item1 <<  std::endl <<item2 <<  std::endl << item3 << std::endl;
        while(!queue.isEmpty()){
            queue.Dequeue(item1);
            std::cout <<item1 << std::endl;
        }


    return 0;
}