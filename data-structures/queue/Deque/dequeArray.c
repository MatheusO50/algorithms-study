#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef struct Deque {
    int *arr , front , rear;
} Deque;

Deque *initDeque() {
    Deque *deque = (Deque*)malloc(sizeof(Deque));
    deque->arr = (int*)malloc(sizeof(int) * MAX);
    deque->front = -1;
    deque->rear = -1;
    return deque;
} 

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

int isFull(Deque *dq) {
    return ((dq->front - 1 == dq->rear) || (dq->front == 0 && dq->rear == MAX - 1));
}

void insertFront(Deque *dq , int data) {
    if(isFull(dq)) {
        printf("Deque is Full");
        return;
    }
    if(isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else if(dq->front == 0) dq->front = MAX - 1;
    else dq->front--;
    dq->arr[dq->front] = data;
}

void insertRear(Deque *dq , int data) {
    if(isFull(dq)) {
        printf("Deque is Full");
        return;
    }
    if(isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else if(dq->rear == MAX - 1) dq->rear = 0;
    else dq->rear++;
    dq->arr[dq->rear] = data;
}

int deleteFront(Deque *dq) {
    if(isEmpty(dq)) {
        printf("Deque is Empty");
        return -1;
    }
    int dataValue = dq->arr[dq->front];
    if(dq->front == dq->rear) dq->front = dq->rear = -1;
    else dq->front++;
    return dataValue;
}

int deleteRear(Deque *dq) {
    if(isEmpty(dq)) {
        printf("Deque is Empty");
        return -1;
    }
    int dataValue = dq->arr[dq->rear];
    if(dq->front == dq->rear) dq->front = dq->rear = -1;
    else dq->rear--;
    return dataValue;
}

void display(Deque *dq) {
    int c = dq->front;
    while(1) {
        printf("%i ",dq->arr[c]);
        if(c == dq->rear) break;
        c = (c + 1) % MAX;
    }
    printf("\n");
}

int main(void) {

    Deque *dq = initDeque();
    insertFront(dq,1);
    insertFront(dq,2);
    insertRear(dq,3);
    display(dq);

    return 0;
}