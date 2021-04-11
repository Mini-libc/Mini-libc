#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <err.h>

typedef struct QueueNode
{
    void *dataptr;
    struct QueueNode *next;
}QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
}Queue;

// Don't forget to free the queue
// Caution when deleting the queue if there is content in it
// Cast when enqueuing something that isn't a pointer :
// int n = 10;
// enqueue(q, (void *) int);
// Cast pointer when dequeing : int n = (int)dequeue(q);
// Cast when dequeing a struct : 
// struct Thing *t = enqueue(q, t);
// struct Thing *t2 = (struct Thing*)dequeue(q);

Queue *createQueue();
void enqueue(Queue *q, void *dataptr);
void *dequeue(Queue *q);
int isEmpty(Queue *q);
