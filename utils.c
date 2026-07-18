#include "utils.h"
#include <string.h>
#include <ctype.h>

char get_char_for_cell(board_t cell) {
  switch (cell) {
    case CELL_EMPTY:
      return '0';
    case CELL_X:
      return 'X';
    case CELL_O:
      return 'O';
    default:
      return '?';
  }
}

void trim_leading(char* str) {
  char* start = str;
  

  while (isspace((unsigned char)* start) || *start == '\n')
    start++;

  memmove(str, start, strlen(start) + 1);
}
