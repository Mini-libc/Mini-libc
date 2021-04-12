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
void vectAddScalar(Vect *v, double lambda); // add a constant to each coordinate of v
double dotProduct(Vect *v, Vect *v2);
double vectNorm(Vect *v); // return the length of v
void vectNormalize(Vect *v); // set the lenght of v to 1

int isCollinear(Vect *v, Vect *v2);
int isOrthogonal(Vect *v, Vect *v2);
