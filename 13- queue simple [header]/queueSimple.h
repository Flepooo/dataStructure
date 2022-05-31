#ifndef QUEUESIMPLE_H_INCLUDED
#define QUEUESIMPLE_H_INCLUDED

#include <iostream>

using namespace std;

#define MAXQUEUE 5

struct Queue{
    int front;
    int tail;
    int size;
    int entry[MAXQUEUE];
};

void CreateQueue(Queue *pq);

void Push(int e, Queue* q);

void Serve(Queue* q);

int QueueEmpty(Queue* q);

int QueueFull(Queue* q);

int QueueSize(Queue* q);

void ClearQueue(Queue* q);

void TraverseQueue(Queue* q);

void menuQueueSimple();

void queuSimpleMain();

#endif // QUEUESIMPLE_H_INCLUDED
