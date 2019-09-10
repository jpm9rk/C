#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

double factorial(double n){
  double  nfact = 1;
  if (n==0) return nfact;
  if (n<0){
    printf("Error: factorial(..): Only non-negative integers allowed.\n");
    return -1;
  }
  for(double i=n;i>0;i--){
    nfact *= i;    
  }
  return nfact;
}


void  biDis(int numTrial, double prob,int x){
  double distribution;
  for (int q=1;q<x;q++)
    {

      double NminusX=(numTrial-x);
      double OneminusP=(1-prob);
      // double nFact=factorital;

      //for(int i=0;i<numTrial;i++)
      //{



      

  distribution=(factorial(numTrial)/(factorial(x)*factorial(NminusX)));
		   
      printf("the probability of getting %d successes in a row is %lf\n",q,distribution);
    }
    //}


		 
 

}

int main(int argc, char *argv[]){


  srand(time(NULL));

  FILE *inptr=fopen("points.dat","w");

  




  // int x=rand()% 20;

  int n=atoi(argv[1]);

  double p=atof(argv[2]);


  biDis(n,p,21);












  return 0;
}
