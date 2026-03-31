#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 100
#define EMPTY 0
#define OCCUPIED 1
#define DELETE 2

typedef struct {
    char *key;
    char *value;
    int isOccupied;
} HashItem;

HashItem HashTable[TABLE_SIZE];

int len(const char *str) {
    const char *temp = str;
    while(*temp) temp++;
    return temp - str;
}

int equals(char *value01 , char *value02) {
    while((*value01 && *value02) && (*value01 == *value02)) {
        value01++;
        value02++;
    }
    return *value01 == *value02;
}

void copy(char *destination , char *origin) {
    while(*origin) {
        *destination = *origin;
        destination++;
        origin++;
    }
    *destination = '\0';
}

void initTable(void) {
    for(int i = 0 ; i < TABLE_SIZE ; i++) HashTable[i].isOccupied = EMPTY; 
}

int hash_function(char *key) {
    int hash = 5381 , c;
    while((c = *key++)) hash = ((hash << 5) + hash) + c;
    return hash % TABLE_SIZE;
}

void insert(char *key , char *value) {
    int index = hash_function(key) , startIndex = index;
    while(HashTable[index].isOccupied == OCCUPIED) {
        if(equals(HashTable[index].key,key)) {
            free(HashTable[index].value);
            HashTable[index].value = (char*)malloc(len(value) + 1);
            copy(HashTable[index].value,value);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if(index == startIndex) break;
    }
    HashTable[index].key = (char*)malloc(len(key) + 1);
    copy(HashTable[index].key,key);
    HashTable[index].value = (char*)malloc(len(value) + 1);
    copy(HashTable[index].value,value);
    HashTable[index].isOccupied = OCCUPIED;
}

char *search(char *key) {
    int index = hash_function(key) , startIndex = index;
    while(HashTable[index].isOccupied != EMPTY) {
        if((HashTable[index].isOccupied == OCCUPIED) && (equals(HashTable[index].key,key))) return HashTable[index].value;
        index = (index + 1) % TABLE_SIZE;
        if(index == startIndex) break; 
    }
    printf("Invalid Value\n");
    return NULL;
}

void delete_item(char *key) {
    int index = hash_function(key) , startIndex = index;
    while(HashTable[index].isOccupied != EMPTY) {
        if(HashTable[index].isOccupied == OCCUPIED) {
            free(HashTable[index].key);
            free(HashTable[index].value);
            HashTable[index].isOccupied = DELETE;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if(index == startIndex) break;
    }
    printf("Invalid Value");
}

void