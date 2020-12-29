// 鞍点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define N 3
#define M 3
int main()
{
	int a[N][M];
	int n, k, t, j;int num,min,max;
	printf("请输入二维数组a[3][3]:\n");
	for (n = 0;n <N;n++)
	{
		for (k = 0;k <M;k++)
		{
			scanf_s("%d", &a[n][k]);
		}
	}
	int* p[M];
	for (n = 0;n < N;n++)
	{
		p[n] = a[n];
	}
	int** pp=p;
	for (t = 0;t <N;t++)
	{
		max = *(pp[t] + 0);
		num = 0;
		for (j = 0;j < M;j++)
		{
			if (*(pp[t] + j) > max)
			{
				max = *(pp[t] + j);
				num = j;
			}
		}
		for (k = 0;k < N;k++)
		{
			if (max > *(pp[k] + num))
			{
				printf("无鞍点");
			}
		}
		printf("鞍点为：a[%d][%d]=%d", t, num, max);
		break;
	}
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
