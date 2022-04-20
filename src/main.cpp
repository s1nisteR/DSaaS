#include <iostream>

#include "Data Structures/stack.h"
//#include "Data Structures/queue.h"

int main()
{
    //Testing Stack
    int temp;

    Stack mS;
    mS.push(56);
    mS.push(35);
    mS.getTop(&temp);
    std::cout << "Top: " << temp << std::endl;
    mS.pop(&temp);
    mS.getTop(&temp);
    std::cout << "Top: " << temp << std::endl;

    //==================================================

    //Testing Queue




    return 0;
}
