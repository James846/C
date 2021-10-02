#include <stdio.h>
#include <stdlib.h>

typedef int Datetype;//给int起一个别名 
typedef int value;

/*定义结点结构*/
typedef struct NODE {
    Datetype date;
    struct NODE* next;
}Node, * LinkList;

void AddNode_List(LinkList Head)//增加节点 
{
    char c = 0;
    value x;
    printf("插入结点：一次可插入多个结点，输入换行符结束插入\n输入格式：2 5 3 8回车\n");
    while (c != '\n')//输入字符为'\n'时 结束输入 
    {
        LinkList p0 = Head;
        LinkList p1 = p0->next;
        scanf_s("%d", &x);
        while ((p1 != NULL) && (x >= p1->date))
        {
            p0 = p1;
            p1 = p1->next;//寻找插入的合适位置 
        }
        //插入节点 
        p0->next = (LinkList)malloc(sizeof(Node));
        p0->next->date = x;
        p0->next->next = p1;//插入节点 
        c = getchar();
    }
    printf("插入结束\n");
}

void Traverse_List(LinkList Head)//遍历节点 
{
    LinkList p = Head;
    printf("\n遍历结果：");
    while (p->next != NULL)//当p的后继结点非空时 继续输出 
    {
        p = p->next;
        printf("%d", p->date);
    }
    printf("\n");
}

void Reverse_Traverse_List(LinkList Head)//逆序遍历 
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
        p1 = Head->next;//p0为头指针 p11为p0的后继结点 
    printf("请输入要删除的节点值: x = ");
    value x = 0;
    scanf_s("%d", &x);
    while (p1 != NULL)//当p1非空时 
    {
        if (p1->date == x)
            p0->next = p1->next;//从链表中删除值为 X 的节点
        else  p0 = p0->next;
        p1 = p1->next;           //p1指针继续后移      
    }
    printf("\n删除结束\n");
}

void CMD_Select(void)
{
    printf("\n**************请输入操作命令******************");
    printf("\nCMD命令提示:");
    printf("\n1:插入结点，2:遍历链表，3:删除结点，10:退出程序\n");
    printf("**********************************************\n");
    printf("CMD命令:");
}

int main()
{
    LinkList Head = (LinkList)malloc(sizeof(Node));
    Head->next = NULL;//创建头指针，头指针的后继一定要记得置为空 
    int cmd = NULL;
    CMD_Select();//输入命令提示        
    scanf_s("%d", &cmd);
    while (cmd != 10)
    {
        switch (cmd)
        {
        case 1: AddNode_List(Head);//插入节点 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 2: Traverse_List(Head);//遍历结点 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 3: DeleteNode_List(Head);//删除节点 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        case 4: Reverse_Traverse_List(Head);//删除节点 
            CMD_Select(); scanf_s("%d", &cmd);
            break;
        default:printf("命令输入错误,结束运行"); cmd = 10;
        }
    }
    return 0;
}
