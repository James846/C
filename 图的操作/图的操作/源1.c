#include<stdio.h>

#define MAX 100
# define INF 65535

typedef struct {
	char vexs[MAX];
	int arc[MAX][MAX];
	int numVertexes, numEdges;
}MGraph;

int visited[MAX];

void CreateMGraph(MGraph* G) {
	int i, j;
	//printf("���붥�����ͱ���:\n");
	//scanf_s("%d,%d", &G->numVertexes, &G->numEdges);
	G->numVertexes = 4;
	G->numEdges = 4;
	//printf("���붥����Ϣ:\n");
	/*
	for (i = 0; i < G->numVertexes; i++) { //���붥����Ϣ
		while (getchar() != '\n') {
			;
		}
		scanf_s("%c", &(G->vexs[i]));
	}
	*/
	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	for (i = 0; i < G->numVertexes; i++) { //��ʼ���ڽӾ���
		for (j = 0; j < G->numVertexes; j++) {
			G->arc[i][j] = INF;
		}
	}
	/*
	for (k = 0; k < G->numEdges; k++) { //��������֮��Ĺ�ϵ
		printf("����ߣ�vi��vj�����ϱ�i���±�j��Ȩw:");
		scanf_s("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
	}
	*/
	G->arc[0][1] = 1;
	G->arc[0][2] = 1;
	G->arc[2][3] = 1;
	G->arc[3][0] = 1;
}

void DFS(MGraph G, int i) {//�ڽӾ������������㷨 ����ͨͼ��
	int j;
	visited[i] = 1;
	printf("%c\n", G.vexs[i]);
	for (j = 0; j < G.numVertexes; j++) {
		if (G.arc[i][j] == 1 && visited == 0) {
			DFS(G, j);
		}
	}
}

void DFSTraverse(MGraph G) {
	int i = 0;
	for (i = 0; i < MAX; i++) {//��ʼ���������
		visited[i] = 0;
	}
	printf("��������㷨��\n");
	for (i = 0; i < G.numVertexes; i++) {
		if (visited[i] == 0) {
			DFS(G, i);
		}
	}
}

void getPath(MGraph G) {
	int u, v;
	printf("����·���Ŀ�ʼ����ͽ�������:\n");
	scanf_s("%d,%d", &u, &v);
	int i;
	int stack[MAX];
	int top = -1;
	for (i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
	top++;
	stack[top] = u;//������ʼλ��
	visited[u] = 1;
	int NL;
	while (top != -1) {
		NL = stack[top];
		i = 0;
		int flag = 0;
		while (flag == 0) {
			if (G.arc[NL][i] == 1 && visited[i] == 0) {
				flag = 1;
				top++;
				stack[top] = i;
				visited[i] = 1;
				if (i == v) {
					printf("�ҵ�·��\n");
					for (int p = 0; p < top; p++) {
						printf("%c-->", G.vexs[stack[p]]);

					}
					printf("%c\n", G.vexs[v]);
				}
			}
			if (i < G.numVertexes)i++;
			else {
				top--;
				flag = 1;
			}
		}
	}
}

void DFSTraverse2(MGraph G) {
	int i, j;
	for (i = 0; i < MAX; i++) {//��ʼ���������
		visited[i] = 0;
	}
	int stack[MAX];
	int NL;
	int top = 0;
	stack[top] = 0;
	visited[0] = 1;
	printf("�ǵݹ���ȱ��������\n");
	while (top != -1) {
		i = 0;
		int flag = 0;
		NL = stack[top];
		//printf("1:%c\n", G.vexs[NL]);
		while (flag == 0) { //flag�ж��Ƿ��ҵ���һ����·���Ķ���
			if (G.arc[NL][i] == 1 && visited[i] == 0) {
				flag = 1;
				top++;
				stack[top] = i;
				visited[i] = 1;
			}
			else {
				if (i < G.numVertexes)i++;
				else {//��û�ҵ�����ص���һ�����㣬�ظ�ѭ��
					printf("%c\n", G.vexs[NL]);
					top--;
					flag = 1;
				}
			}

		}
	}

}
void main() {
	MGraph G;
	CreateMGraph(&G);
	DFSTraverse(G);
	getPath(G);
	DFSTraverse2(G);
}