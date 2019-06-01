#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//function to find the number of all the longest words
int getLongestWords(char text[200]){
	int longestWords = 0;
	int counter = 0;
	int longestWordCount = 0;
	int invalidWord = 0;
	for(int i = 0; i < strlen(text); i++){
		if(text[i] < 65 || text[i] > 122){
			invalidWord = 1;
		}
		if(text[i] >= 91 && text[i] <= 96){
			invalidWord = 1;
		}
		if(text[i] == 44 || text[i] == 45){
			invalidWord = 0;
		}
		//checking empty spaces (thats how wordsd are surrounded, by space)
		if(text[i] != ' '){
			counter++;
		}
		else{
			counter = 0;
			invalidWord = 0;
		}
		//setting a new longestWords counter if we find a longer word
		if(counter > longestWords && invalidWord == 0){
			longestWordCount = 0;
			longestWords = counter;
		}
		//making the longestWords counter go up
		if(counter == longestWords && invalidWord == 0){
			longestWordCount++;
		}
	}
	
	return longestWordCount;
}

int main(){
	char text[200];
	fgets(text, 200, stdin);
	printf("Number of longest word: %d\n", getLongestWords(text));
	return 0;
}
