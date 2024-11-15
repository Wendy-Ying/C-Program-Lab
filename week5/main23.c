#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int search(int a[3][3],int b[5][5]);
float correlation(int a[3][3],int b[5][5],int i,int j);

int main(int argc, char *argv[]) {
	int a[3][3];
	int i,j;
	printf("Please enter matrix A:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Please enter matrix B:\n");
	int b[5][5]; 
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	int t;
	t=search(a,b);
	printf("The most related location is:\n");
	printf("row: %d to %d\ncolumn: %d to %d\n",(t/10+1),(t/10+3),(t%10+1),(t%10+3));
	printf("which is:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",b[t/10+i][t%10+j]);
		}
		printf("\n");
	}
	return 0;
}

int search(int a[3][3],int b[5][5])
{
	float c[3][3];
	int i,j;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			c[i][j]=(float)correlation(a,b,i,j);
		}
	}
	float max=0;
	int t=-1;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if(c[i][j]>max)
			{
				max=c[i][j];
				t=i*10+j;
			}
		}
	}
	return t;
}

float correlation(int a[3][3],int b[5][5],int i,int j)
{
	int sum=0;
	int m,n;
	int divisor=0; 
	for(m=0;m<=2;m++)
	{
		for(n=0;n<=2;n++)
		{
			int p=m+i;
			int q=n+j;
			sum+=a[p][q]*b[p][q];
			divisor+=b[p][q];
		}
	}
	return (float)sum/divisor;
}




