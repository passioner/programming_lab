#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int unique_paths(int m, int n)
{
	int i, j;
	int **roadmap = NULL;

	roadmap = (int **)malloc(sizeof(int *) * m);
	if (roadmap == NULL) {
		printf("malloc failed\n");
		return 0;
	}
	for (i = 0; i < m; i++) {
		roadmap[i] = (int *)malloc(sizeof(int) * n);
		if (roadmap[i] == NULL) {
			printf("malloc failed\n");
			return 0;
		}
	}
	/* addr is not serial, can't use memset(roadmap, 0, sizeof(int) * m * n) */
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			roadmap[i][j] = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				roadmap[i][j] = 1;
				continue;
			}
			roadmap[i][j] = roadmap[i][j - 1] + roadmap[i - 1][j];
		}
	}
	return roadmap[m - 1][n - 1];
}

int main(void)
{
	int result;

	result = unique_paths(3, 2);
	printf("%s: result=%d\n", __func__, result);
	return 0;
}
