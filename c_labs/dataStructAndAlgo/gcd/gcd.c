/**
 * @file gcd.c
 * @brief calculate greatest common dividor
 *        calculate leaset common multiple
 * @author passio91@163.com
 * @version 1.0
 * @date 2019-11-10
 */

#include <stdio.h>

int calc_gcd(int m, int n)
{
	int a, b, tmp;

	if (m >= n) {
		a = m;
		b = n;
	} else {
		a = n;
		b = m;
	}

	while (b > 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int calc_lcm(int m, int n)
{
	int gcd = calc_gcd(m, n);

	return m * n / gcd;
}

int main(void)
{
	printf("gcd for 10 3 is %d, lcm is %d\n", calc_gcd(10, 3), calc_lcm(10, 3));
	printf("gcd for 12 7 is %d, lcm is %d\n", calc_gcd(12, 7), calc_lcm(12, 7));
	printf("gcd for 12 3 is %d, lcm is %d\n", calc_gcd(12, 3), calc_lcm(12, 3));
	return 0;
}
