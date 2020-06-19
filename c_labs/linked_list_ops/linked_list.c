#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} link_list;

link_list * creat(n)
{
	link_list *head, *node, *end;
	head = (link_list *)malloc(sizeof(link_list));
	end = head;
	int i;
	for (i = 0; i < n; i++) {
		node = (link_list *)malloc(sizeof(link_list));
		/* grow from head */
		head->next = node;
		node->next = end;

		/* grow from end*/
		//end->next = node;
		//end = node;
	}
	end->next = NULL;
	return head;
}

/**
 * @brief insert new node after pos;
 * for example:
 *     pos = 1, new list will be
 *     head->second->new_node->...
 *
 * @param head: list head
 * @param pos: new node to be posited
 */
void insert(link_list *head, unsigned int pos)
{
	if (head == NULL)
		return;
	link_list *t = head;
	unsigned int i = 0;
	while (i < pos && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		link_list *in = (link_list *)malloc(sizeof(link_list));
		in->next = t->next;
		t->next = in;
	} else {
		printf("node is not exist\n");
	}
}

void print_list(link_list *head)
{
	link_list *t = head;
	while(t != NULL) {
		printf("%s: val=%d\n", __func__, t->val);
		t = t->next;
	}
}
