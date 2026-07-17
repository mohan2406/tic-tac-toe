#include "player.h"


player_t* get_next_player(player_t* players) {
  static int player_index = 0;
  player_index %= NO_OF_PLAYERS;
  return &(players[player_index++]);
}
