// Marji Symonds
// Binary Search Tree 
// Smaller values are added to the left, and larger to right

#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	int value;
	struct tree *left;
	struct tree *right;
}tree_t;

void insert(tree_t **tree, int value);
tree_t * newLeaf(int value);
void printTree(tree_t *root);

// driver code to fill and then print tree
int main() 
{
	tree_t *root = NULL;
	
	insert(&root, 7);
	insert(&root, 4);
	insert(&root, 30);
	insert(&root, 12);
	insert(&root, 17);
	insert(&root, 70);
	insert(&root, 42);
	insert(&root, 3);
	insert(&root, 0);

 	printTree(root);

	return 0;
} 

void insert(tree_t **tree, int value) 
{
	// if tree is empty or we've found tbhe right spot, make new leaf with the value 
	if (*tree == NULL) {
		*tree = newLeaf(value);
    	return;
	}
	if (value < (*tree)->value)
	  insert(&(*tree)->left, value);
	else
		insert(&(*tree)->right, value);
}

// helper to set member values of a new leaf
tree_t * newLeaf(int value)
{
	tree_t *new_leaf;
	new_leaf = (tree_t *)malloc(sizeof(tree_t));
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	new_leaf->value = value;

	return new_leaf;
}

// helper to print tree in order
void printTree(tree_t *root)
{
  if (root == NULL)
    return;

  printTree(root->left);
  printf("%d \n", root->value);
  printTree(root->right);
}