#include <gameboard.h>
#include <string.h>

static int gameboard_soc;

typedef struct PLAYER{
  void name;
  int x;
  int y;
  int wall;
  int number; // 
  int winy;
}Player;

Player p1, p2;
Player *winner = 0;
Player *turnPlayer = &p1;

void gameboard_init(int soc, Player * p1, Player * p2){
  gameboard_soc = soc;
  p1->x = 11; // 
  p1->y = 18; // 
  p1->wall = 10; // 壁の枚数
  p1->winy = 2; // 勝利判定に使う y 座標

  p2->x = 11;
  p2->y = 2; // 
  p2->wall = 10; // 壁の枚数
  p2->winy = 18;
}

void gameboard_show(){
  for(int i = 0;i <= 19; i++){
    printf("%s\n", gameboard[i]);
  }
}

// 相手番
int gameboard_peer_turn(){
  char data[10];
  int x, y;

  read(gameboard_soc, data, 10);
  if(strcmp("quit", data) == 0) return -1;
}

// コマか壁を置く
void updateBoard(Player *player){
  if(x % 2 == 0 && y % 2 == 0){
    isMovable(player);
  }
  else if(x % 2 != y % 2){ 
    if(x % 2 == 1){
      // horizontal
    }
    else if(y % 2 == 1){
      // vertical
    }

    player->wall -= 1;
  }

  isGameOver();
  if(winner > 0){
    showWinningText(&winner);
  }
}

// 移動判定
int isMovable(Player *player){

}

// 配置判定

// 終了判定
void isGameOver(void){
  if(turnPlayer.y == winy){
    winner = turnPlayer;
    return;
  }
}

void showWiningText(Player *p){
  printf("%s win!", p->name);
}