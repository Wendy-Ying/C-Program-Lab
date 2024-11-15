#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int length(char *a); 

int main(int argc, char *argv[]) {
	printf("Please type the words:\n");
	char a[50];
	scanf("%s",a);
	printf("The length is %d.\n",length(a));
	return 0;
}

int length(char *a)
{
	int len=0;
	char *i=a;
	for(;*i!=0;i++)
	{
		len++;
	}
	return len;
}
