#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int compareInts(void *a, void *b)
{
    int* la = a;
    int* lb = b;

    return *la - *lb;
}

int main(void)
{
    Tree *t = newTree(&compareInts);

    // int arry[] = {2, 12, 44, -12, -22, 0, 0};

    // for(int i = 0 ; i < 6; i++)
    //     add(t, arry + i, &compareInts);

    char arry[] = {'a', 'z', 'c', 'z', 's', 'p'};

    for(int i = 0 ; i < 6; i++)
        add(t, arry + i, &compareInts);    

    printTreeIter(t);

    return 0;
}