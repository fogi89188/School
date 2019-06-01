#include <stdio.h>
#include <stdlib.h>

struct stack_t {

	int size;
	int capacity;
	int *data;
	
};

struct stack_t init(){
	struct stack_t stack;
	stack.capacity = 2;
	stack.size = 0;
	stack.data = malloc(sizeof(int)*stack.capacity);
	return stack;
	
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

void destroy(struct stack_t *stack){
	free(stack->data);
	stack->data = NULL;
	stack->capacity = 0;
	stack->size = 0;
}

int pop(struct stack_t *s){
	s->size--;
	int result = s->data[s->size];
	s->data[s->size] = 0;
	return result;
}

int main(){
	struct stack_t stack = init();
	push(&stack, 5);
	push(&stack, 5);
	push(&stack, 5);
	pop(&stack);
	pop(&stack);
	pop(&stack);	
	destroy(&stack);
	return 0;
}
