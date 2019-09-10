//James Morrissey
//jpm9rk
//HW 06
//Problem 1
//jpm9rk_man3d.cpp
// On my honor as a student I have neither given nor received help on this 
//assignment

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// return the magnitude of a complex number
double magnitude(double re, double im){
  return sqrt(re*re+im*im);
}

//generates a random double between the range xmin and xmax when xmin snd
//xmax are entered as themselves multiplied by 100

int random_num(int min, int max){

 int  randInt= rand()%(max+1-min)+min;

 return randInt;



}
// determine if a point is in the mandelbrot set
int mandel_test(double c_re, double c_im);
const int NTRIALS=100;  // parameter used in main and mandel_test
                        // to tag points as "in the set"
int main(){

  srand(time(NULL));

  //initialize the two sum variables
  double volSum=0;
double volSqSum=0;
 

  

  

//loop to find 100 different values of the volume
 
  for (int j=0;j<100;j++){

    // initialize counter to track how mnay numbers are in the set
  int tracker=0;
  //loop to generate random coordinates and checks to see if they are in the 
  // set, and updates a counter if they are
  for (int i=0;i<1000;i++){
   double  x=double(random_num(-200,50))/100.0;
   double y=double(random_num(-125,125))/100.0;
   double z=double(random_num(-125,125))/100.0;

   double z2_re=x;
   double z2_im=sqrt(y*y+z*z);

   int counts1=mandel_test(z2_re,z2_im);

   

   if (counts1==100)
     tracker++;

   



		
 }

  // finds the volume, and updates the sum of the volumes, and 
  // the sum of the squares of the volumes
  double rectangleVol= 15.625;

  double volume = (((tracker))/1000.0)*rectangleVol;
  
   double volSq= volume*volume;

  volSqSum=volSqSum+volSq;

   volSum=volSum + volume;


  }

  double volAvg= volSum/(100);

  double stanDev=sqrt(((1)/99.0))*(volSqSum-((1)/100.0)*(volSum*volSum));

  printf("The avaerage volume is %lf , and the standard deviation is %lf\n",volAvg,stanDev);
  




  


  
  return 0;
}


// test to see if a given point is in the set, return the number of 
// iterations it takes to prove the point is not in the set, or 
// NTRIALS if the magnitude at the point is not found to diverge

int mandel_test(double c_re, double c_im){  

  // If a point is in the set, its magnitude will remain bounded by
  // 2.0 over iterations of z -> z^2 + C.  Stop the loop after a 
  // maximum of NTRIALS and consider this point to be in the set

  double z_re = c_re;
  double z_im = c_im;
  int counts = 0;
  while ((z_re*z_re+z_im*z_im)<=4.0  && counts<NTRIALS) {
    counts++;
    double re=z_re;  // careful! keep old values for calculation
    double im=z_im;
    // z -> z^2
    z_re = re*re-im*im;
    z_im = 2*re*im;
    // add c to z^2
    z_re = z_re + c_re;
    z_im = z_im + c_im;
  }
  return counts;
}
