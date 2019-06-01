#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct fish_t{
	float weight;
	int chance;
	int bait_type;
};

struct bait_t{
	int chance;
	int is_alive;
	int bait_type;
};

float profi_fishing(struct fish_t fisht[10], struct bait_t *bait[10]){

	float sum = 0;
	for(int i = 0; i < 10; i ++){
		for(int j = 0; j < 10; j++){
			if(bait[i]->chance >= fisht[j].chance && bait[i]->is_alive != 0 && bait[i]->bait_type == fisht[j].bait_type){
				sum += fisht[i].weight;
				bait[i]->is_alive = 0;
			}
		}
	}

	return 0.0;
}

int main(){
	srand(time(NULL));
	
	struct fish_t fishes[10];
	for(int i = 0; i < 10; i++){
		fishes[i].weight = (float)(i+1);
		fishes[i].chance = (float)(i+1);
		fishes[i].bait_type = (float)(i+1);
	}
	struct bait_t *baits[10];
	for(int i = 0; i < 10; i++){
		baits[i]->is_alive = 1;
		baits[i]->chance = (float)(i+1);
		baits[i]->bait_type = (float)(i+1);
	}
	
	printf("%f\n", profi_fishing(fishes, &baits));

	return 0;
}
