#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int findMin(int activeNodes[], int values[], bool visited[]){

  int min = INT_MAX;
  int index = -1;

  for(int i = 0; i < 6; i++){
    if(activeNodes[i] && !visited[i] && values[i] < min){
      min = values[i];
      index = i;
    }
  }
  return index;
}

int main(){

  int * heurystics = malloc(sizeof(int) * 6);

  printf("Podaj heurystyki dla każdego węzła: \n");

  for(int i = 0; i < 6; i++){
    int value;
    scanf("h(0) = %d/n",&value);
    heurystics[i] = value;
  }

  printf("Podaj koszty krawędzi (macierz 6x6, 0 oznacza brak krawędzi): \n");

  int ** neighbourhood = (int**)malloc(6 * sizeof(int*));

  for(int i = 0; i < 6; i++){
    neighbourhood[i] = (int*)malloc(6*sizeof(int));
  }

  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 6; j++){
      int weight;
      scanf("%d", &weight);
      neighbourhood[i][j] = weight;
    }
  }

  int start, destiny;

  printf("Podaj węzeł startowy i docelowy: ");
  scanf("%d", &start);
  scanf("%d", &destiny);

  bool visited[6] = {false};

  int activeNodes[6] = {0};

  int costs[6];
  int values_costs_and_heurystics[6];
  int parents[6];

  for(int i = 0; i < 6; i++){
    costs[i] = INT_MAX;
    parents[i] = -1;
    values_costs_and_heurystics[i] = INT_MAX;
  }

  //Koszt dotarcie do samego siebie
  costs[start] = 0;
  values_costs_and_heurystics[start] = heurystics[start]; //Heurystyka dla pierwszego
  activeNodes[start] = 1;

  //Właściwy algorytm
  while(true){
    int current = findMin(activeNodes, values_costs_and_heurystics, visited);
    if(current == -1){
      return 1;
    }

    if(current == destiny){
      int node = destiny;

      printf("Najkrótsza ścieżka: ");
      while(node != -1){
        printf("%d ", node);

        node = parents[node];
      }

      printf("\nCałkowity koszt: %d\n", costs[destiny]);
      break;
    }

    activeNodes[current] = 0;
    visited[current] = true;

    for(int i = 0; i < 6; i++){
      if(neighbourhood[current][i] && !visited[i]){
        int tempG = costs[current] + neighbourhood[current][i];
        if(tempG < costs[i]){
          costs[i] = tempG;
          values_costs_and_heurystics[i] = costs[i] + heurystics[i];
          parents[i] = current;
          activeNodes[current] = 1;
        }
      }
    }
  }

  return 0;
}