#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
int main(int argc, char *argv[]) {
	
//设置类型	
	typedef struct
	{
		int stu_number;
		char name[20];
		int score;
	}score;
	score Transcripts[10];
	
	int i,j;
	for(i=0;i<10;i++)
	{
		Transcripts[i].stu_number=0;
		Transcripts[i].name[0]='\0';
		Transcripts[i].score=0;
	}
	
/*	for(i=0;i<10;i++)
	{
		printf("number:%d\t\tname:%s\t\tscore:%d\n",Transcripts[i].stu_number,Transcripts[i].name,Transcripts[i].score);
	}
	printf("\n");
*/	

//开始读取数据	
	FILE *pfile;
	pfile=fopen("data.bin","rb");
	
	fread(&Transcripts,sizeof(Transcripts),10,pfile);
	
/*	for(i=0;i<10;i++)
	{
		printf("number:%d\t\tname:%s\t\tscore:%d\n",Transcripts[i].stu_number,Transcripts[i].name,Transcripts[i].score);
	}
	printf("\n");
*/	
//读取数据完毕
	
//排序	
	score temp;
	for (i=0;i<9;i++)
	{
		for (j=8-i;j>=0;j--)
		{
			if (Transcripts[j].score<Transcripts[j+1].score)
			{
				temp=Transcripts[j];
				Transcripts[j]=Transcripts[j+1];
				Transcripts[j+1]=temp;
			}
		}	
	}
	
	for(i=0;i<10;i++)
	{
		printf("number:%d\t\tname:%s\t\tscore:%d\n",Transcripts[i].stu_number,Transcripts[i].name,Transcripts[i].score);
	}
//排序完毕	
	
	
	
	
	
	
	
	
	
	return 0;
}
