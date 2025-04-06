#include <stdio.h>
#include <math.h>

typedef double (*pointer)(double);

double f1(double x){
  return (x*x) + (3*x) + 1;
}

double f2(double x){
  return sin(x);
}

double f3(double x){
  double euler = exp(1.0);
  double result = pow(euler,x);
  return result;
}

double f4(double x){
  if(x != -1){
    return (1 / (x + 1));
  }else{
    return 0;
  }
}

double integrate(pointer f, double a, double b, int step){

  double h = (b - a) / step;

  double sum = (0.5 * (f(a) + f(b)));

  for(int i = 0; i < step; i++){
    sum += f(a + i * h);
  }

  double result = sum * h;
  return result;
}



int main(){

//  int a = 5;
//  int *ptr = &a;
//
//  printf("%d\n", *ptr); s
//  printf("%p\n", ptr); wsk
//  printf("%p\n", &a); wks
//  printf("%d\n",a); 5

  printf("Podaj przedział [a, b]: ");
  double a, b, suma;
  scanf("%lf %lf", &a, &b);
  printf("Podaj liczbe przedziałów do scałkowoania: ");
  int n;
  scanf("%d", &n);
  pointer type = NULL;
  int nType;
  printf("Wybierz funkcję do całkowania: ");
  printf("1. f(x) = x^2 +3x + 2");
  printf("2. f(x) = sin(x)");
  printf("3. f(x) = e^2");
  printf("4. f(x) = 1/(x+1)");
  printf("Twój wybór: ");
  scanf("%d",&nType);

  if(nType>4 && nType < 0){
    printf("Nieznany typ");
    return 1;
  }
  switch(nType){
    case 1:
      type = f1;
      break;
    case 2:
      type = f2;
      break;
    case 3:
      type = f3;
      break;
    case 4:
      type = f4;
      break;
    default:
      type = f1;
      break;
  }
  double * suma_ptr = &suma;
  *suma_ptr = integrate(f1, a, b, n);
  printf("%lf\n", *suma_ptr);


  return 0;
}
