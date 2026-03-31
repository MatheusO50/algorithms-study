#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct Node {
	char *key;
	char *value;
	struct Node *next;
} Node;

typedef struct HashMap {
	int capacity , numberElements;
	Node **arr;
} HashMap;

int len(const char *str);
void copy(char *destination , char *origin);
int my_strcmp(char *value01 , char * value02);
Node *createNode(char *key , char *value);
void initTable(HashMap *mp);
void insert_element(HashMap *mp , char *key , char *value);
char *search(HashMap *mp , char *key);
void delete_element(HashMap *mp , char *key);
void destroy_table(HashMap *mp);

#endif
