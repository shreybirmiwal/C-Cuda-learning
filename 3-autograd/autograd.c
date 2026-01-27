#include "autograd.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct Value *newVal = createLeafValue(3.0);
    printValue(newVal);

    return 0;
}

struct Value *createLeafValue(float data)
{
    struct Value *newValPointer = malloc(sizeof(struct Value));
    newValPointer->data = data;
    newValPointer->grad = 0.0;
    newValPointer->isLeaf = 1;
    newValPointer->child1 = NULL;
    newValPointer->child2 = NULL;
    newValPointer->op = '\0';

    return newValPointer;
}

struct Value *addValue(struct Value *val1, struct Value *val2)
{
}

void printValue(struct Value *val)
{
    printf("Value\nData: %f\nGrad: %f\nisLeaf: %d\nChild1 Pointer: %p\nChild2 Pointer: %p\nOperation: %c", val->data, val->grad, val->isLeaf, val->child1, val->child2, val->op);
}
