#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef int value;

typedef struct Node {
	datatype date;
	struct Node* next;
}Node,*Linklist;

void addnodelist(Linklist head) {
	char c = 0;
	value x;
	printf("插入结点：");
	while (c != '\n') {
		Linklist p0 = head;
		Linklist p1 = p0->next;
		scanf_s("%d", &x);
		while ((p1 != NULL) && (x >= p1->date)) {
			p0 = p1;
			p1 = p1->next;
		}
		p0->next = (Linklist)malloc(sizeof(Node));
		p0->next->date = x;
		p0->next->next = p1;
		c = getchar();
	}
	printf("插入结束\n");
}

void checklist(Linklist head) {
	Linklist p = head;
	printf("遍历链表");
	while (p->next != NULL) {
		p = p->next;
		printf(" %d ", p->date);
	}
	printf("\n");
}

int main() {
	Linklist head = (Linklist)malloc(sizeof(Node));
	head->next = NULL;
	addnodelist(head);
	checklist(head);
}