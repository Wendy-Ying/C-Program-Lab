#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX 6	//中文拼音中最长字符串
//char *dest 为目标字符串，需要在被调用前，保证空间已经被分配
//int num 为待转换的数字 
int chinese(char *dest, int num);

int main(int argc, char *argv[]) {
	int Len, Val;	//Len是十进制字长，Val为具体数字 
	char *Buf;	//保存结果的字符串指针 
	printf("How many numbers do you want to type: ");	//为了分配空间用 
	scanf("%d",&Len);
	printf("Please type the numbers: ");	//输入实际数值 
	scanf("%d",&Val); 
	Buf = (char *)malloc(Len*MAX*sizeof(char));	//分配最大可能的空间，与后续的free对应，保证内存不溢出 
	chinese(Buf, Val);	//调用函数 
	printf("Result = [%s]\n", Buf);	//打印结果 
	free(Buf);	//释放分配的空间 
	return 0;
}

//strcat的标准实现方式 
char * strcat2(char *a, const char *b)
{
    char *save = a;  //save作为指向char *a字符串的头部指针的备用，返回时用到；
    while((*a))    //当 当前指针指向内容不为0时，挪动指针到下一个对象
        a++;
    while(((*a++)=(*b++))!=0)    // 当 当前指针*b指向对象不为0时，赋值给 *a执行的位置，执行结束后，a、b分别指向下一个对象的位置
        ;
    return save;    //字符串a的原始位置作为返回值，在函数内部，当前a指向的位置已经被改变了，所以不能作为返回值。
}

//要求dest是已经分配好空间的空字符串
//num是传入的待转换的数值 
int chinese(char *dest, int num)
{
	//定义了一个参数表作为查表使用，均做了前后倒置，以便结果转置 
	char *Table[10] = {" gniL", " iY", " rE", " naS", " iS", " uW", " uiL", " iQ", " aB", " uiJ"};	//每个字符串不超过6，用了指针数组，即十个空间的位置，每个空间都是一个指针，其指针指向固定的字符串 
	//指针数组是一个非常好用的东西，仔细思考一下实际计算机内部的物理空间是怎么组织 
	*dest = 0;	//字符串清零，避免之前dest已经使用过 
	int cur;	//余数变量 
	do
	{
		cur = num % 10;
		num = num / 10;
		strcat2(dest, Table[cur]);
	} while(num != 0);	//直到整除结束 
	
	//下面做转置工作 
	char *Tmp;
	int StrLen;
	int i;
	StrLen = strlen(dest);	//先获知当前目标字符串长度值 
	Tmp = (char *)malloc(StrLen);	//分配一个新的空间，与本函数的free对应，保证内存不溢出 
	for(i=StrLen-1; i>=0; i--)	//转置 具体操作逻辑，可以思考可能还有更好的方法 
	{
		Tmp[StrLen-1-i]=dest[i];
	}
	Tmp[StrLen-1]= 0;	//强制结束当前字符串，最后一个本来就是空格 
	strcpy(dest, Tmp);//结果重新赋值到目标字符串 
	free(Tmp);	//释放分配的空间 
	
	return 1;
} 

