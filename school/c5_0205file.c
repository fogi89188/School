#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	char *string = "Blah Blah Binary";
	
	FILE *fp;
	//fp = fopen("binaryText.bin", "wb");
	//fwrite(string, sizeof(string), 1, fp);
	
	fp = fopen("binaryText.bin", "wr");
	fread(string, sizeof(string), 1, fp);
	
	fclose(fp);
	
	return 0;
}


