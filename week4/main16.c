#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int pmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int rmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	
	int year,month,day; 
	printf("The date is:");
	scanf("%d %d %d",&year,&month,&day);
	
	int date;
	int i;
	for(i=0;i<month-1;i++)
	{
		if(year%4!=0)
		{
			date+=pmonth[i];
		}
		if(year%4==0)
		{
			date+=rmonth[i];
		}
	}
	date+=day;
	
//	printf("%d",date);
	
	if(date%10==1){printf("%d %d %d is %dst day of %d.\n",year,month,day,date,year);	}
	if(date%10==2){printf("%d %d %d is %dnd day of %d.\n",year,month,day,date,year); }
	if(date%10==3){printf("%d %d %d is %drd day of %d.\n",year,month,day,date,year);	}
	if((date%10>4)||(date%10==0)){printf("%d %d %d is %dth day of %d.\n",year,month,day,date,year);	}
	
	return 0;
}
