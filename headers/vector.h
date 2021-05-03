#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <assert.h>
#include <err.h>

#define DEFAULTCAPACITY 16

typedef struct Vector
{
    size_t capacity;
    size_t length;
    void **data; // array of struct pointers
}Vector;

Vector *newVector();
void freeVector(Vector *v); // free the vector without freeing its content

void vectorPush(Vector *v, void *dataPtr); // add an element at last index
void *vectorPop(Vector *v); // remove element at last index. usage : (myStruct *)vectorPop(v); Pop when empty return NULL

void *vectorGet(Vector *v, size_t i); // usage : (myStruct *)vectorGet(v, i);

void vectorInsert(Vector *v, size_t i, void *dataPtr); // insert and moves next elements to the right
void *vectorRemove(Vector *v, size_t i); // return the struct at indice i and move next elements to the left. When empty return NULL

int vectorIsEmpty(Vector *v);

#endif
