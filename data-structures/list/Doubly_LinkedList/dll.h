#ifndef DLL_H
#define DLL_H

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List {
    int size;
    Node *head;
} List;

Node *create_node(int data);
void insert_at_beginning(List *list , int data);
void insert_at_end(List *list , int data);
void insert_at_position(List *list , int data , int index);
void delete_at_beginning(List *list);
void delete_at_end(List *list);
void delete_at_position(List *list , int index);
void display(List *list);

#endif