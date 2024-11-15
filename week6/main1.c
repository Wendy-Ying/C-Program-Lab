#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float function(float *a,float *b,float *sum);

int main(int argc, char *argv[]) {
	printf("Please type the arguments:\n");
	float a,b,sum;
	scanf("%f %f",&a,&b);
//	printf("a = %f\n",a);
//	printf("b = %f\n",b);
	function(&a,&b,&sum);
	printf("a = %f\n",a);
	printf("b = %f\n",b);
	printf("sum = %f\n",sum);
	return 0;
}

float function(float *a,float *b,float *sum)
{
	float temp;
	temp=*a;
	*a=*b;
	*b=temp;
	*sum=*a+*b;
}
