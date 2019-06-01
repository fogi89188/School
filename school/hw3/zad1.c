#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//func to sum the digits of a numebr
int SumDigits(int number){
	//creating a temporary variable to store the digits in
	int tmp = 0;
	//creating the sum
	int sum = 0;
	
	//actual cycle to sum it
	while(1){
		if(number <= 0){
			//returning the value
			return sum;	
		}
		//the logic
		tmp = number % 10;
		number /= 10;
		sum += tmp;
	}
}


//func to check if a number is valid
int checkIfValid(int number){
	//summing the digits of the numnber
	int sum = SumDigits(number);
	//checking if its valid and returning 1/0
	
	
	//why am I stopping at 31? because our cycle ends at 10000, so the biggest possible sum is 36.
	//I dont need more than 31 because it will never get to the next prime number which is 37.
	//thats why I stop the if at 31.
	if(sum == 2 || 
	sum == 3 || 
	sum == 5 || 
	sum == 7 || 
	sum == 11 || 
	sum == 13 || 
	sum == 17 || 
	sum == 19 || 
	sum == 23 || 
	sum == 29 || 
	sum == 31)
	{
		return 1;
	}
	return 0;
	
}

int main(){
	//the actual 'for' that calls the functions
	int num;
	printf("Show valid numebrs untill: ");
	scanf("%d", &num);
	printf("\n");
	for(int i = 1; i <= num; i++){
		if(checkIfValid(i) == 1){
			printf("%d\n", i);
		}
	}
}
