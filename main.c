#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "utils.h"

void get_player_details(player_t *players)
{
  char input[50];

  for (int i = 0; i < NO_OF_PLAYERS; i++)
  {
    printf("Enter player %d name: ", (i + 1));

    while (1)
    {
      if (fgets(input, sizeof(input), stdin) == NULL)
      {
        perror("fgets");
        exit(EXIT_FAILURE);
      }
      trim_leading(input);
      input[strcspn(input, "\n")] = '\0';

      if (strlen(input) != 0)
      {
        strcpy(players[i].name, input);
        break;
      }
      printf("Please Enter player %d name to continue: ", (i + 1));
    }
    players[i].category = PLAYER_HUMAN;
  }
}

void clear_screen()
{
  printf("\033[2J\033[3J");
  printf("\033[3;0H");
  fflush(stdout);
}

int main()
{
  clear_screen();
  printf("===================================\n");
  printf("      Welcome to tic tac toe\n");
  printf("===================================\n");
  printf("Press 'Ctrl+c' at any time to exit\n");
  printf("\n\n");

  player_t players[NO_OF_PLAYERS];

  get_player_details(players);

  run_game_loop(players);

  return EXIT_SUCCESS;
}
