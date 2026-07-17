#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "../board.h"


int main(void) {
  board_t board[BOARD_SIZE];

  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = CELL_EMPTY;
  }

  assert(check_draw(board) == false);
  assert(check_win(board) == false);
  
  board[0] = CELL_X;
  board[1] = CELL_X;
  board[8] = CELL_X;
  assert(check_draw(board) == false);
  assert(check_win(board) == false);
  
  board[2] = CELL_X;
  assert(check_win(board) == true);
  assert(check_draw(board) == false);

  board[2] = CELL_O;
  board[4] = CELL_X;
  board[7] = CELL_X;
  assert(check_win(board) == true);
  assert(check_draw(board) == false);

  board[7] = CELL_O;
  board[8] = CELL_X;
  assert(check_win(board) == true);
  assert(check_draw(board) == false);

  board[8] = CELL_O;
  board[6] = CELL_X;
  board[2] = CELL_X;
  assert(check_win(board) == true);
  assert(check_draw(board) == false);

  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i] == CELL_EMPTY) {
      board[i] = CELL_X;
    }
  }

  assert(check_draw(board) == true);

  printf("All testcases passed!\n");

  return 0;
}
  
