#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	struct point
	{
		int x;
		int y;
		float distance;
	};
	
	struct point pts[20] = { {49,95},{58,93},{78,6},{20,80},{86,97},
	{65,60},{92,23},{34,43},{65,69},{13,80},
	{22,56},{72,41},{67,22},{81,14},{41,84},
	{61,42},{78,93},{2,30},{73,33},{45,2}};
	
	int i;
	for(i=0;i<20;i++)
	{
		pts[i].distance=sqrt((40-pts[i].x)*(40-pts[i].x)+(65-pts[i].y)*(65-pts[i].y));
		printf("The distance of P and point %d\t£¨%d,%d) is %f.\n",i+1,pts[i].x,pts[i].y,pts[i].distance);
	}
	
	return 0;
}
