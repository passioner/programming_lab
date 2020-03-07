#include <stdio.h>

/*
 * @brief check big/little endians
 *
 * 0x12345678
 * Addr:           0x01 0x02 0x03 0x04
 * Big endians:    0x78 0x56 0x34 0x12
 * Little endians: 0x12 0x34 0x56 0x78
 *
 * @return 
 */
int main(void)
{
	unsigned int num = 0x0;
	unsigned int *p = &num;

	*(char *)p = 0xff;

	if (num == 0xff)
		printf("little endians\n");
	if (num == 0xff000000)
		printf("big endians\n");
	return 0;
}
