#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {

	int i;

	//定义
	typedef enum category { A, B } Enum;
	typedef struct point
	{
		int x;
		int y;
		Enum category;
	}Point;

	Point points[100];
	float distance[100];

	//初始化数据
	for (i = 0; i < 100; i++)
	{
		points[i].x = 0;
		points[i].y = 0;
		points[i].category = 0;
		distance[i] = 0;
	}
	
	//读入数据
	FILE* fp;
	fp = fopen("D:\\wendy\\study\\C program\\homework\\week9\\Points.bin", "rb");
	fread(&points, sizeof(Point), 100, fp);

	//输入数据
	int x1 = 0;
	int y1 = 0;
	printf("Please enter the coordinate of a new point(x,y):\n");
	scanf("%d,%d", &x1, &y1);

	int k;
	printf("The value of K is:\n");
	scanf("%d", &k);

	//检查输入
	for (i = 0; i < 100; i++)
	{
		printf("%d. x:%d  y:%d  category:%d\n", (i+1), points[i].x, points[i].y, points[i].category);
	}

	//计算长度
	for (i = 0; i < 100; i++)
	{
		distance[i] = (float)sqrt((x1 - points[i].x) * (x1 - points[i].x) + (y1 - points[i].y) * (y1 - points[i].y));
	}

	//排序
	int m, n;
	for (m = 0; m < 99; m++)
	{
		for (n = 0; n < 99 - m; n++)
		{
			if (distance[n] > distance[n+1])
			{
				float temp=0;
				temp = distance[n];
				distance[n] = distance[n + 1];
				distance[n + 1] = temp;
				int value=0;
				value = points[n].x;
				points[n].x = points[n + 1].x;
				points[n + 1].x = value;
				value = points[n].y;
				points[n].y = points[n + 1].y;
				points[n + 1].y = value;
				Enum c = points[n].category;
				points[n].category = points[n + 1].category;
				points[n + 1].category = c;
			}
		}
	}

	//检验
	for(i=0;i<100;i++)
	{
		printf("%d. x:%d  y:%d  distance:%f  category:%d\n",(i+1),points[i].x,points[i].y, distance[i], points[i].category);
	}
	
	//输出结果
	printf("P belongs to: ");

	float sum=0;
	for (i = 0; i < k; i++)
	{
		sum += points[i].category;
	}

	float s = 0;
	s = (float)k;
	s = s / 2;

	printf("%f,%f\n", sum,s);

	if (sum >= s)
	{
		printf("B.\n");
	}
	else
	{
		printf("A.\n");
	}

	return 0;
}