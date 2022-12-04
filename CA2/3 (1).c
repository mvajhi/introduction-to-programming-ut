#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define NUM_CARD 44
#define NUM_TYPE_CARD 4
#define NUM_CARD_PER_TYPE 11
#define NUM_CARD_PER_DECK 11
#define MAX_CARD_POWER 10
#define MIN_CARD_POWER 0
#define TMP_CARD -1

#define NUM_PLAYER 4
#define NUM_TEAMS 2
#define NEXT_TEAMMATE 2
#define PLAYER_STARTER 0
#define USER_PLAYER_NUM 0

#define NUM_SET 2
#define WIN_SCORE 1
#define FIRST_SCORE 0
#define FIRST_SET_SCORE 0
#define SCORE_TO_WIN_SET 6
#define SET_WIN_SCORE 1
#define DOUBLE_SET_WIN_SCORE 2

#define CARD_SPEARD_R1 5
#define CARD_SPEARD_R2 4
#define CARD_SPEARD_R3 2

#define LENGTH 50
#define WIDTH 10
#define SPACE_FOR_CARD 5

#define True 1
#define False 0

int print_table(int score[NUM_TEAMS], int set_win[NUM_TEAMS], int card_played[NUM_PLAYER], int user_deck[NUM_CARD_PER_DECK], int bakhsh_name);
int start_game(int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int *bakhsh_name, int player_starter, int score[NUM_TEAMS], int set_win[NUM_TEAMS]);
void shuffle_card(int *card);
int card_speard(int card[NUM_CARD], int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int num_speard);
int enter_bakhsh_name(int player_starter, int deck[CARD_SPEARD_R1], int score[NUM_TEAMS], int set_win[NUM_TEAMS], int card_played[NUM_PLAYER], int bakhsh_name);
int while_game(int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int bakhsh_name, int *player_starter, int score[NUM_TEAMS], int set_win[NUM_TEAMS]);
int player(int deck[NUM_CARD_PER_DECK], int first_card);
int is_buffer_free();
int bot(int deck[NUM_CARD_PER_DECK], int first_card, int bakhsh_name, int card_played[NUM_PLAYER], int turn);
int is_played_biggest_card(int card_played[NUM_PLAYER], int turn);
int who_is_winner(int card_played[NUM_PLAYER], int bakhsh_name, int *player_starter, int score[NUM_TEAMS]);
int end_game(int score[NUM_TEAMS], int set_win[NUM_TEAMS], int user_deck[], int bakhsh_name);
int repeat_print(int count, char txt[]);
int repeat_row(int row, char symbole[], char space[]);
int print_card(int card);
int finale_end(int set_win[NUM_TEAMS]);



int main(void)
{
	char card_name[NUM_TYPE_CARD] = {'A', 'B', 'C', 'D'};
	int player_starter = PLAYER_STARTER;
	int set_win[NUM_TEAMS] = {FIRST_SET_SCORE};

	for (int i = 0; i < NUM_SET; i++)
	{
		int decks[NUM_PLAYER][NUM_CARD_PER_DECK];
		int bakhsh_name = TMP_CARD;
		int score[NUM_TEAMS] = {FIRST_SCORE, FIRST_SCORE};

		for (int k = 0; k < NUM_PLAYER; k++)
		{
			for (int j = 0; j < NUM_CARD_PER_DECK; j++)
			{
				decks[k][j] = TMP_CARD;
			}
		}

		start_game(decks, &bakhsh_name, player_starter, score, set_win);
		while_game(decks, bakhsh_name, &player_starter, score, set_win);
		end_game(score, set_win, decks[USER_PLAYER_NUM], bakhsh_name);
	}

	finale_end(set_win);

	return 0;
}

int start_game(int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int *bakhsh_name, int player_starter, int score[NUM_TEAMS], int set_win[NUM_TEAMS])
{
	int card[NUM_CARD] = {0};
	shuffle_card(card);

	card_speard(card, decks, CARD_SPEARD_R1);
	int tmp_arr[NUM_PLAYER] = {TMP_CARD, TMP_CARD, TMP_CARD, TMP_CARD};
	*bakhsh_name = enter_bakhsh_name(player_starter, decks[player_starter], score, set_win, tmp_arr, *bakhsh_name);
	card_speard(card, decks, CARD_SPEARD_R2);
	card_speard(card, decks, CARD_SPEARD_R3);

	return 1;
}

void shuffle_card(int *card)
{
	int i, r, temp;
	for (temp = 0, i = 0; temp < 44; i++, temp++)
		card[temp] = i;
	srand(time(NULL));
	for (i = 43; i > 0; i--)
	{
		r = rand() % i;
		temp = card[i];
		card[i] = card[r];
		card[r] = temp;
	}
}

int card_speard(int card[NUM_CARD], int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int num_speard)
{
	for (int i = 0; i < NUM_PLAYER; i++)
	{
		/*find start point in card arr*/
		int start_point = 0;
		for (; card[start_point] == TMP_CARD; start_point++)
		{
		}

		int deck_start_point = 0;
		for (; decks[i][deck_start_point] != TMP_CARD; deck_start_point++)
		{
		}

		for (int j = 0; j < num_speard; j++)
		{
			decks[i][deck_start_point + j] = card[start_point + j];
			card[start_point + j] = TMP_CARD;
		}
	}

	return 1;
}

int enter_bakhsh_name(int player_starter, int deck[CARD_SPEARD_R1], int score[NUM_TEAMS], int set_win[NUM_TEAMS], int card_played[NUM_PLAYER], int bakhsh_name)
{
	if (player_starter == USER_PLAYER_NUM)
	{
		char input = 'a';
		int is_get_input = False;

		while (!is_get_input)
		{
			int tmp_arr[NUM_PLAYER] = {TMP_CARD, TMP_CARD, TMP_CARD, TMP_CARD};
			print_table(score, set_win, tmp_arr, deck, bakhsh_name);
			is_get_input = True;

			printf("Enter bakhsh name: ");
			scanf("%c", &input);

			if (is_buffer_free() == False || !(('a' <= input && input <= 'd') || ('A' <= input && input <= 'D')))
			{
				printf("Try again, invalid input\n");
				is_get_input = False;
			}
		}
		return (int)(toupper(input) - 'A');
	}

	else
	{
		int counter_card_per_type[NUM_TYPE_CARD] = {0};
		for (int i = 0; i < CARD_SPEARD_R1; i++)
		{
			if (deck[i] != TMP_CARD)
			{
				counter_card_per_type[deck[i] / NUM_CARD_PER_TYPE]++;
			}
		}

		int most_type_card = 0;
		for (int i = 0; i < NUM_TYPE_CARD; i++)
		{
			if (counter_card_per_type[i] > counter_card_per_type[most_type_card])
			{
				most_type_card = i;
			}
		}

		return most_type_card;
	}
}

int while_game(int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int bakhsh_name, int *player_starter, int score[NUM_TEAMS], int set_win[NUM_TEAMS])
{
	while (score[0] != SCORE_TO_WIN_SET && score[1] != SCORE_TO_WIN_SET)
	{
		int card_played[NUM_PLAYER] = {TMP_CARD, TMP_CARD, TMP_CARD, TMP_CARD};
		int first_card = TMP_CARD;

		for (int i = 0; i < NUM_PLAYER; i++)
		{
			int turn = (*player_starter + i) % NUM_PLAYER;


			if (turn == USER_PLAYER_NUM)
			{
				print_table(score, set_win, card_played, decks[USER_PLAYER_NUM], bakhsh_name);
				card_played[turn] = player(decks[USER_PLAYER_NUM], first_card);
			}
			else
			{
				card_played[turn] = bot(decks[turn], first_card, bakhsh_name, card_played, turn);
			}

			if (first_card == TMP_CARD)
			{
				first_card = card_played[turn];
			}
		}

		int winer_team_num = who_is_winner(card_played, bakhsh_name, player_starter, score);
		print_table(score, set_win, card_played, decks[USER_PLAYER_NUM], bakhsh_name);
		printf("team %i get this round.\n", winer_team_num);
		printf("press ENTER to next round\n");
		getchar();
	}
	return 1;
}

int player(int deck[NUM_CARD_PER_DECK], int first_card)
{
	int input;
	int is_get_input = False;
	int select_card = TMP_CARD;

	while (!is_get_input)
	{
		is_get_input = True;

		printf("Select the card: ");
		scanf("%d", &input);

		if (is_buffer_free() == False || (input < 0 || input > 10) || deck[input] == TMP_CARD)
		{
			printf("Try again, invalid input\n");
			is_get_input = False;
			continue;
		}

		select_card = deck[input];

		if (first_card != TMP_CARD)
		{
			if (select_card / NUM_CARD_PER_TYPE != first_card / NUM_CARD_PER_TYPE)
			{
				int have_first_card_type = False;
				for (int i = 0; i < NUM_CARD_PER_DECK; i++)
				{
					if (deck[i] / NUM_CARD_PER_TYPE == first_card / NUM_CARD_PER_TYPE)
					{
						have_first_card_type = True;
						break;
					}
				}

				if (have_first_card_type)
				{
					printf("\e[1;31mTry again, you have first card type\n\e[0m");
					is_get_input = False;
					continue;
				}
			}
		}
	}

	deck[input] = TMP_CARD;

	return select_card;
}

int is_buffer_free()
{
	int is_free = True;
	char tmp;

	while ((tmp = getchar()) != '\n')
	{
		is_free = False;
	}

	return is_free;
}

int bot(int deck[NUM_CARD_PER_DECK], int first_card, int bakhsh_name, int card_played[NUM_PLAYER], int turn)
{
	/*first player logic*/
	if (first_card == TMP_CARD)
	{
		int biggest_card = TMP_CARD;
		int biggest_card_num = 0;
		int biggest_card_power = MIN_CARD_POWER;

		for (int i = 0; i < NUM_CARD_PER_DECK; i++)
		{
			if (deck[i] != TMP_CARD && deck[i] % NUM_CARD_PER_TYPE > biggest_card_power)
			{
				biggest_card = deck[i];
				biggest_card_num = i;
				biggest_card_power = deck[i] % NUM_CARD_PER_TYPE;
			}
		}

		if (biggest_card_power < 10)
		{
			int smallest_card = TMP_CARD;
			int smallest_card_num = 0;
			int smallest_card_power = MAX_CARD_POWER;

			for (int i = 0; i < NUM_CARD_PER_DECK; i++)
			{
				if (deck[i] != TMP_CARD && deck[i] / NUM_CARD_PER_TYPE != bakhsh_name && deck[i] % NUM_CARD_PER_TYPE < smallest_card_power)
				{
					smallest_card = deck[i];
					smallest_card_num = i;
					smallest_card_power = deck[i] % NUM_CARD_PER_TYPE;
				}
			}
			if (smallest_card != TMP_CARD)
			{
				deck[smallest_card_num] = TMP_CARD;
				return smallest_card;
			}
		}

		deck[biggest_card_num] = TMP_CARD;
		return biggest_card;
	}

	/*other player logic*/
	else
	{
		int is_my_teammate_played_biggest = is_played_biggest_card(card_played, (turn + NEXT_TEAMMATE) % NUM_PLAYER);

		if (is_my_teammate_played_biggest)
		{
			int smallest_card = TMP_CARD;
			int smallest_card_num = 0;
			int smallest_card_power = MAX_CARD_POWER;

			for (int i = 0; i < NUM_CARD_PER_DECK; i++)
			{
				if (deck[i] != TMP_CARD && deck[i] / NUM_CARD_PER_TYPE != bakhsh_name && deck[i] % NUM_CARD_PER_TYPE < smallest_card_power)
				{
					smallest_card = deck[i];
					smallest_card_num = i;
					smallest_card_power = deck[i] % NUM_CARD_PER_TYPE;
				}
			}

			if (smallest_card == TMP_CARD)
			{
				for (int i = 0; i < NUM_CARD_PER_DECK; i++)
				{
					if (deck[i] != TMP_CARD && deck[i] % NUM_CARD_PER_TYPE < smallest_card_power)
					{
						smallest_card = deck[i];
						smallest_card_num = i;
						smallest_card_power = deck[i] % NUM_CARD_PER_TYPE;
					}
				}
			}

			deck[smallest_card_num] = TMP_CARD;
			return smallest_card;
		}

		else
		{
			/*find biggest power card with first card type*/
			int biggest_card = TMP_CARD;
			int biggest_card_num = 0;
			int biggest_card_power = MIN_CARD_POWER;

			for (int i = 0; i < NUM_CARD_PER_DECK; i++)
			{
				if (deck[i] != TMP_CARD && deck[i] / NUM_CARD_PER_TYPE == first_card / NUM_CARD_PER_TYPE && deck[i] % NUM_CARD_PER_TYPE > biggest_card_power)
				{
					biggest_card = deck[i];
					biggest_card_num = i;
					biggest_card_power = deck[i] % NUM_CARD_PER_TYPE;
				}
			}

			/*if we dont have this find biggest bakhsh name*/
			if (biggest_card == TMP_CARD)
			{
				for (int i = 0; i < NUM_CARD_PER_DECK; i++)
				{
					if (deck[i] != TMP_CARD && deck[i] / NUM_CARD_PER_TYPE == bakhsh_name && deck[i] % NUM_CARD_PER_TYPE > biggest_card_power)
					{
						biggest_card = deck[i];
						biggest_card_num = i;
						biggest_card_power = deck[i] % NUM_CARD_PER_TYPE;
					}
				}
			}

			if (biggest_card != TMP_CARD)
			{
				deck[biggest_card_num] = TMP_CARD;
				return biggest_card;
			}

			/*if we dont have that find smallest with other type*/
			int smallest_card = TMP_CARD;
			int smallest_card_num = 0;
			int smallest_card_power = MAX_CARD_POWER;

			for (int i = 0; i < NUM_CARD_PER_DECK; i++)
			{
				if (deck[i] != TMP_CARD && deck[i] % NUM_CARD_PER_TYPE < smallest_card_power)
				{
					smallest_card = deck[i];
					smallest_card_num = i;
					smallest_card_power = deck[i] % NUM_CARD_PER_TYPE;
				}
			}

			deck[smallest_card_num] = TMP_CARD;
			return smallest_card;
		}
	}
}

int is_played_biggest_card(int card_played[NUM_PLAYER], int turn)
{
	int biggest_card_power = MIN_CARD_POWER;
	for (int i = 0; i < NUM_PLAYER; i++)
	{
		if (card_played[i] != TMP_CARD && card_played[i] % NUM_CARD_PER_TYPE > biggest_card_power)
		{
			biggest_card_power = card_played[i] % NUM_CARD_PER_TYPE;
		}
	}

	if (card_played[turn] != TMP_CARD && card_played[turn] % NUM_CARD_PER_TYPE == biggest_card_power)
	{
		return True;
	}
	else
	{
		return False;
	}
}

int who_is_winner(int card_played[NUM_PLAYER], int bakhsh_name, int *player_starter, int score[NUM_TEAMS])
{
	/*check have bakhsh name*/
	int have_bakhsh_name = False;
	for (int i = 0; i < NUM_PLAYER; i++)
	{
		if (card_played[i] / NUM_CARD_PER_TYPE == bakhsh_name)
		{
			have_bakhsh_name = True;
			break;
		}
	}
	/*find biggest card*/
	int biggest_card = TMP_CARD;
	int biggest_card_player_num = 0;
	int biggest_card_power = MIN_CARD_POWER;
	for (int i = 0; i < NUM_PLAYER; i++)
	{
		if ((card_played[i] / NUM_CARD_PER_TYPE == bakhsh_name || have_bakhsh_name == False) && card_played[i] % NUM_CARD_PER_TYPE > biggest_card_power)
		{
			biggest_card = card_played[i];
			biggest_card_player_num = i;
			biggest_card_power = card_played[i] % NUM_CARD_PER_TYPE;
		}
	}

	/*set winner*/
	*player_starter = biggest_card_player_num;
	score[biggest_card_player_num % NEXT_TEAMMATE] += WIN_SCORE;
	return biggest_card_player_num % NEXT_TEAMMATE + 1;
}

int end_game(int score[NUM_TEAMS], int set_win[NUM_TEAMS], int user_deck[], int bakhsh_name)
{
	int tmp_arr[NUM_PLAYER] = {TMP_CARD, TMP_CARD, TMP_CARD, TMP_CARD};
	char massage[100] = "";

	int set_win_score = SET_WIN_SCORE;
	if (score[0] * score[1] == 0)
	{
		strcat(massage, "\e[1mDOUBLE SCORE!!!\n\e[0m");
		set_win_score = DOUBLE_SET_WIN_SCORE;
	}

	if (score[0] == SCORE_TO_WIN_SET)
	{
		set_win[0] += set_win_score;
		strcat(massage, "Team 1 win this set\n");
	}
	else
	{
		set_win[1] += set_win_score;
		strcat(massage, "Team 2 win this set\n");
	}

	print_table(score, set_win, tmp_arr, user_deck, bakhsh_name);
	printf("%s", massage);
	
	return 1;
}

int finale_end(int set_win[NUM_TEAMS])
{
	if (set_win[0] > set_win[1])
	{
		printf("\e[1;32mTEAM 1 WIN GAME\n\e[0m");
	}
	else if (set_win[0] < set_win[1])
	{
		printf("\e[1;32mTEAM 2 WIN GAME\n\e[0m");
	}
	else
	{
		printf("\e[1;33mDRAW\n\e[0m");
	}
	return 1;
}

int print_table(int score[NUM_TEAMS], int set_win[NUM_TEAMS], int card_played[NUM_PLAYER], int user_deck[NUM_CARD_PER_DECK], int bakhsh_name)
{
	printf("\n\n\n\n\n");

	printf("\t");
	repeat_print(LENGTH / 2 - 1, " ");
	printf("p3");
	printf("\n");

	printf("\t");
	repeat_print(LENGTH, "_");
	printf("\t\e[1mteam 1\tscore: %d  set: %d\n", score[0], set_win[0]);

	printf("\t|");
	repeat_print(LENGTH / 2 - 2, " ");
	print_card(card_played[2]);
	repeat_print(LENGTH / 2 - 2, " ");
	printf("|\n");

	repeat_row(WIDTH, "|", " ");

	repeat_print(6, " ");
	printf("p2|");
	print_card(card_played[1]);
	repeat_print(LENGTH - 8, " ");
	print_card(card_played[3]);
	printf("|p3");
	if (bakhsh_name != TMP_CARD)
	{
		printf("\t\tbakhsh name: %c", (char)(bakhsh_name + 65));
	}
	printf("\n");

	repeat_row(WIDTH, "|", " ");

	printf("\t|");
	repeat_print(LENGTH / 2 - 2, " ");
	print_card(card_played[0]);
	repeat_print(LENGTH / 2 - 2, " ");
	printf("|\n");

	printf("\t");
	repeat_print(LENGTH, "_");
	printf("\t\e[1mteam 2\tscore: %d  set: %d\n", score[1], set_win[1]);

	printf("\t");
	repeat_print(LENGTH / 2 - 1, " ");
	printf("p1");
	printf("\n");

	printf("\n\t");
	repeat_print(NUM_CARD_PER_DECK * SPACE_FOR_CARD, "-");

	printf("\n  symbol|");
	for (int i = 0; i < NUM_CARD_PER_DECK; i++)
	{
        if (user_deck[i] != TMP_CARD)
        {
		    printf(" %c  |", (char)(user_deck[i] / NUM_CARD_PER_TYPE + 65));
        }
        else
        {
            printf(" -  |");
        }
	}

	printf("\n\t");
	repeat_print(NUM_CARD_PER_DECK * SPACE_FOR_CARD, "-");

	printf("\n  number|");
	for (int i = 0; i < NUM_CARD_PER_DECK; i++)
	{
        if (user_deck[i] != TMP_CARD)
        {
		    printf(" %i ", (user_deck[i] % NUM_CARD_PER_TYPE + 1));
		    if (user_deck[i] % NUM_CARD_PER_TYPE + 1 < 10)
		    {
		    	printf(" ");
		    }
            printf("|");
        }
        else
        {
            printf(" -  |");
        }
	}

	printf("\n\t");
	repeat_print(NUM_CARD_PER_DECK * SPACE_FOR_CARD, "-");
	printf("\n\t");
	for (int i = 0; i < NUM_CARD_PER_DECK; i++)
	{
		printf("  %d  ", i);
	}
	printf("\n");

	return 1;
}

int repeat_print(int count, char txt[])
{
	for (int i = 0; i < count; i++)
	{
		printf("%s", txt);
	}
	return 1;
}

int repeat_row(int row, char symbole[], char space[])
{
	for (int i = 0; i < WIDTH / 2; i++)
	{
		printf("\t%s", symbole);
		repeat_print(LENGTH, space);
		printf("%s\n", symbole);
	}
	return 1;
}

int print_card(int card)
{
    if(card != TMP_CARD)
    {
	    printf("%c ", (char)(card / NUM_CARD_PER_TYPE + 65));
	    printf("%i", card % NUM_CARD_PER_TYPE + 1);
	    if (card % NUM_CARD_PER_TYPE + 1 < 10)
	    {
	    	printf(" ");
	    }
    }
    else
    {
        printf("    ");
    }
    return 1;
}