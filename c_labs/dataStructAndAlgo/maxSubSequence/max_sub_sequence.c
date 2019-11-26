/**
 * @file max_sub_sequence.c
 * @brief get max sum of sub sequence
 *        we asume the min max value is zero
 * @author passio91@163.com
 * @version 1.0
 * @date 2019-11-09
 */

#include <stdio.h>
#include <time.h>
#define array_size(array)  sizeof(array)/sizeof((array)[0])

int self_max(int a, int b)
{
	return a > b ? a : b;
}
int get_max_n3(int *array, int len)
{
	int i,j,k;
	int sum = 0;
	int max = 0;

	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			sum = 0;
			for (k = i; k < j; k++) {
				sum += array[k];
			}
			if (sum > max)
				max = sum;
		}
	}

	return max;
}

int get_max_n2(int *array, int len)
{
	int i,j;
	int sum = 0;
	int max = 0;

	for (i = 0; i < len; i++) {
		sum = 0;
		for (j = i; j < len; j++) {
			sum += array[j];
			if (sum > max)
				max = sum;
		}
	}

	return max;
}

int get_max_nlogn(int *array, int left, int right)
{
	int max_left, max_right, max_border;
	int max_border_left = 0;
	int max_border_right = 0;
	int sum_border_left = 0;
	int sum_border_right = 0;
	int core, i;

	if (left == right)
		return array[left];

	core = (left + right) / 2;

	max_left = get_max_nlogn(array, left, core);
	max_right = get_max_nlogn(array, core + 1, right);

	for (i = core; i >= left; i--) {
		sum_border_left += array[i];
		if (sum_border_left > max_border_left)
			max_border_left = sum_border_left;
	}
	for (i = core + 1; i <= right; i++) {
		sum_border_right += array[i];
		if (sum_border_right > max_border_right)
			max_border_right = sum_border_right;
	}
	max_border = max_border_left + max_border_right;

	return self_max(self_max(max_left, max_right), max_border);
}

int get_max_n1(int *array, int len)
{
	int i;
	int sum = 0;
	int max = 0;

	for (i = 0; i < len; i++) {
		sum += array[i];
		if (sum > max)
			max = sum;
		else if (sum < 0)
			sum = 0;
	}

	return max;
}

int main(void)
{
	int array[] = { -2, 11, -4, 13, -5, -2, 12, 43, -12, -43, 23, -9, 4, 1 , 13, -42};
	//int array[] = { -2, -11, -4, -13, 5, -2, -12, -43, -12, -43, -23, -9, -4, -1 , -13, -42};
	int max;
	time_t t1,t2;

	printf("sizeof array is %lu\n", array_size(array));
	time(&t1);
	max = get_max_n3(array, array_size(array));
	time(&t2);
	printf("n3 max is %d, time consumed %f\n", max, difftime(t2, t1));

	time(&t1);
	max = get_max_n2(array, array_size(array));
	time(&t2);
	printf("n2 max is %d, time consumed %f\n", max, difftime(t2, t1));
	
	time(&t1);
	max = get_max_nlogn(array, 0, array_size(array) -1);
	time(&t2);
	printf("nlogn max is %d, time consumed %f\n", max, difftime(t2, t1));

	time(&t1);
	max = get_max_n1(array, array_size(array));
	time(&t2);
	printf("n1 max is %d, time consumed %f\n", max, difftime(t2, t1));
	return 0;
}
