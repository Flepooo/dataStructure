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

}

void Push(int e, Stack *ps){
    StackNode *pn = new StackNode;
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    cout << e << " is Pushed" << endl;
    ps->size++;
}

void Pop(int *pe, Stack *ps){
    StackNode *pn;
    cout << ps->top->entry << " is Popped" << endl;
    *pe = ps->top->entry;
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
    StackNode *pn = ps->top;
    while(pn){
        cout << pn->entry << " ";
        pn = pn->next;
    }
}

int StackSize(Stack *ps){
    return ps->size;
}


int main()
{
    int e = 5;
    Stack s;
    CreateStack(&s);
    Push(e, &s);
    Push(6, &s);
    Push(7, &s);

    TraverseStack(&s);

    return 0;
}
