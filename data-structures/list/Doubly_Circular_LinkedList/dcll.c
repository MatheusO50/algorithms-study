#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List {
    Node *head , *last;
    int size;
} List;

void initList(List *list) {
    list->head = list->last = NULL;
    list->size = 0;
}

Node *createNode(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void insert_at_beginning(List *list , int data) {
    Node *new_node = createNode(data);
    if(list->head == NULL) list->head = list->last = new_node;
    else {
        new_node->next = list->head;
        new_node->prev = list->last;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}

void insert_at_end(List *list , int data) {
    Node *new_node = createNode(data);
    if(list->head == NULL) list->head = list->last = new_node;
    else {
        new_node->next = list->head;
        new_node->prev = list->last;
        list->last->next = new_node;
        list->last = new_node;
    }
    list->size++;
}

void insert_at_position(List *list , int data , int index) {
    if(index > list->size || index < 0) return;
    if(index == 0) {
        insert_at_beginning(list,data);
        return;
    }
    if(index == list->size) {
        insert_at_beginning(list,data);
        return;
    }
    Node *new_node = createNode(data) , *current = list->head;
    for(int i = 0 ; i < index ; i++) current = current->next;
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev = new_node;
    list->size++;
}

void delete_at_beginning(List *list) {
    if(list->head == NULL) return;
    Node *current = list->head;
    if(list->size == 1) list->head = list->last = NULL;
    else {
        list->head = current->next;
        list->head->prev = list->last;
        list->last->next = list->head;
    }
    free(current);
    list->size--;
    return;
}

void delete_at_end(List *list) {
    if(list->head == NULL) return;
    Node *current = list->last;
    if(list->size == 1) list->head = list->last = NULL;
    else {
        list->last = current->prev;
        list->last->next = list->head;
        list->head->prev = list->last;
    }
    free(current);
    list->size--;
    return;
}

void delete_at_position(List *list , int index) {
    if(index > list->size || index < 0) return;
    if(index == 0) {
        delete_at_beginning(list);
        return;
    }
    if(index == list->size - 1) {
        delete_at_end(list);
        return;
    }
    Node *current = list->head;
    for(int i = 0 ; i < index ; i++) current = current->next;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    list->size--;
}

void display(List *list) {
    Node *current = list->last;
    while(1) {
        printf("%i->",current->data);
        if(current == list->head) break;
        current = current->prev;
    }
    printf("\n");
}

int main(void) {
    
    List list;
    initList(&list);
    insert_at_beginning(&list,1);
    insert_at_beginning(&list,0);
    insert_at_end(&list,2);
    insert_at_end(&list,3);
    //delete_at_beginning(&list);
    //delete_at_end(&list);
    delete_at_position(&list,1);
    display(&list);

    return 0;
}

