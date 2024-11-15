#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float distance(float i,float j)
{
	float dividend=2*i+6*j+8;
	float divisor=sqrt(40);
	float d;
	d=dividend/divisor;
	if(d<0){d=-d;}
	return d;
}

int main(int argc, char *argv[]) {
	printf("Where is the point?");
	float i,j;
	scanf("%f,%f",&i,&j);
	printf("The distance is from 2x+6y+8=0 to (%f,%f) is%f.",i,j,distance(i,j));
	return 0;
}
