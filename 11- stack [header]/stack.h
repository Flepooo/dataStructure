#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAXSTACK 10

struct Stack{
    int top;
    int entry[MAXSTACK];
};

void CreateStack(Stack *ps);

void Push(int e, Stack *ps);

int StackFull(Stack *ps);

void Pop(Stack *ps);

int StackEmpty(Stack *ps);

int StackSize(Stack *ps);

void ClearStack(Stack *ps);

void TraverseStack(Stack *ps);

void menu();

void stackMain();

#endif // STACK_H_INCLUDED
