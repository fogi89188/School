#include <stdio.h>
#include <stdlib.h>


int is_digit(char digit)
{
	if(digit > '0' && digit < '9')
		return 1;

	else 
		return 0;
}

int to_digit(char digit)
{
	if(is_digit(digit) == 1)
		return digit - '0';
	if(is_digit(digit) == 0)
		return 1;
	return 0;
}

int contains(int long_number,char digit)
{
	while(long_number != 0)
	{
		if(is_digit(digit) == 0)
			return 0;
		if(long_number % 10 == to_digit(digit))
			return 1;
		long_number = long_number / 10;
	}
	return 0;
}

int main()
{
	char number = '7';
	char letter = 'q';
	int long_number1 = 89178;
	int long_number2 = 89188;

	printf("\nIf the char is a digit with an input of \"7\": (Y-1,N-0)");
	printf("\nAnswer: %d\n", is_digit(number));
	printf("\nIf the char is a digit, returning a num with an input of \"7\" (Num-Int,N-1)");
	printf("\nAnswer: %d\n", to_digit(number));


	printf("\nIf the char is a digit with an input of \"q\": (Y-1,N-0)");
	printf("\nAnswer: %d\n", is_digit(letter));
	printf("\nIf the char is a digit, returning a num with an input of \"q\" (Num-Int,N-1)");
	printf("\nAnswer: %d\n", to_digit(letter));

	printf("\nIf there is a digit in a long num with an input of \"7\": (Y-1,N-0)");
	printf("\nAnswer: %d\n", contains(long_number1, number));
	printf("\nIf there is a digit in a long num with an input of \"7\": (Y-1,N-0)");
	printf("\nAnswer: %d\n", contains(long_number2, number));

	printf("\nIf there is a digit in a long num with an input of \"q\": (Y-1,N-0)");
	printf("\nAnswer: %d\n", contains(long_number1, letter));

	

	return 0;
}
