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

void PreOrder(Node *root) {
	if(root == NULL) return;

	printf("%i ",root->key);
	PreOrder(root->left);
	PreOrder(root->right);
}

void PostOrder(Node *root) {
	if(root == NULL) return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%i ",root->key);
}

Node *search(Node *root , int data) {
	if(root == NULL) return root;
	Node *current = root;

	while(current && current->key != data) {
		if(data > current->key) current = current->right;
		else if(data < current->key) current = current->left;
	}

	return current;
}

Node *insert_item(Node *root , int data) {
	Node *new_node = createNode(data);
	if(root == NULL) return new_node;
	Node *parent = NULL , *current = root;

	while(current) {
		parent = current;
		if(data > current->key) current = current->right;
		else if(data < current->key) current = current->left;
		else {
			free(new_node);
			return root;
		}
	}

	if(data > parent->key) parent->right = new_node;
	else parent->left = new_node;

	return root;
}

Node *delete_item(Node *root , int data) {
	if(root == NULL) return root;

	Node *parent = NULL , *current = root;
	while(current != NULL && current->key != data) {
		parent = current;
		if(data > current->key) current = current->right;
		else current = current->left;
	}

	if(current == NULL) return root;

	if(current->right != NULL && current->left != NULL) {
		Node *parentPrev = current , *prev = current->right;
		while(prev->left) {
			parentPrev = prev;
			prev = prev->left;
		}

		current->key = prev->key;
		current = prev;
		parent = parentPrev;
	}

	Node *temp;
	if(current->left != NULL) temp = current->left;
	else temp = current->right;

	if(parent == NULL) {
		free(current);
		return temp;
	}

	if(parent->left == current) parent->left = temp;
	else parent->right = temp;

	free(current);
	return root;
}

int main(void) {

	Node *root = NULL;

	root = insert_item(root,50);
	root = insert_item(root,40);
	root = insert_item(root,30);
	root = insert_item(root,20);
	root = insert_item(root,10);
	root = delete_item(root,30);
	inOrder(root);

	return 0;
}