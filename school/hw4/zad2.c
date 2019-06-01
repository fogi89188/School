#include <stdio.h>
#include <stdlib.h>

//global time
int time = 0;
//passengers left on the station to suffer

void leftoutPass(int left){
	printf("There wasn't room for %d passengers\n", left);
}

void station(int *train[4], int maxpass){
	int leaving[4] = {0, 0, 0, 0};
	int entering[4] = {0, 0, 0, 0};
	int tmp1 = 0, tmp2 = 0;
	int passleft = 0;
	//leaving
	for(int j = 0; j < 4; j++){
		scanf("%d", &leaving[j]);
	}
	//leaving logic
	for(int i = 0; i < 4; i++){
		tmp1 = train[i];
		tmp2 = leaving[i];
		tmp1 -= tmp2;
		train[i] = tmp1;
		time += leaving[i];
	}
	printf("Train: %d %d %d %d\n", train[0], train[1], train[2], train[3]);
	//entering
	for(int j = 0; j < 4; j++){
		scanf("%d", &entering[j]);
	}
	//entering logic
	for(int i = 0; i < 4; i++){
		tmp1 = train[i];
		tmp2 = entering[i];
		tmp1 += tmp2;
		if(tmp1 > maxpass){
			int tmp3 = tmp1-maxpass;
			passleft += tmp3;
			tmp1 = maxpass;
		}
		time += tmp1-(int)train[i];
		train[i] = tmp1;
	}
	if(passleft > 0){
		leftoutPass(passleft);
		passleft = 0;
	}
	printf("Train: %d %d %d %d\n", train[0], train[1], train[2], train[3]);
	
	
}

int main(int argc, char* argv[]){
	int *train[4] = {0, 0, 0, 0};
	//maximum passengers
	int maxpass = atoi(argv[1]);
	printf("Train: %d %d %d %d\n", train[0], train[1], train[2], train[3]);
	for(int i = 0; i < 5; i++){
		station(&train, maxpass);
	}
	printf("\nTime spent waiting: %d\n", time);
	return 0;
}
