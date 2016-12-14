#include <iostream>
#include "functions.h"


int main(void)
{
    AvlTree tree;
    for (int i = 0; i < 6; i++)
    {
    tree.insert(i);
    }
    tree.printTree();
    return 0;
}
