#include <stdio.h>
#include "integrate.h"
#include "function.h"

int main(){
  printf("Podaj przedział [a, b]: ");
  double a,b;
  scanf("%lf %lf",&a,&b);
  printf("Podaj liczbę przedziałów: ");
  int n;
  scanf("%d",&n);
  int type;
  printf("Wybierz funkcję do całkowania: ");
  printf("1. f(x) = x^2 +3x + 2");
  printf("2. f(x) = sin(x)");
  printf("3. f(x) = e^2");
  printf("4. f(x) = 1/(x+1)");
  printf("Twój wybór: ");
  scanf("%d",&type);
  if(type>4 && type<0){
    printf("Nieznany typ");
    return 1;
  }
  double sum = integrate(a,b,n,type);
  printf("Wynik całkowania: %.6f\n",sum);
  return 0;
}