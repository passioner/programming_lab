#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int chess_board[8] = {0};
int n = 0;

/**
 * @brief print position of queen in chess board
 */
void print_chess_board()
{
	int i, j;
	
	printf("--solution %d--\n", n);
	n++;
	printf("[");
	for (i = 0; i < 8; i++)
		printf("%d ", chess_board[i]);
	printf("]\n");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
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
 *            row reach the boarder, means cur_row == 7
 *        the traversion of first row make sure to get all positions of queens.
 *        while every colum of cur_row is conflict with pre-row queens,
 *        there is no need to check cur_row++,
 *        switch to cur_row--, and calculate the next colum of (cur_row--).
 *
 * @param row
 */
void eight_queen(int row)
{
	int col;

	for (col = 0; col < 8; col++) {
		if (check_is_ok(row, col)) {
			chess_board[row] = col;
			if (row == 7) {
				print_chess_board();
				return;
			}
			eight_queen(row + 1);
		}
	}
}

int main(void)
{
	eight_queen(0);

	return 0;
}
