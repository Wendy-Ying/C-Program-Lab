#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a[4][4];
	int m,n;
	for(m=0;m<=3;m++)
	{
		for(n=0;n<=3;n++)
		{
			if(m==n)
			{
				a[m][n]=m+1;
			}
			else
			{
				a[m][n]=0;
			}
		}
	}
	
	for(m=0;m<=3;m++)
	{
		for(n=0;n<=3;n++)
		{
			printf("%d\t",a[m][n]);
		}
		printf("\n");
	}
	return 0;
}
