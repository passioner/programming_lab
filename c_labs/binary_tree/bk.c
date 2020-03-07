#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
	int val;
	int cnt;
	struct node *left;
	struct node *right;
};

struct node *insert(int x, struct node *root)
{
	if (root == NULL) {
		root = (struct node *)malloc(sizeof(struct node));
		if (root == NULL) {
			printf("malloc failed\n");
			return NULL;
		}
		memset(root, 0, sizeof(struct node));
	} else if (x < root->val) {
		root->left = insert(x, root->left);
	} else if (x > root->val) {
		root->right = insert(x, root->right);
	} else {
		root->cnt++;
	}
	return root;
}

struct node *find(int x, struct node *root)
{
	if (root == NULL)
		return NULL;
	if (x < root->val)
		return find(x, root->left);
	if (x > root->val)
		return find(x, root->right);
	return root;
}

struct node *make_empty(struct node *root)
{
	if (root != NULL) {
		make_empty(root->left);
		make_empty(root->right);
		free(root);
	}
	return NULL;
}
