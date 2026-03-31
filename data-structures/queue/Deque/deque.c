#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct Queue {
	int size;
	Node *front , *rear;
} Queue;

Node *createNode(int data) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void initQueue(Queue *q) {
	q->size = 0;
	q->front = q->rear = NULL;
}

int isEmtpy(Queue *q) {
	return q->front == NULL;
}

void insertFront(Queue *q , int data) {
	Node *new_node = createNode(data);
	if(isEmpty) q->front = q->rear = new_node;
	else {
		new_node->next = q->front;
		q->front->prev = new_node;
		q->front = new_node;
	}
	q->size++;
}

void insertRear(Queue *q , int data) {
	Node *new_node = createNode(data);
	if(isEmpty) q->front = q->rear = new_node;
	else {
		q->rear->next = new_node;
		new_node->prev = q->rear;
		q->rear = new_node;
	}
	q->size++;
}

int deleteFront(Queue *q) {
	if(isEmtpy) {
		printf("Queue is Empty");
		return -1;
	}
	Node *delNode = q->front;
	int dataValue = q->front->data;
	q->front = q->front->next;
	q->front->prev = NULL;
	free(delNode);
	q->size--;
	return dataValue;
}

int deleteRear(Queue *q) {
	if(isEmtpy) {
		printf("Queue is Empty");
		return -1;
	}
	Node *delNode = q->rear;
	int dataValue = q->rear->data;
	q->rear = q->rear->prev;
	q->rear->next = NULL;
	free(delNode);
	q->size--;
	return dataValue;
}

int peek(Queue *q) {
	if(isEmtpy(q)) {
		printf("Queue is Empty");
		return -1;
	}
	return q->front->data;
}

void display(Queue *q) {
	if(isEmpty(q)) return;
	Node *current = q->front;
	while(current) {
		printf("%i ",current->data);
		currrent = current->next;
	}
	printf("\n");
}

int main(void) {

	Queue q;
	initQueue(&q);
	
	insertFront(&q,2);	
	insertFront(&q,1);
	insertRear(&q,3);
	displa(&q);

	return 0;
}
