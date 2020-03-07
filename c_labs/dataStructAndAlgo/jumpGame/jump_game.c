#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool can_jump(int *nums, int numSize)
{
	int i, j;
	int *f = NULL;

	f = (int *)malloc(numSize * sizeof(int));
	if (f == NULL) {
		printf("malloc failed\n");
		return false;
	}
	f[0] = 1;
	for (j = 1; j < numSize; j++) {
		f[j] = 0;
		for (i = 0; i < j; i++) {
			if (f[i] && (i + nums[i] >= j)) {
				f[j] = 1;
				break;
			}
		}
	}
	if (f[numSize - 1] == 1)
		return true;
	return false;
}

int main(void)
{
	int nums[5] = {2,3,1,1,4};
	bool res = false;

	res = can_jump(nums, sizeof(nums) / sizeof(nums[0]));
	printf("%s: res=%d\n", __func__, res);
	return 0;
}
