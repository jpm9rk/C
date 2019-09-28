//James Morrissey
//jpm9rk


#include<stdio.h>
#include<math.h>




  double sinCosSquared(double x){

   
    double c=cos(x);

    double s=sin(x);

    return s*c*c;


}

double differentiate(double (*f)(double), double x){
  double dx=powf(10,-4);
  return (f(x+dx)-f(x-dx))/(2*dx);










}


