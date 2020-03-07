#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEBUG
struct player {
	int *card_buff;
	int idx_start;
	int idx_end;
	int size;
	int is_empty;
};

int get_cnt(int s, int e, int size)
{
	if (s <= e)
		return e - s + 1;
	return s + size - e + 1;
}

void player_init(struct player *player, int n)
{
	player->card_buff = (int *)malloc(sizeof(int) * n * 2);
	memset(player->card_buff, 0, sizeof(int) * n * 2);
	player->idx_start = 0;
	player->idx_end = 0;
	player->size = n * 2;
	player->is_empty = 1;
}

void card_buff_clear(struct player *player)
{
	int i;

	player->idx_start = 0;
	player->idx_end = 0;
	player->is_empty = 1;

	for (i = 0; i < player->size; i++)
		player->card_buff[i] = 0;
}

bool is_game_over(struct player *mm, struct player *xx, int *winner)
{
	if (mm->is_empty) {
		*winner = 2;
		return true;
	}
	if (xx->is_empty) {
		*winner = 1;
		return true;
	}
	*winner = 0;
	return false;
}

void card_buff_append(struct player *player, int *content, int len)
{
	int idx = player->idx_end;
	int size = player->size;
	int i;

	if (player->is_empty) {
		player->idx_start = (player->idx_start + 1) % size;
		player->is_empty = 0;
	}

	for (i = 1; i <= len; i++)
		player->card_buff[(idx + i) % size] = content[i - 1];
	player->idx_end = (idx + len) % size;
}

void card_buff_delete(struct player *player, int pos, int len)
{
	int s = player->idx_start;
	int e = player->idx_end;
	int size = player->size;
	int i;

	for (i = 0; i < len; i++)
		player->card_buff[(pos + i) % size] = 0;
	if (len == get_cnt(s, e, size)) {
		card_buff_clear(player);
		return;
	}
	if (pos == s) // delete from ether head or tail
		player->idx_start = (s + len) % size;
	else
		player->idx_end = (pos + size -1) % size;
	if (player->idx_start == player->idx_end && player->card_buff[player->idx_start] == 0)
		player->is_empty = 1;
}

void post_card(struct player *player, struct player *desk)
{
	int idx = player->idx_start;

	card_buff_append(desk, &(player->card_buff[idx]), 1);
	card_buff_delete(player, idx, 1);
}

void update_card_buff(struct player *player, struct player *desk)
{
	int s = desk->idx_start;
	int e = desk->idx_end;
	int size = player->size;
	int i;

	for (i = s; ;i++, i %= size) {
		if (i == e)
			break;
		if (desk->card_buff[i] == desk->card_buff[e])
			break;
	}
	if (i == e) {
		printf("no need update buff\nn");
		return;
	}
	printf("update card buff\n");
	card_buff_append(player, &(desk->card_buff[i]), get_cnt(i, e, size));
	card_buff_delete(desk, i, get_cnt(i, e, size));
}

void print_card_buff(struct player *player)
{
	int i;
	int s = player->idx_start;
	int e = player->idx_end;
	int size = player->size;

	if (player->is_empty)
		printf("\n");

	for (i = s; ; i++, i %= size) {
		if (i == e) {
			printf("%d\n", player->card_buff[i]);
			break;
		}
		printf("%d ", player->card_buff[i]);
	}
}

int main()
{
	struct player mm;
	struct player xx;
	struct player desk;
	int n;
	int i;
	int tmp;
	int rounds = 0;
	int winner = 0;

	scanf("%d", &n);

	player_init(&mm, n);
	player_init(&xx, n);
	player_init(&desk, n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		mm.card_buff[i] = tmp;
	}
	mm.idx_end = n - 1;
	mm.is_empty = 0;

	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		xx.card_buff[i] = tmp;
	}
	xx.idx_end = n - 1;
	xx.is_empty = 0;

	while (!is_game_over(&mm, &xx, &winner)) {
		if (rounds % 2 == 0) {
			// mm's turn
			// mm post card
			post_card(&mm, &desk);
			// update player card buff
			update_card_buff(&mm, &desk);
		} else {
			// xx's turn
			// xx post card
			post_card(&xx, &desk);
			// update player card buff
			update_card_buff(&xx, &desk);
		}
#ifdef DEBUG
		printf("rounds: %d\n", rounds);
		printf("\tmm: s = %d, e = %d\n", mm.idx_start, mm.idx_end);
		printf("\t\t");
		print_card_buff(&mm);
		printf("\txx: s = %d, e = %d\n", xx.idx_start, xx.idx_end);
		printf("\t\t");
		print_card_buff(&xx);
		printf("\tdesk: s = %d, e = %d\n", desk.idx_start, desk.idx_end);
		printf("\t\t");
		print_card_buff(&desk);
		rounds++;
		printf("--------------\n");
#endif
	}
	printf("%d\n", rounds);
	if (winner == 1) {
		printf("mm\n");
		print_card_buff(&mm);
	}
	if (winner == 2) {
		printf("mm\n");
		print_card_buff(&xx);
	}
}
