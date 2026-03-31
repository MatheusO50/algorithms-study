#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left , *right;
} Node;

Node *createNode(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->key = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void inOrder(Node *root) {
    if(root == NULL) return;

    inOrder(root->left);
    printf("%i ",root->key);
    inOrder(root->right);
}

void preOrder(Node *root) {
    if(root == NULL) return;

    printf("%i ",root->key);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%i ",root->key);
}

Node *findMind(Node *root) {
    if(root == NULL) return root;

    if(root->left != NULL) return findMind(root->left);
    return root;
}

Node *insert_item(Node *root , int data) {
    if(root == NULL) return createNode(data);
    if(data > root->key) root->right = insert_item(root->right,data);
    else if(data < root->key) root->left = insert_item(root->left,data);
    
    return root;
}

Node *delete_item(Node *root , int data) {
    if(root == NULL) return root;

    if(data > root->key) root->right = delete_item(root->right,data);
    else if(data < root->key) root->left = delete_item(root->left,data);
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if(root->left == NULL || root->right == NULL) {
            Node *temp;
            if(root->left == NULL) temp = root->right;
            else temp = root->left;

            free(root);
            return temp;
        } else {
            Node *temp = findMind(root->right);
            root->key = temp->key;
            root->right = delete_item(root->right,temp->key);
        }
    }
    return root;
}

int main(void) {

    Node *root = NULL;

    root = insert_item(root,10);
    root = insert_item(root,5);
    root = insert_item(root,20);
    root = insert_item(root,2);
    root = insert_item(root,1);
    root = insert_item(root,15);
    root = insert_item(root,30);
    inOrder(root);   

    return 0;
}