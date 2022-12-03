#include<stdio.h>

#define NUM_SET 5
#define NUM_CARD 44
#define NUM_TYPE_CARD 4
#define NUM_CARD_PER_TYPE 11
#define NUM_CARD_PER_DECK 11
#define NUM_PLAYER 4
#define NUM_TEAMS 2

#define FIRST_SCORE 0
#define TMP_CARD 0
#define PLAYER_STARTER 0
#define USER_PLAYER_NUM 0

#define CARD_SPEARD_R1 5
#define CARD_SPEARD_R2 4
#define CARD_SPEARD_R3 2

#define True 1
#define False 0

int main(void)
{
	char card_name[NUM_TYPE_CARD] = {'A', 'B', 'C', 'D'};
	int player_starter = PLAYER_STARTER;

	for (int i = 0; i < NUM_SET; i++)
	{
		int decks[NUM_PLAYER][NUM_CARDE_PER_DECK] = {TMP_CARD};
		int bakhsh_name = TMP_CARD;
		int score[NUM_TEAMS] = {FIRST_SCORE};

		start_game(decks, bakhsh_name, player_starter);
		while_game(decks, bakhsh_name, &player_starter, score);
		end_game();
	}

	finale_end();

	return 0;
}

int start_game(int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int bakhsh_name, int player_starter)
{
	int card[NUM_CARD] = {0};
	shuffle_card(card);

	card_speard(decks, CARD_SPEARD_R1);
	print_table();/*TODO*/
	bakhsh_name = enter_bakhsh_name(player_starter);
	card_speard(decks, CARD_SPEARD_R2);
	card_speard(decks, CARD_SPEARD_R3);

	return 1;
}

int shuffle_card(int card[NUM_CARD])
{
	/*TODO*/
	return 1;
}

int card_speard(int card[NUM_CARD], int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int num_speard)
{
	/*find start point in card arr*/
	int start_point = 0;
	for (; card[start_point] == TMP_CARD; start_point++)
	{}


	for (int i = 0; i < NUM_PLAYER; i++)
	{
		int deck_start_point = 0;
		for (; decks[i][deck_start_point] != TMP_CARD; deck_start_point++)
		{}

		for (int j = 0; j < num_speard, j++)
		{
			decks[i][deck_start_point + j] = card[satrt_point + j]	
			card[start_point + j] = TMP_CARD;
		}
	}

	return 1;
}

int enter_bakhsh_name(int player_starter)
{
	/*TODO*/
	return 1;
}

int while_game(int decks[NUM_PLAYER][NUM_CARD_PER_DECK], int bakhsh_name,int *player_starter, int score[NUM_TEAMS])
{
	while (score[0] == 6 || score[1] == 6)
	{
		int card_played[NUM_PLAYER] = {TMP_CARD};
		int first_card = TMP_CARD;
		
		for (int i = 0; i < NUM_PLAYER; i++)
		{
			int turn = (*player_starter + i) % NUM_PLAYER;

			print_table();

			if (turn == USER_PLAYER_NUM)
			{
				card_played[turn] = player(decks[USER_PLAYER_NUM], first_card);
			}
			else
			{
				card_played[turn] = bot(decks[turn], first_card);
			}

			if (first_card == TMP_CARD)
			{
				first_card = card_played[turn];
			}
		}
		
		print_table();
		who_is_winner(card_played);
	}
}

int player(int deck[NUM_CARD_PER_DECK], first_card)
{
	int is_get_input = True;
	int select_card = TMP_CARD;

	while (!is_get_input)
	{
		is_get_input = True;

		int input;
		printf("Select the card: ");
		scanf("%d", input);

		if (is_buffer_free() == False || (input < 0 || input > 10))
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
					printf("\e[1;31mTry again, you have first card type\n\e[0m"}
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
