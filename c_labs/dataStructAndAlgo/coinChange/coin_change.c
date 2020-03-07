#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VALUE 0x7FFFFFF0

int min(int a, int b)
{
	return a > b ? b : a;
}

int coin_change(int *coins, int coins_size, int amount)
{
	int *min_nums = NULL;
	int i, j;
	int ans;

	min_nums = (int *)malloc((amount + 1) * sizeof(int));
	if (min_nums == NULL) {
		printf("malloc failed\n");
		return -1;
	}
	for (i = 0; i <= amount; i++)
		min_nums[i] = MAX_VALUE;
	min_nums[0] = 0;

	for (i = 0; i <= amount; i++) {
		// min_nums[i] = min(min_nums[i - coins[0]] + 1, ..., min_nums[i - coins[amount - 1]] + 1);
		for (j = 0; j < coins_size; j++) {
			if (i - coins[j] >= 0 && min_nums[i - coins[j]] != MAX_VALUE)
				min_nums[i] = min(min_nums[i], min_nums[i - coins[j]] + 1);
		}
	}
	if (min_nums[amount] == MAX_VALUE)
		min_nums[amount] = -1;
	ans = min_nums[amount];
	free(min_nums);

	return ans;
}

int main(void)
{
	int coins[4] = { 2, 5, 7 };

	int min =  coin_change(coins, sizeof(coins) / sizeof(coins[0]), 27);
	printf("min is %d\n", min);

	return 0;
}
