#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int product(int m[2][2],int n[2][2])
{
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",m[i][j]*n[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int a[2][2];
	int b[2][2];
	printf("Please enter matrix A:\n");
	scanf("%d %d %d %d",&a[0][0],&a[0][1],&a[1][0],&a[1][1]);
	printf("Please enter matrix B:\n");
	scanf("%d %d %d %d",&b[0][0],&b[0][1],&b[1][0],&b[1][1]);
	printf("The result is:\n");
	product(a,b);
	return 0;
}
