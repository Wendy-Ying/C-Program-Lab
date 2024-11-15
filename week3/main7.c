#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	for(i=0;i<2;i++)
	{	
		int score;
		printf("Please enter a score:");
		scanf("%d",&score);
		printf("The grade is:");
		if(score>=90&&score<=100){printf("A");}
		if(score>=80&&score<=89){printf("B");}
		if(score>=70&&score<=79){printf("C");}
		if(score>=60&&score<=69){printf("D");}
		if(score>=0&&score<=59){printf("E");}
		printf("\n");
	}
	return 0;
}
