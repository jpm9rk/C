//James Morrissey
//jpm9rk
//Problem 2
//HW 06
//jpm9rk_trap2.cpp
//On my honor as a student I have neither given nor received 
//help on this assignment.



#include <stdio.h>
#include <math.h>
#include <stdlib.h>




//1 dimensional trap rule, with the added y argument

double trap_rule1(double (*f)(double,double), double min,double max, double y, int steps)


{


  int i=0;
  double sum=0;
  double dx=( max-min)/(steps);
 
  for (i=0;i<steps;i++)
    sum+=f(min+i*dx,y);
  

  return dx*(f(min,y)+f(max,y))/2+sum;


   




}


//function that returns what we are trying to find the integral of

double integrand (double x, double y){

  return  exp(cos(y))*exp(sin(x+y));



}

//2 dimensional trap rule that calls the integrand and trap1 function

double trap_rule2(double (*f)(double,double),double xmin, double xmax, double ymin, double ymax, int steps){

  int i;

  double volume=0;

  double j=0;

  double sumy=ymin;

  double dy=(ymax-ymin)/steps;

  for(i=1; i<steps;i++)
    sumy+=dy;
  volume+=sumy*(trap_rule1(integrand,0,10.0,sumy,100));

  j=(volume*dy);

  return j;


}












int main(){

 


  printf("The volume is %lf\n",trap_rule2(integrand,0.0,10.0,10.0,20.0,1000));













  return 0;

}



//The trapezoid rule will work best for best for surfaces, and if
//there are changes in how much the surface curves up or down, that they 
//occur instantaneously
// The trapezoid rule works by 
//approximating with the area of trapezoids with straight lines, so functions
//that produce surfaces that are closest to the "ribbons" shown on the 
//homework will best be estimated by the trapezoid rule.
//If the function produces a surface that is concave down, it will
//under estimate the area under the curve, because the trapezoids will never 
//include the full colume
// under the surface, unless there are an infinite amount,
//and they will not extend above the surface
//A function that produces a concave down surface will over estimate
//the value of the volume under the surface because the trapezoids will
//extend out over the surface.
