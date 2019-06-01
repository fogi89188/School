#include <stdio.h>

int power(int num, int num1)
{
	int i;
	int k;	
	k=num;
	for(i=1; i<num1; i++)
	{
		num=num*k;
	}
	return num;
}

int main()
{
	printf("\n%d\n\n", power(4, 4));
	return 0;
}
