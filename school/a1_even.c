#include <stdio.h>

int is_even(int num)
{
	return num%2==0;
}

int main()
{
	printf("\n%d\n\n", is_even(22));
	printf("\n%d\n\n", is_even(13));
	return 0;
}
