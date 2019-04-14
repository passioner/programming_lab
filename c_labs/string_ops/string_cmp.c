/**
 * @file string_cmp.c
 * @brief string compare func
 * @author passio91@163.com
 * @version 1.0
 * @date 2019-04-14
 */
#include <stdio.h>
#include <string.h>

/**
 * @brief string compare
 *
 * @param src: src string
 * @param dst: dst string
 *
 * @return : 0: equal
 *          -1: lenght is not equal
 *           i: index of the first different char
 */
int string_cmp(const char *src, const char *dst)
{
	unsigned int src_len = strlen(src);
	unsigned int dst_len = strlen(dst);
	unsigned int i;

	if (src_len != dst_len) {
		printf("length is not equal\n");
		return -1;
	}

	for (i = 0; i < src_len; i++) {
		if (src[i] != dst[i]) {
			printf("dst is different for src\n");
			return i;
		}
	}
	return 0;
}

/*
int main()
{
	int ret;
	const char *A = "my name is hanmeimei";
	const char *B = "my name is hanmeimEi";
	ret = string_cmp(A, B);
	printf("%s: ret=%d\n", __func__, ret);
	return 0;
}
*/
