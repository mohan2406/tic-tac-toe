#include <stdlib.h>
#include "board.h"
#include "utils.h"


cell_index_t get_valid_index_or_throw_error(board_t* board, char* input) {
  if (board == NULL) return -1;

  trim_leading(input);
  char* end;
  cell_index_t int_input = (cell_index_t) strtol(input, &end, 10);

  if (end == input) {
    return -1;
  }

  cell_index_t index = get_actual_index(int_input);

  if (index < 0 || index >= BOARD_SIZE) return -1;

  if (board[index] == CELL_X || board[index] == CELL_O) return -1;

  return index;
}


void update_board(board_t* board, player_t* player, cell_index_t index) {
  board[index] = (player->symbol == 'X') ? CELL_X : CELL_O;
}


bool check_draw(board_t* board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i] == CELL_EMPTY)
      return false;
  }
  return true;
}

bool check_win(board_t* board) {

  // check rows
  for (int i = 0; i < BOARD_SIZE; i += BOARD_COLS) {
    if (board[i] != CELL_EMPTY && board[i] == board[i+1] && board[i] == board[i+2]) {
      return true;
    }
  }
  
  // check cols
  for (int i = 0; i < BOARD_COLS; i++) {
    if (board[i] != CELL_EMPTY && board[i] == board[i + BOARD_COLS] && board[i] == board[i + BOARD_COLS * 2]) {
      return true;
    }
  }

  // check diagonals
  if (board[0] != CELL_EMPTY && board[0] == board[(BOARD_COLS + 1)] && board[0] == board[(BOARD_COLS + 1) * 2]) {
    return true;
  }

  if (board[2] != CELL_EMPTY && board[2] == board[2 + BOARD_COLS - 1] && board[2] == board[2 + (BOARD_COLS - 1) * 2]) {
    return true;
  }

  return false;
}



void init_board(board_t* board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    board[i] = CELL_EMPTY;
  }
}
