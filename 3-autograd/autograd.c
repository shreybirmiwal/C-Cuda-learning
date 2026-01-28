#include "autograd.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct Value *newVal = createLeafValue(3.0);
    struct Value *val2 = createLeafValue(2.0);
    struct Value *out = addValue(newVal, val2);
    printValue(out);

    freeGraph(out);
    return 0;
}

struct Value *createLeafValue(float data)
{
    struct Value *newValPointer = malloc(sizeof(struct Value));
    newValPointer->data = data;
    newValPointer->label = data;
    newValPointer->grad = 0.0;
    newValPointer->isLeaf = 1;
    newValPointer->child1 = NULL;
    newValPointer->child2 = NULL;
    newValPointer->op = '\0';

    return newValPointer;
}

struct Value *addValue(struct Value *val1, struct Value *val2)
{
    struct Value *newValPointer = malloc(sizeof(struct Value));

    newValPointer->data = val1->data + val2->data;
    newValPointer->label = "(" + (val1->label) + ")+(" + (val2->label) + ")";
    newValPointer->grad = 0.0;
    newValPointer->isLeaf = 0;
    newValPointer->child1 = val1;
    newValPointer->child2 = val2;
    newValPointer->op = '+';

    return newValPointer;
}

struct Value *multiplyValue(struct Value *val1, struct Value *val2)
{
    struct Value *newValPointer = malloc(sizeof(struct Value));

    newValPointer->data = (val1->data) * (val2->data);
    newValPointer->label = "(" + (val1->label) + ")*(" + (val2->label) + ")";
    newValPointer->grad = 0.0;
    newValPointer->isLeaf = 0;
    newValPointer->child1 = val1;
    newValPointer->child2 = val2;
    newValPointer->op = '*';

    return newValPointer;
}

void printValue(struct Value *val)
{
    printf("Value\nData: %f\nGrad: %f\nisLeaf: %d\nChild1 Pointer: %p\nChild2 Pointer: %p\nOperation: %c", val->data, val->grad, val->isLeaf, val->child1, val->child2, val->op);
}

void freeGraph(struct Value *head)
{
    if (head->isLeaf == 1)
    {
        return;
    }

    if (head->child1 != NULL)
    {
        freeGraph(head->child1);
    }
    if (head->child2 != NULL)
    {
        freeGraph(head->child2);
    }
    free(head);
}