#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int find_pivot(int *tab, int low, int high){

  int pivot = tab[high];
  int iterator = low -1;

  for (int j = low; j < high; j++){

    if (tab[j] <= pivot){
      iterator++;
      swap(&tab[j], &tab[iterator]);
    }
  }
  swap(&tab[iterator+1], &tab[high]);
  return iterator+1;
}

//Sort
void quick_sort(int *tab, int low, int high){
  if(low < high){
    int pivot = find_pivot(tab, low, high);
    quick_sort(tab, low, pivot-1);
    quick_sort(tab, pivot+1, high);
  }
}
