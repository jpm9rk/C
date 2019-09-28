// fcnplot.cpp
// plot the function y=x*x 
// compile with
// g++ -O -Wall -I$P2660LIBV0 fcnplot.cpp -ofcnplot -L$P2660LIBV0 -lp2660
 
 
#include "hist.hpp"
 
int main(){
  h1 hist;
  h1init(&hist,0,50);
  for (int i=0; i<50; i++) h1fill(&hist, i+0.5 , (i+.5)*(i+.5));
  h1plot(&hist);
  return 0;
}
