#include<stdio.h>
#include<math.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	float sum = 0;
	float temp = 0;
	printf("Please enter the number of n:");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		temp = 1;
		for (j = 0; j < i; j++)
		{
			temp = temp / (j + 1);
		}
		sum += temp;
	}
	printf("The approximation of e is: %f .", sum);
	return 0;
}