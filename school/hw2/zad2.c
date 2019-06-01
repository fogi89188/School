#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining a struct of a tree
struct tree_t{

	int age;
	float height;
};

//defining a struct of a forest
struct forest_t{
	int tree_count;
	struct tree_t trees[10];
};

//function that ages the forest, increasing the trees' height and age by a random number
struct forest_t age_trees(struct forest_t forest){

	//making a random number
	float a = 2.0;
	float r = ((float)rand()/(float)(RAND_MAX) * a) + 0.1;
	
	for(int i = 0; i < forest.tree_count; i++) {
		//making a random number
		r = ((float)rand()/(float)(RAND_MAX) * a) + 0.1;
		//aging the trees and giving them bonus height
		forest.trees[i].age += 1;
		forest.trees[i].height += r;
	}
	return forest;
}

//func that prints info about a certain tree
void print_tree(struct tree_t tree) {
	printf("Age: %d Height: %.1f\n" ,tree.age, tree.height);
}

//func that prints info about a certain forest using print_trees()
void print_forest(struct forest_t forest) {
	for(int i = 0; i < forest.tree_count; i++){
		print_tree(forest.trees[i]);
	}
}

//function cutting old trees and replacing them with new ones
struct forest_t cut_old_trees(struct forest_t forest, int age_treshold) {
	for(int i = 0; i < forest.tree_count; i++){
		if(forest.trees[i].age >= age_treshold){
			//printing the number of the tree cut and why its cut
			//printing i+1 because we start the for from 0 and not 1, this way we print the actual number of th tree
			printf("Cut No:%d - Age\n", i+1);
			forest.trees[i].age = 1;
			forest.trees[i].height = 0.5;
		}
	}
	return forest;
}

//function cutting tall trees and replacing them with new ones
struct forest_t cut_tall_trees(struct forest_t forest, float height_treshold) {
	for(int i = 0; i < forest.tree_count; i++){
		if(forest.trees[i].height >= height_treshold){
			//printing the number of the tree cut and why its cut
			//printing i+1 because we start the for from 0 and not 1, this way we print the actual number of th tree
			printf("Cut No:%d - Height\n", i+1); 
			forest.trees[i].age = 1;
			forest.trees[i].height = 0.5;
		}
	}
	return forest;
}

int main(int argc, char *argv[]){
	
	//making sure that the program starts correctly
	if(argc < 4) { printf("Too little console arguments (needed 3)\n"); return 0; }
	if(argc > 4) { printf("Too many console arguments (needed 3)\n"); return 0; }
	
	//using atof function to get from argv and write it in an integer and float
	//atof converts a string to a number with a decimal
	int count_cycles = atof(argv[1]);
	int cut_of_old = atof(argv[2]);
	float cut_of_tall = atof(argv[3]);
	
	//defining a forest with 5 trees
	struct forest_t forest;
	forest.tree_count = 5;
	
	struct tree_t tree1;
	tree1.age = 1;
	tree1.height = 0.1;
	forest.trees[0] = tree1;
	
	struct tree_t tree2;
	tree2.age = 3;
	tree2.height = 0.6;
	forest.trees[1] = tree2;
	
	struct tree_t tree3;
	tree3.age = 40;
	tree3.height = 28.4;
	forest.trees[2] = tree3;
	
	struct tree_t tree4;
	tree4.age = 17;
	tree4.height = 10.2;
	forest.trees[3] = tree4;
	
	struct tree_t tree5;
	tree5.age = 23;
	tree5.height = 15.7;
	forest.trees[4] = tree5;
	
	//printing the forest before the aging and cutting
	print_forest(forest);
	//cutting and aging in a cycle
	for(int i = 0; i < count_cycles; i++) {
		//aging and cutting
		forest = age_trees(forest);
		forest = cut_old_trees(forest, cut_of_old);
		forest = cut_tall_trees(forest, cut_of_tall);
	}
	//printing the new forest
	print_forest(forest);	
} 	
