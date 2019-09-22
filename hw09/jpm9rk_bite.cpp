//James Morrissey
//jpm9rk
//hw09
//jpm9rk_bite.cpp
//On my honor as a student I have neither given nor received help on this assignment


//histograms for the two specific cases listen should have been submitted in
//two pdf files


#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "hist.hpp"
#include "random.hpp"

int main(int argc,char *argv[]){
  //check to make sure number of arguments is correct
  if(argc!=2)
    printf("please enter a single distance value following the program name\n");
  else if (argc==2)
    {

  double mosquito;

  //bite counter
  double nBites=0;
  int i,j,k;

  double walk=atof(argv[1]);

  //bite histogram initialization
  h1 nBitesWalk;
  h1init(&nBitesWalk,75,0,25,"Mosquito Bites in 200m Walk");
  h1labels(&nBitesWalk,"Number of Mosquito Bites","Frequency of given amount of mosquito bites");

  //simulating the walk 500 times
  for(k=0;k<500;k++)
    {

      nBites=0;
  
      //for loop for the distance
     for(i=0;i<walk;i++)

      {
	//for loop to give each mosquito a chance to bite
       for(j=0;j<100;j++)
 	 {
      mosquito=randui(0,10000);
     

      if(mosquito==100)
	
	  nBites++;
          }

       
      }
     //fillling the histogram with the number of bites from each walk
     h1fill(&nBitesWalk,nBites,1.0);
    }
   h1plot(&nBitesWalk,"");
   h1plot(&nBitesWalk,"jpm9rk_walks_200.pdf");
    }

  return 0;
}
