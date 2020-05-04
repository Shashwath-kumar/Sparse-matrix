#define MAX 2 /* size of largest matrix */
typedef enum
{
    head,
    entry
} tagfield;

typedef struct matrixNode *matrixPointer;

typedef struct entryNode
{
    int row;
    int col;
    int value;
}entryNode;

typedef struct matrixNode
{
    matrixPointer down;
    matrixPointer right;
    tagfield tag;
    union {
        matrixPointer next;
        entryNode entry;
    } u;
}matrixNode;