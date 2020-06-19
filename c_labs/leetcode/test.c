#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int myComp(const void *a, const void *b)
{
    char x = *(char *)a;
    char y = *(char *)b;
    if (x > y) {
        return 1;
    }
    if (x == y) {
        return 0;
    }
    return -1;
}

char *sortStr(char *str)
{
    qsort(str, strlen(str), sizeof(char), myComp);
    return str;
}
typedef struct Node {
    char *key;
    char *val;
    struct Node *next;
} Node;

typedef struct hashMap {
    Node *hash;
    struct hashMap *next;
} hashMap;

Node *newNode(char *key, char *val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = sortStr(key);
    p->val = val;
    p->next = NULL;
    return p;
}

hashMap *newHashMapNode(Node *p)
{
    hashMap *q = (hashMap *)malloc(sizeof(hashMap));
    q->hash = newNode(" ", " ");
    q->next = p;
    return q;
}

hashMap *hashMapInit(void)
{
    hashMap *obj = (hashMap *)malloc(sizeof(hashMap));
    obj->hash = newNode(" ", " ");
    obj->next = NULL;
    return obj;
}
void listAdd(Node *head, char *key, char *val)
{
    Node *iter = head;
    while (iter->next != NULL) {
        if (strcmp(iter->next->val, val) == 0) {
            return;
        }
        iter = iter->next;
    }
    iter->next = newNode(key, val);
}

void hashMapAdd(hashMap *obj, char *key, char *val)
{
    hashMap *iter = obj;
    while (iter->next != NULL) {
        if (strcmp(iter->next->hash->next->key, sortStr(key)) == 0) {
            listAdd(iter->next->hash, key, val);
            return;
        }
        iter = iter->next;
    }
    iter->next = newHashMapNode(newNode(key, val));
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    hashMap *obj = hashMapInit();
    for (int i = 0; i < strsSize; i++) {
        hashMapAdd(obj, strs[i], strs[i]);
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    hashMap *iter = obj;
    Node *p = NULL;
    int retSize = 0;
    while (iter->next != NULL) {
        int count = 0;
        p = iter->next->hash;
        while (p->next != NULL) {
            count++;
            p = p->next;
        }
        (*returnColumnSizes)[retSize] = count;
        retSize++;
        iter = iter->next;
    }
    *returnSize = retSize;
    char ***retArray = (char ***)malloc(sizeof(char **) * retSize);
    printf("retSize=%d\n", retSize);
    for (int i = 0; i < retSize; i++) {
        printf("retColSize=%d\n", (*returnColumnSizes)[i]);
        retArray[i] = (char **)malloc(sizeof(char *) * ((*returnColumnSizes)[i]));
    }
    iter = obj;
    int i = 0;
    while (iter->next != NULL) {
        int count = 0;
        p = iter->next->hash;
        while (p->next != NULL) {
            retArray[i][count] = p->next->val;
            count++;
            p = p->next;
        }
        i++;
        iter = iter->next;
    }
    return retArray;
}



int main(void) {
	// ["eat","tea","tan","ate","nat","bat"]
	char *a = "eat";
	char *b = "tea";
	char *c = "tan";
	char *d = "ate";
	char *e = "nat";
	char *f = "bat";
	char **array = (char **)malloc(sizeof(char *) * 6);
	array[0] = a;
	array[1] = b;
	array[2] = c;
	array[3] = d;
	array[4] = e;
	array[5] = f;
	int n;
	int *m = NULL;
	groupAnagrams(array, 6, &n, &m);
 
  return 0;
}
