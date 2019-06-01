#include <stdio.h>
#include <stdlib.h>

void print_bits(int n)
{
	int res = 0;
	while(n>0){
		
		res += n % 2;
		n = n >> 1;
		if(n>0) {
			res *= 10;
		}
	}
	while(res > 0){
		printf("%d", res % 10);
		res /= 10;
	}
}

int main()
{
	int a;
	scanf("%d", &a);
	print_bits(a);
	printf("\n");
	return 0;
}
