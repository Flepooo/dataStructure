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

void CreateQueue(Queue *q){
    q->front = NULL;
    q->tail = NULL;
    q->size = 0;
}

void Push(int e, Queue* q){
    QueueNode* n= new QueueNode;
    n->next = NULL;
    n->entry = e;
    if (!q->tail){
        q->front = n;
    }
    else {
      q->tail->next = n;
    }
    q->tail = n;
    q->size++;
}

void Serve(Queue* pq){
    QueueNode *pn=pq->front;
    int *pe = new int(pn->entry);
    pq->front=pn->next;
    delete pn;
    pq->size--;
}

int QueueEmpty(Queue* pq){
    return !pq->front;
}

int QueueFull(Queue* pq){
    return 0;
}

int QueueSize(Queue* pq){
    return pq->size;
}

void ClearQueue(Queue* pq){
    while(pq->front){
        pq->tail=pq->front->next;
        delete pq->front;
        pq->front=pq->tail;
    }
    pq->size = 0;
}

void TraverseQueue(Queue* pq){
    for(QueueNode *pn=pq->front; pn; pn=pn->next){
        cout << pn->entry <<" ";
    }
}

int main()
{
    int e = 1;
    Queue q;
    CreateQueue(&q);
    Push(e++, &q);
    Push(e++, &q);
    Push(e++, &q);
    Push(e++, &q);
    Push(e++, &q);
    Push(e++, &q);
    Serve(&q);
    TraverseQueue(&q);

    return 0;
}
