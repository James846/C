#include<stdio.h>
#include<malloc.h>
#define MAX 200
#define MAXSIZE 20
typedef char ElemType;
//二叉树的数据结构
typedef struct BTree {
	ElemType data;
	struct BTree* lchild, * rchild;
}BTNode, * BTree;

int getNum(BTree t, int k) {
	if (t == NULL || k <= 0) return 0;
	if (k == 1)return 1;
	return getNum(t->lchild, k - 1) + getNum(t->rchild, k - 1);
}


void createBTree(BTree* T) {
	ElemType ch;
	printf("输入结点：\n");
	scanf_s("%c", &ch);
	while (getchar() != '\n');
	if (ch == '#') *T = NULL;
	else {
		*T = (BTree)malloc(sizeof(BTNode));
		if (!*T) {
			printf("空间不足\n");
			return;
		}
		(*T)->data = ch;//生成根结点
		printf("success\n\n");
		createBTree(&(*T)->lchild);
		createBTree(&(*T)->rchild);
	}
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

void last(BTNode* p) {
	if (p != NULL) {
		last(p->lchild);
		last(p->rchild);
		printf("%6c", p->data);
	}
}

void main() {
	BTree T;
	createBTree(&T);
	//int i = getNum(T, 2);
	//printf("%d", i);
	lastorder(T);
	printf("\n");
	last(T);
}
