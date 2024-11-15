#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	typedef enum vote { egon, erick }Vote;
	typedef struct stu
	{
		int stu_number;
		Vote result;
	}Stu;
	Stu students[10];
	FILE* fp;
	fp = fopen("D:\\wendy\\study\\C program\\homework\\week12\\data.bin", "rb");
	fread(&students, sizeof(students), 10, fp);
	int i = 0;
	printf("The votes are:\n");
	for (i = 0; i < 10; i++)
	{
		printf("student number:%d\tresult:%d\t\n", students[i].stu_number,students[i].result);
	}
	int sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum = sum + students[i].result;
	}
	printf("The winner is: ");
	if (sum < 5)
	{
		printf("egon.");
	}
	if (sum > 5)
	{
		printf("erick.");
	}
	if (sum == 5)
	{
		printf("two candidates get the same votes.");
	}
	fclose(fp);
	return 0;
}