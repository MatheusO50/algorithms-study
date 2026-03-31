#ifndef HEAP_H
#define HEAP_H
#define MAX 10

typedef struct MaxHeap {
    int *data , size , capacity;
} MaxHeap;

MaxHeap *createHeap(void);
void swap(int *value01 , int *value02);
void heapify_down(MaxHeap *mh , int root);
void insert_item(MaxHeap *mh , int data);
int delete_item(MaxHeap *mh);
void buildHeap(MaxHeap *mh);

#endif
