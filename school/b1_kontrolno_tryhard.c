#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int var;
int var10[10];

int main(){
	for(int i = 0; i < 10 ; i++){
		var10[i] = i+5;
	}
	
	for(int i = 0; i < 10 ; i++){
		int val = var10[i];
		printf("var10[%d] = %d\n", i, val);
	}
	return 0;
}*/

/*struct book_t {
	char author[100];
	char title[100];
	int year;
}; 	

struct shelf_t{
	int book_count;
	struct book_t all[10];
};

int main(){
	struct book_t book1;
	strcpy(book1.author, "Mr. Wolf");
	strcpy(book1.title, "The Hidden Truth About Howling");
	book1.year = 2000;
	
	struct shelf_t shelf;
	shelf.all[0] = book1;
	shelf.book_count = 5;
	
	for(int i = 1; i < shelf.book_count; i++){
		strcpy(shelf.all[i].author, "Mr. Wolf");
		strcpy(shelf.all[i].title, "The Hidden Truth About Howling");
		shelf.all[i].year = 2000 + i;
	}
	
	
	for(int i = 0; i < shelf.book_count; i++){
		printf("%s - \"%s\" - %d\n", shelf.all[i].author, shelf.all[i].title, shelf.all[i].year);
	}
	return 0;
}*/

int main(){
	int number = 68; //0 0100 0100
	int other = 317; //1 0011 1101
	
	const int IS_MAN = 1;      // 0000 0001
	const int IS_WOMAN = 2;    // 0000 0010
	const int IS_CHILD = 4;    // 0000 0100
	const int IS_OLD = 8;      // 0000 1000
	const int IS_OLDER = 16;   // 0001 0000
	const int IS_ANCIENT = 32; // 0010 0000
	const int IS_SMALL = 64;   // 0100 0000
	const int IS_TINY = 128;   // 1000 0000
	
	short person = IS_WOMAN | IS_SMALL | IS_OLD;         // 0100 1010
	
	// & - 0 0000 0100 - 4
	// | - 1 0111 1101 - 381
	// ~ - 1 1011 1011 - -69
	// ^ - 1 0111 1011 - 377
	/*printf("%d %d\n", number, number & other);
	printf("======\n");
	printf("%d %d\n", number, number | other);
	printf("======\n");
	printf("%d %d\n", number, ~number);
	printf("======\n");
	printf("%d %d\n", number, number ^ other);
	printf("======\n");*/
	printf("%d %d %d %d\n", person & IS_MAN, person & IS_WOMAN, person & IS_SMALL, person & IS_TINY);
	return 0;
}

