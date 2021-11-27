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
	//printf("输入顶点数和边数:\n");
	//scanf_s("%d,%d", &G->numVertexes, &G->numEdges);
	G->numVertexes = 4;
	G->numEdges = 4;
	//printf("输入顶点信息:\n");
	/*
	for (i = 0; i < G->numVertexes; i++) { //输入顶点信息
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
	for (i = 0; i < G->numVertexes; i++) { //初始化邻接矩阵
		for (j = 0; j < G->numVertexes; j++) {
			G->arc[i][j] = INF;
		}
	}
	/*
	for (k = 0; k < G->numEdges; k++) { //输入边与边之间的关系
		printf("输入边（vi，vj）的上标i、下标j和权w:");
		scanf_s("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
	}
	*/
	G->arc[0][1] = 1;
	G->arc[0][2] = 1;
	G->arc[2][3] = 1;
	G->arc[3][0] = 1;
}

void DFS(MGraph G, int i) {//邻接矩阵的深度优先算法 （连通图）
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
	for (i = 0; i < MAX; i++) {//初始化访问情况
		visited[i] = 0;
	}
	printf("深度优先算法：\n");
	for (i = 0; i < G.numVertexes; i++) {
		if (visited[i] == 0) {
			DFS(G, i);
		}
	}
}

void getPath(MGraph G) {
	int u, v;
	printf("输入路径的开始顶点和结束顶点:\n");
	scanf_s("%d,%d", &u, &v);
	int i;
	int stack[MAX];
	int top = -1;
	for (i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
	top++;
	stack[top] = u;//存入起始位置
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
					printf("找到路径\n");
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
	for (i = 0; i < MAX; i++) {//初始化访问情况
		visited[i] = 0;
	}
	int stack[MAX];
	int NL;
	int top = 0;
	stack[top] = 0;
	visited[0] = 1;
	printf("非递归深度遍历结果：\n");
	while (top != -1) {
		i = 0;
		int flag = 0;
		NL = stack[top];
		//printf("1:%c\n", G.vexs[NL]);
		while (flag == 0) { //flag判断是否找到下一个有路径的顶点
			if (G.arc[NL][i] == 1 && visited[i] == 0) {
				flag = 1;
				top++;
				stack[top] = i;
				visited[i] = 1;
			}
			else {
				if (i < G.numVertexes)i++;
				else {//若没找到，则回到上一个顶点，重复循环
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