#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

//输入矩阵	
	int a[4][2]={14,45,34,43,54,67,67,26};
	int b[2][4];
	int m,n;
	for(m=0;m<4;m++)
	{
		for(n=0;n<2;n++)
		{
			b[n][m]=a[m][n];
		}
	}
	
/*	//确认矩阵a、b无误 
	for(n=0;n<2;n++)
	{
		for(m=0;m<4;m++)
		{
			printf("%d\t",b[n][m]);
		}
		printf("\n");
	}
*/

//计算出c	
	float c[4][4];
	int i,j,t;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(t=0;t<2;t++)
			{
				c[i][j]+=(float)a[i][t]*b[t][j];
			}
		}
	}
	 
/*	//确认c无误 
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%f\t",c[i][j]);
		}
		printf("\n");
	}
*/
	
//形成压缩矩阵	
	float d[2][2];
	int p,q;
	for(p=0;p<2;p++)
	{
		for(q=0;q<2;q++)
		{
			d[p][q]=c[2*p][2*q]+c[2*p+1][2*q]+c[2*p][2*q+1]+c[2*p+1][2*q+1];
			d[p][q]=d[p][q]/4;
		}
	}

//打印结果	
	for(p=0;p<2;p++)
	{
		for(q=0;q<2;q++)
		{
			printf("%f\t",d[p][q]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
