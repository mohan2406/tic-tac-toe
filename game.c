#include <stdbool.h>
#include "game.h"
#include "board.h"
#include "player.h"


void run_game_loop(player_t* players) {
  bool rand_symbol = get_random_symbol_choice();

  if (!rand_symbol) {
    ask_user_symbol(players);
  } else {
    assign_random_symbol(players);
  }

  board_t* board[BOARD_SIZE];
  init_board(board);

  bool running = true;
  char input[100];
  player_t* current_player = &players[0];

  while (running) {
    draw_board(board);
    get_player_input(input, current_player);
    cell_index_t index = get_valid_index_or_throw_error(board, input);
    if (index == -1) {
      printf("Please enter a valid cell index.\n");
      continue;
    }
    update_board(board, current_player, index);
    if (check_win(board)) {
      running = false;
      show_win_message(current_player);
      continue;
    }
    if (check_draw(board)) {
      running = false;
      show_draw_message();
      continue;
    }
    current_player = get_next_player(players);
  }
}
