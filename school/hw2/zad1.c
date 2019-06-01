#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//making lots of empty places for which number the bullet hit so that it can be used as an example of gaussian distribution later
int num0 = 0;
int num1 = 0;
int num2 = 0;
int num3 = 0;
int num4 = 0;
int num5 = 0;
int num6 = 0;
int num7 = 0;
int num8 = 0;
int num9 = 0;
int num10 = 0;

//define a struct of a gun
struct gun_t{

	char model[128];
	int accuracy;
	int ammo_capacity;

};

//func to get the score of a certain shot
int get_score(int gun_accuracy, float shot_accuracy){
	int score = 0;
	int score_outside = 9;
	
	//defining the scores by making a "linear"(even though its being calculated like a linear distribution, 
	//its actually a gaussian distribution because everything is the power of the thing that it has to be) calculation
	
	//everithing is the "power of the number / 100" so that it becomes a parabola and it looks like a gaussian distribution
	float change = (float)((10000 - (gun_accuracy * gun_accuracy))/100)/10;
	float left_bumper = (float)((gun_accuracy+1) * (gun_accuracy+1))/100;
	float right_bumper = (float)(gun_accuracy * gun_accuracy)/100 + change;
	
	//checking if the score is 10 points
	if(shot_accuracy <= gun_accuracy) {
		score += 10;
	}
	
	//else checking for lesser points
	else for(int i = 0; i < 10; i++, score_outside--, left_bumper = right_bumper, right_bumper += change){
		//keeping the score equal to 0 if it goes under 0
		if(score_outside < 0){
			score_outside = 0;
		}
		//giving points
		if((float)(shot_accuracy*shot_accuracy)/100 >= left_bumper && ((float)shot_accuracy*shot_accuracy)/100 <= right_bumper){
			score += score_outside;
		}
		
	}
	//writing which number the bullet hit so that it can be used as an example after that
	if(score == 0) num0++;
	if(score == 1) num1++;
	if(score == 2) num2++;
	if(score == 3) num3++;
	if(score == 4) num4++;
	if(score == 5) num5++;
	if(score == 6) num6++;
	if(score == 7) num7++;
	if(score == 8) num8++;
	if(score == 9) num9++;
	if(score == 10) num10++;
	
	//returning the score after the logic
	return score;
}

//defining function that tests how accurate the gun is
void test_gun(struct gun_t gun, int shot_count){
	float r = 0;
	float total_score = 0;
	float average_score = 0;
	int q = 0;
	//making a reloading system (because I felt like it, its not needed but it makes everything better)
	int reload = gun.ammo_capacity;
	int reload_const = gun.ammo_capacity;
	
	//work is done here:
	for(int i = 1; i <= shot_count; i++){
		//reloading system (because I felt like it, its not needed but it makes everything better)
		if(i >= reload+1){
			reload += reload_const;
			printf("Reloading...\n");
		}
		//getting a random number from 0 to 100
		r = rand() % 101;
		q = get_score(gun.accuracy, r);
		total_score += q;
		//printing details about certain shot
		printf("No%d -> Shot Accuracy: %.0f, Shot Score: %d\n", i, r, q);
	}
	
	//printing the final result
	average_score = total_score/shot_count;
	printf("\nTotal Score: %.0f\n", total_score);
	printf("Average Score: %.2f\n", average_score);
}

int main(){

	//defining a gun
	struct gun_t gun;
	printf("Input Gun Model: ");
	fgets(gun.model, 128, stdin);
	printf("Input Gun Accuracy: ");
	scanf("%d", &gun.accuracy);
	printf("Input Gun Ammo Capacity: ");
	scanf("%d", &gun.ammo_capacity);
	int shot_count;
	printf("How many shots: ");
	scanf("%d", &shot_count);
	
	//work is done here:
	test_gun(gun, shot_count);
	
	//printing an example of gaussian distribution (made by using the power of the numbers given)
	printf("\nExample of Gaussian Distribution: \n(Example works best if you shoot the gun 10 000 times or more)\n\n");
	printf("Number 10 has been hit: %d times\n", num10);
	printf("Number  9 has been hit: %d times\n", num9);
	printf("Number  8 has been hit: %d times\n", num8);
	printf("Number  7 has been hit: %d times\n", num7);
	printf("Number  6 has been hit: %d times\n", num6);
	printf("Number  5 has been hit: %d times\n", num5);
	printf("Number  4 has been hit: %d times\n", num4);
	printf("Number  3 has been hit: %d times\n", num3);
	printf("Number  2 has been hit: %d times\n", num2);
	printf("Number  1 has been hit: %d times\n", num1);	
	printf("Number  0 has been hit: %d times\n", num0);
	
	return 0;
}
