#include <stdio.h>
#include <stdlib.h>
#include "struct.c"
void init(matrixNode *s1,int row, int column)
{
    int i;
    
    s1->tag = entry;
    s1->u.entry.col = column;
     s1->u.entry.row = row;
    s1->u.entry.value = 0;
    matrixNode *temp = s1;
    //creating columns
    for (i = 0; i < column; i++)
    {
        temp->right = malloc(sizeof(matrixNode));
        temp = temp->right;
        temp->tag = head;
        temp->down = temp;
    }
    temp->right = s1;

    temp = s1;
    //creating rows
    for (i = 0; i < row; i++)
    {
        temp->down = malloc(sizeof(matrixNode));
        temp = temp->down;
        temp->tag = head;
        temp->right = temp;
    }
    temp->down = s1;

}

int count(int *s)
{
    int cnt = 0, i;

    for (i = 0; i < MAX * MAX; i++)
    {
        if (s[i] != 0)
            cnt++;
    }
    return cnt;
}

int *create_array()
{
    int n, i;

    int *a = malloc(sizeof(int) * MAX * MAX);

    /* get the element and store it */
    for (i = 0; i < MAX * MAX; i++)
    {
        printf("Enter element no. %d:", i);
        scanf("%d", &n);
        a[i] = n;
    }

    return a;
}

void display(int *a)
{
    int i;
    /* traverses the entire matrix */
    for (i = 0; i < MAX * MAX; i++)
    {
        /* positions the cursor to the new line for every new row */
        if (i % MAX == 0)
            printf("\n");
        printf("%d\t", a[i]);
    }
}

int *create_triplet(int *s)
{
    int r = 0, c = -1, l = -1, i;

    int n = count(s);
    int *p = (int *)malloc(n * 3 * sizeof(int));

    for (i = 0; i < MAX * MAX; i++)
    {
        c++;
        /* sets the row and column values */
        if (((i % MAX) == 0) && (i != 0))
        {
            r++;
            c = 0;
        }

        /* checks for non-zero element. Row, column and
           non-zero element value is assigned to the matrix */
        if (*(s + i) != 0)
        {
            l++;
            *(p + l) = r;
            l++;
            *(p + l) = c;
            l++;
            *(p + l) = s[i];
        }
    }
    return p;
}

matrixNode *getnode(int row, int col, int val)
{
    matrixNode *node = malloc(sizeof(matrixNode));
    node->tag = entry;
    node->u.entry.row = row;
    node->u.entry.col = col;
    node->u.entry.value = val;
    node->down = NULL;
    node->right = NULL;
    return node;
}

void insert(matrixNode *s1, int row, int col, int val)
{
    s1->u.entry.value++;
    int i;
    matrixNode *temp, *temp1, *temp2;
    matrixNode *node = getnode(row, col, val);

    //going to the correct row
    temp = s1;
    for (i = -1; i < row; i++)
        temp = temp->down;
    temp1 = temp->right;
    temp2 = temp->right;

    while (temp1 != temp && temp1->u.entry.col < col)
    {
        temp2 = temp1;
        temp1 = temp1->right;
    }
    temp2->right = node;
    node->right = temp1;

    //going to correct col
    temp = s1;

    for (i = -1; i < col; i++)
        temp = temp->right;
    temp1 = temp->down;
    temp2 = temp->down;

    while (temp1 != temp && temp1->u.entry.row < row)
    {
        temp2 = temp1;
        temp1 = temp1->down;
    }
    temp2->down = node;
    node->down = temp1;
}

int mul(matrixPointer a, matrixPointer b)
{
    matrixPointer temp = b;
    int prod = 0;
    while (a->tag != head)
    {
        while (temp->tag != head)
        {
            if (a->u.entry.col == temp->u.entry.row)
            {
                prod += a->u.entry.value*temp->u.entry.value;
            }
            temp = temp->down;
        }temp =b;
        a = a->right;
    }

    return prod;
}

int multi(matrixPointer s1, matrixPointer s2, matrixPointer s)
{
    if(s1->u.entry.col != s2->u.entry.row)
    {
        printf("\nInvalid Multiplication\n");
        return 0;
    }
    init(s,s1->u.entry.row,s2->u.entry.col);
   // matrixPointer s;
    matrixPointer t1 = s1->down, t2 = s2->right;
    int i, j;
    int prod;

    for (i = 0; i < MAX; i++ )
    {   
        for (j = 0; j < MAX; j++)
        {prod =0;
            prod += mul(t1->right, t2->down);
            if (prod != 0)
            {
                insert(s, i, j, prod);
            }
            t2 = t2->right;
        }t2 = s2->right;
        t1 = t1->down;
    }

    return 1;
}

void makeSparse(matrixNode *s1)
{
    int row,col,val;

    while(1)
    {
        printf("\nRow:");
        scanf("%d",&row);
        if(row<0 || row>s1->u.entry.row)
            break;
        printf("\nColumn:");
        scanf("%d",&col);
        if(col<0 || col>s1->u.entry.col)
            break;
        printf("\nValue:");
        scanf("%d",&val);
        
        insert(s1,row, col, val);
    }
}

void transpose(matrixPointer t, matrixNode s)
{
    init(t,s.u.entry.col,s.u.entry.row);
    matrixPointer temp, temp1;
    int i;
    temp = s.down;
    while (temp->tag != entry)
    {
        temp1 = temp->right;
        while (temp1 != temp)
        {
            insert(t,temp1->u.entry.col, temp1->u.entry.row, temp1->u.entry.value);
            temp1 = temp1->right;
        }
        temp = temp->down;
    }
}

void showSparse(matrixNode *s)
{
    matrixPointer temp, temp1;
    int i;
    temp = s->down;
    while (temp != s)
    {
        temp1 = temp->right;
        while (temp1 != temp)
        {
            printf("Row:%d Col:%d Value:%d\n", temp1->u.entry.row, temp1->u.entry.col, temp1->u.entry.value);
            temp1 = temp1->right;
        }
        temp = temp->down;
    }
}

void destnode(matrixPointer s)
{
    matrixPointer prev;
    while (s->tag != head)
    {
        prev = s;
        s = s->right;
        free(prev);
    }
}

void dest(matrixNode *s)
{
    matrixNode *temp = s, *prev;

    //free all nodes
    while (temp != s)
    {
        destnode(temp->right);
        temp = temp->down;
    }

    //free all col
    temp = s->right;
    while (temp != s)
    {
        prev = temp;
        temp = temp->right;
        free(prev);
    }
    s->right = NULL;

    //free all col
    temp = s->down;
    while (temp != s)
    {
        prev = temp;
        temp = temp->down;
        free(prev);
    }
    s->down = NULL;
}