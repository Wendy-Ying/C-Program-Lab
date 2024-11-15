#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int student;
	int a,b,c;
	printf("The number of students in the last row is: (group as 3 persons in a row)");
	scanf("%d",&a);
	printf("The number of students in the last row is: (group as 5 persons in a row)");
	scanf("%d",&b);
	printf("The number of students in the last row is: (group as 7 persons in a row)");
	scanf("%d",&c);
	
	for(student=10;student<=100;student++)
	{
		if((student%3==a)&&(student%5==b)&&(student%7==c))
		{
			printf("There are %d students on the playground.",student);
		}
	}
	
	return 0;
}
