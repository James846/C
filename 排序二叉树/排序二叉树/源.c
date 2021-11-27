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
            printf("分配存储空间失败！");
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
    printf("\n请输入排序二叉树的顶点（以-1作为结束）：");
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
        printf("不存在指定的删除值！");
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
    printf("请输入结点1和结点2：");
    scanf_s("%d %d", &p1,&p2);
    printf("\n最近公共祖先：");
    result = lowestAncestor(root, p1, p2);
    printf("%d", result);
}

void CMD_Select(void)//命令提示符利于所有功能的实现
{
	printf("\n\n**************3200608046 吴天雄******************");
	printf("\nCMD命令提示:");
	printf("\n1:建立二叉树 2:中序遍历 3:删除指定结点 4:查找指定结点的最近公共祖先 10：退出程序\n");
	printf("**********************************************\n");
	printf("CMD命令:");
}

int main() {
    BiTree* T;
    T = (BiTree*)malloc(sizeof(BiTree));
    int cmd = 0; int n;
    CMD_Select();//输入命令提示        
    scanf_s("%d", &cmd);
    while (cmd != 10)
    {
        switch (cmd)
        {
        case 1:T=CreateBST();//建立二叉树 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 2:LDR(T) ;//中序遍历 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 3:{printf("请输入想要删除的结点：");scanf_s("%d", &n);DeleteBST(T, n); }//删除
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 4:FindShareAncestor(T);//查找指定结点的公共祖先
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        default:printf("命令输入错误,结束运行"); cmd = 10;
        }
    }
    return 0;
}