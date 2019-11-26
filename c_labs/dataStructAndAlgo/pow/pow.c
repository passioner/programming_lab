/**
 * @file pow.c
 * @brief calc pow of x
 * @author passio91@163.com
 * @version 1.0
 * @date 2019-11-10
 */

#include <stdio.h>

int self_pow(int x, int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n & 0x1)
		return self_pow(x * x, (n - 1) / 2) * x;
	else
		return self_pow(x * x, n / 2);
}

int main(void)
{
	printf("3 pow of 2 is %d\n", self_pow(2, 3));
	printf("4 pow of 3 is %d\n", self_pow(3, 4));
	return 0;
}
