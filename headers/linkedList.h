#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Singly linked list
// Has a sentinel
// If empty : only a sentinel
typedef struct List
{
    // Pointer to next element
    struct List *next;

    // Data for element, can be anything
    void *data;

    // Total size of the List
    // An empty List has a size = -1
    int len;
} List;

// Return a pointer to the sentinel of a new empty linked List
List *listNew();

// Insert elmt at the begining of list (after sentinel)
// Elmt already exists and list can be empty
List *listPushFront(List *list, List *elmt);

// Get and remove the first element of the List (not the sentinel)
// Does not free nor malloc anything
// If list is empty, return NULL
List *listPopFront(List *list);

// Find the first node in List that has the same data as toFind
// Does not free (or remove) nor malloc anything
// If no node is found, return NULL
List *listFindValue(List *list, void *toFind);

// Find the element at the given position pos
List *listFindPos(List *list, int pos);

// Return true if the list is sorted in increasing order
// Otherwise, return false
List *listIsSorted(List *list);

// Insert elmt in the sorted list (keeping the List sorted)
// elmt already exists
// Does not free nor malloc anything
int listInsert(List *list, List *elmt);

// Reverse in place the element of the List (except for the sentinel)
void listReverse(List *list);

// Split the list in half and put the second half in 'second'
// 'second' is an empty List
// Does not free nor malloc anything
void listHalfSplit(List *list, List *second);

// Free every node of the list (including the sentinel)
void listFree(List *list)


#endif
