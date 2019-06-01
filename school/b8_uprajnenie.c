#include <stdio.h>
#define num 250


int count_symbols(char*);

int main(){
	
	char str[num];
	fgets(str, num, stdin);
	printf("%d\n", count_symbols(str));
	
	return 0;
}


int count_symbols(char* str){
	int counterMax = 0;
	int counter = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == '*' || str[i] == '$' || str[i] == ')' || str[i] == '+'){
			counter++;
		}
		else{
			if(counter > counterMax){
				counterMax = counter;
			}
			counter = 0;
		}
	}
	return counterMax;
}
