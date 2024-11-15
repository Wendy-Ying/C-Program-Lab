#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int depart(int a,int *num,int t);
char *strcat1(char *a,char *b);
char *chinese(int *a,int t,char *b);
int main(int argc, char *argv[]) {
	int a;
	int t;
	printf("How many numbers do you want to type?\n");
	scanf("%d",&t);
	printf("Please type the numbers:\n");
	scanf("%d",&a); 
	int *num;
	num=(int*)malloc(t*sizeof(int)); 
	depart(a,num,t);
	char *number;
	number=(int*)malloc(t*50*sizeof(char));
	chinese(num,t,number);
	number[0]=strcat1(number[0],number[1]);
	number[0]=strcat1(number[0],number[2]);
	number[0]=strcat1(number[0],number[3]);
	number[0]=strcat1(number[0],number[4]);
	printf("The result is %s.",number[0]);
	free(num);
	free(number);
	return 0;
}
int depart(int a,int *num,int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		int k=1;
		int m;
		for(m=1;m<t;m++)
		{
			k=10*k;
		}
		num[i]=a/k;
	}
}
char *chinese(int *a,int t,char *b)
{
	char result[10][50]={"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
	int i;
	for(i=0;i<t;i++)
	{
		int j;
		for(j=0;j<50;j++)
		{
			*b[t][j]=result[a[t]][j];
		}
	}
}

char *strcat1(char *a,char *b)
{
	char *c;
	char *save;
	c =(char*)malloc(sizeof(a)+sizeof(b));
	save=c;
	while(!(*a))
	*c++=*a++;
	while(!(*b))
	*c++=*b++;
	return save;
}
