#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int m_max(int a, int b)
{
	return a > b ? a : b;
}
bool is_unique(char *string, int *t)
{
	int i;
	int len;

	len = strlen(string);
	for (i = 0; i < len; i++) {
		if (1 << (string[i] - 'a') & *t)
			return false;
		*t |= 1 << (string[i] - 'a');
	}
	return true;
}

int dfs(char ** arr, int index, int *t, int arrSize)
{
	int max;
	int m = *t;
	int l1, l2;
	int cur_len;

	if (index == arrSize)
		return 0;

	cur_len = strlen(arr[index]);
	if (is_unique(arr[index], t)) {
		l1 = cur_len + dfs(arr, index + 1, t, arrSize);
		l2 = dfs(arr, index + 1, &m, arrSize);
		return m_max(l1, l2);
	}
	return dfs(arr, index + 1, &m, arrSize);
}

int violence_solution(char **arr, int arrSize)
{
	int n;
	int i;
	int j = 0;
	int tmp;
	int ans = 0;
	int len = 0;
	int *bit_map = NULL;

	bit_map = (int *)malloc(arrSize * sizeof(int));
	memset(bit_map, 0, arrSize * sizeof(int));

	for (i = 0; i < arrSize; i++) {
		tmp = 0;
		if (!is_unique(arr[i], &tmp))
			continue;
		bit_map[i] = tmp;
	}

	n = 1 << arrSize;
	for (i = 0; i < n; i++) {
		tmp = 0;
		for (j = 0; j < arrSize; j++) {
			if ((i >> j) & 0x1) {
				if (bit_map[j] == 0)
					break;
				if (tmp & bit_map[j]) {
					len = 0;
					break;
				} else {
					tmp |= bit_map[j];
					len += strlen(arr[j]);
				}
			}
		}
		if (ans < len)
			ans = len;
		len = 0;
	}
	free(bit_map);

	return ans;

}
int maxLength(char ** arr, int arrSize) {
	/* solutioin A: use dfs */
	int idx = 0;

	return dfs(arr, 0, &idx, arrSize);

	/* solution B: use violence */
	// return violence_solution(arr, arrSize);
}

int main(void) {
	char *arr[] = {"cha","r","act","ers"};
	int max_len = 0;

	max_len = maxLength(arr, 4);
	printf("%s: max_len=%d\n", __func__, max_len);
	return 0;
}
