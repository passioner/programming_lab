#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int getLeftLowestIndex(int *heights, int heightsSize, int K)
{
	if (K == 0)
		return -1;

	int idx = K;
	for (int i = K - 1; i >= 0; i--) {
		if (heights[i] > heights[idx])
			break;
		if (heights[i] < heights[idx])
			idx = i;
	}
	if (idx != K)
		return idx;
	return -1;
}

int getRightLowestIndex(int *heights, int heightsSize, int K)
{
	if (K == heightsSize)
		return -1;

	int idx = K;
	for (int i = K + 1; i < heightsSize; i++) {
		if (heights[i] > heights[idx])
			break;
		if (heights[i] < heights[idx])
			idx = i;
	}
	if (idx != K)
		return idx;
	return -1;
}

void print_array(int *heights, int heightsSize)
{
	for (int i = 0; i < heightsSize; ++i) {
		printf("%d ", heights[i]);
	}
	printf("\n");
}
int* pourWater(int* heights, int heightsSize, int V, int K, int* returnSize)
{
	if (V == 0)
		return heights;
	*returnSize = heightsSize;

	int leftLowestIndex = getLeftLowestIndex(heights, heightsSize, K);
	if (leftLowestIndex != -1) {
		printf("leftLowestIndex = %d\n", leftLowestIndex);
		heights[leftLowestIndex]++;
		print_array(heights, heightsSize);
		return pourWater(heights, heightsSize, V - 1, K, returnSize);
	}
	int rightLowestIndex = getRightLowestIndex(heights, heightsSize, K);
	if (rightLowestIndex != -1) {
		printf("rightLowestIndex = %d\n", rightLowestIndex);
		heights[rightLowestIndex]++;
		print_array(heights, heightsSize);
		return pourWater(heights, heightsSize, V - 1, K, returnSize);
	}
	printf("mid idx = %d\n", K);
	heights[K]++;
	print_array(heights, heightsSize);
	return pourWater(heights, heightsSize, V - 1, K, returnSize);
}

int main()
{
	int heights[13] = {1,2,3,4,3,2,1,2,3,4,3,2,1};
	int V = 10;
	int K = 2;
	int *result = malloc(sizeof(int) * 13);
	int size;
	memset(result, 0, sizeof(int) * 13);
	result = pourWater(heights, 13, V, K,&size);

	print_array(heights, 13);
	return 0;
}
