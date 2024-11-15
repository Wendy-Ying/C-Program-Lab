#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define sigmoid(num) (exp(num)/(exp(num)+1)) 

#define tanh1(num) ((exp(num*2)-1)/(exp(num*2)+1))

#define ReLU(num) (num>0?num:0)

#define Leaky_ReLU(num) (num>0.1*num?num:0.1*num)

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
