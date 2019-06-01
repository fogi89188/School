#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct packet_t{
	char content[255];
	char destination[16];
	char source[16];
};

struct stack_t {

	int size;
	int capacity;
	struct packet_t *data;
	
};

//func to print a given packet
//the name pPrint comes from "Packet Print"
void pPrint(struct packet_t packet){
	printf("From %s To %s Content:%s", packet.source, packet.destination, packet.content);
}

void init(struct stack_t *s){
	s->size = 0;
	s->capacity = 2;
	s->data = malloc(s->capacity*sizeof(struct packet_t));
}

void destroy(struct stack_t *s){
	s->size = 0;
	s->capacity = 0;
	free(s->data);
	s->data = NULL;
}

void push(struct stack_t *s, struct packet_t packet){
	if(s->data == NULL){
		return;
	}
	if(s->size == s->capacity){
		s->capacity*=2;
		s->data = realloc(s->data, s->capacity*sizeof(struct packet_t));
	}
	
	s->data[s->size] = packet;
	s->size++;
}
int main(){
	//creating an arrya struct
	struct stack_t buffer;
	int id = 0;
	init(&buffer);
	//filling the array
	printf("The program works untill you enter stop\n");
	struct packet_t packet;
	while(strcmp("stop", packet.source)){
		scanf("%s", &packet.source);
		if(!strcmp("stop", packet.source)){
			break;
		}
		scanf("%s", &packet.destination);
		fgets(packet.content, 255, stdin);
		push(&buffer, packet);
		id++;
	}


	printf("sending out packets...\n");
	
	//Start of sorting (selection sort)
	struct packet_t empty;
	int j = 0;
	int tmp = 0;
	for(int i = 0; i < buffer.size; i++){
		tmp = i;
		for(j = i+1; j < buffer.size; j++){
			if(strlen(buffer.data[j].content) < strlen(buffer.data[tmp].content)){
				tmp = j;
			}
		}		
		empty = buffer.data[i];
		buffer.data[i] = buffer.data[tmp];
		buffer.data[tmp] = empty;
	}	
	//printing the final result
	
	for(int i =0; i < buffer.size; i++){	
		pPrint(buffer.data[i]);
	}	
	destroy(&buffer);
	return 0;
}
