#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int *count[], int unvisited[]){
	int n = count[0];
	int j = 0;
	for(int i = 0; count[i] != '\0'; i++){
		if(count[i] < n && unvisited[i] == 1){
			n = count[i];
			j = i;
		}
	}
	return j;
}

int smallest(int *count[], int unvisited[]){
	int n = count[0];
	int j = 0;
	for(int i = 0; count[i] != '\0'; i++){
		if(count[i] < n && unvisited[i] == 1){
			n = count[i];
			j = i;
		}
	}
	return n;
}

void find(int index1, int index2, int n, int *name[n], int *count[n], int *prev[n], int matrix[n][n]){
	
	printf("test\n");
	int unvisited[n];
	for(int i = 0; i < n; i++){
		unvisited[i] = 1;
	}
	//setting the values
	for(int i = 0; i < n; i++){
		name[i] = i;
		count[i] = 1000000;
		prev[i] = NULL;
	}
	count[index1] = 0;
	for(int j = 0; j < n; j++){
	for(int i = 0; i < n; i++){
		if(!(matrix[min(&count, unvisited)][i] == 0 || matrix[min(&count, unvisited)][i] == -1)){
			printf("if %d > %d + %d\n", count[i], matrix[min(&count, unvisited)][i], count[min(&count, unvisited)]);
			printf("%d - %d\n", i, min(&count, unvisited));
			if(count[i] > matrix[min(&count, unvisited)][i] + count[min(&count, unvisited)]){
				printf("count[%d] = %d + %d\n", i, matrix[min(&count, unvisited)][i], count[min(&count, unvisited)]);
				count[i] = matrix[min(&count, unvisited)][i] + count[min(&count, unvisited)];
				prev[i] = min(&count, unvisited);
			}
		}
		
	}
	unvisited[min(&count, unvisited)] = 0;
	}
	printf("\n\n%d\n\n", count[index2]);
}

int main(){
	int n = 0;
	FILE *f;
	f = fopen("in.txt", "r");
	int index1 = 0;
	int index2 = 0;
	int *name[n];
	int *count[n];
	int *prev[n];
	//getting the n number
	scanf("%d", &index1);
	scanf("%d", &index2);
	//printing the matrix
	fscanf(f, "%d", &n);
	printf("%d\n", n);
	int matrix[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fscanf(f, "%d", &matrix[i][j]);
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	//logic goes here      	    	
      	//############
      	//############
      	find(index1, index2, n, &name, &count, &prev, matrix);
      	
      	
      	//############
      	//############
      	     	
	fclose(f);
	return 0;
}
