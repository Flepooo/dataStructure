#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

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

void CreateList(List *pl);

int ListEmpty(List *pl);

int ListFull(List *pl);

int ListSize(List *pl);

void DestroyList(List *pl);

void TraverseList(List* pl);

void InsertList(int pos, int e, List *pl);

void DeleteList(int pos, int *pe, List *pl);

void RetrieveItem(int pos, int *pe, List *pl);

void ReplaceItem(int pos, int e, List *pl);

void menuList();

void listMain();

#endif // LIST_H_INCLUDED
