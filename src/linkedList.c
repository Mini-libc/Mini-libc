#include <stdlib.h>
#include <err.h>
#include <stdio.h>

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

void listPushFront(List *list, List *elmt)
{
    elmt->next = list->next;
    list->next = elmt;
}

List *listPopFront(List *list)
{
    if (list->next == NULL)
        return NULL;

    List *res = list->next;
    list->next = res->next;

    return res;
}

List *listFindValue(List *list, int toFind)
{
    for (List *l = list->next; l != NULL; l = l->next)
        if ( *l->data == toFind)
            return l;

    return NULL;
}

List *listFindPos(List *list, int pos)
{
    for (List *l = list->next; pos > -1; pos--)
        if (pos == 0)
            return l;

    return NULL;
}

int listIsSorted(List *list)
{
    if (list->next == NULL || list->next->next == NULL)
        return 1;

    while (list->next != NULL && list->data <= list->next->data)
        list = list->next;

    return list->next == NULL;
}

void ListFree(List *list)
{
    while (list != NULL)
    {
        List *next = list->next;
        free(list);
        list = next;
    }
}

int main(void)
{

    return 1;
}
