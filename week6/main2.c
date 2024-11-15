#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int reverse(int *a,int t);

int main(int argc, char *argv[]) {
	int a[8]={0,10,20,30,40,50,60,70};
	int t=sizeof(a)/4; 
	reverse(a,t);
	int i;
	for(i=0;i<sizeof(a)/4;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

int reverse(int *a,int t)
{
	int i;
	i=t-1;
	int j=0;
	int temp;
	for(;i>j;i--,j++)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp; 
	}
}
