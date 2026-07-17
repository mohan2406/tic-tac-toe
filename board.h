#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include "player.h"

#define BOARD_ROWS 3
#define BOARD_COLS 3
#define BOARD_SIZE (BOARD_ROWS * BOARD_COLS)

typedef enum {
  CELL_EMPTY,
  CELL_X,
  CELL_O
} board_t;

typedef int cell_index_t;

static inline cell_index_t get_actual_index(cell_index_t cell) { return (cell - 1); }

extern void init_board(board_t* board);

extern cell_index_t get_valid_index_or_throw_error(board_t* board, char* input);

// Always calls it after "get_valid_index_or_throw_error"
extern void update_board(board_t* board, player_t* player, cell_index_t index);

extern bool check_draw(board_t* board);

extern bool check_win(board_t* board);

#endif
