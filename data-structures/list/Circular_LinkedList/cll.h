#ifndef CLL_H
#define CLL_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head , *last;
    int size;
} List;

Node *create_node(int data);
void initList(List *list);
void insert_at_beginning(List *list , int data);
void insert_at_end(List *list , int data);
void insert_at_position(List *list , int data , int index);
void delete_at_beginning(List *list);
void delete_at_end(List *list);
void delete_at_position(List *list , int index);
void display(List *list);

#endif