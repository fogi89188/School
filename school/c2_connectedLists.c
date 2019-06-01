#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t{
	int data;
	struct node_t *next;
};

struct list_t{
	struct node_t *head;
};

struct list_t init_list(){
	struct list_t result;
	return result;
}

void insert(struct list_t *l, int value){
	struct node_t *tmp = l->head;
	
	struct node_t *new_node = malloc(sizeof(struct node_t));
	new_node->data = value;
	new_node->next = NULL;
	if(tmp == NULL){
		l->head = new_node;
		return;	
	}
	
	while(tmp->next != NULL){
	tmp = tmp->next;
	}
	
	tmp->next = new_node;
}

void destroy_list(struct list_t *list){
	 struct node_t *tmp = list->head;
	 struct node_t *node = tmp;
	 while(tmp != NULL)
	 {
	 	tmp = tmp->next;
	 	free(node);
	 }
}

int main(){
	struct list_t l = init_list();
	insert(&l, 5);
	insert(&l, 7);
	insert(&l, 12);
	destroy_list(&l);
	return 0;
}
