#include <stdio.h>
#include <stdlib.h>

int string_compare(char string1[30], char string2[30])
{
	for(int i=0; string2[i] != '\0'; i++	)
	{
		if(string1[i] > string2[i])
		{
			return -1;
		}
		if(string1[i] < string2[i])
		{
			return 1;
		}
		
	}
	return 0;
}

int main()
{
	char string1[30], string2[30];
	scanf("%s", &string1);
	scanf("%s", &string2);
	printf("\n%d\n", string_compare(string1, string2));
}
