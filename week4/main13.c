#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float a[5];
	int i;
	for(i=0;i<5;i++)
	{
		printf("Please type the number %d :",i+1);
		scanf("%f",&a[i]);
	}
	printf("The result is:\n");
	for(i=4;i>=0;i--)
	{
		printf("%f\t",1/a[i]);
	}
	
	
	return 0;
}
