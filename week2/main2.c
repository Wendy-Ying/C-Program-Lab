#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a, b, c, d, e;
	printf("Please type the numbers:\n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	scanf("%f", &d);
	scanf("%f", &e);


	float minimum;
	minimum = a;
	minimum = minimum<b?minimum:b;
	minimum = minimum<c?minimum:c;
	minimum = minimum<d?minimum:d;
	minimum = minimum<e?minimum:e;
	
	
	float maximum;
	maximum = a;
	maximum = maximum>b?maximum:b;
	maximum = maximum>c?maximum:c;
	maximum = maximum>d?maximum:d;
	maximum = maximum>e?maximum:e;
	
	
	float average;
	average=a+b+c+d+e;
	average=average/5;
	
	
	float standard_deviation;
	standard_deviation=0;
	standard_deviation+=(a-average)*(a-average);
	standard_deviation+=(b-average)*(b-average);
	standard_deviation+=(c-average)*(c-average);
	standard_deviation+=(d-average)*(d-average);
	standard_deviation+=(e-average)*(e-average);
	standard_deviation=standard_deviation/5;
	standard_deviation=sqrt(standard_deviation);
	
		
	printf("minimum=%f\n",minimum);
	printf("maximum=%f\n",maximum);
	printf("average=%f\n",average);
	printf("standard_deviation=%f\n",standard_deviation);
	
	return 0;
}
