#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int product=1;
	int num;
	printf("Please print the number:");
	scanf("%d",&num);
	for(num;num>0;num--)
	{
		product=product*num;
	}
	
	printf("The factorial of the number is:%d",product);
	
	
	return 0;
}
