#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int transfer(int *raw,int *rgb);

int main(int argc, char *argv[]) {
	
	//输入raw 
	printf("Please type the matrix:\n");
	int raw[16];
	int m,n;
	for(m=0;m<4;m++)
	{
		for(n=0;n<4;n++)
		{
			scanf("%d",&raw[m*4+n]);
		}
	} 
	
	//变成RGB 
	int rgb[12];
	transfer(raw,rgb);
	
	//打印RGB 
	printf("The result is:\n");
	for(m=0;m<2;m++)
	{
		for(n=0;n<2;n++)
		{
			printf("r%dg%db%d\t",rgb[m*6+n*3+0],rgb[m*6+n*3+1],rgb[m*6+n*3+2]);
		}
		printf("\n");
	}	
	
	return 0;
}

int transfer(int *raw,int *rgb)
{
	int m,n;
	for(m=0;m<4;m=m+2)
	{
		for(n=0;n<4;n=n+2)
		{
			int i,j;
			i=m/2;
			j=n/2;
			rgb[6*i+j*3+0]=raw[(m+1)*4+n];
			rgb[6*i+j*3+1]=(raw[m*4+n]+raw[(m+1)*4+n+1])/2;
			rgb[6*i+j*3+2]=raw[m*4+n+1];
		}
	} 
}

