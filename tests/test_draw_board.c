#include "../draw.h"


int main(void) {
  board_t board[BOARD_SIZE] = {
    CELL_X, CELL_O, CELL_EMPTY,
    CELL_EMPTY, CELL_X, CELL_EMPTY,
    CELL_O, CELL_EMPTY, CELL_X
  };

  draw_board(board);
  return 0;
}
