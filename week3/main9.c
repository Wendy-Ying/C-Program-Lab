#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int num;
	printf("The prime numbers are:");
	for(num=100;num<=200;num++)
	{
		int result=1;
		int i;
		for(i=num-1;i>1;i--)
		{
//			printf("%d\t",i);
			if(num%i==0)
			{
				result=0;
			}
		}
//		printf("%d\n",result); 
		if(result==1)
		{
			printf("%d,",num);
		}
	} 
	return 0;
}
