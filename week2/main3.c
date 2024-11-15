#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float radius;
	float perimetric;
	float area;
	
	printf("The radius is\n");
	scanf("%f",&radius);
	
	perimetric = 2*3.14*radius;
	
	area = 3.14*radius*radius;
	
	printf("The perimetric is %f\n",perimetric);
	printf("The area is %f\n",area);
	
	
	return 0;
}
