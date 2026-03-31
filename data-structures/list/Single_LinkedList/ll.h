#ifndef LL_H
#define LL_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    struct Node *head;
    int size;   
} List;

int isEmpty(List *list);
void initList(List *list);
Node *create_node(int data);
void insert_at_beginning(List *list , int data);
void insert_at_end(List *list , int data);
void insert_at_position(List *list , int data , int index);
void delete_at_beginning(List *list);
void delete_at_end(List *list);
Node *reverseList(List *list , Node *head);
void display(List *list);

#endif