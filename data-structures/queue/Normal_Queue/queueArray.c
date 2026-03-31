#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Queue {
    int *arr , front , rear;    
} Queue;

Queue *initQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(sizeof(int) * MAX);
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q , int data) {
    if(isFull(q)) {
        printf("Queue is Full");
        return;
    }
    if(isEmpty(q)) q->front = 0;
    q->arr[++q->rear] = data;
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty");
        return -1;
    }
    int delValue = q->arr[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else q->front++;
    return delValue;
}

void display(Queue *q) {
    for(int i = q->front ; i <= q->rear ; i++) printf("%i ",q->arr[i]);
    printf("\n");
}

int main(void) {

    Queue *q = initQueue();
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    display(q);

    return 0;
}