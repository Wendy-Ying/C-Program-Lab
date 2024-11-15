#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a,b,c;
	
	printf("The lengths of the triangle are:\n");
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	
	printf("The solutions:");
	int i,j,k;
	i=a+b>c?1:0;
	j=b+c>a?1:0;
	k=a+c>b?1:0;
	
	if(i+j+k!=3)
		{
			printf("-1");
		}
	if(i+j+k==3)
		{
			float product;
			product=(a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c);
			float area;
			area=sqrt(product);
			area=0.25*area;
			printf("%f",area);
		}
	
	
	return 0;
}
