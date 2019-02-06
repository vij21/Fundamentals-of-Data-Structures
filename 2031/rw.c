#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define row 10
#define col 10
int main (int argc, char *argv[]) {

int i, j;
int m, path;

char board[row][col];
 char letters = 'A';
srand ((unsigned) time(NULL));

    /* Populate the grid with '.' */

for (i = 0; i < row; i++)
  for (j = 0; j < col; j++)
    board[i][j] = '.';
i=0;
j=0;
m=1;
board[i][j] = letters++;   

    // calculating position of next character

while (letters <= 'Z') {
  path=rand() % 4;
   
if (board[i][j] == '.')

board[i][j] = letters++;  
if ((board[i][j + 1] != '.' || j == row - 1 )&& (board[i + 1][j] != '.' || i == col -1) && (board[i - 1][j] != '.' || i == 0) 
    && (board[i][j - 1] != '.' || j == 0))
break;
//there are 4 different maximum moves left right up and down
    switch (path) {
        //to move right side 
      case 0: if (j < row - 1 && board[i][j + 1] == '.'){ 
              j++;
              break;     }
              //To move down 
      case 1: if (i < col -1 && board[i + 1][j] == '.') {  
              i++;
              break; }
              //To move up
      case 2: if (i > 0 && board[i - 1][j] == '.'){  
              i--;
              break;  }    
              //To move left 
      case 3: if (j > 0 && board[i][j - 1] == '.') {
              j--;
              break; }
}
}
    /* Print the final grid state */

for (i = 0; i < row; i++) {
  for (j = 0; j < col; j++)
    printf ("%4c", board[i][j]);
  printf ("\n");//print it 
}

printf("\n");
}