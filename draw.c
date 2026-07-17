#include <stdio.h>
#include "draw.h"
#include "utils.h"

void draw_board(const board_t* board) {
  printf("\n┌───┬───┬───┐\n");
  printf("│");
  for (int i = 0; i < BOARD_SIZE; i++) {
    board_t cell = board[i];
    if (i != 0 && (i % BOARD_COLS) == 0) {
      printf("\n├───┼───┼───┤\n");
      printf("│");
    }

    if (cell == CELL_EMPTY) {
      printf(" %d │", (i + 1));
    } else {
      printf(" %c │", get_char_for_cell(board[i]));
    }
  }

  printf("\n└───┴───┴───┘\n");
}
