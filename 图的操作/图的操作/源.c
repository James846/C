#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 100//数组大小
#define INFINITY 99//定义的无穷大
int visited[MaxVertices];//访问数组
int stack[MaxVertices];//记录经过路径的顶点数据

typedef struct {
	char Vertices[MaxVertices];//顶点信息数组
	int Edge[MaxVertices][MaxVertices];//边数信息数组
	int numV;//顶点个数
	int numE;//边数
}AdjMatrix;

void CreateGraph(AdjMatrix *G, int n, int e) {
	int vi, vj, w; char c = 0;
	G->numE = e;
	G->numV = n;
	printf("请输入顶点信息（字符型）：");
	for (int i = 0; i < G->numV; i++) {
		scanf_s("%c", &(G->Vertices[i]),1);//一个一个字符读取
	}
	for (int i = 0; i < G->numV; i++) {
		for (int j = 0; j < G->numV; j++) {
			if (i == j)G->Edge[i][j] = 0;
			else G->Edge[i][j] = INFINITY;//其中，INFINITY为定义的无穷大 即表示图中不连通的两点
		}
	}
	for (int k = 0; k < G->numE; k++) {
		printf("请输入边的信息（vi,vj,w)：");
		scanf_s("%d %d %d", &vi, &vj, &w);
		G->Edge[vi - 1][vj - 1] = w;
	}
}

void DispGraph(AdjMatrix *G) {
	int i;
	printf("\n 输出顶点信息：\n");
	for (i = 0; i < G->numV; i++) { printf("%c ", G->Vertices[i]); }
	printf("\n 输出邻接矩阵：\n");
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
	int j, EndPosition = end-1, startPosition = start-1,i;//记录在数组结构中的初末位置
	int top = -1;
	for (j = 0; j < MaxVertices; j++) {
		visited[j] = 0;
	}
	top++;
	stack[top] = startPosition;//将初始顶点入栈
	visited[startPosition] = 1;
	int vertex;
	while (top != -1) {//当存放路径顶点的栈不为空时持续寻找路径
		vertex = stack[top];
		i = 0;
		int flag = 0;//flag表示是否找到当前顶点所连通的顶点
		while (flag == 0) {
			if (G->Edge[vertex][i] != 0 && G->Edge[vertex][i] != 99 && visited[i] == 0) {//遍历当前顶点所连通的顶点
				flag = 1;
				top++;
				stack[top] = i;
				visited[i] = 1;
				if (i == EndPosition) {
					printf("\n找到路径经过的顶点：%c\n",G->Vertices[vertex]);
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
	printf("请输入想要深度遍历的结点：");
	scanf_s("%d", &node);
	printf("邻接矩阵的深度遍历：");
	DFS(Martrix, node-1);
	printf("\n请输入想要找路径的起始点和终止点:");
	scanf_s("%d", &begin);
	scanf_s("%d", &end);
	EasyPath(Martrix, begin,end);
}