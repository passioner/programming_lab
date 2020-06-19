#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int l, r, n;
int d[10] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
long t[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void init(void)
{
	scanf("%d %d %d", &l, &r, &n);
}

int get_len(int r)
{
	int len = 1;
	while (r / 10) {
		len++;
		r /= 10;
	}
	return len;
}
int calc(int r, int len)
{
	int ans = 0;
	if (len == 1) {
		return r >= n ? 1 : 0;
	}
	if (r / t[len -1] > n ) {
		ans += d[len];
		r = r - n * t[len - 1];
		ans += calc(r, get_len(r));
	} else {
		ans += d[len - 1];
	}
	return ans;
}


int main(void)
{
	int ans;
	init();

	ans = calc(r, get_len(r));
	printf("%d\n", ans);
	return 0;
}
