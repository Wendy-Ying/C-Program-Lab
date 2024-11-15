#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

int main()
{
	int* p = NULL;
	p = (int*)malloc(10 * sizeof(int));
	realloc(p, 20 * sizeof(int));
	p[19] = 100;
	free(p);
	return 0;
}