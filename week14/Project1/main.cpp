#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <opencv2/opencv.hpp>
#define num_of_points 200
#define learning_rate 0.1
typedef struct
{
	float x[2];
	int label;
}Point;
Point points[num_of_points];

void show_result(Point* points, int num, float a, float b, float c);
int sign(float i);

int main()
{
	//打开文件
	FILE* fp;
	fp = fopen("D://wendy//study//C program//homework//week14//perception.csv", "r");
	if (fp == NULL)
	{
		printf("读取数据失败");
	}

	//读数据
	char* buffer = (char*)malloc(50 * sizeof(char));
	char seps[] = " ,";
	char* token;
	double number[600];//number为预先存数据的数组

	int i = 0;
	int j = 0;

	for (i = 0; i < 200; i++)
	{
		fgets(buffer, 50, fp);//存数据
		token = strtok(buffer, seps);

		while (token != NULL)
		{
			number[j] = atof(token);
			j++;
			token = strtok(NULL, seps);
		}
		//一组数据分解完毕
	}
	fclose(fp);
	free(buffer);//读取完毕，全部关闭释放

	for (j = 0; j < 600; j++)
	{
		//printf("%f\n", number[j]);
	}//检验数据读取分解无误

	for (i = 0; i < 200; i++)
	{
		points[i].x[0] = (float)number[i * 3];
		points[i].x[1] = (float)number[i * 3 + 1];
		points[i].label = (int)number[i * 3 + 2];
	}//保存数据到结构体中

	for (i = 0; i < 200; i++)
	{
		//printf("The %d point is:  \tlength:%f  \tcolour:%f  \tlabel:%d\n", (i + 1), points[i].x[0], points[i].x[1], points[i].label);
	}//检验上述所有操作，完成准备工作 Read the csv file and convert ASCII data into float

	//进入循环
	int sum_loss = 0;
	float c1 = 0;
	float c2 = 0;
	float c3 = 0;
	int iteration = 0;
	int loss = 0;
	float temp = 0;
	//准备变量

	while(1)
	{
		iteration++;//记录迭代次数

		sum_loss = 0;//重置

		for (i = 0; i < 200; i++)
		{
			temp = (float)c1 * points[i].x[0] + c2 * points[i].x[1] + c3;
			loss = points[i].label - sign(temp);
			loss = loss / 2;
			c1 = c1 + learning_rate * loss * points[i].x[0];
			c2 = c2 + learning_rate * loss * points[i].x[1];
			c3 = c3 + learning_rate * loss;
			sum_loss = sum_loss + abs(loss);
		}//计算每组数据

		if (iteration == 100)
		{
			break;
		}
		if (sum_loss == 0)
		{
			break;
		}//判断退出条件
	}

	//printf("%d\n", iteration);//了解退出条件

	//输出结果
	if (c2 < 0)
	{
		if (c3 < 0)
		{
			printf("The result is :\t%fx %fy %f=0\n", c1, c2, c3);
		}
		else
		{
			printf("The result is :\t%fx %fy +%f=0\n", c1, c2, c3);
		}
	}
	else
	{
		if (c3 < 0)
		{
			printf("The result is :\t%fx +%fy %f=0\n", c1, c2, c3);
		}
		else
		{
			printf("The result is :\t%fx +%fy +%f=0\n", c1, c2, c3);
		}
	}

	//在opencv中查看结果
	show_result(points, 200, c1, c2, c3);

	return 0;
}
void show_result(Point* points, int num, float a, float b, float c)
{
	cv::Mat result = cv::Mat(750, 1500, CV_8UC3, cv::Scalar(0, 0, 0));
	for (int i = 0; i < num; i++)
	{
		cv::Point2f fish_point = cv::Point2f(points[i].x[0] * 50,
			points[i].x[1] * 50);
		if (points[i].label == 1)
			cv::circle(result, fish_point, 5, cv::Scalar(255, 0, 0), -1);
		else
			cv::circle(result, fish_point, 5, cv::Scalar(0, 0, 255), -1);
	}
	cv::line(result, cv::Point2f(0, -1 * c * 50 / b), cv::Point2f(1500, -1
		* (a * 1500 + c * 50) / b), cv::Scalar(0, 255, 0), 2);
	std::cout << (float)c / b << " " << (-1 * a * 1400 + c) / b;
	imshow("result", result);
	cv::waitKey(0);
}
int sign(float i)
{
	int k = 0;
	if (i < 0)
	{
		k = -1;
	}
	else
	{
		k = 1;
	}
	return k;
}