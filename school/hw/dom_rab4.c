#include <stdio.h>
#include <stdlib.h>


int valid_symbol(char symbol)
{
	if(symbol >= '0' && symbol <= '9')
		return 1;

	if(symbol >= 'a' && symbol <= 'f')
		return 1;
	return 0;
}

int valid_mac(char mac[20])
{
	int i = 0;
	int counter1 = 0;
	int counter2 = 0;
	for(i=0; mac[i] != '\0'; i++)
	{
		if(valid_symbol(mac[i]) == 0)
		{
			
			if(mac[i] == ':')
			{
				counter2 = 1;
				if(counter1 != 2)
				{
					return 0;
				}
				counter1 = 0;
			}
			
			else 
			{
				return 0;
			}
		}
		if(counter2 == 1)
		{
			counter2 = 0;	
		}
		else 
			counter1++;
	}
	if(i<17 || i>17)
		return 0;
	return 1;
}

int main(int argc, char* argv[])
{
	for(int i=1;i<argc;i++)
	{
		if(valid_mac(argv[i])==1)
			printf("\nValid Mac Adress\n");
		else printf("\nInvalid Mac Adress\n");
	}

	return 0;
}
