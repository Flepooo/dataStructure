#include <iostream>

using namespace std;

struct StackNode{
    int entry;
    struct StackNode *next;
};

struct Stack{
    StackNode *top;
    int size;
};

void CreateStack(Stack *ps){
    ps->top = NULL;
    ps->size = 0;
    cout << "STACK CREATED" << endl;

}

void Push(int e, Stack *ps){
    StackNode *pn = new StackNode;
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    cout << e << " is Pushed at index : " << ps->size << endl;
    ps->size++;
}

void Pop(Stack *ps){
    StackNode *pn;
    cout << ps->top->entry << " is Popped" << endl;
    pn = ps->top;
    ps->top = ps->top->next;
    delete pn;
    ps->size--;
}

int StackEmpty(Stack *ps){
    return ps->top==NULL;
}

void ClearStack(Stack *ps){
    StackNode *pn = ps->top;
    while(pn){
        pn=pn->next;
        delete ps->top;
        ps->top=pn;
    }
    ps->size = 0;
}

void TraverseStack(Stack *ps){
    if(ps->size == 0){
        cout << "empty" << endl;
    } else {
        StackNode *pn = ps->top;
        while(pn){
            cout << pn->entry << " ";
            pn = pn->next;
        }
    }
}

int StackSize(Stack *ps){
    return ps->size;
}

void menuStackLinked(){
    cout << "choose a function : " << endl;
    cout << endl;
    cout << "\t 1- CreateStack" << endl;
    cout << "\t 2- Push" << endl;
    cout << "\t 3- Pop" << endl;
    cout << "\t 4- TraverseStack" << endl;
    cout << "\t 5- StackSize" << endl;
    cout << "\t 6- ClearStack" << endl;
    cout << "\t 7- StackEmpty" << endl;
    cout << "\t 8- exit" << endl;
    cout << endl;
}

void stackLinkedMain() {
    int i;
    do{
        cin >> i;
        switch(i) {
          case 1:
            Stack s;
            CreateStack(&s);
            break;
          case 2:
            cout << "Enter the number : " ;
            int e;
            cin >> e;
            Push(e, &s);
            break;
          case 3:
            Pop(&s);
            break;
          case 4:
            cout << "The is stack : " ;
            TraverseStack(&s);
            cout << endl;
            break;
          case 5:
            cout << "The size is : " << StackSize(&s) << endl ;
            break;
          case 6:
            ClearStack(&s);
            break;
          case 7:
            if(StackEmpty(&s)){
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
            break;
        }
    }while(i != 8);
}

