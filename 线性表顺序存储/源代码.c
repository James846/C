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
	printf("请输入想要的数组大小：");
	scanf_s("%d", &n);
	s->length = n;
	printf("数组大小为：%d ", s->length);
}
int main() {
	Sqlist s;
	createlist(&s);
}