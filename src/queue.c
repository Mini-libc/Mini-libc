#include "queue.h"

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

QueueNode *createNode(void *dataptr)
{
    QueueNode *qN = malloc(sizeof(QueueNode));
    qN->dataptr = dataptr;
    qN->next = NULL;
    return qN;
}

void enqueue(Queue *q, void *dataptr)
{
    QueueNode *qN = createNode(dataptr);
    if(q->rear == NULL)
    {
        q->front = qN;
        q->rear = qN;
    }
    else
    {
        q->rear->next = qN;
        q->rear = qN;
    }
}

void *dequeue(Queue *q)
{
    if(q->front == NULL)
        return NULL;

    QueueNode *qN = q->front;
    q->front = q->front->next;
    void *dataptr = qN->dataptr;

    if(q->front == NULL)
        q->rear = NULL;
    free(qN);
    return dataptr;
}

int isEmpty(Queue *q)
{
    return q->rear == NULL;
}

