#include "../headers/vect.h"


Vect *createVect(size_t dimension)
{
    Vect *v = malloc(sizeof(Vect));
    if(v == NULL)
        errx(EXIT_FAILURE, "Cannot create vect");
    v->dim = dimension;
    v->co = calloc(dimension, sizeof(double));
    if(v->co == NULL)
        errx(EXIT_FAILURE, "Cannot create vect");
    return v;
}

inline void freeVect(Vect *v)
{
    free(v->co);
    free(v);
}

void vectSet(Vect *v, double *coordinates)
{
    //assert(v->dim == len(coordinates)); Use vector struct
    for(size_t i = 0; i < v->dim; i++)
        v->co[i] = coordinates[i];
}

void vectScale(Vect *v, double lambda)
{
    for(size_t i = 0; i < v->dim; i++)
        v->co[i] *= lambda;
}

void vectAdd(Vect *vSource, Vect *vDest)
{
    assert(vSource->dim == vDest->dim);
    for(size_t i = 0; i < vSource->dim; i++)
        vDest->co[i] += vSource->co[i];
}

void vectSub(Vect *vSource, Vect *vDest)
{
    assert(vSource->dim == vDest->dim);
    for(size_t i = 0; i < vSource->dim; i++)
        vDest->co[i] -= vSource->co[i];
}

void vectAddScalar(Vect *v, double lambda)
{
    for(size_t i = 0; i < v->dim; i++)
        v->co[i] += lambda;
}

double dotProduct(Vect *v, Vect *v2)
{
    assert(v->dim == v2->dim);
    double result = 0;
    for(size_t i = 0; i < v->dim; i++)
        result += v->co[i] * v2->co[i];
    return result;
}

double vectNorm(Vect *v)
{
    double result = 0;
    for(size_t i = 0; i < v->dim; i++)
        result += v->co[i] * v->co[i];
    result = sqrt(result);
    return result;
}

static double inverseSquareRootdouble(double number)
{
    double y = number;
    double x2 = y * 0.5;
    long i = *(long *) &y;
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
    y = *(double *) &i;
    y = y * (1.5 - (x2 * y * y));
    return y;
}

void vectNormalize(Vect *v)
{
    double sum = 0;
    for(size_t i = 0; i < v->dim; i++)
        sum += v->co[i] * v->co[i];
    sum = inverseSquareRootdouble(sum);

    for(size_t i = 0; i < v->dim; i++)
        v->co[i] *= sum;
}

int isCollinear(Vect *v, Vect *v2)
{
    assert(v->dim > 0 && v->dim == v2->dim);
    double coeff = v->co[0] / v2->co[0]; // get ratio from first coordinates
    for(size_t i = 1; i < v->dim; i++)
    {
        if(fabs(v->co[i] / v2->co[i] - coeff) > 0.0e3) // if ratio is different, not collinear
            return 0;
    }
    return 1;
}

int isOrthogonal(Vect *v, Vect *v2)
{
    return dotProduct(v, v2) < 0.0e3;
}
