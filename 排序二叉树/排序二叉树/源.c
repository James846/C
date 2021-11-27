#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree *lchild,*rchild;
}BiTree;

BiTree* F = NULL;

BiTree* SearchBST(BiTree*root,int key) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->data == key) {
        return root;  
    }
    else {
        F = root;
        if (key < root->data) {
            return SearchBST(root->lchild, key);
        }
        else {
            return SearchBST(root->rchild, key);
        }
    }
}

BiTree* InsertBST(BiTree*root,int key) {
    BiTree* C, * s;
    C=SearchBST(root, key);
    if (C == NULL) {
        s = (BiTree*)malloc(sizeof(BiTree));
        if (s == NULL) {
            printf("����洢�ռ�ʧ�ܣ�");
            return NULL;
        }
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (F == NULL)root = s;
        else if (key < F->data)F->lchild = s;
        else F->rchild = s;
    }
    return root;
}

BiTree* CreateBST() {
    int key;
    BiTree* Tree = NULL;
    printf("\n����������������Ķ��㣨��-1��Ϊ��������");
    scanf_s("%d", &key);
    while (key != -1) {
        Tree = InsertBST(Tree, key);
        scanf_s("%d", &key);
    }
    return Tree;
}

void LDR(BiTree *root) {
    if (root == NULL) { 
        return; 
    }
    else {
        LDR(root->lchild);
        printf(" %d ",root->data);
        LDR(root->rchild);
    }
       
}

int DeleteBST(BiTree* T, int key) {
    BiTree* p, *s = NULL,*q;
    p = SearchBST(T, key);
    if (!p) {
        printf("������ָ����ɾ��ֵ��");
        return 0;
    }
    if (p->lchild == NULL) {
        q = p; 
        p = p->rchild;
    }
    else if (p->rchild == NULL) {
        q = p;
        p = p->lchild;
    }
    else {
        q = p;
        s = p->lchild;
        while (s->rchild != NULL) {
            q = s;
            s = s->rchild;
        }
        if (q == p) {
            q->lchild = s->lchild;
        }
        else {
            q->rchild = s->rchild;
        }
        p->data = s->data;
        q = s;
    }
    if (F == NULL) {
        T = p;
    }
    else {
        if (q != s) {
            if (key > F->data) {
                F->rchild = p;
            }
            else {
                F->lchild = p;
            }
        free(q);    
        }   
    }
    return 1;
}

int lowestAncestor(BiTree* root, int begin, int end) {
    if (root == NULL) {
        return -1;
    }
    if (begin == root->data || end == root->data) {
        return root->data;
    }
    int left = lowestAncestor(root->lchild, begin, end);
    int right = lowestAncestor(root->rchild, begin, end);
    if (left == -1) {
        return right;
    }
    if (right == -1) {
        return left;
    }
    return root->data;
}

void FindShareAncestor(BiTree *root) {
    int p1, p2; int result;
    printf("��������1�ͽ��2��");
    scanf_s("%d %d", &p1,&p2);
    printf("\n����������ȣ�");
    result = lowestAncestor(root, p1, p2);
    printf("%d", result);
}

void CMD_Select(void)//������ʾ���������й��ܵ�ʵ��
{
	printf("\n\n**************3200608046 ������******************");
	printf("\nCMD������ʾ:");
	printf("\n1:���������� 2:������� 3:ɾ��ָ����� 4:����ָ����������������� 10���˳�����\n");
	printf("**********************************************\n");
	printf("CMD����:");
}

int main() {
    BiTree* T;
    T = (BiTree*)malloc(sizeof(BiTree));
    int cmd = 0; int n;
    CMD_Select();//����������ʾ        
    scanf_s("%d", &cmd);
    while (cmd != 10)
    {
        switch (cmd)
        {
        case 1:T=CreateBST();//���������� 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 2:LDR(T) ;//������� 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 3:{printf("��������Ҫɾ���Ľ�㣺");scanf_s("%d", &n);DeleteBST(T, n); }//ɾ��
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 4:FindShareAncestor(T);//����ָ�����Ĺ�������
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        default:printf("�����������,��������"); cmd = 10;
        }
    }
    return 0;
}