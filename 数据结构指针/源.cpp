#include<iostream>
#include<stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;
void createLink(Node* head, int size) {
	Node* rear = head;
	int i;
	for (i = 0; i < size; i++) {
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->next = NULL;
		scanf_s("%d", &newnode->data);
		rear->next = newnode;
		rear = newnode;
	}
}
void travelLink(Node* head) {
	Node* p = head->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	putchar('/n');
}
int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	createLink(head, 10);
	travelLink(head);
}
