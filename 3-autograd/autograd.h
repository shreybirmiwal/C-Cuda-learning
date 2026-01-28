#include <stdbool.h>

struct Value
{
    float data;
    float grad; // this is filled on .backward() later
    bool isLeaf;
    bool isVisited; // for the topological sort

    // if it's not a leaf, we have to fill these in below
    struct Value *child1;
    struct Value *child2;
    char op; // +, *, /, - etc.
};

// operations
struct Value *createLeafValue(float data);
struct Value *addValue(struct Value *val1, struct Value *val2);
struct Value *multiplyValue(struct Value *val1, struct Value *val2);

void getTopo(struct Value *head, struct Value **topologicalArray, int *size);
void backward(struct Value **topologicalArray, int size);
void printValue(struct Value *val);
void freeGraph(struct Value **topologicalArray, int size);
void zeroGrad(struct Value **topologicalArray, int size);