#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

Node *create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void initList(List *list) {
    list->head = list->last = NULL;
    list->size = 0;
}

void insert_at_beginning(List *list , int data) {
    Node *new_node = create_node(data);
    if(list->head == NULL) list->head = list->last = new_node;
    else {
        new_node->next = list->head;
        list->last->next = new_node;
        list->head = new_node;
    }
    list->size++;
}

void insert_at_end(List *list , int data) {
    Node *new_node = create_node(data);
    if(list->head == NULL) list->head = list->last = new_node;
    else {
        new_node->next = list->head;
        list->last->next = new_node;
        list->last = new_node;
    }
    list->size++;
}

void insert_at_position(List *list , int data , int index) {
    if(index < 0 || index > list->size) {
        printf("Invalid Index");
        return;
    }
    if(index == 0 || list->head == NULL) {
        insert_at_beginning(list,data);
        return;
    }
    if(index == list->size) {
        insert_at_end(list,data);
        return;
    }
    Node *new_node = create_node(data) , *current = list->head;
    for(int i = 0 ; i < index - 1; i++) current = current->next;
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
}

void delete_at_beginning(List *list) {
    if(list->head == NULL) {
        printf("Void list");
        return;
    }
    Node *current = list->head;
    if(list->size == 1) list->head = list->last = NULL;
    else {
        list->head = current->next;
        list->last->next = list->head;
    }
    free(current);
    list->size--;
}

void delete_at_end(List *list) {
    if(list->head == NULL) {
        printf("Void list");
        return;
    }
    Node *current = list->head;
    if(list->size == 1) list->head = list->last = NULL;
    else {
        while(current->next != list->last) current = current->next;
        list->last = current;
        list->last->next = list->head;
    }
    list->size--;
}

void delete_at_position(List *list , int index) {
    if(index < 0 || index > list->size) {
        printf("Invalid Index");
        return;
    }
    if(index == 0 || list->size == 1) {
        delete_at_beginning(list);
        return;
    }
    if(index == list->size - 1) {
        delete_at_end(list);
        return;
    }
    Node *current = list->head , *prev = NULL;
    for(int i = 0 ; i < index ; i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    list->size--;
}

void display(List *list) {
    Node *current = list->head;
    do {
        printf("%i->",current->data);
        current = current->next;
    } while(current != list->head);
    printf("\n");
}

int main(void) {

    List list;
    initList(&list);
    insert_at_beginning(&list,1);
    insert_at_end(&list,3);
    insert_at_position(&list,2,1);
    delete_at_position(&list,0);
    display(&list);

    return 0;
}