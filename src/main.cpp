#include <iostream>

#include "Data Structures/stack.h"

int main()
{
    int temp;
    push(56);
    push(75);
    push(86);
    getTop(&temp);
    std::cout << temp << std::endl;
    push(25);
    push(36);
    pop(&temp);

    getTop(&temp);
    std::cout << temp << std::endl;

    return 0;
}
