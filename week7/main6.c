#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	typedef enum category {A, B} Enum;
	typedef struct point
	{
		int x;
		int y;
		float dist;
		Enum category;
	}Point;
	
	Point points[20] = {49,95,0,A,58,93,0,A,78,6,0,A,20,80,0,A,
	86,97,0,A,65,60,0,A,92,23,0,A,34,43,0,A,65,69,0,A,13,80,0,A,
	22,56,0,B,72,41,0,B,67,22,0,B,81,14,0,B,41,84,0,B,61,42,0,B,
	78,93,0,B,2,30,0,B,73,33,0,B,45,2,0,B};
	
	int i;
	for(i=0;i<20;i++)
	{
		points[i].dist=sqrt((45-points[i].x)*(45-points[i].x)+(60-points[i].y)*(60-points[i].y));
	}
	
/*	for(i=0;i<20;i++)
	{
		printf("%f\n",points[i].dist);
	}
	printf("\n");
*/	
	int m,n; 
	for(m=0;m<19;m++)
	{
		for(n=0;n<19-m;n++)
		{
			if(points[n].dist>points[n+1].dist)
			{
				float temp;
				temp=points[n].dist;
				points[n].dist=points[n+1].dist;
				points[n+1].dist=temp;
				temp=points[n].x;
				points[n].x=points[n+1].x;
				points[n+1].x=temp;
				temp=points[n].y;
				points[n].y=points[n+1].y;
				points[n+1].y=temp;
				Enum c=points[n].category;
				points[n].category=points[n+1].category;
				points[n+1].category=c;
			}
		}
	} 
	
/*	for(i=0;i<20;i++)
	{
		printf("%f\n",points[i].dist);
	}	
*/	
	
	printf("P belongs to: "); 
//	printf("%d,%d,%d\n",points[0].category,points[1].category,points[2].category);

	if(points[0].category+points[1].category+points[2].category>=2)
	{
		printf("B.\n");
	}
	else
	{
		printf("A.\n");
	}
	
	return 0;
}
