#include <stdlib.h>
#include <malloc.h>
#include <err.h>
#include <assert.h>
#include <math.h>

typedef struct Vect {
    size_t dim;
    double *co; //coordinates
}Vect;

Vect *createVect(size_t dimension);
void freeVect(Vect *v);

void vectSet(Vect *v, double *coordinates);
void vectScale(Vect *v, double lambda);
void vectAdd(Vect *vSource, Vect *vDest);
void vectSub(Vect *vSource, Vect *vDest);
void vectAddScalar(Vect *v, double lambda);
double dotProduct(Vect *v, Vect *v2);
double vectNorm(Vect *v);
void vectNormalize(Vect *v);
