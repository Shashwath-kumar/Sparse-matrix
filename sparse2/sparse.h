#include "struct.c"

void init(matrixNode *,int,int);
int * create_array();
void display(int *);
int* create_triplet(int *);
void makeSparse(matrixNode *);
void showSparse(matrixNode *);
void dest(matrixNode *);
int islowert(matrixNode *);
int multi(matrixPointer s1,matrixPointer s2, matrixPointer s);
void transpose(matrixPointer , matrixNode);