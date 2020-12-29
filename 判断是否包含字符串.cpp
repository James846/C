// 判断是否包含字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string.h>
void function(char* p1,  char *p2)
{
    int n, k, t, index = -1;
    for (n = 0; p1[n] != '\0'; n++)
    {
        for (k = n, t = 0; p2[t] != '\0' && p1[k] == p2[t]; k++, t++)
        if (p2[k] =='\0')
        {
            index = n + 1;
            break;
        }
    }
    printf("字符串：%s\n", p1);
    if (index != -1)
    printf("字符串中存在查找的字符串：%s  下标开始位置为： %d\n", p2, index);
    else printf("字符串中不存在查找的字符串");
}

int main()
{
    char str[100]; 
    char sub_str[100] ;
    printf("请输入字符串：");
    scanf_s("%s", str, 100);
    printf("\n请输入想查找的字符串：");
    scanf_s("%s", sub_str,100);
    function(str, sub_str);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
