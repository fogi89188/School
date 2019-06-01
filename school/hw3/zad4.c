#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack_t {

	int size;
	int capacity;
	struct process_t *data;
	
};

struct process_t{
	int id;
	int time;
};


void init(struct stack_t *s){
	s->size = 0;
	s->capacity = 2;
	s->data = malloc(s->capacity*sizeof(struct process_t));
}


void push(struct stack_t *s, struct process_t num){
	if(s->data == NULL){
		return;
	}
	if(s->size == s->capacity){
		s->capacity*=2;
		s->data = realloc(s->data, s->capacity*sizeof(struct process_t));
	}
	
	s->data[s->size] = num;
	s->size++;
}

void destroy(struct stack_t *s){
	s->size = 0;
	s->capacity = 0;
	free(s->data);
	s->data = NULL;
}

int total(struct stack_t s){
	int total = 0;
	for(int i = 0; i < s.size; i++){
		total += s.data[i].time;
	}
	return total;
}

int count(struct stack_t s){
	int count = 0;
	for(int i = 0; i < s.size; i++){
		count++;
	}
	return count;
}

void printall(struct stack_t s, int processor){
	printf("Queue for processor %d: %d processes, Total time: %d\n", processor, count(s), total(s));
}

int main(){
	int id = 0;
	char string[250] = "";
	int counter = 1;
	
	struct stack_t stack1;
	struct stack_t stack2;
	struct stack_t stack3;
	struct stack_t stack4;
	
	init(&stack1);
	init(&stack2);
	init(&stack3);
	init(&stack4);
	
	while(strcmp(string, "exit")){
		scanf("%s", &string);
		if(!strcmp(string, "exit")){
			continue;
		}
		struct process_t pro;
		pro.time = atoi(string);
		pro.id = id;
		
		if(total(stack1) <= total(stack2) && total(stack1) <= total(stack3) && total(stack1) <= total(stack4)){
			//stack1
			push(&stack1, pro);	
		}
		else if(total(stack2) <= total(stack1) && total(stack2) <= total(stack3) && total(stack2) <= total(stack4)){
			//stack2
			push(&stack2, pro);
		}
		else if(total(stack3) <= total(stack2) && total(stack3) <= total(stack1) && total(stack3) <= total(stack4)){
			//stack3
			push(&stack3, pro);
		}
		else if(total(stack4) <= total(stack2) && total(stack4) <= total(stack3) && total(stack4) <= total(stack1)){
			//stack4
			push(&stack4, pro);
		}
		if(counter % 5 == 0 && id != 0){
			printall(stack1, 1);
			printall(stack2, 2);
			printall(stack3, 3);
			printall(stack4 ,4);
		}
		counter++;
		id++;
	}	
	
	destroy(&stack1);
	destroy(&stack2);
	destroy(&stack3);
	destroy(&stack4);	
		
	return 0;
}
