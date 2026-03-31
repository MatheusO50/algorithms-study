#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Stack {
    int top , capacity , *arr;
} Stack;

Stack *initStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = MAX;
    stack->arr = (int*)malloc(sizeof(int) * MAX);
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

void push(Stack *stack , int data) {
    if(isFull(stack)) {
        printf("Stack is Full");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is Empty");
        return -1;
    }
    int popValue = stack->arr[stack->top];
    stack->top--;
    return popValue;
}

int peek(Stack *stack) {
    if(isEmpty(stack)) {
        printf("Stack is Empty");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(Stack *stack) {
    for(int i = stack->top ; i >= 0 ; i--) printf("%i ",stack->arr[i]);
    printf("\n");
}

int main(void) {

    Stack *stack = initStack();
    push(stack,1);
    push(stack,2);
    push(stack,3);
    printf("%i",peek(stack));

    return 0;
}

