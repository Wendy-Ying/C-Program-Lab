#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char strcat1(char *a,char *b,int i,char *c);

int main(int argc, char *argv[]){
	char a[]="Ilove\0";
	char b[]="CHINA\0";
	int i;
	i=sizeof(a)+sizeof(b);
	char c[20];
	strcat1(&a,&b,i,c);
	printf("The result is %s.",c);
	return 0;
}

char strcat1(char *a,char *b,int i,char *c)
{
	int p=0;
	int t;
	for(t=0;a[t]!=0;t++)
	{
		c[p]=a[t];
		p++;
	}
	for(t=0;b[t]!=0;t++)
	{
		c[p]=b[t];
		p++;
	}
}
