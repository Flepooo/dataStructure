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
    cout << "LIST CREATED" << endl;
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
        cout << p->entry << " -> ";
        p = p->next;
    }
}

void InsertList(int pos, int e, List *pl){
    ListNode *p, *q;
    int i;
    p = new ListNode;
    p->entry = e;
    p->next = NULL;
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
    cout << e << " inserted at index " << pos << endl;
}

void DeleteList(int pos,  List *pl){
    int *pe = new int(0);
    int i;
    ListNode *q, *tmp;
    if (pos==0){
        *pe=pl->head->entry;
        tmp=pl->head->next;
        delete pl->head;
        pl->head=tmp;
    } else {
        for(q=pl->head, i=0; i<pos-1; i++)
        q=q->next;
        *pe=q->next->entry;
        tmp=q->next->next;
        delete q->next;
        q->next=tmp;
    }
    pl->size--;
}

void ReplaceItem(int pos, int e, List *pl){
    int i;
    ListNode *q;
    for(q = pl->head, i = 0; i < pos; i++){
        q = q->next;
    }
    q->entry = e;
}

void pushStart(int e, List *list){
    ListNode *newNode = new ListNode;
    newNode->entry = e;
    if(list->head == NULL){
        newNode->next = NULL;
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->size++;
    cout << e << " pushed from the start " << endl;
}

void menuList(){
    cout << "choose a function : " << endl;
    cout << endl;
    cout << "\t 1- CreateList" << endl;
    cout << "\t 2- InsertList" << endl;
    cout << "\t 3- ReplaceItem" << endl;
    cout << "\t 4- TraverseList" << endl;
    cout << "\t 5- DeleteList" << endl;
    cout << "\t 6- DestroyList" << endl;
    cout << "\t 7- pushStart" << endl;
    cout << "\t 8- ListSize" << endl;
    cout << "\t 9- exit" << endl;
    cout << endl;
}

void listMain(){
    int i;
    do{
        cin >> i;
        switch(i) {
          case 1:
            List s;
            CreateList(&s);
            break;
          case 2:
            int pos, value;
            cout << "Enter the position : ";
            cin >> pos;
            cout << endl;
            cout << "Enter the value : ";
            cin >> value;
            InsertList(pos, value, &s);
            cout << endl;
            break;
          case 3:
            cout << "Enter the position : ";
            cin >> pos;
            cout << endl;
            cout << "Enter the value : ";
            cin >> value;
            ReplaceItem(pos, value, &s);
            cout << endl;
            break;
          case 4:
            cout << "The List : ";
            TraverseList(&s);
            cout << endl;
            break;
          case 5:
            cout << "Enter the position : ";
            cin >> pos;
            DeleteList(pos, &s);
            cout << "item deleted" << endl;
            break;
          case 6:
            DestroyList(&s);
            cout << "list destroyed" << endl;
            break;
          case 7:
            int e;
            cout << "Enter the value : ";
            cin >> e;
            pushStart(e , &s);
            cout << "item added" << endl;
            break;
          case 8:
            cout << "The list size is : " << ListSize(&s) << endl;
            break;
        }
    }while(i != 9);
}

