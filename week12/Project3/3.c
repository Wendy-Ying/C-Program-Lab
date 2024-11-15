/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	FILE* fp;
	fp = fopen("D:\\wendy\\study\\C program\\homework\\week12\\data.csv", "r");
	char* buffer = malloc(100 * sizeof(char));
	fgets(buffer, 100, fp);
	printf("%s", buffer);
	char* flag = malloc(100 * sizeof(char));
	*flag = '\0';
	int num[10];
	num[0] = strtok_s(buffer, ',', &flag);
	int i = 0;
	while (num[i])
	{
		i++;
		num[i] = strtok_s(NULL, ',', &flag);
	}
	num[i] = "\0";
	double number[10];
	for (i = 0; i < 10; i++)
	{
		number[i] = atof(num[i]);
	}
	double sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum = sum + number[i];
	}
	printf("The result is : %f.", sum);
	fclose(fp);
	free(buffer);
	return 0;
}*/