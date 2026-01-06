#include "funcs.h"

#define full "\u2588"
const char *block = "\u2588";
char frame[9][9] = {"xxxxxxxx", "xxxxxxxx", "xxxxxxxx", "xxxxxxxx", "xxxxxxxx", "xxxxxxxx", "xxxxxxxx", "xxxxxxxx"};

//todo: implement frame, should be 8 rows of 8 characters
void animation(char row1[], int size){
  for(int i = 1 ; i < size; i++){
    printf("%s\n", row1);
    row1[i] = 'g';
    row1[i-1] = 'x';
    fflush(stdout);
    //row1+i = " ";
    msleep(500);
  }
}

void draw_frame(char a[][9]){
 for(int i = 0; i < 8; i++){
    printf("%s\n", a[i]);
 }
}

int main(void){
  char input[] = "w";
  setvbuf(stdout, NULL, _IONBF, 0);
  Position player;
  player.x = 0;
  player.y = 0;
  frame[player.y][player.x] = 'o';
  draw_frame(frame);
  while(input[0] =='w' || input[0] =='a' || input[0] =='s' || input[0] =='d'){
    printf("player: (%d,%d)\n", player.x, player.y);
    printf("Enter a direction wasd: ");
    scanf("%s", &input);
    if(input[0] =='w' && (player.y > 0)){
      player.y--;
      frame[player.y][player.x] = 'o';
      frame[player.y+1][player.x] = 'x';
      draw_frame(frame);
    }
    if(input[0] =='a' && (player.x > 0)){
      player.x--;
      frame[player.y][player.x] = 'o';
      frame[player.y][player.x+1] = 'x';
      draw_frame(frame);
    }
    if(input[0] =='s' && (player.y < 7)){
      player.y++;
      frame[player.y][player.x] = 'o';
      frame[player.y-1][player.x] = 'x';
      draw_frame(frame);
    }
    if(input[0] =='d' && (player.x < 7)){
      player.x++;
      frame[player.y][player.x] = 'o';
      frame[player.y][player.x-1] = 'x';
      draw_frame(frame);
    }
  }
}

/*
  for(int i = 0; i < 8; i++){
    if (i == location){
      printf(" ");
      fflush(stdout);
      #sleep for 500 milliseconds
      msleep(500);
      //nanosleep(5000);
    }
    else{
      printf("%s", full);
      fflush(stdout);
      msleep(5*10e4);
      //nanosleep(5000);
    }
  }
  */
