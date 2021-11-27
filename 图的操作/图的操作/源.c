#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 100//�����С
#define INFINITY 99//����������
int visited[MaxVertices];//��������
int stack[MaxVertices];//��¼����·���Ķ�������

typedef struct {
	char Vertices[MaxVertices];//������Ϣ����
	int Edge[MaxVertices][MaxVertices];//������Ϣ����
	int numV;//�������
	int numE;//����
}AdjMatrix;

void CreateGraph(AdjMatrix *G, int n, int e) {
	int vi, vj, w; char c = 0;
	G->numE = e;
	G->numV = n;
	printf("�����붥����Ϣ���ַ��ͣ���");
	for (int i = 0; i < G->numV; i++) {
		scanf_s("%c", &(G->Vertices[i]),1);//һ��һ���ַ���ȡ
	}
	for (int i = 0; i < G->numV; i++) {
		for (int j = 0; j < G->numV; j++) {
			if (i == j)G->Edge[i][j] = 0;
			else G->Edge[i][j] = INFINITY;//���У�INFINITYΪ���������� ����ʾͼ�в���ͨ������
		}
	}
	for (int k = 0; k < G->numE; k++) {
		printf("������ߵ���Ϣ��vi,vj,w)��");
		scanf_s("%d %d %d", &vi, &vj, &w);
		G->Edge[vi - 1][vj - 1] = w;
	}
}

void DispGraph(AdjMatrix *G) {
	int i;
	printf("\n ���������Ϣ��\n");
	for (i = 0; i < G->numV; i++) { printf("%c ", G->Vertices[i]); }
	printf("\n ����ڽӾ���\n");
	for (i = 0; i < G->numV; i++) {
		for (int j = 0; j < G->numV; j++) {
			printf("  %d  ",G->Edge[i][j]);		
		}
			printf("\n");
	}
}

void DFS(AdjMatrix* G, int v0) {
	printf(" %c ", G->Vertices[v0]); 
	visited[v0] = 1;
	for (int j = 0; j < G->numV; j++) {
		if (G->Edge[v0][j] !=0 && visited[j] == 0)
			DFS(G, j);
	}
}

void EasyPath(AdjMatrix *G,int start,int end){
	int j, EndPosition = end-1, startPosition = start-1,i;//��¼������ṹ�еĳ�ĩλ��
	int top = -1;
	for (j = 0; j < MaxVertices; j++) {
		visited[j] = 0;
	}
	top++;
	stack[top] = startPosition;//����ʼ������ջ
	visited[startPosition] = 1;
	int vertex;
	while (top != -1) {//�����·�������ջ��Ϊ��ʱ����Ѱ��·��
		vertex = stack[top];
		i = 0;
		int flag = 0;//flag��ʾ�Ƿ��ҵ���ǰ��������ͨ�Ķ���
		while (flag == 0) {
			if (G->Edge[vertex][i] != 0 && G->Edge[vertex][i] != 99 && visited[i] == 0) {//������ǰ��������ͨ�Ķ���
				flag = 1;
				top++;
				stack[top] = i;
				visited[i] = 1;
				if (i == EndPosition) {
					printf("\n�ҵ�·�������Ķ��㣺%c\n",G->Vertices[vertex]);
				}
			}
			if (i < G->numV) { i++; }
			else {
				top--;
				flag = 1;
			}
		}
	}
}



int main() {
	AdjMatrix *Martrix;
	Martrix = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	int begin, end; int node;
	CreateGraph(Martrix, 4, 4);
	DispGraph(Martrix);
	printf("��������Ҫ��ȱ����Ľ�㣺");
	scanf_s("%d", &node);
	printf("�ڽӾ������ȱ�����");
	DFS(Martrix, node-1);
	printf("\n��������Ҫ��·������ʼ�����ֹ��:");
	scanf_s("%d", &begin);
	scanf_s("%d", &end);
	EasyPath(Martrix, begin,end);
}