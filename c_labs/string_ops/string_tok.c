/**
 * @file string_tok.c
 * @brief cut string into pieces, with delims
 * @author passio91@163.com
 * @version 1.0
 * @date 2019-04-14
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_string.h"

/**
 * @brief element of delim
 */
const char delim[] = {',', '.', '.', ' ', '!'};

/**
 * @brief judge wheter a character is delim element or not.
 *
 * @param c
 * @param delims
 *
 * @return 
 */
bool is_delim(const char c, const char *delims)
{
	int i;
	int len = sizeof(delim);
	for (i = 0; i < len; i++) {
		if (c == delim[i]) {
			return true;
		}
	}
	return false;
}

/**
 * @brief cut string into pieces, at delims
 *
 * @param str: src string
 * @param delims: delim element
 */
void string_tok(const char *str, const char *delims)
{
	int i;
	int len = strlen(str);
	int word_len = 0;
	int word_start_curse= 0;
	char *p = NULL;

	for (i = 0; i < len; i++) {
		if (is_delim(str[i], delims)) {
			if (word_len == 0) {
				word_start_curse += 1;
				continue;
			}
			p = (char *)malloc(word_len + 1);
			string_sub(str, p, word_start_curse, word_len);
			word_start_curse += word_len + 1;
			word_len = 0;
			printf("%s: %s\n", __func__, p);
			free(p);
			p = NULL;
		} else {
			word_len++;
		}
	}
}

/*
int main()
{
	const char *A = "w shi hanmeimei, , ni  shi shei a ?";
	string_tok(A, delim);
	return 0;
}
*/
