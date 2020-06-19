#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int getWordIdx(char c)
{
	int wordIdx;

	if (c >= 'a' && c <= 'z') {
		wordIdx = c - 'a';
	} else {
		wordIdx = c - 'A' + 26;
	}
	return wordIdx;
}

bool isEmpty(int *nums, int len)
{
	for (int i = 0; i < len; i++) {
		if (nums[i] != 0) {
			return false;
		}
	}
	return true;
}

void clearNums(int *nums, int len)
{
	for (int i = 0; i < len; i++) {
		nums[i] = 0;
	}
}

int *GetNum(char *word, int *returnSize)
{
	int len = strlen(word);
	int top = -1;
	int bukket[52] = {0};
	int letterPool[52] = {0};
	int wordIdx = 0;

	*returnSize = 0;

	for (int i = 0; i < len; i++) {
		wordIdx = getWordIdx(word[i]);
		bukket[wordIdx]++;
	}
	int *result = (int *)malloc(sizeof(int) * 100000);

	for (int i = 0; i < len; i++) {
		wordIdx = getWordIdx(word[i]);
		/* for a new i, bukket[wordIdx] will never be zero */
		if (top == -1 && bukket[wordIdx] == 1) {
			bukket[wordIdx]--;
			result[*returnSize] = 1;
			(*returnSize)++;
			top = -1;
			clearNums(letterPool, 52);
			continue;
		}
		if (top == -1 && bukket[wordIdx] != 1) {
			bukket[wordIdx]--;
			top++;
			letterPool[wordIdx] = 1;
			continue;
		}
		if (top != -1 && bukket[wordIdx] == 1) {
			if (letterPool[wordIdx] == 0) {
				top++;
			} else {
				letterPool[wordIdx] = 0;
				top++;
				if (isEmpty(letterPool, 52)) {
					result[*returnSize] = top + 1;
					(*returnSize)++;
					top = -1;
					clearNums(letterPool, 52);
				}
			}
			bukket[wordIdx]--;
			continue;
		}
		if (top != -1 && bukket[wordIdx] != 1) {
			if (letterPool[wordIdx] == 0) {
				letterPool[wordIdx] = 1;
			}
			top++;
			bukket[wordIdx]--;
			continue;
		}
	}
	return result;
}

int main(void)
{
	/* char *word = "leetcode"; */
	char *word = "ijbbacefah";
	/* char *word = "Kick"; */
	int returnSize = 0;
	int *result = NULL;

	result = GetNum(word, &returnSize);
	printf("returnSize = %d\n", returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("val = %d\n", result[i]);
	}
	free(result);
	return 0;
}
