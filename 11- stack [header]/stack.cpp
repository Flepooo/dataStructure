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
    cout << "STACK CREATED" << endl;
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
    if (ps->top==0){
        cout << "empty";
    } else {
        for(int i = ps->top ; i > 0; i--)
        cout<< ps->entry[i-1] << " ";
    }
}

void menu(){
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

void stackMain() {
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
