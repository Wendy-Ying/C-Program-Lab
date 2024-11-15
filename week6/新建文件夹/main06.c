#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int convert(unsigned int *RawData, unsigned int *RData, unsigned int *GData, unsigned int *BData, unsigned int row, unsigned int col);

int main(int argc, char *argv[]) {
	unsigned int *Raw, *R, *G, *B;
	unsigned int Row, Col, tmp, i, j;
	printf("Enter the target Matrix Row = ");
	scanf("%d", &Row);
	printf("Enter the target Matrix Col = ");
	scanf("%d", &Col);
	tmp = Row * Col;
	R = (unsigned int *)malloc(tmp * sizeof(unsigned int));	//scanf输入的必须是4字节的int，所以分配int类型对象，实际图像存储中，是以unsigned byte保存的 
	G = (unsigned int *)malloc(tmp * sizeof(unsigned int));
	B = (unsigned int *)malloc(tmp * sizeof(unsigned int));
	tmp = tmp*4;
	Raw = (unsigned int *)malloc(tmp *sizeof(unsigned int));

	printf("Enter the Raw Matrix with Row = [%d]\tCol =[%d] :", Row, Col);
	
	for(i=0; i<tmp; i++)
		scanf("%d", &(Raw[i]));
	convert(Raw, R, G, B, Row, Col);

	printf("\nThe RAW Matrix = \n");
	tmp = 0;
	for(i=0; i<Row*2; i++)
	{
		for(j=0; j<Col*2; j++)
		{
			printf("%d\t", Raw[tmp]);
			tmp ++;
		}
		printf("\n");
	}
	
	printf("\nThe Convert Result Matrix = \n");
	printf("# RRR #\t\t\t\t# GGG #\t\t\t\t# BBB #\n");
	for(i=0; i<Row; i++)
	{
		tmp = i*Row;
		for(j=0; j<Col; j++)
		{
			printf("%d\t", R[tmp++]);
		}
		printf("\t\t");
		tmp = i*Row;
		for(j=0; j<Col; j++)
		{
			printf("%d\t", G[tmp++]);
		}
		printf("\t\t");
		tmp = i*Row;
		for(j=0; j<Col; j++)
		{
			printf("%d\t", B[tmp++]);
		}
		printf("\n");
	}
	if(Raw != NULL)	//先判断是否为空指针，然后释放 
		free(Raw);
	if(B != NULL)
		free(B);
	if(G != NULL)
		free(G);
	if(R != NULL)
		free(R);
	return 0;
}

//row, col均是转换后RGB矩阵的行列数，所以Raw大小为2*Row 2*Col 
//函数内部的指针必须是已经分配好空间 
int convert(unsigned int *RawData, unsigned int *RData, unsigned int *GData, unsigned int *BData, unsigned int row, unsigned int col)
{
	unsigned int m, n, tmp, tmp2;
	for(m=0; m<row; m++)
	for(n=0; n<col; n++)
	{
		tmp= m*row+n;
		tmp2 = m*(4*row) + 2* n;	//先计算每个2x2子模块的顶点位置 
		RData[tmp] = RawData[tmp2 + 2*row];
		BData[tmp] = RawData[tmp2 + 1];
		GData[tmp] = (RawData[tmp2] + RawData[tmp2+2*row+1])/2;
	} 
	return 0;
}


