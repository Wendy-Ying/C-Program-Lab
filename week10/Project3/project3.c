#include<stdio.h>
#include<malloc.h>
int main()
{
	int row = 0;
	int column = 0;
	printf("How many rows do you want to print?\t");
	scanf_s("%d", &row);
	printf("How many columns do you want to print?\t");
	scanf_s("%d", &column);
	
	int* a = (int*)malloc(((row * column) + 1) * sizeof(int));
	int i;
	for (i = 0; i < row * column; i++)
	{
		scanf_s("%d", &(a[i]));
	}
	int sum=0;
	for (i = 0; i < column; i++)
	{
		sum = sum + a[i];
	}
	int j;
	i--;
	for (j = 0; j < row - 2; j++)
	{
		i++;
		sum = sum + a[i];
		i = i + column - 1;
		sum = sum + a[i];
	}
	i++;
	for (; i < row * column; i++)
	{
		sum = sum + a[i];
	}
	printf("%d", sum);
	free(a);
	return 0;
}