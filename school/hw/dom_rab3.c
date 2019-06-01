#include <stdio.h>
#include <stdlib.h>

int is_fingerprint_symbol(char symbol)
{
	switch(symbol)
	{
		case '\\': return 1; break;
		case '/': return 1; break;
		case '|': return 1; break;
		case '~': return 1; break;
		case '_': return 1; break;
		case '-': return 1; break;
		default: return 0; break;
	}
}

int is_fingerprint_row_valid(char fingerprint[20])
{	
	int i=0;
	for( i=0; fingerprint[i] != '\0'; i++){}
	if(i < 16 || i > 16)
		return 0;
	if(i == 16)
	{
		for(i=0;fingerprint[i] != '\0'; i++)
		{
			if(is_fingerprint_symbol(fingerprint[i])==1)
				return 1;
		}
		return 0;
	}
	return 0;
}

void return_answer(char fingerprint[20])
{	
	if (is_fingerprint_row_valid(fingerprint) == 0)
		printf("\nInvalid Fingerprint!\n");
	if (is_fingerprint_row_valid(fingerprint) == 1)
		printf("\nValid Fingerprint!\n");
}

int main(int argc, char *argv[])
{
	for(int i=1; i<argc; i++)
	{
		return_answer(argv[i]);
	}
	return 0;
}
