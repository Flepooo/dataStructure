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
    cout << "QUEUE CREATED" << endl;
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
    cout << e << " is Pushed to index " << q->size << endl;
}

void Serve(Queue* pq){
    QueueNode *pn=pq->front;
    int *pe = new int(pn->entry);
    pq->front=pn->next;
    cout << *pe << " is Served front" << endl;
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

void menuQueueLinked(){
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

void queuLinkedMain(){
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
