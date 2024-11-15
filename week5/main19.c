#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float sigmoid(float num)
{
	float dividend=exp(num);
	float divisor=exp(num)+1;
	return dividend/divisor;
}

float tanh1(float num)
{
	float dividend=exp(num*2)-1;
	float divisor=exp(num*2)+1;
	return dividend/divisor;
}

float ReLU(float num)
{
	return num>0?num:0;
}

float Leaky_ReLU(float num)
{
	float i=0.1*num;
	return num>i?num:i;
}

int main(int argc, char *argv[]) {
	
	float num;
	printf("Please enter a number:");
	scanf("%f",&num);
	printf("sigmoid of %f is %f\n",num,sigmoid(num)) ;
	printf("tanh of %f is %f\n",num,tanh1(num)) ;
	printf("ReLU of %f is %f\n",num,ReLU(num)) ;
	printf("Leaky_ReLU of %f is %f\n",num,Leaky_ReLU(num)) ;
	
	return 0;
}
