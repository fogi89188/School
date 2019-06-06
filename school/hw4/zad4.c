#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product_t {
	char name[100];
	float quality;
	float quantity;
};

struct factory_t {
	char fname[100];
	char pname[100];
	float quality;
	float quantity;
};

struct warehouse{
	int departments;
	int produc_per_department;
	struct product_t product;
};

int main(){
	return 0;
}
