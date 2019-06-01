#include <stdio.h>
#include <stdlib.h>

int main(){
/*
malloc(size_t size) zadelq pamet
free(void *ptr) osvobojdava pamet (poluchava adresa na malloc [pointer kum malloc])
sizeof()
memset(void *s, int c, int n) - zadava purvite "n" baita ot pametta s constanta c
memcopy(void *dst, const void *src, size_t n) - kopira purvite n baita ot src v dst - vrushta ukazatel kum dst
valgrind - proverqva za memory leaking
*/

/*	
	int size;
	scanf("%d", &size);
	
	int *ptr = malloc(sizeof(int)*size);
	
	for(int i = 0; i < size; i++){
		scanf("%d", &ptr[i]);
	}
	
	for(int i = size-1; i >= 0; i--){
		printf("%d", ptr[i]);
	}
	printf("\n");
	return 0;
	*/
	
	
	char str;
	scanf("%s", &str);
	int i = 1;
	int count = 0;
	int *ptr = malloc(sizeof(char)*i);
	while(str != "EOF"){
		i++;
		realloc(ptr, sizeof(char)*i);
		scanf("%c", &ptr[count]);
	}
	printf("end");
	return 0;
}
