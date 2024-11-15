#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	struct weather
	{
		int date;
		char day[10];
		int temperature;
	};
	
	enum week {Monday=0,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday};
	
	struct weather weather[7]={
		{17,"Monday",28},
		{18,"Tuesday",27},
		{19,"Wednesday",27},
		{20,"Thurday",28},
		{21,"Friday",30},
		{22,"Saturday",32},
		{23,"Sunday",31}
	};
	
	struct weather *p=weather;
	printf("Hot days are:\n");
	int i;
	for(i=Monday;i<=Sunday;i++)
	{
		if(p->temperature>30)
		{
			printf("Date:10.%d\t",p->date);
			printf("Day:%s\n",p->day);
		}
		p++;
	}
	
	return 0;
}
