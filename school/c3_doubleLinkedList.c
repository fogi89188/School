#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t{
	int data;
	struct node_t *next;
	struct node_t *prev;
};

struct d_list_t{
	struct node_t *head;
	struct node_t *tail;	
};

int is_empty(struct d_list_t l){
	if(l.head == NULL){
		if(l.tail == NULL){
			return 1;
		}	
	}
	return 0;
}

void addLast(struct d_list_t *l, int value){
	struct node_t *newNode = malloc(sizeof(struct node_t));
	
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = value;
	if(is_empty(*l)){
		l->head = newNode;
		l->tail = newNode;
	}
	else{
		struct node_t *tmp = l->tail;
		l->tail = newNode;
		newNode->prev = tmp;
		tmp->next = newNode;
	}
}

void addAt(struct d_list_t *l, int value, int index){
	struct node_t *newNode = malloc(sizeof(struct node_t));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = value;
	struct node_t *current = l->head;
	int count = 0;
	while(count < index){
		current = current->next;
		count++;
	}
	newNode->next = current->next;
	newNode->next->prev = newNode;
	newNode->prev = current;
	current->next = newNode;
}

struct d_list_t list_init(){
	struct d_list_t result;
	result.head = NULL;
	result.tail = NULL;
	
	return result;
	
}

int main(){
	struct d_list_t list = list_init();
	printf("%d\n", is_empty(list));
	addLast(&list, 7);
	addLast(&list, 12);
	printf("%d\n", is_empty(list)); 
	return 0;
}
