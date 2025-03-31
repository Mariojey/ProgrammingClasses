#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 20
#define HEIGHT 10

int countNeighbours(char board[HEIGHT][WIDTH], int row, int col){

  int offsets[] = {-1,0,1};
  int neighbours = 0;

  for(int i = 0; i < 3; i++){

    for(int j = 0; j < 3; j++){

      if(offsets[i] == 0 && offsets[j] == 0) continue; //Exceptive of itself

      int nx = row + offsets[i];
      int ny = col + offsets[j];

      if(nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && board[nx][ny] == 'O'){

        neighbours++;

      }
    }
  }
  return neighbours;
}

int main(){

  char board[HEIGHT][WIDTH];
  char nextBoard[HEIGHT][WIDTH];

  int count_of_alive;
  int iterations;

  printf("Podaj liczbę początkowo żywych komórek: ");
  scanf("%d", &count_of_alive);

  printf("Podaj liczbę iteracji symulacji: ");
  scanf("%d", &iterations);

  srand(1234);

  //Board init
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      board[i][j] = '.';
    }
  }


  //Random board fill
  int count = 0;
  while(count < count_of_alive){

    int x = rand() % HEIGHT;
    int y = rand() % WIDTH;

    //Put O if unfilled
    if(board[x][y] == '.'){
      board[x][y] = 'O';
      count++;
    }
  }

  for(int i = 0; i < iterations; i++){

    printf("Rok %d:\n", i + 1);

    //Print board
    for(int t = 0; t < HEIGHT; t++){
      for(int j = 0; j < WIDTH; j++){
        printf("%c", board[t][j]);
      }
      printf("\n");
    }
    printf("\n");

    //Generate next generation
    for(int k = 0; k < HEIGHT; k++){

      for(int j = 0; j < WIDTH; j++){

        int neighbours = countNeighbours(board, k, j);

        if(board[i][j] == 'O'){
          nextBoard[k][j] = (neighbours == 2 || neighbours == 3) ? 'O' : '.';
        }else{
          nextBoard[k][j] = (neighbours == 3) ? 'O' : '.';
        }
      }
    }
  }

  //Copy board
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      board[i][j] = nextBoard[i][j];
    }
  }

  sleep(1);

  return 0;
}
