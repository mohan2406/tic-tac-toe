#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../board.h"
#include "../draw.h"


void test_get_valid_index_or_throw_error(board_t* board) {
  char in[20];
  strcpy(in, "7");
  assert(get_valid_index_or_throw_error(board, in) == 6);
  strcpy(in, "9");
  assert(get_valid_index_or_throw_error(board, in) == 8);
  strcpy(in, "  3   ");
  assert(get_valid_index_or_throw_error(board, in) == 2);
  strcpy(in, " 3a32");
  assert(get_valid_index_or_throw_error(board, in) == 2);
  
  
  strcpy(in, "0");
  assert(get_valid_index_or_throw_error(board, in) == -1);
  strcpy(in, "10");
  assert(get_valid_index_or_throw_error(board, in) == -1);
  strcpy(in, "abc");
  assert(get_valid_index_or_throw_error(board, in) == -1);
  strcpy(in, "5");
  assert(get_valid_index_or_throw_error(NULL, in) == -1);
  strcpy(in, "");
  assert(get_valid_index_or_throw_error(board, in) == -1);
  strcpy(in, "4");
  assert(get_valid_index_or_throw_error(board, in) == -1);

  printf("get_valid_index_or_throw_error tests passed!\n");
}


void test_update_board(board_t* board) {
  player_t player1 = {
   .name = "mohan",
   .category = PLAYER_HUMAN,
   .symbol = 'X'
  }; 

  player_t player2 = {
    .name = "neerthana",
    .category = PLAYER_HUMAN,
    .symbol = 'O'
  };

  update_board(board, &player1, 4);

  assert(board[4] == CELL_X);

  update_board(board, &player2, 0);

  assert(board[0] == CELL_O);

  printf("update_board tests passed!\n");
}


int main(void) {
  board_t board[BOARD_SIZE];

  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = CELL_EMPTY;
    if (i == 3) {
      board[i] = CELL_X;
    }
  }

  draw_board(board);

  test_get_valid_index_or_throw_error(board);
  test_update_board(board);

  draw_board(board);

  printf("All tests passed!\n");
  return 0;
}
