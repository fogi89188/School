#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//defining a double array S
char S[2][16];

//defining func to move bits of the array S
char F (char x) {
	return S[0][x>>6] + S[1][x>>4];
}

//defining a func that encrypts using the F func
void encrypt(char L, char R, char* out) {
	
	for(int i = 0; i < 16; i++) {
		R = R ^ F(L);
		L = L ^ F(R);
	}
	//changing L and R's spaces
	char Change;
	Change = R;
	R = L;
	L = Change;
	//"returning" the changed and encrypted characters
	out[0] = L;
	out[1] = R;
}

//defining a func that decrypts using the F func
void decrypt(char L, char R, char* out) {

	for(int i = 0; i < 16; i++) {
		R = R ^ F(L);
		L = L ^ F(R);
	}
	//changing L and R's spaces
	char Change;
	Change = R;
	R = L;
	L = Change;
	//"returning" the changed and decrypted characters
	out[0] = L;
	out[1] = R;
}

//defining a function that uses the key to fill the whole S array
void init_boxes(char* key) {

	for(int j = 0,g = 0; j != 32; j++, g++) {
		
		//if- then writing in the first line of the S array
		if(j<16){
			if(g == strlen(key)){
				g = 0;
			}
			S[0][j] = key[g];
		}
		//else- then writing in the second line of the S array
		else if(j >= 16){
			if(g == strlen(key)){
				g = 0;
			}
			S[1][j-16] = key[g];
		}
	}
}

// first filling the S array with the key, then using the encrypion func to encript the given text and write it
void perform_encryption(char* text, char* key, char* encrypted) {

	init_boxes(key);
	char boxes[2];
	for(int i = 0; text[i] != '\0'; i+=2) {
		encrypt(text[i], text[i+1], boxes);
		//because the ecrypt func returns 2 chars, we use them and concatenate them at the end of the "encrypted" string.
		strcat(encrypted, boxes);
	}
}

// then using the decrypion func to decript the given text and write it
void perform_decryption(char* text, char* decrypted) {
	
	char boxes[2];
	for(int i = 0; text[i] != '\0'; i+=2) {
		decrypt(text[i], text[i+1], boxes);
		//because the decrypt func returns 2 chars, we use them and concatenate them at the end of the "decrypted" string.
		strcat(decrypted, boxes);
	}	
}

// the main func where you use console arguments to give informations for the program
int main(int argc, char* argv[]) {
	// if the program has been given the right number of console arguments, then continue normally if true
	if(argc == 3){
		//defining
		char key[64];
		char encrypted[64];
		char decrypted[64];
		char text[100];
		
		//writing the console arguments in their respective places
		strcpy(key, argv[1]);
		strcpy(text, argv[2]);
		
		// performing the encryption and decryption
		perform_encryption(text, key, encrypted);
		perform_decryption(encrypted, decrypted);
		
		// writing out the results
		printf("%s\n", encrypted);
		printf("%s\n", decrypted);
	}
	// else if the program has invalid input - print an error
	else{
		printf("ER#0R: Invalid Input.\n");
	}
}
