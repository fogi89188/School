#include <stdio.h>

struct particle_t{
	float weight;
	float position;
};

void move_particles(struct particle_t* first, struct particle_t* second){
	
	float distance = first->position - second->position;
	
	if(distance < 0){
		distance = distance * -1;
	}
	
	float force = (first->weight * second->weight) / (distance * distance);
	float moveFirst = force / first->weight;
	float moveSecond = force / second->weight;
	
	if(first->position > second->position){
		second->position += moveSecond;
		first->position -= moveFirst;
	}
	else{
		second->position -= moveSecond;
		first->position += moveFirst;
	}
}

int main(){


	struct particle_t first = {10, 10};
	struct particle_t second = {10, 20};
	move_particles(&first, &second);
	printf("%.1f %.1f\n", first.position, second.position);
	return 0;
}
