#include "autograd.h"

struct Neuron *createNeuron(int numInputs)
{

    struct Neuron *neuron = malloc(sizeof(struct Neuron));
    neuron->weights = calloc(sizeof(struct Value *), numInputs);

    for (int i = 0; i < numInputs; i++)
    {
        float rand = 3;
        neuron->weights[i] = createLeafValue(rand);
    }

    neuron->bias = createLeafValue(0);

    return neuron;
}

struct Value *forwardNeuron(struct Neuron *neuron, struct Value **inputs, int size)
{
    struct Value *cur;

    if (size != neuron->num_inputs)
    {
        // err
        return Value(-9999);
    }

    struct Value *curFinalSumPointer = createLeafValue(0);

    for (int i = 0; i < size; i++)
    {
        struct Value *scaled = multiplyValue(neuron->weights[i], inputs[i]);
        struct Value *summed = addValue(curFinalSumPointer, scaled);

        curFinalSumPointer = summed;
    }

    return curFinalSumPointer;
}