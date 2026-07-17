#include <stdio.h>
#include <assert.h>
#include "../player.h"


int main(void) {
  player_t p[NO_OF_PLAYERS] = {
    {
    .name = "mohan",
    .category = PLAYER_HUMAN,
    .symbol = 'X'
    },
    {
    .name = "neerthana",
    .category = PLAYER_HUMAN,
    .symbol = 'O'
    },
};

  
  
  assert(get_next_player(p)->name == p[0].name);
  assert(get_next_player(p)->name == p[1].name);
  assert(get_next_player(p)->name == p[0].name);

  printf("All testcases passed!\n");

  return 0;
}
