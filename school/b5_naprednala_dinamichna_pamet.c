#include <stdio.h>
#include <stdlib.h>
#define INIT_CAPACITY 5

struct vector_t{
	int capacity;
	int size;
	int *data;
};

struct vector_t init();
void add(struct vector_t *vector, int element);
void destroy(struct vector_t *vector);
void resize(struct vector_t *vector);
int get(struct vector_t vector, int index);
void add_front(struct vector_t *vector, int element);
void add_at(struct vector_t *vector, int position, int element);

int main()
{	
	struct vector_t v = init();
	add(&v, 1);
	printf("%d\n", get(v, 0));
	add_front(&v, 8);
	printf("%d\n", get(v, 0));
	add(&v, 2);
	add(&v, 3);
	add(&v, 4);
	add(&v, 5);
	printf("%d\n", get(v, 5));
	add_at(&v, 5, 11);
	printf("%d\n", get(v, 5));
	add(&v, 6);
	add(&v, 7);
	destroy(&v);
	return 0;
}

void add(struct vector_t *vector, int element){
	add_at(vector, vector->size, element);
}

void add_front(struct vector_t *vector, int element){
	add_at(vector, 0, element);
}

void resize(struct vector_t *vector){
	vector->capacity *= 2;
	int *tmp = vector->data;
	vector->data = malloc(vector->capacity * sizeof(int));
	for(int i = 0; i < vector->size; i++){
		vector->data[i] = tmp[i];
	}
	free(tmp);
}

struct vector_t init(){
	struct vector_t vector;
	vector.capacity = INIT_CAPACITY;
	vector.data = malloc(INIT_CAPACITY * sizeof(int));
	vector.size = 0;
	return vector;
}

void add_at(struct vector_t *vector, int position, int element){
	if(vector->data == NULL){
		return;
	}
	
	if(vector->capacity == vector->size){
		resize(vector);
	}
	
	if(position < 0 || position > vector->size){
		return;
	}
	
	for(int i = position; i > 0; i--){
		vector->data[i] = vector->data[i-1];
	}
	
	vector->data[position] = element;
	vector->size++;
}

int get(struct vector_t vector, int index){
	if(index < 0){
		return -2;
	}
	if(index > vector.size){
		return -1;
	}
	return vector.data[index];
}

void destroy(struct vector_t *vector){
	free(vector->data);
	vector->data = NULL;
	vector->capacity = 0;
	vector->size = 0;
}

