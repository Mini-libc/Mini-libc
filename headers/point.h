#ifndef POINT_H
#define POINT_H

#include <stdlib.h>

typedef struct Point
{
    double x;
    double y;
    double z;
}Point;

Point *newPoint(double x, double y, double z);
void freePoint(Point *p);

#endif
