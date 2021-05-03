#include "vector.h"

Vector *newVector()
{
    Vector *v = malloc(sizeof(Vector));
    v->capacity = DEFAULTCAPACITY;
    v->length = 0;
    v->data = calloc(v->capacity, sizeof(void *));

    return v;
}

void freeVector(Vector *v)
{
    free(v->data);
    free(v);
}

static void doubleCapacity(Vector *v)
{
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * sizeof(void *));
}

static void reduceCapacity(Vector *v)
{
    if(v->capacity > DEFAULTCAPACITY)
    {
        v->capacity /= 2;
        v->data = realloc(v->data, v->capacity * sizeof(void *));
    }
}

void vectorPush(Vector *v, void *dataPtr)
{
    v->data[v->length] = dataPtr;
    v->length++;

    if(v->length == v->capacity)
        doubleCapacity(v);
}

void *vectorPop(Vector *v)
{
    if(v->length == 0)
        return NULL;

    void *result = v->data[v->length - 1];
    v->length--;

    if(v->length < v->capacity / 4)
        reduceCapacity(v);

    return result;
}

void *vectorGet(Vector *v, size_t i)
{
    assert(i < v->length);
    return v->data[i];
}

void vectorInsert(Vector *v, size_t i, void *dataPtr)
{
    if(i >= v->length)
        return vectorPush(v, dataPtr);

    v->length++;

    if(v->length == v->capacity)
        doubleCapacity(v);

    for(size_t j = v->length; j > i; j--)
        v->data[j] = v->data[j - 1];
    v->data[i] = dataPtr;
}

void *vectorRemove(Vector *v, size_t i)
{
    if(v->length == 0)
        return NULL;

    if(i >= v->length)
        return vectorPop(v);

    void *result = v->data[i];

    for(size_t j = i; j < v->length; j++)
        v->data[j] = v->data[j + 1];

    v->length--;
    if(v->length < v->capacity / 4)
        reduceCapacity(v);

    return result;
}

int vectorIsEmpty(Vector *v)
{
    return v->length == 0;
}
