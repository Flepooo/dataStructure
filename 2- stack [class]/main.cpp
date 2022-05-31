#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAXSTACK 10

class Stack{
    int top;

public:
    int entry[MAXSTACK];

    Stack() { top = 0; }
    void Push(int e);
    void Pop();
    void TraverseStack();
    int StackSize();
};

void Stack::Push(int e){
    if (top == MAXSTACK){
       cout << "Stack is Overflow" << endl;
    }
    else {
        entry[top] = e;
        cout << e << " is Pushed at index " << top << endl;
        top++;
    }
}

void Stack::Pop(){
    if (top==0){
        cout << "Stack is Empty" << endl;
    } else {
        cout << entry[top-1] << " is Popped" << endl;
        top--;
    }
}

void Stack::TraverseStack(){
    for(int i = top ; i > 0; i--){
       cout<< entry[i-1] << " ";
    }
    cout << endl;
}

int Stack::StackSize(){
    return top;
}

int main()
{
    class Stack s;

    s.Push(5);
    s.Push(34);
    s.Push(7);

    s.Pop();
    s.TraverseStack();
    cout << s.StackSize();
    return 0;
}
