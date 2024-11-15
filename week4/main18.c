#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a[101];
	int i,t;
	//所有灯关闭 
	for(i=1;i<=100;i++)
	{
		a[i]=0;
	}
	//开关灯 
	for(i=1;i<=100;i++)
	{
		for(t=1;t<=100;t++)
		{
			if(i%t==0)
			{
				a[i]=1-a[i];
			}
		}
	}
	printf("The lights below are on:");
	//输出开灯的灯 
	for(i=1;i<=100;i++)
	{
		if(a[i]==1)
		{
			printf("%d\t",i);
		}
	}
	return 0;
}
