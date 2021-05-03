#include "point.h"

Point *newPoint(double x, double y, double z)
{
    Point *p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

void freePoint(Point *p)
{
    free(p);
}
