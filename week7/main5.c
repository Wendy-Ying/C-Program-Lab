#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	const char text[40][20] = {"Every","night","in","my","dreams", "I","see","you", 
	"I","feel","you","that","is","how","I","know","you","go","on","far","across",
	"the","distance","and","spaces","between","us","you","have","come","to","show",
	"you","go","on","near","far","wherever","you","are"};
	
	char dictionary[40][20]={"Every","night","in","my","dreams","I","see","you", 
	"I","feel","you","that","is","how","I","know","you","go","on","far","across",
	"the","distance","and","spaces","between","us","you","have","come","to","show",
	"you","go","on","near","far","wherever","you","are"};
	
	int occur[40];
	
	int i,j;
	
	for(i=0;i<40;i++)
	{
		occur[i]=1;
		for(j=39;j>i;j--)
		if(strcmp(dictionary[i],text[j])==0)
		{
			*dictionary[j]='z';
			occur[i]++;
		}
	}
	
	for(i=0;i<40;i++)
	{
		if(*dictionary[i]!='z')
		{
			printf("The word %s\toccurs %d times.\n",dictionary[i],occur[i]);
		}
	}
	
	return 0;
}

