#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char a[3][15];
	char b[3][15];
	printf("Please type the words:");
	scanf("%s %s %s",&a[0],&a[1],&a[2]);
	//复制数组 
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<15;j++)
		{
			b[i][j]=a[i][j];
		}
	}
	//修改文字 
	char e[15]="china";
	int k;
	for(k=0;k<3;k++)
	{
		if(strcmp(a[k],e)==0)
		{
			strupr(a[k]);
		}
	}
	strcat(a[0],a[1]);
	strcat(a[0],a[2]);
	//打印结果 
	printf("%s\n",a[0]);
//	printf("There are %d words in the sentence.",strlen(a[0]));
	//计算单词数 
	char c[6]="@";
	strcat(b[0],c);
	strcat(b[1],c);
	strcat(b[2],c);
	strcat(b[0],b[1]);
	strcat(b[0],b[2]);
//	printf("%s\n",b[0]);
//	printf("There are %d words in the sentence.",strlen(a[0]));
//	printf("There are %d words in the sentence.",strlen(b[0]));
	printf("There are %d words in the sentence.",(strlen(b[0])-strlen(a[0])));
	return 0;
}
