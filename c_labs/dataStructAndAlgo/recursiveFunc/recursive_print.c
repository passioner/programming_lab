/**
 * @file recursive_print.c
 * @brief print int/string in positive and negative sequence
 * @author passio91@163.com
 * @version 
 * @date 2019-11-09
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_digital(int n)
{
	printf("%d", n);
}

void print_char(char c)
{
	printf("%c", c);
}

void print_positive_int(int n)
{
	if (n > 10)
		print_positive_int(n / 10);
	print_digital(n % 10);
}

void print_negative_int(int n)
{
	if (n / 10 == 0) {
		print_digital(n);
		return;
	}
	print_digital(n % 10);
	print_negative_int(n / 10);
}

void print_positive_string(char *string, int length)
{
	char c;
	char *s = string;

	if (length == 1) {
		c = s[0];
		print_char(c);
		return;
	}

	c = s[0];
	print_char(c);
	s++;
	print_positive_string(s, length - 1);
}

void print_negative_string(char *string, int length)
{
	char *s = string;
	char c;

	if (length > 1) {
		s++;
		print_negative_string(s, length - 1);
	}
	c = string[0];
	print_char(c);
}
int main(void)
{
	int input;
	char string[20];
	int len;

	printf("please input a inter data\n");
	scanf("%d", &input);
	print_positive_int(input);
	printf("\n");
	print_negative_int(input);
	printf("\n");

	printf("please input a string\n");
	scanf("%s", string);
	len = strlen(string);
	print_positive_string(string, len);
	printf("\n");
	print_negative_string(string, len);
	printf("\n");
	return 0;
}
