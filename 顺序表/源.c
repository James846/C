#include<stdio.h>
#define max 20
typedef int ElemType;

typedef struct List {
	ElemType data [max]; //结构体中的数组用于存放数据
	ElemType length;
}List;

void Initialize(List *l) {//顺序表初始化 
	l->length= 0;
	for (int i = 0; i <max; i++) {
		l->data[i] = 0;
	}
}

List Add(List* l) {//插入数据
    char c = 0;
    printf("请输入想要插入的数：");
    while (c != '\n') {//使用回车来停止输入
    int n = 0;
    scanf_s("%d", &n);
    l->data[l->length] = n;
    l->length=l->length+1;
    c = getchar();
    }
    return *l;//返回结果值
}

List Del(List* l) {
    printf("请输入想要删除的元素值：");
    int del = 0;
    int n = l->length;
    scanf_s("%d", &del);
    for(int i=0;i<n;i++){
        if (del == l->data[i]) {
            int* p = &l->data[i+1];
            int* q = &l->data[n];
            for (p; p <= q; p++) {
                *(p - 1) = *p;
            }
            l->length--;
        }
    }
    return *l;
}

void Combine(List* l) {

}

List SpecialDel(List* l) {
    printf("请输入想要删除的起点位置：");
    int start = 0;
    scanf_s("%d", &start);
    printf("请输入想要删除的终点位置：");
    int end = 0;
    scanf_s("%d", &end);
    if (start >= end || l->length == 0) {
        printf("非法删除");
    }
    int* first = &l->data[0];
    int* last = &l->data[l->length-1];
    int num = end - start + 1;
    l->length = l->length - num; 
    int calculate = 0;
    int* s = &l->data[start - 2];
    int* e = &l->data[end];
    List *result=NULL;
         for (int n = 1; n < start; n++) { 
             for (first; first <= s; first++) {
              result->data[n-1] = *first; 
              calculate=calculate+1;
            }
    }
    
        for (calculate; calculate <= l->length; calculate++) {
            for (e; e <= last; e++) {
                result->data[calculate] = *e;
        }
    }
    return *result;
}

void Traverse_List(List*l)//遍历节点（冒泡排序）
{
    printf("\n遍历结果：");
    int n = l->length;
    for (int j = 0; j < l->length - 1; j++) {//冒泡排序
        for (int k = 0; k < l->length - 1; k++) {
            if (l->data[k] > l->data[k + 1]) {
                int temp = l->data[k];
                l->data[k] = l->data[k + 1];
                l->data[k + 1] = temp;
            }
        }
    }
    for (int i = 0; i <n; i++) {//输出遍历
        printf(" %d ", l->data[i]);
    }
}

void CMD_Select(void)//命令提示符利于所有功能的实现
{
	printf("\n**************请输入操作命令******************");
	printf("\nCMD命令提示:");
	printf("\n1:插入定值e 2:删除定值e 3:合并表 4:删除给定值之间的所有元素 5:遍历顺序表（冒泡排序并输出结果） 10：退出程序\n");
	printf("**********************************************\n");
	printf("CMD命令:");
}

int main() {
	List l,result;
	Initialize(&l);
	Initialize(&result);
    int cmd =0;
    CMD_Select();//输入命令提示        
    scanf_s("%d", &cmd);
    while (cmd != 10)
    {
        switch (cmd)
        {
        case 1: result=Add(&l);//插入定值e 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 2: result = Del(&l);//删除定值e 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 3:;//合并表
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 4:result=SpecialDel(&l);//删除给定值之间的所有元素 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 5:Traverse_List(&result); //遍历顺序表（冒泡排序并输出结果）
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        default:printf("命令输入错误,结束运行"); cmd = 10;
        }
    }
    return 0;
}