#include <sys/types.h>
#include "mylib.h"

#define PORT (in_port_t)50000
#define HOSTNAME_LENGTH 64

// make game board
static char gameboard[][] = {
  "   a b c d e f g h  " ,
  " +-----------------+"
  " |* * * * * * * * *|",
  "A|                 |",
  " |* * * * * * * * *|",
  "B|                 |",
  " |* * * * * * * * *|",
  "C|                 |",
  " |* * * * * * * * *|",
  "D|                 |",
  " |* * * * * * * * *|",
  "E|                 |",
  " |* * * * * * * * *|",
  "F|                 |",
  " |* * * * * * * * *|",
  "G|                 |",
  " |* * * * * * * * *|",
  "H|                 |",
  " |* * * * * * * * *|",
  " +-----------------+"
}

typedef struct PLAYER{
  int id;
  int x;
  int y;
  int wall;
  int number;
}Player;

extern void gameboard_init(int soc, Player * p1, Player * p2);
extern void gameboard_show_plane();
extern int gameboard_peer_turn();
extern int gameboard_my_turn();

int set_wall(int x, int y);
int set_player(int x, int y);