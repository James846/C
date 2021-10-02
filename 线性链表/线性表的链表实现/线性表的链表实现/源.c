#include <stdio.h>
#include <stdlib.h>

typedef int Datetype;//��int��һ������ 
typedef int value;

/*������ṹ*/
typedef struct NODE {
    Datetype date;
    struct NODE* next;
}Node, * LinkList;

void AddNode_List(LinkList Head)//���ӽڵ� 
{
    char c = 0;
    value x;
    printf("�����㣺һ�οɲ�������㣬���뻻�з���������\n�����ʽ��2 5 3 8�س�\n");
    while (c != '\n')//�����ַ�Ϊ'\n'ʱ �������� 
    {
        LinkList p0 = Head;
        LinkList p1 = p0->next;
        scanf_s("%d", &x);
        while ((p1 != NULL) && (x >= p1->date))
        {
            p0 = p1;
            p1 = p1->next;//Ѱ�Ҳ���ĺ���λ�� 
        }
        //����ڵ� 
        p0->next = (LinkList)malloc(sizeof(Node));
        p0->next->date = x;
        p0->next->next = p1;//����ڵ� 
        c = getchar();
    }
    printf("�������\n");
}

void Traverse_List(LinkList Head)//�����ڵ� 
{
    LinkList p = Head;
    printf("\n���������");
    while (p->next != NULL)//��p�ĺ�̽��ǿ�ʱ ������� 
    {
        p = p->next;
        printf("%d", p->date);
    }
    printf("\n");
}

void Reverse_Traverse_List(LinkList Head)//������� 
{
    LinkList p = Head;
    if (p->next == NULL);
    else
    {
        p = p->next;
        Reverse_Traverse_List(p);
        printf("%d ", p->date);
    }
}

void DeleteNode_List(LinkList Head)
{
    LinkList p0 = Head;
    LinkList
        p1 = Head->next;//p0Ϊͷָ�� p11Ϊp0�ĺ�̽�� 
    printf("������Ҫɾ���Ľڵ�ֵ: x = ");
    value x = 0;
    scanf_s("%d", &x);
    while (p1 != NULL)//��p1�ǿ�ʱ 
    {
        if (p1->date == x)
            p0->next = p1->next;//��������ɾ��ֵΪ X �Ľڵ�
        else  p0 = p0->next;
        p1 = p1->next;           //p1ָ���������      
    }
    printf("\nɾ������\n");
}

void CMD_Select(void)
{
    printf("\n**************�������������******************");
    printf("\nCMD������ʾ:");
    printf("\n1:�����㣬2:��������3:ɾ����㣬10:�˳�����\n");
    printf("**********************************************\n");
    printf("CMD����:");
}

int main()
{
    LinkList Head = (LinkList)malloc(sizeof(Node));
    Head->next = NULL;//����ͷָ�룬ͷָ��ĺ��һ��Ҫ�ǵ���Ϊ�� 
    int cmd = NULL;
    CMD_Select();//����������ʾ        
    scanf_s("%d", &cmd);
    while (cmd != 10)
    {
        switch (cmd)
        {
        case 1: AddNode_List(Head);//����ڵ� 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 2: Traverse_List(Head);//������� 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 3: DeleteNode_List(Head);//ɾ���ڵ� 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 4: Reverse_Traverse_List(Head);//ɾ���ڵ� 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        default:printf("�����������,��������"); cmd = 10;
        }
    }
    return 0;
}
