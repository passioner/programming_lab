#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int *chess_board = NULL;
int solution_exist;
int solution_idx = 0;

/**
 * @brief print position of queen in chess board
 */
void print_chess_board(int size)
{
	int i, j;
	printf("--solution %d--\n", solution_idx);
	solution_idx++;
	printf("[");
	for (i = 0; i < size; i++)
		printf("%d ", chess_board[i]);
	printf("]\n");
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (chess_board[i] == j)
				printf("Q ");
			else
				printf("# ");
		}
		printf("\n");
	}
}
/**
 * @brief check whether current queen's position is conflict with pre-row queens
 *
 * @param row
 * @param col
 *
 * @return 
 */
bool check_is_ok(int row, int col)
{
	int i;

	if (row == 0)
		return true;

	for (i = 0; i < row; i++) {
		if (chess_board[i] == col)
			return false;
		if (i - row == chess_board[i] - col)
			return false;
		if (i - row == col - chess_board[i])
			return false;
	}
	return true;

}
/**
 * @brief chess_board[row] records queen's position for each row.
 *        for position [cur_row, cur_col], should check whether or not
 *        is conflict with pre-row queens.
 *        if conflict:
 *            for cur_row, cur_col++.
 *        if not conflict:
 *            update chess_board[cur_row], records cur_col. then cur_row++
 *            cur_row++, using recursion algorithm.
 *        recursion interruption:
 *            row reach the boarder, means cur_row == size - 1
 *        the traversion of first row make sure to get all positions of queens.
 *        while every colum of cur_row is conflict with pre-row queens,
 *        there is no need to check cur_row++,
 *        switch to cur_row--, and calculate the next colum of (cur_row--).
 *
 *        solution_exsit to record if there is solution for n x n chess_board
 *
 * @param row
 * @param size
 */
void eight_queen(int row, int size)
{
	int col;

	for (col = 0; col < size; col++) {

		if (check_is_ok(row, col)) {
			chess_board[row] = col;
			if (row == size - 1) {
				print_chess_board(size);
				solution_exist = 1;
				return;
			}
			eight_queen(row + 1, size);
		}
	}
}

int main(void)
{
	int n;

	printf("please input the size of chess_board\n");
	printf("example: input 8, means the size of chess_board is [8 x 8]\n");
	scanf("%d", &n);
	printf("the size of chess_board is [%d x %d]\n", n, n);
	chess_board = (int *)malloc(sizeof(int) * n);
	if (chess_board == NULL) {
		printf("malloc failed\n");
		return -1;
	}
	memset(chess_board, 0, sizeof(int) * n);
	eight_queen(0, n);
	if (!solution_exist)
		printf("there is no solution for chess board size %d\n", n);

	free(chess_board);

	return 0;
}
