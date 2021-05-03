#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "point.h"

void printVectorWithPoints(Vector *v)
{
    Point *p = newPoint(0.0, 0.0, 0.0);
    for(size_t i = 0; i < v->length; i++)
    {
        p = v->data[i];
        printf("(%lf, %lf, %lf) ", p->x, p->y, p->z);
    }
    printf("\n");
    freePoint(p);
}

/*
void setupVector(void)
{
}

void teardownVector(void)
{
}

cr_assert(f(x) == expected, "Expected this");
*/

Test(vectorPush, pushEmpty)
{
    Vector *v = newVector();
    Point *p = newPoint(1.0, 1.0, 1.0);
    vectorPush(v, (void *)p);
    Point *p2 = v->data[0];
    cr_assert(p2->x == 1.0);
    cr_assert(p2->y == 1.0);
    cr_assert(p2->z == 1.0);
    //printVectorWithPoints(v);
    freePoint(p);
    freeVector(v);
}

Test(vectorPush, pushToMaxCapacity)
{
    Vector *v = newVector();
    Point *p = newPoint(1.0, 1.0, 1.0);
    for(size_t i = 0; i <= v->capacity; i++)
        vectorPush(v, (void *)p);
    //printVectorWithPoints(v);
    cr_assert(v->length == 16 + 1);
    cr_assert(v->capacity == 32);
    //printf("v->length, v->capacity : (%zu, %zu)\n", v->length, v->capacity);
    freePoint(p);
    freeVector(v);
}

/*
Test(vectorPop, test1)
{
    //cr_assert(add(2, 2) == 5, "Testing purpose for test2");
}

Test(vectorGet, test2)
Test(vectorInsert, test3)
Test(vectorRemove, test4)
Test(vectorIsEmpty, test5)
*/
