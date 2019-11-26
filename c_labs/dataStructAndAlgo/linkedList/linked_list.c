/**
 * @file linked_list.c
 * @brief linked list ops
 * @author passio91@163.com
 * @version 1.0
 * @date 2019-11-10
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct element {
	int num;
	int price;
};

struct node {
	struct element ele;
	struct node *next;
};

void print_list(struct node *list);
struct node *make_empty(struct node *list);
bool is_empty(struct node *list);
bool is_last(struct node *pos, struct node *list);
struct node *find(struct element ele, struct node *list);
void delete(struct element ele, struct node *list);
struct node *find_previous(struct element ele, struct node *list);
void insert(struct element ele, struct node *list, struct node *pos);
void delete_list(struct node *list);

struct node *header(struct node *list);
struct node *first(struct node *list);
struct node *advance(struct node *pos);
struct element retrieve(struct node *pos);

void print_list(struct node *list)
{
	struct node *pos = list;

	while (pos->next) {
		printf("(addr:0x%x, ele[%d,%d])->", (int)(list->next), list->next->ele.num, list->next->ele.price);
		pos = pos->next;
	}
	printf("NULL\n");
}
bool element_equal(struct element a, struct element b)
{
	if (a.num == b.num && a.price == b.price)
		return true;
	return false;
}

bool is_empty(struct node *list)
{
	if (list->next == NULL)
		return true;
	return false;
}

bool is_last(struct node *pos, struct node *list)
{
	if (pos != NULL && list != pos && pos->next == NULL)
		return true;
	return false;
}

struct node *find(struct element ele, struct node *list)
{
	struct node *pos = list;

	while (pos) {
		if (element_equal(pos->ele, ele))
			return pos;
		pos = pos->next;
	}
	return NULL;
}

struct node *find_previous(struct element ele, struct node *list)
{
	struct node *pos = list;

	while (pos->next) {
		if (element_equal(pos->next->ele, ele))
			return pos;
		pos = pos->next;
	}
	return NULL;
}

void delete(struct element ele, struct node *list)
{
	struct node *pre = find_previous(ele, list);
	struct node *cur = find(ele, list);

	if (pre == NULL || cur == NULL)
		return;
	pre->next = cur->next;
	free(cur);
}

struct node *make_empty(struct node *list)
{
	struct node *pos = list;

	while (pos->next)
		delete(pos->next->ele, list);

	return list;
}

void delete_list(struct node *list)
{
	struct node *pos = make_empty(list);

	free(list);
	list = NULL;
}
/**
 * @brief insert ele after pos
 *
 * @param ele
 * @param list
 * @param pos
 */
void insert(struct element ele, struct node *list, struct node *pos)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	if (new_node == NULL) {
		printf("inset malloc failed\n");
		return;
	}

	new_node->ele = ele;
	new_node->next = pos->next;
	pos->next = new_node;
}

int main(void)
{
	struct node *header = (struct node *)malloc(sizeof(struct node));
	struct element ele;

	if (header == NULL) {
		printf("malloc list failed\n");
		return -1;
	}

	header->next = NULL;		
	ele.num = 1;
	ele.price = 10;
	insert(ele, header, header);
	print_list(header);

	delete_list(header);
	printf("delete list success\n");

	return 0;
}
