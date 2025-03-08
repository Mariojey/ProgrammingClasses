#include <stdio.h>
#include <math.h>
#include "function.h"
#include "integrate.h"

double integrate(double a, double b, int n, int type){

  double h = (b - a) / n;

  double sum;

  switch (type){
    case 1:
      sum =  (0.5 * (f1(a) + f1(b)));
      for (int i = 1; i <= n; i++){
        sum += f1(a + i * h);
      }
      break;
    case 2:
      sum =  (0.5 * (f2(a) + f2(b)));
      for (int i = 1; i <= n; i++){
        sum += f2(a + i * h);
      }
      break;
    case 3:
      sum =  (0.5 * (f3(a) + f3(b)));
      for (int i = 1; i <= n; i++){
        sum += f3(a + i * h);
      }
      break;
    case 4:
      sum =  (0.5 * (f4(a) + f4(b)));
      for (int i = 1; i <= n; i++){
        sum += f4(a + i * h);
      }
      break;
    default:
      break;
  }

  double result = sum * h;
  return result;
}