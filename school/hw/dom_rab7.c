#include <stdio.h>
#include <stdlib.h>


void alphabeth(char letter)
{
	switch(letter)
	{
		case 'a': printf(".- "); break;
		case 'b': printf("-... "); break;
		case 'c': printf("-.-. "); break;
		case 'd': printf("-.. "); break;
		case 'e': printf(". "); break;
		case 'f': printf("..-. "); break;
		case 'g': printf("--. "); break;
		case 'h': printf(".... "); break;
		case 'i': printf(".. "); break;
		case 'j': printf(".--- "); break;
		case 'k': printf("-.- "); break;
		case 'l': printf(".-.. "); break;
		case 'm': printf("-- "); break;
		case 'n': printf("-. "); break;
		case 'o': printf("--- "); break;
		case 'p': printf(".--. "); break;
		case 'q': printf("--.- "); break;
		case 'r': printf(".-. "); break;
		case 's': printf("... "); break;
		case 't': printf("- "); break;
		case 'u': printf("..- "); break;
		case 'v': printf("...-- "); break;
		case 'w': printf(".-- "); break;
		case 'x': printf("-..- "); break;
		case 'y': printf("-.-- "); break;
		case 'z': printf("--.. "); break;

		case 'A': printf(".- "); break;
		case 'B': printf("-... "); break;
		case 'C': printf("-.-. "); break;
		case 'D': printf("-.. "); break;
		case 'E': printf(". "); break;
		case 'F': printf("..-. "); break;
		case 'G': printf("--. "); break;
		case 'H': printf(".... "); break;
		case 'I': printf(".. "); break;
		case 'J': printf(".--- "); break;
		case 'K': printf("-.- "); break;
		case 'L': printf(".-.. "); break;
		case 'M': printf("-- "); break;
		case 'N': printf("-. "); break;
		case 'O': printf("--- "); break;
		case 'P': printf(".--. "); break;
		case 'Q': printf("--.- "); break;
		case 'R': printf(".-. "); break;
		case 'S': printf("... "); break;
		case 'T': printf("- "); break;
		case 'U': printf("..- "); break;
		case 'V': printf("...-- "); break;
		case 'W': printf(".-- "); break;
		case 'X': printf("-..- "); break;
		case 'Y': printf("-.-- "); break;
		case 'Z': printf("--.. "); break;

		case 0: printf("----- "); break;
		case 1: printf(".---- "); break;
		case 2: printf("..--- "); break;
		case 3: printf("...-- "); break;
		case 4: printf("....- "); break;
		case 5: printf("..... "); break;
		case 6: printf("-.... "); break;
		case 7: printf("--... "); break;
		case 8: printf("---.. "); break;
		case 9: printf("----. "); break;
	}
}

int transform_word(char word[50])
{
	for(int i=0;word[i]!='\0';i++)
	{
		alphabeth(word[i]);
	}
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{
	for(int i=1;i<argc;i++)
	{
		transform_word(argv[i]);
	}
	return 0;
}
