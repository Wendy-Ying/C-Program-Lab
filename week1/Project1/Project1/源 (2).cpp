#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {
	// ‰»Î 
	int num[15];
	printf("Please print the numbers:");
	int i;
	for (i = 0; i < 15; i++)
	{
		scanf("%d", &num[i]);
	}

	//≈≈–Ú
	int j, k, s;
	int temp;
	for (j = 1; j < 15; j++)
	{
	label:
		k = j - 1;
		while (k >= 0)
		{
			s = j;
			if (num[k] < num[s])
			{
				goto label;
			}
			else
			{
				temp = num[k];
				num[k] = num[s];
				num[s] = temp;
				k = s - 1;
			}
		}
	}


	// ‰≥ˆ 
	for (i = 0; i < 15; i++)
	{
		printf("%d\t", num[i]);
	}
	printf("\n");
	return 0;
}