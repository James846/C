#include<stdio.h>
#define Max 20
typedef int elemtype;
typedef struct
{
	elemtype data[Max];
	int length;
}Sqlist;
void createlist(Sqlist *s) {
	int n,i;
	printf("��������Ҫ�������С��");
	scanf_s("%d", &n);
	s->length = n;
	printf("�����СΪ��%d ", s->length);
}
int main() {
	Sqlist s;
	createlist(&s);
}