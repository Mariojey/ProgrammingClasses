#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 9999

int main(){

  int count_of_nodes;

  printf("Podaj liczbe wierzcholkow w grafie: ");
  scanf("%d", &count_of_nodes);

  int ** neighbourhood = malloc(sizeof(int * ) * count_of_nodes);

  for(int i = 0; i < count_of_nodes; i++){
    neighbourhood[i] = malloc(sizeof(int) * count_of_nodes);
  }

  printf("Podaj macierz sasiedztwa (wagi krawedzi, 0 oznacza brak krawedzi): ");

  for (int i = 0; i < count_of_nodes; i++){
    for (int j = 0; j < count_of_nodes; j++){
      int weight;
      scanf("%d", &weight);
      neighbourhood[i][j] = weight;
    }
  }

  int firstNode;
  printf("Podaj wierzcholek poczatkowy: ");
  scanf("%d", &firstNode);

  int * len = malloc(sizeof(int) * count_of_nodes);
  bool * visited = malloc(sizeof(bool) * count_of_nodes);

  for (int i = 0; i < count_of_nodes; i++){
    len[i] = INFINITY;
    visited[i] = false;
  }

  len[firstNode] = 0;

  //Właściwy Dijkstra

  for (int i = 0; i < count_of_nodes - 1; i++){


    //Szukamy najmniejszej odległości spośród nieodwiedzonych
    int minLength = INFINITY;
    int minIndex;

    for(int k = 0; k < count_of_nodes; k++){
      if(len[k] < minLength){
        if(visited[k] == false){
          minLength = len[k];
          minIndex = k;
        }
      }
    }

    visited[minIndex] = true;

    //Zmiana odległości sąsiadów
    for(int l = 0; l < count_of_nodes; l++){
      if(visited[l] == false){

        if(neighbourhood[minIndex][l]){

          if(len[minIndex] != INFINITY){

            if(len[minIndex] + neighbourhood[minIndex][l] < len[l]){
              len[l] = len[minIndex] + neighbourhood[minIndex][l];
            }
          }
        }
      }
    }

  }

  printf("Wierzchołek     ");
  printf("Odległość od startu");
  printf("\n");
  for(int i = 0; i < count_of_nodes; i++){
     printf("%d     ", i);
     printf("%d", len[i]);
     printf("\n");
  }

  return 0;
}