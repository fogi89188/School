#include <stdio.h>
#include <stdlib.h>


int to_digit(char digit)
{ 
	return digit - '0';
}

int to_integer(char argv[])
{
	int result = 0;
	for(int i=0; argv[i] != '\0' ;i++)
	{	
		result = (result*10)+to_digit(argv[i]);
	}
	return result;
}

int main(int argc, char* argv[])
{
	int sum = 0;
	for(int i=1; i < argc; i++)
	{
		printf("\n%d\n", to_integer(argv[i]));
		sum = sum + to_integer(argv[i]);
	}
	printf("\n-> %d\n", sum);
}
