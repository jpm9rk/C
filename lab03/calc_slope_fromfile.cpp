
//Calculates Slope of the Line
// Input Variables: x1,y1-coordinates of point 1, x2,y2-coordinates of point 2





#include <stdio.h>
int main(){

  float x1,y1,x2,y2;
  double yintercept,xintercept;
  float slope;
  FILE *nptr;
  FILE *iptr;



  nptr=fopen("points.dat","r");
  iptr=fopen("slope_and_intercepts.out","r");


  fprintf("slope_and_intercepts.out","r");
  
  
  fscanf(nptr,"%f %f %f %f", &x1, &y1, &x2, &y2);
  fprintf("slope_and_intercepts.out","r");
  fprintf("slope_and_intercepts.out","r");
  if(x1 != x2)
    {
      slope=(y2-y1)/(x2-x1);
      fprintf("slope_and_intercepts.out","r");
      yintercept=(y1)-(slope*x1);
      xintercept=(-yintercept)/slope;
      fprintf("slope_and_intercepts.out","r");
      fprintf("slope_and_intercepts.out","r");
    }
  else
    fprintf("slope_and_intercepts.out","r");


    


 
   return 0;
}
