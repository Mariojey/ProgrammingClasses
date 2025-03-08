//
// Created by marri on 08.03.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(){

  int arraySize;

  printf("Podaj rozmiar tablicy: ");
  scanf("%d", &arraySize);

  if(arraySize < 1){
    printf("Rozmiar tablicy musi byc calkowita liczba dodatnia");
    return 1;
  }

  printf("Podaj %d elementów tablicy:\n", arraySize);
  int *array;
  array = (int*)malloc(arraySize * sizeof(int));

  for (int i = 0; i < arraySize; i++){
    scanf("%d", &array[i]);
  }

  printf("Wybierz algorytm sortowania: \n");
  printf("1 - Bubble Sort\n");
  printf("2 - Insertion Sort\n");
  printf("3 - Quick Sort\n");
  printf("4 - Merge Sort\n");

  int typeOfSort;
  scanf("%d", &typeOfSort);
  printf("Twój wybór: %d\n", typeOfSort);
  printf("Tablica przed sortowaniem: ");
  for (int i = 0; i < arraySize; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
  switch(typeOfSort){
    case 1:
      bubble_sort(array, arraySize);
      break;
    case 2:
      insertion_sort(array, arraySize);
      break;
    case 3:
      quick_sort(array, 0, arraySize-1);
      break;
    case 4:
      merge_sort(array, 0, arraySize-1);
      break;
    default:
      break;
  }
  printf("Tablica po sortowaniu: ");
  for (int i = 0; i < arraySize; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

}