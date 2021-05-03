#include <stdlib.h>
#include <stdio.h>
#include "addition.h"
#include "queue.h"
#include "vector.h"

void printVectorDouble(Vector *v)
{
    //double d = 0.0;
    for(size_t i = 0; i < v->length; i++)
    {
        //d = *(double *)v->data[0];
        printf("%lf ", *(double *)v->data[i]);
    }
    printf("\n (v->length, v->capacity) : (%zu,%zu)\n", v->length, v->capacity);
}

void testVectorPushEmpty(void)
{
    printf("PushEmpty\n");
    Vector *v = newVector();
    double d = 1.0;
    vectorPush(v, (void *)&d);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorPushMax(void)
{
    printf("PushMax\n");
    Vector *v = newVector();
    double d = 1.0;
    for(size_t i = 0; i < 16; i++)
        vectorPush(v, (void *)&d);
    double d2 = 2.0;
    vectorPush(v, (void *)&d2);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorPopEmpty(void)
{
    printf("PopEmpty\n");
    Vector *v = newVector();
    double *d;
    d = (double *)vectorPop(v);
    printf("d is NULL ? %i\n", d == NULL);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorPopCommon(void)
{
    printf("PopCommon\n");
    Vector *v = newVector();
    double d = 1.0;
    double *dptr;
    vectorPush(v, &d);
    dptr = (double *)vectorPop(v);
    printf("*dptr == d ? %i\n", *dptr == d);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorPopFull(void)
{
    printf("PopFull\n");
    Vector *v = newVector();
    double d = 1.0;
    for(size_t i = 0; i < 16; i++)
        vectorPush(v, &d);
    double d2 = 2.0;
    vectorPush(v, &d2);
    double *dptr;
    dptr = (double *)vectorPop(v);
    printf("*dptr == d2 ? %i\n", *dptr == d2);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorInsertEmpty(void)
{
    printf("InsertEmpty\n");
    Vector *v = newVector();
    double d = 1.0;
    vectorInsert(v, 0, &d);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorInsertOutOfBound(void)
{
    printf("InsertOutOfBound\n");
    Vector *v = newVector();
    double d = 1.0;
    vectorInsert(v, 10, &d);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorInsertMiddle(void)
{
    printf("InsertMiddle\n");
    Vector *v = newVector();
    double d = 1.0;
    for(size_t i = 0; i < 10; i++)
        vectorPush(v, &d);
    double d2 = 2.0;
    vectorInsert(v, 5, &d2);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorInsertFull(void)
{
    printf("InsertFull\n");
    Vector *v = newVector();
    double d = 1.0;
    for(size_t i = 0; i < 16; i++)
        vectorPush(v, &d);
    double d2 = 2.0;
    vectorInsert(v, 5, &d2);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorRemoveEmpty(void)
{
    printf("RemoveEmpty\n");
    Vector *v = newVector();
    vectorRemove(v, 0);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorRemoveCommon(void)
{
    printf("RemoveCommon\n");
    Vector *v = newVector();
    double d = 1.0;
    for(size_t i = 0; i < 10; i++)
        vectorPush(v, &d);
    double d2 = 2.0;
    vectorInsert(v, 5, &d2);
    double *d3 = vectorRemove(v, 5);
    printf("d3 = %lf\n", *d3);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorRemoveFull(void)
{
    printf("RemoveFull\n");
    Vector *v = newVector();
    double d = 1.0;
    for(size_t i = 0; i < 17; i++)
        vectorPush(v, &d);
    double *d3 = vectorRemove(v, 5);
    printf("d3 = %lf\n", *d3);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

void testVectorIsEmpty(void)
{
    printf("IsEmpty\n");
    Vector *v = newVector();
    printVectorDouble(v);
    printf("isEmpty ? %d\n", vectorIsEmpty(v));
    double d = 1.0;
    vectorPush(v, &d);
    printVectorDouble(v);
    printf("isEmpty ? %d\n", vectorIsEmpty(v));
    freeVector(v);
    printf("\n");
}

void testVectorReduceCapacity(void)
{
    printf("ReduceCapacity\n");
    Vector *v = newVector();
    double d = 1.0;
    for(size_t i = 0; i < 33; i++)
        vectorPush(v, &d);
    printVectorDouble(v);
    for(size_t i = 0; i < 30; i++)
        d = *(double *)vectorPop(v);
    printVectorDouble(v);
    freeVector(v);
    printf("\n");
}

int main(void)
{
    testVectorPushEmpty();
    testVectorPushMax();
    testVectorPopEmpty();
    testVectorPopCommon();
    testVectorPopFull();
    testVectorInsertEmpty();
    testVectorInsertOutOfBound();
    testVectorInsertMiddle();
    testVectorInsertFull();
    testVectorRemoveEmpty();
    testVectorRemoveCommon();
    testVectorRemoveFull();
    testVectorIsEmpty();
    testVectorReduceCapacity();
    return 0;
}
