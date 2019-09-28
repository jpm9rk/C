// This program tests our simple histograming tools
// Compile with:
// g++ -Wall -O test_hist.cpp -o test_hist-I$P2660LIBV0 -L$P2660LIBV0 -lp2660

#include <stdio.h>
#include "random.hpp"
#include "hist.hpp"

int main(){

  h1 hist[1000],bin20;  // create two histograms 
  int i,j;

  h1init(&bin20,0.,50.);
  for(i=0;i<1000;i++)
    {
  h1init(&hist[i],0.,100.);   // init the histograms 
    }                      // using the range 0:100 


  for(j=0;j<1000;j++){

  for (i=0; i<1000; i++) {

  
    double u1=randu(0.,100.);
    h1fill(&hist[j],u1);  // fill hist1 w/ uniform distro.
    // double n1=randn(50.,20.);
	}
  }

  for(i=0;i<1000;i++)
    {

      h1fill(&bin20,hist[i].h_array[20]);
    }



    // h1fill(&hist2,n1);  // fill hist2 w/ normal distro.
  
   h1dump(&bin20,"");           // dumps histogram data to screen 
  h1dump(&bin20,"bin20.dat");  // dumps histogram data to file 
   h1plot(&bin20,"");           // plots histogram to screen, X11 assumed 
  // h1plot(&hist1,"hist1.pdf");  // plots histogram to in pdf format to file
  //h1dump(&hist2,"hist2.dat");  // dumps histogram data to file 
  //h1plot(&hist2,"" );          // plots histogram to screen, X11 assumed
  //h1plot(&hist2,"hist2.pdf" ); 
   return 0;
}
