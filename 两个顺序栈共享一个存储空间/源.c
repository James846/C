#include<stdio.h>
#define Maxsize 10
typedef int datatype;
typedef struct {
	datatype stack[Maxsize];
	int top1;
	int top2;
}sqstack;

sqstack s;

void Initialize(sqstack* S) {//初始化栈
	S->top1 = -1;
	S->top2 = Maxsize;
}

void PushStack(int k, int e) {
	if (s.top2 != s.top1+1) {
		if (k == 1) {
			s.top1++;
			s.stack[s.top1] = e;
		}
		if (k == 2) {
			s.top2--;
			s.stack[s.top2] = e;
		}
	}
	else printf("栈满\n");
}

void Insert() {//进栈输入
	int data;
	char c1 = 0, c2 = 0;
	printf("请依次输入想要插入栈1的数据：");
	while (c1 != '\n') {
		scanf_s("%d", &data);
		PushStack(1, data);
		c1 = getchar();
	}
	printf("请依次输入想要插入栈2的数据：");
	while (c2 != '\n') {
		scanf_s("%d", &data);
		PushStack(2, data);
		c2 = getchar();
	}
}

void Travel(sqstack* S) {//遍历栈里的所有元素
	int i;
	for (i = 0; i <= S->top1; i++) {
		printf("栈1的第%d个元素%d\n", i + 1, S->stack[i]);
	}
	printf("***************\n");
	for (i = Maxsize - 1; i >= S->top2; i--) {
		printf("栈2的第%d个元素%d\n", Maxsize - i, S->stack[i]);
	}
}

void Judge(sqstack* S) {
	if (S->top2 == S->top1 + 1) {
		printf("共享栈满\n");
	}
	else {
		printf("栈未满\n");
	}
	if (S->top1 == -1) {
		printf("栈1为空\n");
	}
	if (S->top2 == Maxsize) {
		printf("栈2为空\n");
	}
}

void Pop() {
	int n,x;
	printf("输入想要进行出栈操作的栈：");
	scanf_s("%d",&n);
	if (n == 1) {
		if (s.top1 == -1) {
			printf("栈空");
		}
		else {
			x = s.stack[s.top1];
			s.top1--;
			printf("出栈的元素：%d\n",x);
		}
	}
	if (n == 2) {
		if (s.top2 == Maxsize) {
			printf("栈空");
		}
		else {
			x = s.stack[s.top2];
			s.top2++;
			printf("出栈的元素：%d\n", x);
		}
	}

}

void CMD_Select(void)//命令提示符利于所有功能的实现
{
	printf("\n**************3200608046 吴天雄******************");
	printf("\n请输入你想要进行的操作(1.初始化栈 2.进栈 3.出栈 4.查看共享栈 5.判断栈满 10.退出程序）：");
	printf("\n**********************************************");
	printf("\nCMD命令:");
}

int main() {
	Initialize(&s);
	int num, data;
	char c=0, c1=0, c2=0;
	int cmd = 0;
	CMD_Select();//输入命令提示        
	scanf_s("%d", &cmd);
	while (cmd != 10)
	{
	switch (cmd)
	{
	case 1: Initialize(&s);//初始化栈 
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 2:Insert();//进栈 
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 3:Pop();//出栈
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 4:Travel(&s);//查看共享栈
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 5:Judge(&s);//判断栈空栈满
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	default:printf("命令输入错误,结束运行");cmd = 10; 
		}
	}
}
	