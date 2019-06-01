#include <stdio.h>
#include "other.c"

int main() {
	int x;
	int *point;
	int y;
	printf("Input the adress:\n");
	scanf("%d", &x);
	printf("Input the number:\n");
	scanf("%d", &y);
	point = (int*)x;
	*point = y;
	//*point = y;
	printf("%p\n", *point);
	printf("%d\n", *point);
	return 0;
}
