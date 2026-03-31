#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front , *rear;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

Node *createNode(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q , int data) {
    Node *new_node = createNode(data);
    if(isEmpty(q)) q->front = q->rear = new_node;
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty");
        return -1;
    }
    Node *delNode = q->front;
    int dataValue = q->front->data;
    if(q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else q->front = q->front->next;
    free(delNode);
    q->size--;
    return dataValue;
}

int peek(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Empty");
        return -1;
    }
    return q->front->data;
}

void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is Emtpy");
        return ;
    }
    Node *current = q->front;
    while(current) {
        printf("%i ",current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void) {

    Queue q;
    initQueue(&q);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    display(&q);

    return 0;
}