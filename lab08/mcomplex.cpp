#include<stdio.h>
#include<math.h>
#include"mcomplex.hpp"


double magnitude(double re, double im){
  return sqrt(re*re+im*im);
}

double printZ(double re, double im){
  printf("the real part is %lf , and the imaginary part is %lf",re,im);
  return 0;
}
