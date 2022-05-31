#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAXSTACK 10

struct Stack{
    int top;
    int entry[MAXSTACK];
};

// Implementation level

void CreateStack(Stack *ps){
    ps->top=0;
}

void Push(int e, Stack *ps){
    if (ps->top==MAXSTACK){
       cout << "Stack is Overflow" << endl;
    }
    else {
        ps->entry[ps->top]=e;
        cout << e << " is Pushed at index " << ps->top << endl;
        ps->top++;
    }
}

int StackFull(Stack *ps){
    if (ps->top == MAXSTACK)
        return 1;
    else
        return 0;
}

void Pop(Stack *ps){
    if (ps->top==0){
        cout << "Stack is Empty" << endl;
    } else {
        cout << ps->entry[ps->top-1] << " is Popped" << endl;
        ps->top--;
    }
}

int StackEmpty(Stack *ps){
    if (ps->top==0)
        return 1;
    else
        return 0;
}

int StackSize(Stack *ps){
    return ps->top;
}

void ClearStack(Stack *ps){
    ps->top=0;
    cout << "Stack Cleared" << endl;
}

void TraverseStack(Stack *ps){
    for(int i = ps->top ; i > 0; i--)
    cout<< ps->entry[i-1] << " ";
}

int main()
{
    // User Level
    int e = 55;
    Stack s;
    CreateStack(&s);
    Push(e, &s);
    Push(7, &s);
    Push(20, &s);
    Pop(&s);
    Pop(&s);

    TraverseStack(&s);

    return 0;
}
