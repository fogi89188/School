#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct entry_t{
	char *key;
	int value;
};

struct map_t {
	struct entry_t *entries;
	int size;
	int capacity;
};


struct map_t init_map(){
	struct map_t map;
	
	
	map.size = 0;
	map.capacity = 2;
	
	map.entries = malloc(map.capacity * sizeof(struct entry_t));
	
	
	return map;
}

void destroy_map(struct map_t *m){
	 m->size = 0;
	 m->capacity = 0;
	 free(m->entries);
	 m->entries = NULL;
}

void put(struct map_t *m, char *key, int value){
	if(m->size == m->capacity){
		m->capacity *= 2;
		m->entries = realloc(m->entries, m->capacity * sizeof(struct entry_t));
	}
	
	struct entry_t new_entry = {
		.key = key,
		.value = value
	};
	
	m->entries[m->size] = new_entry;
	m->size++;
}
int get(struct map_t m, char *key){
	for(int i = 0; i < m.size; i++){
		struct entry_t current = m.entries[i];
		if(strcmp(current.key, key) == 0){
			return current.value;
		}
	}
	return INT_MIN;
}

int main(){
	struct map_t main_map = init_map();
	
	put(&main_map, "first", 1);
	put(&main_map, "second", 2);
	put(&main_map, "third", 3);
	
	int elem = get(main_map, "second");
	
	printf("%s -> %d\n", "second", elem);
		
	destroy_map(&main_map);	
	return 0;
}
