#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a,b,c;
	printf("For the equation:ax^2+bx=c=0,please give the a,b,c.\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	
	printf("The solution:");
	
	float i;
	i=b*b-4*a*c;
	if(i<0){
		printf("-1");
		}else{
			float delta,root_1,root_2;
			delta=sqrt(i);
			root_1=(delta-b)/(2*a);
			root_2=(-delta-b)/(2*a); 
			printf("The root 1 is %f.\nThe root 2 is %f.\n",root_1,root_2);
			}
	
	
	return 0;
}
