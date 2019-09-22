



#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"random.hpp"
#include"hist.hpp"




int main(){

  int i,k;

  double reducedCase1,reducedCase2;

  struct {

    double value[50];
  } randNum[10000];

  for(i=0;i<10000;i++)
    {
      for(k=0;k<50;k++)
	{

	  randNum[i].value[k]=randn(2,1);
	}
    }


    return 0;
}
