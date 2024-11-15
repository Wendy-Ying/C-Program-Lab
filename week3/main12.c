#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int total;
	int month_1=2;
	int month_2=0;
	int month_3=0;
	int month_4=0;
	int month_5=0;
	
	int time;
	printf("How many months have passed?");
	scanf("%d",&time);
	
	int i;
	for(i=time;i>1;i--)
	{
		int t;
		t=month_1;
		month_1=month_2+month_3+month_4;
		month_5=month_4;
		month_4=month_3;
		month_3=month_2;
		month_2=t;
	}
	
	total=month_1+month_2+month_3+month_4+month_5;
	printf("There are %d rabbits in month %d .",total,time);
	 
	return 0;
}
