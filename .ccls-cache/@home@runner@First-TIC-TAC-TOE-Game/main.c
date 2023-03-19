#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char Board[3][3];
char const PLAYER1='X';
char const PLAYER2='O';

void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char winner);



int main(void) {
  char winner=' ';
  resetBoard();
  
  while(winner == ' ' && checkFreeSpace() != 0)
  {
    printBoard();
    
    playerMove();
    winner = checkWinner();
    if(winner != ' ' || checkFreeSpace() == 0)
    {
      break;
    }
    
    computerMove();
    winner = checkWinner();
    if(winner != ' ' || checkFreeSpace() == 0)
    {
      break;
    }
  }
  printBoard();
  printWinner(winner);
  return 0;
}


void resetBoard(){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      Board[i][j] = ' '; 
    }
  }
}
void printBoard(){
  printf(" %c | %c | %c \n",Board[0][0],Board[0][1],Board[0][2]);
  printf("-----------\n");
  printf(" %c | %c | %c \n",Board[1][0],Board[1][1],Board[1][2]);
  printf("-----------\n");
  printf(" %c | %c | %c \n",Board[2][0],Board[2][1],Board[2][2]);
  printf("\n");
}
int checkFreeSpace(){
  int freespace=9;
  for(int i = 0; i<3; i++){
    for(int j=0; j<3; j++){
      if(Board[i][j] != ' '){
        freespace--;
      }
    }
  }
  return freespace;
}
void playerMove(){
  int x;
  int y;
 do{
  printf("Enter row number(1-3) : ");
  scanf("%d",&x);
  x--;
  printf("Enter column number(1-3) : ");
  scanf("%d",&y);
  y--;

  if(Board[x][y] != ' '){
    printf("Invalid move!!\n");
  }
  else{
    Board[x][y] = PLAYER1;
    break;
  }
  }while(Board[x][y] != ' ');
}
void computerMove(){
  //we generate random numbers
  srand(time(0));
  int x;
  int y;

  if(checkFreeSpace() > 0)
  {
    do{
       x= rand() % 3;
       y= rand() % 3;
    }while(Board[x][y] != ' ');

    Board[x][y] = PLAYER2;
  }
  else{
    printWinner(' ');
  }
  
}
char checkWinner()
{
 //check row
  for(int i=0; i<3; i++){
    if(Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2])
    {
    return Board[i][0];
    }
  }
  //check column
  for(int i=0; i<3; i++){
    if(Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i]){
      return Board[0][i];
    }
  }
  //check diagonal
  if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2]){
    return Board[0][0];
  }
  if(Board[0][2] == Board[2][2] && Board[0][2] == Board[2][0]){
    return Board[0][2];
  }

  return ' ';
}
void printWinner(char winner){
  if(winner == PLAYER1) {
    printf("YOU WIN!! ");
  }
  else if(winner == PLAYER2) {
    printf("YOU LOSE!!");
  }
  else{
    printf("MATCH TIE!! ");
  }
 }