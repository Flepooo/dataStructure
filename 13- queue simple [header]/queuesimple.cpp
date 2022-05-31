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
    cout << "STACK CREATED" << endl;

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
    cout << "Stack Cleared" << endl;
}

void TraverseQueue(Queue* q){
    int pos, s;
    for(pos=q->front, s=0; s < q->size; s++)
    {
        cout<< q->entry[pos] << " ";
        pos=(pos+1)%MAXQUEUE;
    }
}

void menuQueueSimple(){
    cout << "choose a function : " << endl;
    cout << endl;
    cout << "\t 1- CreateQueue" << endl;
    cout << "\t 2- Push" << endl;
    cout << "\t 3- Serve" << endl;
    cout << "\t 4- TraverseQueue" << endl;
    cout << "\t 5- QueueSize" << endl;
    cout << "\t 6- ClearQueue" << endl;
    cout << "\t 7- QueueEmpty" << endl;
    cout << "\t 8- exit" << endl;
    cout << endl;
}

void queuSimpleMain(){
    int i;
    do{
        cin >> i;
        switch(i) {
          case 1:
            Queue s;
            CreateQueue(&s);
            break;
          case 2:
            cout << "Enter the number : " ;
            int e;
            cin >> e;
            Push(e, &s);
            break;
          case 3:
            Serve(&s);
            break;
          case 4:
            cout << "The is stack : " ;
            TraverseQueue(&s);
            cout << endl;
            break;
          case 5:
            cout << "The size is : " << QueueSize(&s) << endl ;
            break;
          case 6:
            ClearQueue(&s);
            break;
          case 7:
            if(QueueEmpty(&s)){
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
            break;
        }
    }while(i != 8);
}
