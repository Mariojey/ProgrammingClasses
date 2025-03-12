#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(){

  int arraySize;

  printf("Podaj rozmiar tablicy: ");

  scanf("%d", &arraySize);

  if(arraySize < 1){
    printf("Romziar tablicy musi być dodatnią liczbą całkowitą");
    return 1;
  }

  printf("Podaj %d elementów tablicy:\n", arraySize);

  int * array;

  array = (int*)malloc(arraySize * sizeof(int));

  for(int i = 0 ; i < arraySize; i++){
    scanf("%d", &array[i]);
  }

  quick_sort(array,0, arraySize-1);

  FILE * destiny_file = fopen("output.txt", "w");

  if(destiny_file == NULL){
    perror("Nie można otworzyć pliku");
    return 1;
  }

  for (int i = 0; i < arraySize; i++){
    fprintf(destiny_file, "%d ", array[i]);
  }

  fclose(destiny_file);

  return 0;
}