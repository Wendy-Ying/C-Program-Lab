#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	FILE* fp;
	fp = fopen("D:\\wendy\\study\\C program\\homework\\week12\\data.csv", "r");
	char* buffer = malloc(100 * sizeof(char));
	fgets(buffer, 100, fp);
	printf("%s", buffer);
	char seps[] = " ,";
	char* token;
	double number[10];
	int i = 0;
	token = strtok(buffer, seps);
	while (token != NULL)
	{
		number[i] = atof(token);
		i++;
		token = strtok(NULL, seps);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%f\n", number[i]);
	}
	double sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum = sum + number[i];
	}
	printf("The result is : %f.", sum);
	fclose(fp);
	free(buffer);
	return 0;
}
