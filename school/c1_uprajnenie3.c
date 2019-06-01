#include <stdio.h>

struct flower_t{
	int age;
	char type;
	int is_pollinated;
};

void pollinate(struct flower_t* left, struct flower_t* main, struct flower_t* right){
	if(left->type == main->type && !left->is_pollinated){
		left->is_pollinated = 1;
	}
	if(right->type == main->type && !right->is_pollinated){
		right->is_pollinated = 1;
	}
}

int main(){
	return 0;
}
