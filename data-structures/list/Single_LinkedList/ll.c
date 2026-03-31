#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int isEmpty(List *list) {
    return list->head == NULL;
}

void initList(List *list) {
    list->head = NULL;
    list->size = 0;
}

Node *create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(List *list , int data) {
    Node *new_node = create_node(data);
    if(new_node == NULL) return;
    if(isEmpty(list)) list->head = new_node;
    else {
        new_node->next = list->head;
        list->head = new_node;
    } 
    list->size++;
}

void insert_at_end(List *list , int data) {
    Node *new_node = create_node(data);
    if(new_node == NULL) return;
    if(isEmpty(list)) list->head = new_node;
    else {
        Node *current = list->head;
        while(current->next) current = current->next;
        current->next = new_node;
    }
    list->size++;
}

void insert_at_position(List *list , int data , int index) {
    if(index < 0 || index > list->size) return;
    if(index == 0 || isEmpty(list)) {
        insert_at_beginning(list,data);
        return;
    }
    else if(index == list->size) {
        insert_at_end(list,data);
        return;
    }
    else {
        Node *current = list->head , *new_node = create_node(data);
        for(int i = 0 ; i < index - 1 ; i++) current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
    list->size++;
}

void delete_at_beginning(List *list) {
    if(isEmpty(list)) return;
    Node *current = list->head;
    if(list->size == 1) list->head = NULL;
    else list->head = current->next;
    free(current);
    list->size--;
}

void delete_at_end(List *list) {
    if(isEmpty(list)) return;
    Node *current = list->head;
    if(list->size == 1) list->head = NULL;
    else {
        Node *prev = NULL;
        while(current->next) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
    } 
    free(current);
    list->size--;
}

Node *reverseList(List *list , Node *head) {
    if(head->next == NULL) return head;
    Node *temp = reverseList(list,head->next);
    head->next->next = head;
    head->next = NULL;
    return temp; 
}

void display(List *list) {
    if(isEmpty(list)) return;
    Node *current = list->head;
    while(current) {
        printf("%i->",current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {

    List list;
    initList(&list);
    insert_at_beginning(&list,1);
    insert_at_end(&list,3);
    insert_at_position(&list,2,1);
    //delete_at_beginning(&list);
    //delete_at_end(&list);
    list.head = reverseList(&list,list.head);
    display(&list);

    return 0;
}