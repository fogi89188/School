#include <stdio.h>

int simple(int num)
{
	if(num%2==0||num%3==0)
	{	
		return 0;
	}
	return 1;
}

int main()
{
	printf("\n%d\n\n", simple(7));
	return 0;
}
