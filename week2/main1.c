#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float a, b, c, d, e;
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	scanf("%f", &d);
	scanf("%f", &e);
	float minimum;
	minimum = (a < b ? a : b);
	minimum = (minimum < c ?minimum: c);
	minimum = (minimum < d ? minimum : d);
	minimum = (minimum < e ? minimum : e);
	printf("the minimum of 5 floats is %f\n",minimum);

	printf("the maximum of 5 floats is");
	printf("the average of 5 floats is");
	printf("the standard deviation of 5 floats is");
	system("pause");
	return 0;
}
