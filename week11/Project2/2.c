#include<stdio.h>
int main()
{
	static int a[] = { 1,1,2,3,5,6,6,6,8,8,11,14,14,14,14,17,17,20 };
	int i = 0;
	for (i = 17; i >= 0; i--)
	{
		if (a[i] == a[i - 1])
		{
			a[i] = 0;
		}
	}
	int j = 0;
	int temp = 0;
	for (i = 17; i >= 0; i--)
	{
		if (a[i] == 0)
		{
			for (j = i; j < 17; j++)
			{
				a[j] = a[j + 1];
			}
			a[17] = 0;
		}
	}
	printf("The result is:\n");
	for (i = 0; i < 18; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}