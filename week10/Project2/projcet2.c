#include<stdio.h>
int main()
{
	int i, j, k;
	int m=0;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			for (k = 0; k < 100; k++)
			{
				if ((i + j + k == 100) && (3*i + 2*j + 0.5*k == 100))
				{
					m++;
					printf("第%d种可能：大马%d匹，中马%d匹，小马%d匹\n", m, i, j, k);
				}
			}
		}
	}
	return 0;
}