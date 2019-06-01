#include <stdio.h>
#include <stdlib.h>

struct stack_t {

	int size;
	int capacity;
	int *data;
	
};

void init(struct stack_t*);
void push(struct stack_t*, int);
int pop(struct stack_t*);
void destroy(struct stack_t*);
//int isEmpty(); dali steka e empty
//int peek(); koi e nai gorniq element ama ne go maha
//int contains(struct stack_t, int); dali sudurja chislo vuv stacka (sus pop shte se proveri)
//struct stack_t copy(struct stack_t); za da se izpolzva v contains

int main(){
	
	struct stack_t stack;
	
	init(&stack);
	
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	printf("%d\n", pop(&stack));
	
	printf("%d\n", stack.size);
	printf("%d\n", stack.capacity);
	
	destroy(&stack);
	return 0;
}

void init(struct stack_t *s){
	s->size = 0;
	s->capacity = 2;
	s->data = malloc(s->capacity*sizeof(int));
}

int pop(struct stack_t *s){
	s->size--;
	int result = s->data[s->size];
	s->data[s->size] = 0;
	return result;
}

void destroy(struct stack_t *s){
	s->size = 0;
	s->capacity = 0;
	free(s->data);
	s->data = NULL;
}

void push(struct stack_t *s, int num){
	if(s->data == NULL){
		return;
	}
	if(s->size == s->capacity){
		s->capacity*=2;
		s->data = realloc(s->data, s->capacity*sizeof(int));
	}
	
	s->data[s->size] = num;
	s->size++;
}
