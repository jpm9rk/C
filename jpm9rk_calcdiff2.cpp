//James Morrissey
//jpm9rk




#include<stdio.h>
#include "mymath.hpp"
#include<math.h>





int main(){
  double y;
  double x=(3*(3.14159))/100.0;

  for (double i=0;i<=3*(3.14159);i+=x){

    y=differentiate(sinCosSquared,i);

    printf(" %lf, %lf\n", i,y);



 }







  return 0;
}
