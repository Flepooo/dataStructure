#include <iostream>

using namespace std;

#define MAXQUEUE 5

struct Queue{
    int front;
    int tail;
    int size;
    int entry[MAXQUEUE];
};

void CreateQueue(Queue *pq){
    pq->front = 0;
    pq->tail = -1;
    pq->size = 0;
}

void Push(int e, Queue* q){
    if (q->tail == MAXQUEUE-1 && q->tail != 0){
       q->tail=0;
       cout << "Queue is overflow" <<  endl;
    }
    else{
        q->tail++;
        q->entry[q->tail] = e;
        cout << e << " is Pushed to index " << q->tail << endl;
        q->size++;
    }
}

void Serve(Queue* q){
    int e = q->entry[q->front];
    if (q->front > q->tail){
       q->front = 0;
       cout << "Queue is Empty" <<  endl;
    }
    else{
        cout << e << " is Served from index " << q->front << endl;
        q->front++;
        q->size--;
    }
}

int QueueEmpty(Queue* q){
    return !q->size;
}

int QueueFull(Queue* q){
    return (q->size == MAXQUEUE);
}

int QueueSize(Queue* q){
    return q->size;
}

void ClearQueue(Queue* q){
    q->front = 0;
    q->tail = -1;
    q->size = 0;
}

void TraverseQueue(Queue* q){
    int pos, s;
    for(pos=q->front, s=0; s < q->size; s++)
    {
        cout<< q->entry[pos] << " ";
        pos=(pos+1)%MAXQUEUE;
    }
}



int main()
{
    int e = 28;
    Queue q;
    CreateQueue(&q);
    Push(5, &q);
    Push(7, &q);
    Serve(&q);
    Serve(&q);
    Push(5, &q);
    Push(7, &q);
    TraverseQueue(&q);

    return 0;
}
