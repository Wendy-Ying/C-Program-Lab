#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n,m;
	printf("The total number of chickens and rabbits is ") ;
	scanf("%d",&n); 
	printf("The total number of legs is ");
	scanf("%d",&m);
	
	if (m%2==1)	{printf("-1");	}
	else if (m>4*n)	{printf("-1");	}
	else if (m<2*n)	{printf("-1");	}
	else {
		int t;
		int num_rabbit,num_chicken;
		t=m-2*n;
		t=0.5*t;
		num_rabbit=t;
		num_chicken=n-t;
		printf("The number of rabbit is %d\n",num_chicken); 
		printf("The number of chickens is %d\n",num_rabbit);
		}
	
	return 0;
}
