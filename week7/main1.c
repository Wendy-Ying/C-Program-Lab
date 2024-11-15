#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	struct student
	{
		char name[20];
		float temperature;
	};
	
	struct student stu[10]={{"Jack",36.5},{"Tim",37.6},{"Steve",35.9},{"Mara",36.9},{"Paula",38.1},{"Emma",35.4},{"David",36.1},{"Tyler",37.9},{"Noah",36.8},{"Daniel",37.1}};
	
	struct student *p=stu;
	printf("The students who have a fever are:\n");
	int i;
	for(i=0;i<10;i++)
	{
		if(p->temperature>37.3)
		{
			printf("Name:%s\t",p->name);
			printf("Number:%d\n",i+1);
		}
		p++;
	}
	
	return 0;
}
