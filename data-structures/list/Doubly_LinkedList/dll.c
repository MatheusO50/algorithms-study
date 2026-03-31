#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

Node *create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void initList(List *list) {
    list->head = NULL;
    list->size = 0;
}

void insert_at_beginning(List *list , int data) {
    Node *new_node = create_node(data);
    if(list->head == NULL) list->head = new_node;
    else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}

void insert_at_end(List *list , int data) {
    Node *new_node = create_node(data);
    if(list->head == NULL) list->head = new_node;
    else {
        Node *current = list->head;
        while(current->next) current = current->next;
        current->next = new_node;
        new_node->prev = current;
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
    } else if(index == list->size) {
        insert_at_end(list,data);
        return;
    } else {
        Node *new_node = create_node(data) , *current = list->head;
        for(int i = 0 ; i < index - 1 ; i++) current = current->next;
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
    }
    list->size++;
}

void delete_at_beginning(List *list) {
    if(list->head == NULL) {
        printf("Void list");
        return;
    }
    Node *current = list->head;
    if(list->size == 1) list->head = NULL;
    else {
        list->head = current->next;
        list->head->prev = NULL;
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
    if(list->size == 1) list->head = NULL;
    else {
        while(current->next) current = current->next;
        current->prev->next = NULL;
    }
    free(current);
    list->size--;
}

void delete_at_position(List *list , int index) {
    if(index < 0 || index > list->size) {
        printf("Void list");
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
    Node *current = list->head;
    if(list->size == 1) list->head = NULL;
    else {
        for(int i = 0 ; i < index ; i++) current = current->next;
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);
    list->size--;
}

void display(List *list) {
    Node *current = list->head;
    while(current->next) current = current->next;
    while(current) {
        printf("%i->",current->data);
        current = current->prev;
    }
    printf("\n");
}

int main(void) {

    List list;
    initList(&list);
    insert_at_beginning(&list,1);
    insert_at_end(&list,3);
    insert_at_position(&list,2,1);
    delete_at_position(&list,1);
    display(&list);

    return 0;
}
