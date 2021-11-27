#include<stdio.h>
#include<malloc.h>
#define MAX 100
#define MAXSIZE 10
typedef char ElemType;
//二叉树的数据结构
typedef struct Bi {
	ElemType data;
	struct BTree* lchild, * rchild;
}BTNode, * BTree;

int getNum(BTree t, int k) {
	if (t == NULL || k <= 0) return 0;
	if (k == 1)return 1;
	return getNum(t->lchild, k - 1) + getNum(t->rchild, k - 1);
}

BTNode* createBTree() {
	BTNode* bt;
	char ch;
	ch = getchar();
	if (ch == '#')bt = NULL;
	else {
		bt = (BTNode*)malloc(sizeof(BTNode));
		bt->data = ch;
		bt->lchild = createBTree();
		bt->rchild = createBTree();
	}
	return bt;
}

void lastorder(BTNode* p) {
	BTNode* q;
	q = p;
	int top = 0;
	int flag = 1;
	int s2[MAXSIZE];
	BTNode* s[MAXSIZE];
	printf("\n后序遍历：\n");
	do {
		while (q != NULL) {
			top++;
			s[top] = q;
			s2[top] = 1;
			q = q->lchild;
		}
		if (top == 0) flag = 0;
		else {
			if (s2[top] == 1) {
				s2[top] = 2;
				q = s[top];
				q = q->rchild;
			}
			else {
				q = s[top];
				s2[top] = 0;
				top--;
				printf("%6c", q->data);
				q = NULL;
			}
		}
	} while (flag);
	printf("\n");
}

void main() {
	BTree T;
	printf("请输入结点:");
	T=createBTree();
	int max = 0;
	int Number = 0;
	Number = getNum(T, 1);
	for (int i = 2; Number != 0; i++) {
		if (Number > max)
			max = Number;
		Number = getNum(T, i);
	}
	printf("二叉树最大宽度：%d", max);
	lastorder(T);
	printf("\n");
}
