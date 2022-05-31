#include <iostream>

using namespace std;

struct ListNode{
    int entry;
    struct ListNode *next;
};

struct List{
    ListNode *head;
    int size;
};

void CreateList(List *pl){
    pl->head = NULL;
    pl->size = 0;
}

int ListEmpty(List *pl){
    return (pl->size == 0);
}

int ListFull(List *pl){
    return 0;
}

int ListSize(List *pl){
    return pl->size;
}

void DestroyList(List *pl){
    ListNode *q;
    while(pl->head){
        q = pl->head->next;
        delete pl->head;
        pl->head = q;
    }
    pl->size=0;
}

void TraverseList(List* pl){
    ListNode *p=pl->head;
    while(p){
        cout << p->entry;
        p = p->next;
    }
}

void InsertList(int pos, int e, List *pl)
{
    ListNode *p, *q;
    int i;
    p = new ListNode;
    p->entry = e;
    p->next=NULL;
    if (pos==0){
        p->next = pl->head;
        pl->head = p;
    }
    else{
        for(q=pl->head, i=0; i<pos-1; i++){
           q = q->next;
        }
        p->next=q->next;
        q->next=p;
    }
    pl->size++;
}

void DeleteList(int pos, int *pe, List *pl){
    int i;
    ListNode *q, *tmp;
    if (pos == 0){
        *pe=pl->head->entry;
        tmp=pl->head->next;
        delete pl->head;
        pl->head=tmp;
    } else {
        for(q = pl->head, i=0; i < pos-1; i++){
           q = q->next;
        }
        *pe = q->next->entry;
        tmp = q->next->next;
        delete q->next;
        q->next = tmp;
    }
    pl->size--;
}

void RetrieveItem(int pos, int *pe, List *pl){
    int i;
    ListNode *q;
    for(q = pl->head, i=0; i<pos; i++){
        q = q->next;
    }
    *pe = q->entry;
}

void ReplaceItem(int pos, int e, List *pl){
    int i;
    ListNode *q;
    for(q = pl->head, i = 0; i < pos; i++){
        q = q->next;
    }
    q->entry = e;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
