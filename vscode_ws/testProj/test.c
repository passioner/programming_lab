#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_array(int *a, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(void)
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;

    for (i = 0; i < 9; i++) {
        swap(&(a[i]), &(a[i + 1]));
    }
    print_array(a, sizeof(a) / sizeof(a[0]));
    return 0;
}