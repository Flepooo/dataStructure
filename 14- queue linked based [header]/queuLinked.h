#ifndef QUEULINKED_H_INCLUDED
#define QUEULINKED_H_INCLUDED

#include <iostream>

using namespace std;

struct QueueNode{
    int entry;
    struct QueueNode *next;
};

struct Queue{
    QueueNode *front;
    QueueNode *tail;
    int size;
};

void CreateQueue(Queue *q);

void Push(int e, Queue* q);

void Serve(Queue* pq);

int QueueEmpty(Queue* pq);

int QueueFull(Queue* pq);

int QueueSize(Queue* pq);

void ClearQueue(Queue* pq);

void TraverseQueue(Queue* pq);

void menuQueueLinked();

void queuLinkedMain();

#endif // QUEULINKED_H_INCLUDED
