#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(){

  int count_of_nodes;

  printf("Podaj liczbe wierzcholkow w grafie: ");
  scanf("%d", &count_of_nodes);

  int ** neighbourhood = malloc(sizeof(int *) * count_of_nodes);

  for (int i = 0; i < count_of_nodes; i++){
    neighbourhood[i] = malloc(sizeof(int) * count_of_nodes);
  }

  printf("Podak macierz sasiedztwa (wagi krawedzi, 0 oznacza brak krawedzi): ");

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

  for (int i = 0; i < count_of_nodes; i++){
    for (int j = 0; j < count_of_nodes; j++){
      printf("%d ", neighbourhood[i][j]);
    }
    printf("\n");
  }
}