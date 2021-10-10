#include<stdio.h>
#define max 20
typedef int ElemType;

typedef struct List {
	ElemType data [max]; //�ṹ���е��������ڴ������
	ElemType length;
}List;

void Initialize(List *l) {//˳����ʼ�� 
	l->length= 0;
	for (int i = 0; i <max; i++) {
		l->data[i] = 0;
	}
}

List Add(List* l) {//��������
    char c = 0;
    printf("��������Ҫ���������");
    while (c != '\n') {//ʹ�ûس���ֹͣ����
    int n = 0;
    scanf_s("%d", &n);
    l->data[l->length] = n;
    l->length=l->length+1;
    c = getchar();
    }
    return *l;//���ؽ��ֵ
}

List Del(List* l) {
    printf("��������Ҫɾ����Ԫ��ֵ��");
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
    printf("��������Ҫɾ�������λ�ã�");
    int start = 0;
    scanf_s("%d", &start);
    printf("��������Ҫɾ�����յ�λ�ã�");
    int end = 0;
    scanf_s("%d", &end);
    if (start >= end || l->length == 0) {
        printf("�Ƿ�ɾ��");
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

void Traverse_List(List*l)//�����ڵ㣨ð������
{
    printf("\n���������");
    int n = l->length;
    for (int j = 0; j < l->length - 1; j++) {//ð������
        for (int k = 0; k < l->length - 1; k++) {
            if (l->data[k] > l->data[k + 1]) {
                int temp = l->data[k];
                l->data[k] = l->data[k + 1];
                l->data[k + 1] = temp;
            }
        }
    }
    for (int i = 0; i <n; i++) {//�������
        printf(" %d ", l->data[i]);
    }
}

void CMD_Select(void)//������ʾ���������й��ܵ�ʵ��
{
	printf("\n**************�������������******************");
	printf("\nCMD������ʾ:");
	printf("\n1:���붨ֵe 2:ɾ����ֵe 3:�ϲ��� 4:ɾ������ֵ֮�������Ԫ�� 5:����˳���ð�������������� 10���˳�����\n");
	printf("**********************************************\n");
	printf("CMD����:");
}

int main() {
	List l,result;
	Initialize(&l);
	Initialize(&result);
    int cmd =0;
    CMD_Select();//����������ʾ        
    scanf_s("%d", &cmd);
    while (cmd != 10)
    {
        switch (cmd)
        {
        case 1: result=Add(&l);//���붨ֵe 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 2: result = Del(&l);//ɾ����ֵe 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 3:;//�ϲ���
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 4:result=SpecialDel(&l);//ɾ������ֵ֮�������Ԫ�� 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 5:Traverse_List(&result); //����˳���ð��������������
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        default:printf("�����������,��������"); cmd = 10;
        }
    }
    return 0;
}