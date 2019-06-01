#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//the number of numbers that the program is going to check by. 
//if we have 4 there, the program will check every 4 numbers.

int numSpecified = 4;
int length = 15;

//checking the horizontal side of a given number
//we need two positions because one is the position of the number that is being processed and the other is
//the position of the biggest multiplication number 
//(and we need it being a pointer so that we can change it if we find a bigger value)
void checkHorizontal(int *xPos, int *yPos, int *max, char *side[100], int currentX, int currentY, int matrix[length][length]){
	
	int mult = 1;
	for(int i = 0; i < numSpecified; i++){
		mult *=  matrix[currentY][currentX+i];
	}
	if(mult > *max){
		*max = mult;
		*xPos = currentX;
		*yPos = currentY;
		*side = "horizontal";
	}
}

void checkVertical(int *xPos, int *yPos, int *max, char *side[100], int currentX, int currentY, int matrix[length][length]){
	
	int mult = 1;
	for(int i = 0; i < numSpecified; i++){
		mult *=  matrix[currentY+i][currentX];
	}
	if(mult > *max){
		*max = mult;
		*xPos = currentX;
		*yPos = currentY;
		*side = "vertical";
	}
}

void checkDiagonalRight(int *xPos, int *yPos, int *max, char *side[100], int currentX, int currentY, int matrix[length][length]){
	
	int mult = 1;
	for(int i = 0; i < numSpecified; i++){
		mult *=  matrix[currentY+i][currentX+i];
	}
	if(mult > *max){
		*max = mult;
		*xPos = currentX;
		*yPos = currentY;
		*side = "diagonal";
	}
}

void checkDiagonalLeft(int *xPos, int *yPos, int *max, char *side[100], int currentX, int currentY, int matrix[length][length]){
	
	int mult = 1;
	for(int i = 0; i < numSpecified; i++){
		mult *=  matrix[currentY+i][currentX-i];
	}
	if(mult > *max){
		*max = mult;
		*xPos = currentX;
		*yPos = currentY;
		*side = "diagonal";
	}
}

void checkAll(int *xPos, int *yPos, int *max, char *side[100], int matrix[length][length]){
	
	//this is a cycle that will constantly check for the directions, checking only if they are going to be valid
	//so that there arent any errors (core dumped error specifically)
	for(int row = 0; row < length;row++){
		for(int col = 0; col < length; col++){
			if(row <= length - numSpecified){
				checkHorizontal(xPos, yPos, max, side, row, col, matrix);
			}
			if(col <= length - numSpecified){
				checkVertical(xPos, yPos, max, side, row, col, matrix);
			}
			if(row <= length - numSpecified && col <= length - numSpecified){
				checkDiagonalRight(xPos, yPos, max, side, row, col, matrix);
			}
			if(row >= length - numSpecified && col <= numSpecified - 1){
				checkDiagonalLeft(xPos, yPos, max, side, row, col, matrix);
			}
		}
	}
}

int main(){
	
	//initialising the matrix
	printf("Whats the N in the NxN matrix: ");
	scanf("%d", &length);
	printf("\n");
	printf("How many numbers in a row do you wanna check (the default is 4): ");
	scanf("%d", &numSpecified);
	printf("\n");
	int matrix[length][length];
	char *side[100];
	*side = "blank";
	int *max = 0;
	int *xPos = 0;
	int *yPos = 0;
	
	//filling the matrix
	for(int row = 0; row < length; row++){
		for(int col = 0; col < length; col++){
			scanf("%d", &matrix[row][col]);
		}
	}
	
	checkAll(&xPos, &yPos, &max, &side, matrix);
	
	printf("%d\n", max);
	printf("%d --- %d\n", xPos, yPos);
	printf("%s\n", *side);	
	return 0;
}
