#include<iostream>
typedef int ElemType;
typedef struct Node
{
	int data;
	struct Node* next;
}LNode,LinkList;
int Get(LinkList* first, int i, ElemType* e)
{
	if (i < 1)return 0;
	p = (*first).next;
}