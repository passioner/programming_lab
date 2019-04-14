#ifndef _MY_STRING_H_
#define _MY_STRING_H_

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
int string_cmp(const char *src, const char *dst);

/**
 * @brief get sub string
 *
 * @param str: src string
 * @param out: out string
 * @param start: start index
 * @param length: length of out string
 */
void string_sub(const char *str, char *out, const int start, const int length);

/**
 * @brief cut string into pieces, at delims
 *
 * @param str: src string
 * @param delims: delim element
 */
void string_tok(const char *str, const char *delims);
#endif
