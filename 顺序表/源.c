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

List Del(List* l) {//ɾ��ָ����Ԫ��ֵ
    printf("��������Ҫɾ����Ԫ��ֵ��");
    int del = 0;
    int n = l->length;
    scanf_s("%d", &del);
    for(int i=0;i<n;i++){
        if (del == l->data[i]) {//�ҵ�ָ����Ԫ��ֵ
            int* p = &l->data[i+1];
            int* q = &l->data[n];
            for (p; p <= q; p++) {
                *(p - 1) = *p;//ָ�����
            }
            l->length--;
        }
    }
    return *l;
}

List Combine(List* l) {//�ϲ���
    List s,result;
    Initialize(&s);
    Initialize(&result);
    char c = 0;
    int i,p;
    printf("��������Ҫ���������ݣ�");
    while (c != '\n') {//ʹ�ûس���ֹͣ����
        int n = 0;
        scanf_s("%d", &n);
        (&s)->data[(&s)->length] = n;
        (&s)->length = (&s)->length + 1;
        c = getchar();
    }
    (&result)->length = l->length +(&s)->length;//�µı�
    for (i = 0; i < l->length; i++) {
        (&result)->data[i] = l->data[i];
    }
    for (p = 0,i; p < (&s)->length; p++,i++) {
        (&result)->data[i] = (&s)->data[p];
    }
    return result;//���ؽ��ֵ
}

List SpecialDel(List* l) {
    printf("��������Ҫɾ���Ľ�Сֵ��");
    int min = 0;
    scanf_s("%d", &min);
    printf("��������Ҫɾ���Ľϴ�ֵ��");
    int maxium = 0;
    int i,j;
    scanf_s("%d", &maxium);
    if (min >= maxium || l->length == 0) {//����Ľ�Сֵ���ڵ��ڽϴ�ֵ����Ϊ�ձ�
        printf("�Ƿ�ɾ��");
    }
    for ( i = 0; i < l->length && l->data[i] < min; i++);//�ҵ���һ�����ڵ���min��Ԫ��
    if (i >= l->length) {//������˳�����û�з���Ҫ���ɾ��
        printf("û��ɾ��ֵ");
        return *l;
    }
    for (j = i; j < l->length && l->data[j] <= maxium; j++);//�ҵ���һ������maxium��Ԫ��
    for (; j < l->length; i++, j++) {
        l->data[i] = l->data[j];
    }
    l->length = i;
    return *l;
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
        case 3:result=Combine(&l);//�ϲ���
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