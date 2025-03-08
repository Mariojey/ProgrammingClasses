#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *arr, int l, int m, int r){
  int *temp = malloc((r-l+1)*sizeof(int));
  int i = l, j = m + 1, k = 0;

  while(i <= m && j <= r){
    if(arr[i] <= arr[j]){
      temp[k++] = arr[i++];
    }
    else{
      temp[k++] = arr[j++];
    }
  }

  while(i <= m){
    temp[k++] = arr[i++];
  }

  while(j <= r){
    temp[k++] = arr[j++];
  }

  for(i = l, k=0; i <= r; i++, k++){
    arr[i] = temp[k];
  }
  free(temp);
  return;
}

void merge_sort(int *arr, int l, int r){
  if(l >= r){
    return;
  }
  int mid = l + (r - l)/2;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid+1, r);
  merge(arr, l, mid,r);
  return;
}