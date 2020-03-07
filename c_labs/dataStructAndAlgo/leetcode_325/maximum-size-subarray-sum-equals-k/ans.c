#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max_sub_array_len(int *nums, int num_size, int k)
{
	int max_len = 0;
	int i, j;
	int sum = 0;
		
	for (i = 0; i < num_size; i++) {
		sum = 0;
		for (j = i; j >=0; j--) {
			sum += nums[j];
			if (sum == k && (max_len < i - j + 1))
				max_len = i - j + 1;
		}
	}
	return max_len;
}

int main()
{
	/* int nums[4] = {-2, -1, 2, 1}; */
	int nums[5] = {1, -1, 5, -2, 3};
	int k = 3;
	int out = max_sub_array_len(nums, 5, k);
	printf("ans is %d\n", out);
}
