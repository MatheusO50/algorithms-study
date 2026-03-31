#include <stdio.h>
#include <stdlib.h>
#include "hashMap.h"

int len(const char *str) {
	const char *temp = str;
	while(*temp) temp++;
	return temp - str;
}

void copy(char *destination , char *origin) {
	int counter = 0;
	while(origin[counter] != '\0') {
		destination[counter] = origin[counter];
		counter++;
	}
	destination[counter] = '\0'; 
}

int my_strcmp(char *value01 , char * value02) {
	while((*value01 == *value02)) {
		value01++;
		value02++;
	}
	return *value01 == *value02;
}

Node *createNode(char *key , char *value) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	if(new_node == NULL) return NULL;
	new_node->key = (char*)malloc(len(key) + 1);
	if(new_node->key == NULL) {
		free(new_node);
		return NULL;
	}
	copy(new_node->key,key);
	new_node->value = (char*)malloc(len(value) + 1);
	if(new_node->value == NULL) {
		free(new_node->key);
		free(new_node);
		return NULL;
	}
	copy(new_node->value,value);
	new_node->next = NULL;
	return new_node;
}

void initTable(HashMap *mp) {
	mp->capacity = 100 , mp->numberElements = 0;
	mp->arr = (Node**)malloc(sizeof(Node*) * mp->capacity);
	for(int i = 0 ; i < mp->capacity ; i++) mp->arr[i] = NULL;
	return;
}

int hash_function(HashMap *mp , unsigned char *key) {
	unsigned int hash = 5381;
	int c = 0;
	while(c = *key++) hash = ((hash << 5) + hash) + c;
	return hash % mp->capacity;
}

void insert_element(HashMap *mp , char *key , char *value) {
	int index = hash_function(mp,key);
	if(mp->arr[index] == NULL) mp->arr[index] = createNode(key,value);
	else {
		Node *current = mp->arr[index];
		while(current) {
			if(my_strcmp(current->key , key)) {
				free(current->value);
				current->value = (char*)malloc(len(value) + 1);
				copy(current->value,value);
				return;
			}
			current = current->next;
		}
		Node *new_node = createNode(key,value);
		new_node->next = mp->arr[index];
		mp->arr[index] = new_node;
	}
	mp->numberElements++;
}

char *search(HashMap *mp , char *key) {
	int index = hash_function(mp,key);
	Node *current = mp->arr[index];
	while(current) {
		if(my_strcmp(current->key,key)) return current->value;
		current = current->next;
	}
	printf("Invalid Value\n");
	return NULL;
}

void delete_element(HashMap *mp , char *key) {
	int index = hash_function(mp,key);
	Node *current = mp->arr[index] , *prev = NULL;
	while(current) {
		if(my_strcmp(current->key,key)) {
			if(current == mp->arr[index]) {
				mp->arr[index] = current->next;
			} else prev->next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			mp->numberElements--;
			return;
		}
		prev = current;
		current = current->next;
	}
}

void destroy_table(HashMap *mp) {
	for(int i = 0 ; i < mp->capacity ; i++) {
		Node *current = mp->arr[i];
		while(current) {
			Node *delNode = current;
			current = current->next;
			free(delNode->key);
			free(delNode->value);
			free(delNode);
		}
	}
	for(int i = 0 ; i < mp->capacity ; i++) mp->arr[i] = NULL;
}

int main(void) {

	HashMap mp;
	initTable(&mp);
	insert_element(&mp,"key01","value01");
	insert_element(&mp,"key02","value02");
	insert_element(&mp,"key03","value03");
	//destroy_table(&mp);

	printf("%s\n",search(&mp,"key01"));

	return 0;
}
