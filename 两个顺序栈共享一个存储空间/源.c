#include<stdio.h>
#define Maxsize 10
typedef int datatype;
typedef struct {
	datatype stack[Maxsize];
	int top1;
	int top2;
}sqstack;

sqstack s;

void Initialize(sqstack* S) {//��ʼ��ջ
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
	else printf("ջ��\n");
}

void Insert() {//��ջ����
	int data;
	char c1 = 0, c2 = 0;
	printf("������������Ҫ����ջ1�����ݣ�");
	while (c1 != '\n') {
		scanf_s("%d", &data);
		PushStack(1, data);
		c1 = getchar();
	}
	printf("������������Ҫ����ջ2�����ݣ�");
	while (c2 != '\n') {
		scanf_s("%d", &data);
		PushStack(2, data);
		c2 = getchar();
	}
}

void Travel(sqstack* S) {//����ջ�������Ԫ��
	int i;
	for (i = 0; i <= S->top1; i++) {
		printf("ջ1�ĵ�%d��Ԫ��%d\n", i + 1, S->stack[i]);
	}
	printf("***************\n");
	for (i = Maxsize - 1; i >= S->top2; i--) {
		printf("ջ2�ĵ�%d��Ԫ��%d\n", Maxsize - i, S->stack[i]);
	}
}

void Judge(sqstack* S) {
	if (S->top2 == S->top1 + 1) {
		printf("����ջ��\n");
	}
	else {
		printf("ջδ��\n");
	}
	if (S->top1 == -1) {
		printf("ջ1Ϊ��\n");
	}
	if (S->top2 == Maxsize) {
		printf("ջ2Ϊ��\n");
	}
}

void Pop() {
	int n,x;
	printf("������Ҫ���г�ջ������ջ��");
	scanf_s("%d",&n);
	if (n == 1) {
		if (s.top1 == -1) {
			printf("ջ��");
		}
		else {
			x = s.stack[s.top1];
			s.top1--;
			printf("��ջ��Ԫ�أ�%d\n",x);
		}
	}
	if (n == 2) {
		if (s.top2 == Maxsize) {
			printf("ջ��");
		}
		else {
			x = s.stack[s.top2];
			s.top2++;
			printf("��ջ��Ԫ�أ�%d\n", x);
		}
	}

}

void CMD_Select(void)//������ʾ���������й��ܵ�ʵ��
{
	printf("\n**************3200608046 ������******************");
	printf("\n����������Ҫ���еĲ���(1.��ʼ��ջ 2.��ջ 3.��ջ 4.�鿴����ջ 5.�ж�ջ�� 10.�˳����򣩣�");
	printf("\n**********************************************");
	printf("\nCMD����:");
}

int main() {
	Initialize(&s);
	int num, data;
	char c=0, c1=0, c2=0;
	int cmd = 0;
	CMD_Select();//����������ʾ        
	scanf_s("%d", &cmd);
	while (cmd != 10)
	{
	switch (cmd)
	{
	case 1: Initialize(&s);//��ʼ��ջ 
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 2:Insert();//��ջ 
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 3:Pop();//��ջ
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 4:Travel(&s);//�鿴����ջ
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	case 5:Judge(&s);//�ж�ջ��ջ��
		CMD_Select(); scanf_s("%d", &cmd);
		break;
	default:printf("�����������,��������");cmd = 10; 
		}
	}
}
	