#include <stdio.h>
#include "sort.h"

void insertion_sort(int *array, int n){
  for(int i = 1; i < n; i++){
    int temp = array[i];
    for(int j = i; j>0; j--){
      if(array[j-1] > temp){
        array[j] = array[j-1];
        array[j-1] = temp;
        break;
      }
    }
  }
  return;
}