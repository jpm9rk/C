//James Morrissey
//jpm9rk
//hw 05
//prob1
//jpm9rk_legendre.cpp

#include<stdio.h>
#include<math.h>



double legendre(double,double);

int main(){
    
  FILE *outp = fopen("jpm9rk_legendre.dat","w");
  
  double p=0,p1=0,p2=0,p3=0,p4=0,p5=0;

  
  //provides x values between -1 and 1
    for(double x1=(-100);x1<=100;x1++){
  
      double  x=(double( x1))/(100);
     
 //calculating different legendre values for different n
	p=legendre(0,x);
       
	p1=legendre(1,x);
       
	p2=legendre(2,x);
       
	p3=legendre(3,x);
	
	p4=legendre(4,x);
	
	p5=legendre(5,x);

	fprintf(outp," %10lf    %lf %lf %lf %lf %lf %lf\n",x,p,p1,p2,p3,p4,p5);

    

    





  }



















  return 0;
}
// calculates legendre value for given n and x
double legendre(double  n, double x){

  if( n==0)
    return 1;
  else if (n==1)
    return x;
  else {

    return (2*n-1.0)/n*x*legendre(n-1.0,x)-(n-1.0)/n*legendre(n-2.0,x);
  }







}
