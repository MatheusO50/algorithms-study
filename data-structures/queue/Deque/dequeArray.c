/*
Deque é uma variação de queue 
mas com funções específica como inserir
e deletar tanto no começo tanto no final
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 4

typedef struct Deque {
    int front , *arr , rear;
} Deque;

Deque *init_Deque() {
    Deque *dq = (Deque*)malloc(sizeof(Deque));
    dq->arr = (int*)malloc(sizeof(int) * MAX);
    dq->front = dq->rear = -1;
    return dq;
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

int isFull(Deque *dq) {
    return (dq->rear + 1) % MAX == dq->front;
}

//O(1)
void insertFront(Deque *dq , int data) {
    if(isFull(dq)) {
        printf("Deque is Full");
        return;
    }

    if(isEmpty(dq)) dq->front = dq->rear = 0;
    else dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = data;
}

//O(1)
void insertRear(Deque *dq , int data) {
    if(isFull(dq)) {
        printf("Deque is Full");
        return;
    }

    if(isEmpty(dq)) dq->front = dq->rear = 0;
    else dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = data;
}

//O(1)
void deleteFront(Deque *dq) {
    if(isEmpty(dq)) {
        printf("Deque is Empty");
        return;
    }

    if(dq->front == dq->rear) dq->front = dq->rear = -1;
    else dq->front = (dq->front + 1) % MAX;
}

//O(1)
void deleteRear(Deque *dq) {
    if(isEmpty(dq)) {
        printf("Deque is Emtpy");
        return;
    }

    if(dq->front == dq->rear) dq->front = dq->rear = -1;
    else dq->rear = (dq->rear - 1 + MAX) % MAX;
}

//O(1)
int getFront(Deque *dq) {
    if(isEmpty(dq)) {
        printf("Deque is Empty");
        return INT_MIN;
    }

    return dq->arr[dq->front];
}

//O(1)
int getRear(Deque *dq) {
    if(isEmpty(dq)) {
        printf("Deque is Empty");
        return INT_MIN;
    }

    return dq->arr[dq->rear];
}

//O(n)
void diplay(Deque *dq) {
    int counter = dq->front;

    while(1) {
        printf("%i ",dq->arr[counter]);
        if(counter == dq->rear) break;;
        counter = (counter + 1) % MAX;
    }
    printf("\n");
}

int main(void) {
    Deque *dq = init_Deque();

    insertFront(dq,1);
    insertFront(dq,2);
    insertRear(dq,3);
    insertRear(dq,4);
    deleteRear(dq);
    diplay(dq);

    free(dq->arr);
    free(dq);
}