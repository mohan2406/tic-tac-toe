#ifndef PLAYER_H
#define PLAYER_H

#define NO_OF_PLAYERS 2

typedef enum {
  PLAYER_HUMAN,
} player_category_t;

typedef struct {
  char name[50];
  player_category_t category;
  char symbol;
} player_t;


extern player_t* get_next_player(player_t* players);

#endif
