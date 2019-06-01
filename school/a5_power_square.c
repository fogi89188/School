#include <stdio.h>

int power(int num)
{
	int i;
	int k;	
	k=num;
	for(i=1; i<2; i++)
	{
		num=num*k;
	}
	return num;
}

int main()
{
	printf("\n%d\n\n", power(4));
	return 0;
}
