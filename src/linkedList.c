#include <stdlib.h>
#include <err.h>

#include "../headers/linkedList.h"

List *listNew()
{
    List *list = malloc(sizeof(List));

    if (list == NULL)
        errx(1, "Error, malloc failed at list allocation.");

    list->next = NULL;
    list->data = NULL;

    return list;
}

int main(void)
{
    return 1;
}
