#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int index1(int i)
{
	int m=0;
	while(i!=0)
	{
		m++;
		i=i/10;
	}
	return m;
}

int cal_bits(int i)
{
	//计算
	int bit;
	int t=1;
	int k=index1(i);
	for(;k>1;k--)
	{
		t=10*t;
	}
	bit=i/t;//输出的数 
	i=i-bit*t;//剩下的数 
	//打印 
	printf("%d\t",bit); 
	//递归 
	if(i!=0)
	{
		cal_bits(i);
	}
}

int main(int argc, char *argv[]) {
	printf("Please enter the number:");
	int num;
	scanf("%d",&num);
	printf("The result is:\n");
	cal_bits(num);
	return 0;
}
