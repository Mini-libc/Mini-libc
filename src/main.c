#include <stdlib.h>
#include <stdio.h>
#include "addition.h"
#include "queue.h"

int main(void)
{
    printf("Hello there !\n");
    Queue *q = createQueue();
    free(q);
    printf("Result from add 2 2 : %d\n", add(2, 2));
    return 0;
}
