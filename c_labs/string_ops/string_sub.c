/**
 * @file string_sub.c
 * @brief get sub string
 * @author passio91@163.com
 * @version 1.0
 * @date 2019-04-14
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief get sub string
 *
 * @param str: src string
 * @param out: out string
 * @param start: start index
 * @param length: length of out string
 */
void string_sub(const char *str, char *out, const int start, const int length)
{
	int i;
	int len = strlen(str);
	if (start + length > len) {
		out = NULL;
		return;
	}
	for (i = start; i <= start + length; i++) {
		out[i - start] = str[i];
	}
	out[length] = '\0';
}

int main()
{
	const char *A = "my name is hanmeimei";
	char *p = NULL;
	p = (char *)malloc(5 + 1);
	string_sub(A, p, 3, 5);
	printf("%s: %s\n", __func__, p);
	return 0;
}
