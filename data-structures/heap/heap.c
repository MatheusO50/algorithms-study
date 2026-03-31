#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

MaxHeap *createHeap(void) {
    MaxHeap *mh = (MaxHeap*)malloc(sizeof(MaxHeap));
    mh->capacity = MAX;
    mh->data = (int*)malloc(sizeof(int) * mh->capacity);
    mh->size = 0;
    return mh;
}

void swap(int *value01 , int *value02) {
    int temp = *value01;
    *value01 = *value02;
    *value02 = temp;
}

void heapify_up(MaxHeap *mh , int index) {
    int parent = (index - 1) / 2;
    if(index > 0 && mh->data[index] > mh->data[parent]) {
        swap(&mh->data[index],&mh->data[parent]);    
    } else return;
    heapify_up(mh,parent);
}

void heapify_down(MaxHeap *mh , int root) {
    int parent = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if(left < mh->size && mh->data[left] > mh->data[parent]) {
        parent = left;
    }
    if(right < mh->size && mh->data[right] > mh->data[parent]) {
        parent = right;
    }
    
    if(parent == root) return;

    swap(&mh->data[root],&mh->data[parent]);
    heapify_down(mh,parent);
}

void insert_item(MaxHeap *mh , int data) {
    if(mh->size == mh->capacity) {
        printf("Heap is Full");
        return;
    }

    mh->data[mh->size++] = data;
    heapify_up(mh,mh->size - 1);
}

int delete_item(MaxHeap *mh) {
    if(mh->size == 0) {
        printf("Heap is Empty");
        return -1;
    }

    if(mh->size == 1) {
        mh->size--;
        return mh->data[0];
    }

    int first_item = mh->data[0] , last_item = mh->data[--mh->size];
    
    if(mh->size > 1) {
        mh->data[0] = last_item;
        heapify_down(mh,0);
    }

    return first_item;
}

void buildHeap(MaxHeap *mh) {
    int length = mh->size;
    for(int i = (length - 1) / 2 ; i >= 0 ; i--) heapify_down(mh,i);
}

int main(void) {

    MaxHeap *heap = createHeap();

    heap->data[0] = 10 , heap->data[1] = 12 , heap->data[2] = 20 , heap->data[3] = 30 , heap->data[4] = 40;
    heap->size = 5;
    
    buildHeap(heap);

    for(int i = 0 ; i < heap->size ; i++) {
        printf("%i ",heap->data[i]);
    }
    printf("\n");

    return 0;
}




