#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#define SIZE 10000


int main(){

  FILE *inptr;

  
  double noisy[SIZE];

  double smooth[9991];

  int index;

  



  inptr=fopen("noisy.dat","r");

  for (int i=0;i<SIZE;i++)
    {


      fscanf(inptr,"%d %lf",&index,&noisy[i]);

    }

  for (int j=0;j<=(SIZE-10);j++)

    {

       int jplus=j+1;

      smooth[j]=((noisy[j]+noisy[j+1]+noisy[j+3]+noisy[j+4]+noisy[j+5]+noisy[j+6]+noisy[j+7]+noisy[j+8]+noisy[j+9])/10.0);

      printf("index: %d value: %lf\n",jplus,smooth[j]);
    }



     

  











  return 0;
}
