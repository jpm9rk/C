//James Morrissey
//jpm9rk
//hw10
//problem1
//jpm9rk_trumptweets.cpp
//On my honor as a student I have neither given nor received help on this assignment


#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"hist.hpp"
#include"random.hpp"

int main(){

  //declaration of first set of 9 histograms
  FILE *fptr,*fptr1,*fptr2;
  h1 hist1,hist2,hist3,hist4,hist5,hist6,hist7,hist8,hist9;
  h1init (&hist1,10,0,200,"Observable1");
  h1init (&hist2,10,0,200,"Observable2");
  h1init (&hist3,10,0,200,"Observable3");
  h1init (&hist4,10,-10,10,"Observable4");
  h1init (&hist5,10,-10,10,"Observable5");
  h1init (&hist6,20,0,10,"Observable6");
  h1init (&hist7,100,0,500,"Observable7");
  h1init (&hist8,50,0,1000,"Observable8");
  h1init (&hist9,10,0,10,"Observable9");

  h1labels(&hist1,"Value of Observable 1","Frequency of value");
  h1labels(&hist1,"Value of Observable 2","Frequency of value");
  h1labels(&hist1,"Value of Observable 3","Frequency of value");
  h1labels(&hist1,"Value of Observable 4","Frequency of value");
  h1labels(&hist1,"Value of Observable 5","Frequency of value");
  h1labels(&hist1,"Value of Observable 6","Frequency of value");
  h1labels(&hist1,"Value of Observable 7","Frequency of value");
  h1labels(&hist1,"Value of Observable 8","Frequency of value");
  h1labels(&hist1,"Value of Observable 9","Frequency of value");

  //holds the values for various observables

  double chi=0;
  double observ1[500],observ2[500],observ3[500],observ4[500],observ5[500],observ6[500],observ8[500],observ7[500],observ9[500];

  double signal1[10000],signal2[10000],signal3[10000],signal4[10000],signal5[10000],signal6[10000],signal7[10000],signal8[10000],signal9[10000];

  double bkgd1[10000],bkgd2[10000],bkgd3[10000],bkgd4[10000],bkgd5[10000],bkgd6[10000],bkgd7[10000],bkgd8[10000],bkgd9[10000];
  int i,j,status,status1,status2,counter=0,actualCount=0,counter1=0,counter2=0;
  //char array to store names at beginning of the file
  char names[500];
  fptr=fopen("data.dat","r");

  if (fptr==NULL)
    {
      printf("error finding file");
    }
  //scan in the names at the beginning of the file
  for(i=0;i<18;i++)
    {
      fscanf(fptr,"%s",names);
      //  printf("scanned  %s\n",names);
    }

  //run the scan function a large number of times, break if it reaches end of file

  for(i=0;i<10000;i++)
    {
      
      status= fscanf(fptr,"%lf %lf %lf %lf %lf %lf %lf %lf %lf",&observ1[i],
		     &observ2[i],&observ3[i],&observ4[i],&observ5[i],
		     &observ6[i],&observ7[i],&observ8[i],&observ9[i]);
     if (status==EOF)
       {
       break;
       }
     // printf("scanned %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",observ1[i],
     // observ2[i],observ3[i],observ4[i],observ5[i],
     //           observ6[i],observ7[i],observ8[i],observ9[i]);
      counter++;
	
    }
   actualCount=counter-1;
   //fills the histograms
  for(i=0;i<counter;i++)
    {
       h1fill(&hist1,observ1[i]);     
       h1fill(&hist2,observ2[i]);
       h1fill(&hist3,observ3[i]);
       h1fill(&hist4,observ4[i]);
       h1fill(&hist5,observ5[i]);      
       h1fill(&hist6,observ6[i]);
       h1fill(&hist7,observ7[i]);
       h1fill(&hist8,observ8[i]);
       h1fill(&hist9,observ9[i]);
       

    }

  h1plot(&hist1,"jpm9rk_data1.pdf");
  h1plot(&hist2,"jpm9rk_data2.pdf");
  h1plot(&hist3,"jpm9rk_data3.pdf");
  h1plot(&hist4,"jpm9rk_data4.pdf");
  h1plot(&hist5,"jpm9rk_data5.pdf");
  h1plot(&hist6,"jpm9rk_data6.pdf");
  h1plot(&hist7,"jpm9rk_data7.pdf");
  h1plot(&hist8,"jpm9rk_data8.pdf");
  h1plot(&hist9,"jpm9rk_data9.pdf");

  
  
  //plotting the histograms
  //h1plot(&hist1,"");
  //h1plot(&hist2,"");
  //h1plot(&hist3,"");
  // h1plot(&hist4,"");
  //h1plot(&hist5,"");
  //h1plot(&hist6,"");
  //h1plot(&hist7,"");
  //h1plot(&hist8,"");
  //h1plot(&hist9,"");

	 fclose(fptr);


 //PART 2 STARTS HERE
 //
 //
 //
	
  h1 sig1,sig2,sig3,sig4,sig5,sig6,sig7,sig8,sig9;
  h1 bk1,bk2,bk3,bk4,bk5,bk6,bk7,bk8,bk9;

  //SIGNAL HISTOGRAMS
  h1init (&sig1,10,0,200,"Et Jet 1 signal");
  h1init (&sig2,10,0,200,"Et Jet 2 signa;");
  h1init (&sig3,10,0,200,"Et jet 3 signal");
  h1init (&sig4,10,-10,10,"Eta 1 signal");
  h1init (&sig5,10,-10,10,"Eta 2 signal");
  h1init (&sig6,10,-10,10,"Eta 3 signal");
  h1init (&sig7,25,0,500,"Met signal");
  h1init (&sig8,50,0,1000,"Ht signal");
  h1init (&sig9,10,0,10,"Njet signal");

  h1labels(&sig1,"Value of Et jet 1 signal","Frequency of value");
  h1labels(&sig2,"Value of et jet 2","Frequency of value");
  h1labels(&sig3,"Value of Et jet 3","Frequency of value");
  h1labels(&sig4,"Value of Eta 1","Frequency of value");
  h1labels(&sig5,"Value of Eta 2","Frequency of value");
  h1labels(&sig6,"Value of Eta 3","Frequency of value");
  h1labels(&sig7,"Value of Met","Frequency of value");
  h1labels(&sig8,"Value of Ht","Frequency of value");
  h1labels(&sig9,"Value of Njet","Frequency of value");


  //BKGD HISTOGRAMS
  h1init (&bk1,10,0,200,"Et Jet 1 bkgd");
  h1init (&bk2,10,0,200,"Et Jet 2 bkgd");
  h1init (&bk3,10,0,200,"Et jet 3 bkgd");
  h1init (&bk4,10,-10,10,"Eta 1 bkgd");
  h1init (&bk5,10,-10,10,"Eta 2 bkgd");
  h1init (&bk6,10,-10,10,"Eta 3 bkgd");
  h1init (&bk7,25,0,500,"Met bkgd");
  h1init (&bk8,50,0,1000,"Ht bkgd");
  h1init (&bk9,10,0,10,"Njet bkgd");

  h1labels(&bk1,"Value of Et jet 1 signal","Frequency of value");
  h1labels(&bk2,"Value of et jet 2","Frequency of value");
  h1labels(&bk3,"Value of Et jet 3","Frequency of value");
  h1labels(&bk4,"Value of Eta 1","Frequency of value");
  h1labels(&bk5,"Value of Eta 2","Frequency of value");
  h1labels(&bk6,"Value of Eta 3","Frequency of value");
  h1labels(&bk7,"Value of Met","Frequency of value");
  h1labels(&bk8,"Value of Ht","Frequency of value");
  h1labels(&bk9,"Value of Njet","Frequency of value");

 

 char names1[500],names2[500];
 fptr1=fopen("signal_templates.dat","r");
 fptr2=fopen("bkgd_templates.dat","r");
 
 //Read in data from the files
  if (fptr1==NULL)
    {
      printf("error finding file");
    }
  if(fptr2==NULL)
    {
      printf("error finding file");
    }
  //Scans in the names at the beginning of the file for both sets of data
  for(i=0;i<18;i++)
    {
      fscanf(fptr1,"%s",names1);
      fscanf(fptr2,"%s",names2);
     }

  //Scanning in the values 
  for(i=0;i<10000;i++)
    {
      
      status1= fscanf(fptr1,"%lf %lf %lf %lf %lf %lf %lf %lf %lf",&signal1[i],
		     &signal2[i],&signal3[i],&signal4[i],&signal5[i],
		     &signal6[i],&signal7[i],&signal8[i],&signal9[i]);

      //  printf("scanned signal 1 %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",signal1[i],
      //   signal2[i],signal3[i],signal4[i],signal5[i],
      //          signal6[i],signal7[i],signal8[i],signal9[i]);

  // printf("counter %d\n",counter1);

     if (status1==EOF)
       {
       break;
       }

      counter1++;
      
       
    }
  for(i=0;i<10000;i++)
    {
      
      status2= fscanf(fptr2,"%lf %lf %lf %lf %lf %lf %lf %lf %lf",&bkgd1[i],
		     &bkgd2[i],&bkgd3[i],&bkgd4[i],&bkgd5[i],
		     &bkgd6[i],&bkgd7[i],&bkgd8[i],&bkgd9[i]);
      if (status2 ==EOF)
       {
       break;
       }
      // printf("scanned signal 1 %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",bkgd1[i],
      //  bkgd2[i],bkgd3[i],bkgd4[i],bkgd5[i],
      //        bkgd6[i],bkgd7[i],bkgd8[i],bkgd9[i]);
     
     counter2++;
	
    }
  for(i=0;i<counter1;i++)
    {
      //SIGNAL HISTOGRAM
       h1fill(&sig1,signal1[i],(1/3890.0)*404);    
       h1fill(&sig2,signal2[i],(1/3890.0)*404);
       h1fill(&sig3,signal3[i],(1/3890.0)*404);
       h1fill(&sig4,signal4[i],(1/3890.0)*404);
       h1fill(&sig5,signal5[i],(1/3890.0)*404);      
       h1fill(&sig6,signal6[i],(1/3890.0)*404);
       h1fill(&sig7,signal7[i],(1/3890.0)*404);
       h1fill(&sig8,signal8[i],(1/3890.0)*404);
      
       h1fill(&sig9,signal9[i],1);


	     
       //BKGD HISTOGRAM
       h1fill(&bk1,bkgd1[i],(1/3890.0)*404);     
       h1fill(&bk2,bkgd2[i],(1/3890.0)*404);
       h1fill(&bk3,bkgd3[i],(1/3890.0)*404);
       h1fill(&bk4,bkgd4[i],(1/3890.0)*404);
       h1fill(&bk5,bkgd5[i],(1/3890.0)*404);      
       h1fill(&bk6,bkgd6[i],(1/3890.0)*404);
       h1fill(&bk7,bkgd7[i],(1/3890.0)*404);
       h1fill(&bk8,bkgd8[i],(1/3890.0)*404);
       h1fill(&bk9,bkgd9[i],(1/3890.0)*404);

       // printf("%d\n",i);

    }

  // printf("counter 1 %d\n",counter1);

  //plotting the histograms
   h1plot(&sig1,"jpm9rk_signalJet1.pdf");
   h1plot(&sig2,"jpm9rk_signalJet2.pdf");
  h1plot(&sig3,"jpm9rk_signalJet3.pdf");
  h1plot(&sig4,"jpm9rk_signalEta1.pdf");
  h1plot(&sig5,"jpm9rk_signalEta2.pdf");
  h1plot(&sig6,"jpm9rk_signalEta3.pdf");
  h1plot(&sig7,"jpm9rk_signalMet.pdf");
  h1plot(&sig8,"jpm9rk_signalHt.pdf");
  h1plot(&sig9,"jpm9rk_signalNjet.pdf");

  // h1plot(&sig1,"");
  // h1plot(&sig2,"");
  // h1plot(&sig3,"");
  // h1plot(&sig4,"");
  //  h1plot(&sig5,"");
  // h1plot(&sig6,"");
  // h1plot(&sig7,"");
  // h1plot(&sig8,"");
  // h1plot(&sig9,"");

   h1plot(&bk1,"jpm9rk_bkJet1.pdf");
   h1plot(&bk2,"jpm9rk_bkJet2.pdf");
   h1plot(&bk3,"jpm9rk_bkJet3.pdf");
   h1plot(&bk4,"jpm9rk_bkEta1.pdf");
   h1plot(&bk5,"jpm9rk_bkEta2.pdf");
   h1plot(&bk6,"jpm9rk_bkEta3.pdf");
   h1plot(&bk7,"jpm9rk_bkMet.pdf");
   h1plot(&bk8,"jpm9rk_bkHt.pdf");
   h1plot(&bk9,"jpm9rk_bkNjet.pdf");

  // h1plot(&bk1,"");
  // h1plot(&bk2,"");
  // h1plot(&bk3,"");
  // h1plot(&bk4,"");
  // h1plot(&bk5,"");
  // h1plot(&bk6,"");
  // h1plot(&bk7,"");
  // h1plot(&bk8,"");
  // h1plot(&bk9,"");




   //If I had to chose a variable to try and fit to, it would be HT because its distribution closely resembles something //  were familiar with (gaussian distribution), and its shape is similar across all 3 data sets
  
  
  double predicted,chiSquare=0,chi2,chiSquare1=0,chiCompare=5000;
  // printf("beggining of loop\n");
   for(j=0;j<50;j++)
   {
     //  printf("enetered loop\n");
     // sigBinHeight=sig8.h_array[j];
     // bkBinHeight=bk8.h_array[j];
     // dataBinHeight=hist8.h_array[j];

     // printf("sig bin height %lf\n",sig8.h_array[j]);
      
     if(hist8.h_array[j]!=0)
       {
       

     predicted=0.5*sig8.h_array[j]+0.5*bk8.h_array[j];

      chiSquare+=((hist8.h_array[j]-predicted)*(hist8.h_array[j]-predicted))/(hist8.h_array[j]);

      // printf("chi square value for 50/50 split %lf\n",chiSquare);
       }

   }


   double bkMultiplier=1.0,sigMultiplier=0.0,bkAtMin=0,sigAtMin=0;
   for(i=0;i<100;i++)
     {
       bkMultiplier=bkMultiplier-0.01;
       sigMultiplier+=0.01;

       chiSquare1=0;

       for(j=0;j<50;j++)
	 {


           if(hist8.h_array[j]!=0)
           {
       

            predicted=sigMultiplier*sig8.h_array[j]+bkMultiplier*bk8.h_array[j];

            chiSquare1+=((hist8.h_array[j]-predicted)*(hist8.h_array[j]-predicted))/(hist8.h_array[j]);

	    // printf("chi square value for %lf / %lf split %lf\n",sigMultiplier,bkMultiplier,chiSquare);
           }
	   
	 }
       chi2=sqrt(chiSquare1);
       if(chi2<chiCompare)
	 {
       chiCompare=chi2;
       bkAtMin=bkMultiplier;
       sigAtMin=sigMultiplier;
	 }

       // printf("chi 2 %lf\n",chi2);
     }

   printf("chi value is min at %lf / %lf ratio of bk and sig, the value of chi here is %lf\n",bkAtMin,sigAtMin,chiCompare);
	 
   chi=sqrt(chiSquare);

   printf("chi value for 50/50 is %lf\n",chi);

   //printf("height of bin 25 is %lf\n",sig8.h_array[24]);
	   

	   



    



 return 0;
}
