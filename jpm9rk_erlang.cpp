
// James Morrissey
// jpm9rk_erlang
// jpm9rk
// HW 04
// Problem 0
// On my honor as a student I have neither given nor receievd help on this
// assignment





#include<stdio.h>
#include<math.h>

 double pow(double x , double y);
 double exp(double x);

double erlingvalue(double xvalue, double  muvalue, double  kvalue){

  double  c, kfact = 1;
  double kless=kvalue-1;
  
 
 
  for (c = 1; c <= kless; c++)
     kfact = kfact * c;
 
  double erling=(1/(kfact))*(pow(xvalue,kless))*
    exp(-xvalue);

  return erling;





}
 
int main(){

  double x;

  FILE *outptr=fopen("erlang.dat","w");


  
 

   int j;

    for (j=0;j<40;j++){

    x=double(j)/2;

   double erling1= erlingvalue(x,1,3);

   double erling2=erlingvalue(x,1,5);

   double erling3=erlingvalue(x,1,7);

   double erling4=erlingvalue(x,1,9);


    


   fprintf(outptr,"%-5.2f     %-7f     %-7f     %-10f      %7.5f \n",
   x, erling1, erling2,erling3,erling4);
   
 }

   


















  return 0;

}
