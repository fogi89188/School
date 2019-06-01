#include <stdio.h>
#include <stdlib.h>


int length(char string[])
{	
	int counter=0;
	while(string[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

char combine(char* string1, char* string2)
{
	int counter1=0;
	int counter2=0;
	
	counter1 = length(string1);
	while(string2[counter2] != '\0')
	{
		string1[counter1] = string2[counter2];
		counter1++;
		counter2++;
	}

	string1[counter1] = '\0';
	return 0;
}

int main()
{
	char String1[65];
	char String2[32];
	scanf("%s",&String1);
	scanf("%s",&String2);
	combine(String1, String2);
	printf("\nResult:\n%s\n", String1);
	return 0;
}
