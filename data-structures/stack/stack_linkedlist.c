#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    int size;
    Node *top;
} Stack;

Node *createNode(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void initStack(Stack *stack) {
    stack->size = 0;
    stack->top = NULL;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack , int data) {
    if(isFull(stack)) { 
        printf("Stack is Full");
        return;
    }
    Node *new_node = createStack(data);
    if(isEmpty(stack)) stack->top = new_node;
    else {
        new_node->next = stack->top;
        stack->top = new_node;
    }
    stack->size++;
}

int pop(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is Empty");
        return -1;
    }
    Node *deleteValue = stack->top;
    int popValue = stack->top->data;
    stack->top = stack->top->next;
    free(deleteValue);
    stack->size--;
    return popValue;
}

int peek(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is Empty");
        return -1;
    }
    return stack->top->data;
}

void display(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is Empty");
        return;
    }
    Node *current = stack->top;
    while(current) {
        printf("%i->",current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {

    Stack stack;
    initStack(&stack);
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    pop(&stack);
    display(&stack);

    return 0;
}

