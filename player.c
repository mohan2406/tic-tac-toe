#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "player.h"
#include "utils.h"

player_t *get_next_player(player_t *players)
{
  static int player_index = 1;
  player_index %= NO_OF_PLAYERS;
  return &(players[player_index++]);
}

void ask_user_symbol(player_t *players)
{
  char in[5];
  player_t *player = &players[0];
  printf("Player %s, please choose symbol (X/O): ", player->name);

  while (1)
  {
    if (fgets(in, sizeof(in), stdin) == NULL)
    {
      perror("fgets");
      exit(EXIT_FAILURE);
    }
    if (strchr(in, '\n') == NULL)
    {
      // Clear the input buffer if the input is too long
      int c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;

      printf("Player %s, please enter correct symbol (X/O): ", player->name);
      continue;
    }
    trim_leading(in);
    in[strcspn(in, "\n")] = '\0';

    if (in[0] == 'X' || in[0] == 'O')
    {
      player->symbol = in[0];
      break;
    }
    printf("Player %s, please enter correct symbol (X/O): ", player->name);
  }

  char other_sym = (player->symbol == 'X') ? 'O' : 'X';
  player = &players[1];
  player->symbol = other_sym;

  printf("Automatically assigned symbol %c for %s.\n", player->symbol, player->name);
}

void assign_random_symbol(player_t *players)
{
  srand((unsigned)time(NULL));

  static const char symbols[] = {'X', 'O'};
  char symbol = symbols[rand() % 2];

  players[0].symbol = symbol;
  players[1].symbol = (symbol == 'X') ? 'O' : 'X';

  printf("Randomly assigned symbol '%c' for player %s.\n", players[0].symbol, players[0].name);
  printf("Randomly assigned symbol '%c' for player %s.\n", players[1].symbol, players[1].name);
}
