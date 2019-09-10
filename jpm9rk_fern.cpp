
// James Morrissey
// jpm9rk
// Homework 4
// Problem 2
// jpm9rk_fern.cpp
// On my honor as a student I have neither given nor received help on this
// assignment






#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>







int main()
{
  double i;
  
  srand(time(NULL));
  
  
  
  double y=0,x=0;

  FILE *outptr;

   outptr=fopen("fern.dat","w");

 

  for(int j=0;j<10000;j++){






    i = rand()%100+1;


    if(i<=2){

        x=0;
	y=(0.25*y)-4;

      fprintf(outptr,"%-6.4f  %-6.4f\n",x,y);
    }

      else if (i>2 && i<=86){

	x=(0.95*x)+(0.005*y)-0.002;
	y=(-0.005*x)+(0.93*y)+0.5;

	fprintf(outptr,"%-6.4f   %-6.4f\n",x,y);
      }

      else if(i>86 && i<=93){
	x=(0.035*x)-(0.2*y)-0.09;
	y=(0.16*x)+(0.04*y)+0.02;


        fprintf(outptr,"%-6.4f   %-6.4f\n",x,y);
      }

      else if (i>93 && i<=100){
	x=(-0.04*x)+(0.2*y)+0.083;
	y=(0.16*x)+(0.04*y)+0.12;
        fprintf(outptr,"%-6.4f   %-6.4f\n",x,y);

      }
  

    


    return 0;
  



   }











 

  return(0);
}














