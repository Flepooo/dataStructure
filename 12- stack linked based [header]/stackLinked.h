#ifndef STACKLINKED_H_INCLUDED
#define STACKLINKED_H_INCLUDED
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

void CreateStack(Stack *ps);

void Push(int e, Stack *ps);

void Pop(int *pe, Stack *ps);

int StackEmpty(Stack *ps);

void ClearStack(Stack *ps);

void TraverseStack(Stack *ps);

int StackSize(Stack *ps);

void menuStackLinked();

void stackLinkedMain();


#endif // STACKLINKED_H_INCLUDED
