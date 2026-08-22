#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "player.h"
#include "utils.h"
#include "draw.h"

bool get_random_symbol_choice()
{
  char in[5];
  printf("Do you want random symbol assignment? (y/n) default (y): ");

  if (fgets(in, sizeof(in), stdin) == NULL)
  {
    perror("fgets");
    exit(EXIT_FAILURE);
  }

  trim_leading(in);
  in[strcspn(in, "\n")] = '\0';

  if (in[0] == 'y' || in[0] == 'Y' || strlen(in) == 0)
  {
    return true;
  }

  return false;
}

void get_player_input(char *input, player_t *player)
{
  printf("%s's turn (%c)> ", player->name, player->symbol);
  if (fgets(input, sizeof(input), stdin) == NULL)
  {
    perror("fgets");
    exit(EXIT_FAILURE);
  }
  printf("\n");
}

void show_win_message(player_t *player)
{
  printf("Congrats %s! You've won this game\n", player->name);
}

void show_draw_message()
{
  printf("oops, this game ends up in a draw\n");
}

void clear_board()
{
  printf("\033[14;0H");
  printf("\033[0J");
  fflush(stdout);
}

void run_game_loop(player_t *players)
{
  bool rand_symbol = get_random_symbol_choice();

  if (!rand_symbol)
  {
    ask_user_symbol(players);
  }
  else
  {
    assign_random_symbol(players);
  }

  board_t board[BOARD_SIZE];
  init_board(board);

  bool running = true;
  bool invalid_index = false;
  char input[5];
  player_t *current_player = &players[0];

  while (running)
  {
    draw_board(board);
    if (invalid_index)
    {
      printf("Please enter a valid cell index.\n");
      invalid_index = false;
    }
    get_player_input(input, current_player);
    cell_index_t index = get_valid_index_or_throw_error(board, input);
    if (index == -1)
    {
      invalid_index = true;
      clear_board();
      continue;
    }

    update_board(board, current_player, index);
    if (check_win(board))
    {
      running = false;
      clear_board();
      draw_board(board);
      show_win_message(current_player);
      continue;
    }
    if (check_draw(board))
    {
      running = false;
      clear_board();
      draw_board(board);
      show_draw_message();
      continue;
    }
    current_player = get_next_player(players);
    clear_board();
  }
}
