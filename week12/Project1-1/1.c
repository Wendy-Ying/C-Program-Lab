#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* insert(char* s1, char* s2, int num);
int main()
{
	char s1[] = "IChina";
	char s2[] = "Love";
	char* ss = insert(s1, s2, 1);
	printf("%s", ss);
	return 0;
}
char* insert(char* s1, char* s2, int num)
{
	char* ss = (char*)malloc((strlen(s1) + strlen(s2)+1)*sizeof(char));
	char* save = ss;
	int i;
	int temp1 = (int)strlen(s1);
	int temp2 = (int)strlen(s2);
	for (i = 0; i < num; i++)
	{
		*ss = *s1;
		ss++;
		s1++;
	}
	for (i = 0; i < temp2; i++)
	{
		*ss = *s2;
		ss++;
		s2++;
	}
	for (i = 0; i < temp1 - num; i++)
	{
		*ss = *s1;
		ss++;
		s1++;
	}
	*ss = '\0';
	return save;
}