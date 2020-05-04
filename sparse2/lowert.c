#include <stdio.h>
#include <stdlib.h>
#include "struct.c"

int islowert(matrixNode *s)
{   int i;
    matrixPointer temp = s->down;
    for (i = 0; i < MAX; i++)
    {
        temp = temp->right;
        while (temp->tag!=head)
        {
            if(temp->u.entry.row > i || temp->u.entry.col >i)
                return 0;
            temp = temp->right;
        }
        temp = temp->down;
    }

    return 1;
}