#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARACTERS "abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWYXZ1234567890"

int len(const char *str) {
    const char *temp = str;
    while(*temp) temp++;
    return temp - str;
}

char *generator_id(int size) {
    char *id = (char*)malloc(size + 1);
    int size_caracter = len(CARACTERS) , limit = RAND_MAX - (RAND_MAX % size_caracter);
    int c;
    for(int i = 0 ; i < size ; i++) {
        do {
            c = rand();
        } while(c >= limit);
        id[i] = CARACTERS[c % size_caracter];
    } 
    id[size] = '\0';
    return id;
}