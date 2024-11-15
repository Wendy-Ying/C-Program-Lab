#include<stdio.h>
int main()
{
	int a = 0;
	printf("Please enter the number:");
	scanf_s("%d", &a);
	int sign = 0;
	if (a < 0)
	{
		sign = 1;
		a = 255+a;
	}
	int b[9]={"\0"};
	int i = 0;
	while (a != 0)
	{
		if (a % 2 == 1) 
		{
			b[i] = 1;
		}
		else
		{
			b[i] = 0;
		}
		a = (int)a / 2;
		i++;
	}
	/*if (sign == 0)
	{
		printf("+");
	}
	else
	{
		printf("-");
	}*/
	for (i = 7; i >= 0; i--)
	{
		if (b[i] != 0)
		{
			for (; i >= 0; i--)
			{
				printf("%d", b[i]);
			}
			break;
		}
	}
	return 0;
}