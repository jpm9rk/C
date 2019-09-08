//James Morrissey
//jpm9rk
//final
//problem1
//jpm9rk_ligo.cpp
//On my honor as a student I have neither given nor received help on this assignment



//QUESTIONS ANSWERED HERE
//
//There was 1 gravitational wave, and it lasted from approximately 1.05 seconds to 1.15 seconds, so the
//total time of the wave was about 0.1 seconds. I reached this conclusion by dividing the information
//from the two detectors into packages with the same amount of data points as the model waveform, and
//finding the chi value of each detector with regards to the model.However, I turned this into 20 periods by
//only adding half the interval to the min and max each time, so periods overlap.(i.e if there are 4000 points in the model file,
//the periods would be 0-4000,2000-6000,4000-8000...)
// If there was a possible gravity
//wave in one of these intervals, the chi value should be noticeably lower than the others during those
//two time periods. In period 10, corresponding to the interval from 0.95 to 1.15 seconds the chi
//value at the Hanford monitor was 34.37 and the inverted Livingston data had a chi value of 39.12.
//Inverting the Livingston data over this period dropped its value by about 7. By inspecting the
//graph in gnuplot of the two periods, they both display a shape similar to the model in shape and size
//from 1.05 to 1.13 seconds. It could be argued that the wave starts at 0.95, as the shape also resemble
//the model in the interval 0.95-1.15, but I would be more confident saying 1.05-1.15 is where its the
//closest.
//Period 9 was the only other period with a low chi value in both Hanford and Livingston, but the end
//of Period 9 overlaps with the beginning of Period 10, and this is probably why this period also
//has a low chi value in both detectors.
//
//There were some periods in each detector where the chi value was very low, but was not especially low
//in the other.Here I am considering low as a chi value under 40. The chi value in period 4 of the
//Hanford detector is 36.121, but 44.22 in the Livingston detector. The inverse chi value of period 7 in the
//Hanford Detector is 35.36, but the inverse and regular data at Livingston both have values over 43.
//Period 3 is also low in the Hanford detector and high in the Livingston detector, but once again this
//is most likely due to the overlap of periods.
//



#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"hist.hpp"
#include"random.hpp"

int main(){

  int i,counter1=0,counter2=0,status,status1;

  double hanStrain[50000],livStrain[50000],hanTime[50000],livTime[50000];

  char header1[100],header2[100],header3[100],header4[100],header5[50],header6[50];

  FILE *hanPtr,*livPtr;

  hanPtr=fopen("hanford_waveform_complete.dat","r");
  if(hanPtr==NULL)
    {
      printf("Error, can't find the hanford file");
    }

  fscanf(hanPtr,"%s %s %s %s %s %s",header1,header2,header3,header4,header5,header6);






  //READ IN HANFORD FILES
  hanPtr=fopen("hanford_waveform_complete.dat","r");
  if(hanPtr==NULL)
    {
      printf("Error, can't find the hanford file\n");
    }

  fscanf(hanPtr,"%s %s %s %s %s %s",header1,header2,header3,header4,header5,header6);



  for(i=0;i<50000;i++)
    {

      status=fscanf(hanPtr,"%lf %lf",&hanTime[i],&hanStrain[i]);


      if(status==EOF)
        {
        break;
        }
      counter1++;

    }

  //READ IN LIVINGSTON FILES

  livPtr=fopen("livingston_waveform_complete.dat","r");
  if(livPtr==NULL)
    {
      printf("Error, can't find the livingston file\n");
    }

  fscanf(livPtr,"%s %s %s %s %s %s",header1,header2,header3,header4,header5,header6);



  for(i=0;i<50000;i++)
    {

      status1=fscanf(livPtr,"%lf %lf",&livTime[i],&livStrain[i]);



      if(status1==EOF)
        {
        break;
        }
      counter2++;

    }

  //
  //SCANNING IN MODEL INFO
  //

  int status2,counter3=0;

  double modelTime[10000],modelStrain[10000];

  FILE *modelPtr;

  char head1[50],head2[50],head3[50],head4[50],head5[50],head6[50];

  modelPtr=fopen("hanford_GRmodel.dat","r");

  if(modelPtr==NULL)
    {
      printf("Error, can't find the model data");
    }

  fscanf(modelPtr,"%s %s %s %s %s %s",head1,head2,head3,head4,head5,head6);


  for(i=0;i<10000;i++)
    {
      status2=fscanf(modelPtr,"%lf %lf",&modelTime[i],&modelStrain[i]);


      if(status2==EOF)
        {
          break;
        }

      counter3++;
    }
  //Parcel the raw data from Hanford into packages of 3440 instances of data,
  // representing a time period of about 0.2 seconds. This is the
  //length of the time frame that is predicted for the gravitational wave.
  // Determine the chi value for each of these lengths of time when compared
  //to the predicted model. Those with the noticeably lowest chi values would be where a gravitational wave might have been detected.



  h1 model,han1,han2,han3,han4,han5,han6,han7,han8,han9,han10,han11,han12,han13,han14,han15,han16,han17,han18,han19;
  //Inverse
  h1 hanI1,hanI2,hanI3,hanI4,hanI5,hanI6,hanI7,hanI8,hanI9,hanI10,hanI11,hanI12,hanI13,hanI14,hanI15,hanI16,hanI17,hanI18,hanI19;

  h1 liv1,liv2,liv3,liv4,liv5,liv6,liv7,liv8,liv9,liv10,liv11,liv12,liv13,liv14,liv15,liv16,liv17,liv18,liv19;
  //Inverse
  h1 livI1,livI2,livI3,livI4,livI5,livI6,livI7,livI8,livI9,livI10,livI11,livI12,livI13,livI14,livI15,livI16,livI17,livI18,livI19;



  //
  //HISTOGRAM MODEL
  //
  h1init(&model,80,-2.0,2.0,"Model Strain");
  h1labels(&model,"Value of strain","Frequency of Value");

  //Filling model with 3440 values to compare intervals in the data with

  for(i=0;i<counter3;i++)
    {
      h1fill(&model,modelStrain[i]);
    }

  // h1plot(&model,"");

  //
  //OTHER MODELS
  //


  //HANFORD HISTOGRAMS
   h1init (&han1,80,-2,2,"0 to 0.2 seconds");
   h1init (&han2,80,-2,2,"0.1 to 0.3 seconds");
   h1init (&han3,80,-2,2,"0.2 to 0.4 seconds");
   h1init (&han4,80,-2,2,"0.3 to 0.5 seconds");
   h1init (&han5,80,-2,2,"0.4 to 0.6 seconds");
   h1init (&han6,80,-2,2,"0.5 to 0.7 seconds");
   h1init (&han7,80,-2,2,"0.6 to 0.8 seconds");
   h1init (&han8,80,-2,2,"0.7 to 0.9 seconds");
   h1init (&han9,80,-2,2,"0.8 to 1.0 seconds");
   h1init (&han10,80,-2,2,"0.9 to 1.1 seconds");
   h1init (&han11,80,-2,2,"1.0 to 1.2 seconds");
   h1init (&han12,80,-2,2,"1.1 to 1.3 seconds");
   h1init (&han13,80,-2,2,"1.2 to 1.4 seconds");
   h1init (&han14,80,-2,2,"1.3 to 1.6 seconds");
   h1init (&han15,80,-2,2,"1.4 to 1.6 seconds");
   h1init (&han16,80,-2,2,"1.5 to 1.7 seconds");
   h1init (&han17,80,-2,2,"1.6 to 1.8 seconds");
   h1init (&han18,80,-2,2,"1.7 to 1.9 seconds");
   h1init (&han19,80,-2,2,"1.8 to 2.0 seconds");


   //Inverse

   h1init (&hanI1,80,-2,2,"0 to 0.2 seconds");
   h1init (&hanI2,80,-2,2,"0.1 to 0.3 seconds");
   h1init (&hanI3,80,-2,2,"0.2 to 0.4 seconds");
   h1init (&hanI4,80,-2,2,"0.3 to 0.5 seconds");
   h1init (&hanI5,80,-2,2,"0.4 to 0.6 seconds");
   h1init (&hanI6,80,-2,2,"0.5 to 0.7 seconds");
   h1init (&hanI7,80,-2,2,"0.6 to 0.8 seconds");
   h1init (&hanI8,80,-2,2,"0.7 to 0.9 seconds");
   h1init (&hanI9,80,-2,2,"0.8 to 1.0 seconds");
   h1init (&hanI10,80,-2,2,"0.9 to 1.1 seconds");
   h1init (&hanI11,80,-2,2,"1.0 to 1.2 seconds");
   h1init (&hanI12,80,-2,2,"1.1 to 1.3 seconds");
   h1init (&hanI13,80,-2,2,"1.2 to 1.4 seconds");
   h1init (&hanI14,80,-2,2,"1.3 to 1.6 seconds");
   h1init (&hanI15,80,-2,2,"1.4 to 1.6 seconds");
   h1init (&hanI16,80,-2,2,"1.5 to 1.7 seconds");
   h1init (&hanI17,80,-2,2,"1.6 to 1.8 seconds");
   h1init (&hanI18,80,-2,2,"1.7 to 1.9 seconds");
   h1init (&hanI19,80,-2,2,"1.8 to 2.0 seconds");




   h1labels(&han1,"Hanford Strain","Frequency of value");
   h1labels(&han2,"Hanford Strain","Frequency of value");
   h1labels(&han3,"Hanford Strain","Frequency of value");
   h1labels(&han4,"Hanford Strain","Frequency of value");
   h1labels(&han5,"Hanford Strain","Frequency of value");
   h1labels(&han6,"Hanford Strain","Frequency of value");
   h1labels(&han7,"Hanford Strain","Frequency of value");
   h1labels(&han8,"Hanford Strain","Frequency of value");
   h1labels(&han9,"Hanford Strain","Frequency of value");
   h1labels(&han10,"Hanford Strain","Frequency of value");
   h1labels(&han11,"Hanford Strain","Frequency of value");
   h1labels(&han12,"Hanford Strain","Frequency of value");
   h1labels(&han13,"Hanford Strain","Frequency of value");
   h1labels(&han14,"Hanford Strain","Frequency of value");
   h1labels(&han15,"Hanford Strain","Frequency of value");
   h1labels(&han16,"Hanford Strain","Frequency of value");
   h1labels(&han17,"Hanford Strain","Frequency of value");
   h1labels(&han18,"Hanford Strain","Frequency of value");
   h1labels(&han19,"Hanford Strain","Frequency of value");



   //LIVINGSTON HISTOGRAMS

   h1init (&liv1,80,-2,2,"0 to 0.2 seconds");
   h1init (&liv2,80,-2,2,"0.1 to 0.3 seconds");
   h1init (&liv3,80,-2,2,"0.2 to 0.4 seconds");
   h1init (&liv4,80,-2,2,"0.3 to 0.5 seconds");
   h1init (&liv5,80,-2,2,"0.4 to 0.6 seconds");
   h1init (&liv6,80,-2,2,"0.5 to 0.7 seconds");
   h1init (&liv7,80,-2,2,"0.6 to 0.8 seconds");
   h1init (&liv8,80,-2,2,"0.7 to 0.9 seconds");
   h1init (&liv9,80,-2,2,"0.8 to 1.0 seconds");
   h1init (&liv10,80,-2,2,"0.9 to 1.1 seconds");
   h1init(&liv11,80,-2,2,"fu");
   h1init (&liv12,80,-2,2,"1.0 to 1.2 seconds");
   h1init (&liv13,80,-2,2,"1.1 to 1.3 seconds");
   h1init (&liv14,80,-2,2,"1.2 to 1.4 seconds");
   h1init (&liv15,80,-2,2,"1.3 to 1.5 seconds");
   h1init (&liv16,80,-2,2,"1.4 to 1.6 seconds");
   h1init (&liv17,80,-2,2,"1.5 to 1.7 seconds");
   h1init (&liv18,80,-2,2,"1.6 to 1.8 seconds");
   h1init (&liv19,80,-2,2,"1.7 to 1.9 seconds");

   //Inverse

   h1init (&livI1,80,-2,2,"0 to 0.2 seconds");
   h1init (&livI2,80,-2,2,"0.1 to 0.3 seconds");
   h1init (&livI3,80,-2,2,"0.2 to 0.4 seconds");
   h1init (&livI4,80,-2,2,"0.3 to 0.5 seconds");
   h1init (&livI5,80,-2,2,"0.4 to 0.6 seconds");
   h1init (&livI6,80,-2,2,"0.5 to 0.7 seconds");
   h1init (&livI7,80,-2,2,"0.6 to 0.8 seconds");
   h1init (&livI8,80,-2,2,"0.7 to 0.9 seconds");
   h1init (&livI9,80,-2,2,"0.8 to 1.0 seconds");
   h1init (&livI10,80,-2,2,"0.9 to 1.1 seconds");
   h1init(&livI11,80,-2,2,"fu");
   h1init (&livI12,80,-2,2,"1.0 to 1.2 seconds");
   h1init (&livI13,80,-2,2,"1.1 to 1.3 seconds");
   h1init (&livI14,80,-2,2,"1.2 to 1.4 seconds");
   h1init (&livI15,80,-2,2,"1.3 to 1.5 seconds");
   h1init (&livI16,80,-2,2,"1.4 to 1.6 seconds");
   h1init (&livI17,80,-2,2,"1.5 to 1.7 seconds");
   h1init (&livI18,80,-2,2,"1.6 to 1.8 seconds");
   h1init (&livI19,80,-2,2,"1.7 to 1.9 seconds");

   h1labels(&liv1,"Livingston Strain","Frequency of value");
   h1labels(&liv2,"Livingston Strain","Frequency of value");
   h1labels(&liv3,"Livingston  Strain","Frequency of value");
   h1labels(&liv4,"Livingston Strain","Frequency of value");
   h1labels(&liv5,"Livingston Strain","Frequency of value");
   h1labels(&liv6,"Livingston Strain","Frequency of value");
   h1labels(&liv7,"Livingston Strain","Frequency of value");
   h1labels(&liv8,"Livingston Strain","Frequency of value");
   h1labels(&liv9,"Livingston Strain","Frequency of value");
   h1labels(&liv10,"Livingston Strain","Frequency of value");
   h1labels(&liv11,"Livingston Strain","Frequency of value");
   h1labels(&liv12,"Livingston Strain","Frequency of value");
   h1labels(&liv13,"Livingston Strain","Frequency of value");
   h1labels(&liv14,"Livingston Strain","Frequency of value");
   h1labels(&liv15,"Livingston Strain","Frequency of value");
   h1labels(&liv16,"Livingston Strain","Frequency of value");
   h1labels(&liv17,"Livingston Strain","Frequency of value");
   h1labels(&liv18,"Livingston Strain","Frequency of value");
   h1labels(&liv19,"Livingston Strain","Frequency of value");






   //
   //FILLING HANFORD HISTOGRAMS FOR THE CHOSEN TIME PERIODS
   //


   //Compare the first 3440 values in the hanford data with the model, also fill in inverse
   for(i=0;i<3440;i++)
     {

     h1fill(&han1,hanStrain[i]);
     h1fill(&hanI1,(-hanStrain[i]));

     }

   //Compare the values 1720 to 5160 with the model

   for(i=1720;i<5160;i++)
     {

       h1fill(&han2,hanStrain[i]);
       h1fill(&hanI2,(-hanStrain[i]));
     }
   //Compare values 3440 to 6880 with the model
   for(i=3440;i<6880;i++)
     {

     h1fill(&han3,hanStrain[i]);
     h1fill(&hanI3,(-hanStrain[i]));

     }

   //Compare the values 5160 to 8600 with the model

   for(i=5160;i<8600;i++)
     {

       h1fill(&han4,hanStrain[i]);
       h1fill(&hanI4,(-hanStrain[i]));
     }
   //Compare the values 6880 to 10320 with the model
   for(i=6880;i<10320;i++)
     {

     h1fill(&han5,hanStrain[i]);
     h1fill(&hanI5,(-hanStrain[i]));

     }

   //Compare the values 8600 to 12040 with the model

   for(i=8600;i<12040;i++)
     {

       h1fill(&han6,hanStrain[i]);
       h1fill(&hanI6,(-hanStrain[i]));
     }
   //Compare value 10320 to 13760 with the model
   for(i=10320;i<13760;i++)
     {

     h1fill(&han7,hanStrain[i]);
     h1fill(&hanI7,(-hanStrain[i]));

     }

   //Compare the values 12040 to 15480 with the model

   for(i=12040;i<15480;i++)
     {

       h1fill(&han8,hanStrain[i]);
       h1fill(&hanI8,(-hanStrain[i]));
     }
   //Compares values 13760 to 17200 with model
   for(i=13760;i<17200;i++)
     {

     h1fill(&han9,hanStrain[i]);
     h1fill(&hanI9,(-hanStrain[i]));

     }

   //Compare the values 15480 to 18920 with the model

   for(i=15480;i<18920;i++)
     {

       h1fill(&han10,hanStrain[i]);
       h1fill(&hanI10,(-hanStrain[i]));
     }
   //Compares values 17200 to 20640 with the model
   for(i=17200;i<20640;i++)
     {

     h1fill(&han11,hanStrain[i]);
     h1fill(&hanI11,(-hanStrain[i]));

     }

   //Compare the values 18920 to 22360 with the model

   for(i=18920;i<22360;i++)
     {

       h1fill(&han12,hanStrain[i]);
       h1fill(&hanI12,(-hanStrain[i]));
     }
   //Compares the values 20640 through 24080 with the model
   for(i=20640;i<24080;i++)
     {

     h1fill(&han13,hanStrain[i]);
     h1fill(&hanI13,(-hanStrain[i]));

     }

   //Compare the values 22360 to 25800 with the model

   for(i=22360;i<25800;i++)
     {

       h1fill(&han14,hanStrain[i]);
       h1fill(&hanI14,(-hanStrain[i]));
     }

   //Compare the values 24080 to 27520 with the model
   for(i=24080;i<27520;i++)
     {

     h1fill(&han15,hanStrain[i]);
     h1fill(&hanI15,(-hanStrain[i]));

     }

   //Compare the values 25800 to 29240 with the model

   for(i=25800;i<29240;i++)
     {

       h1fill(&han16,hanStrain[i]);
       h1fill(&hanI16,(-hanStrain[i]));
     }
   //Compare the values 275200 to 30960 with the model
   for(i=275200;i<30960;i++)
     {

     h1fill(&han17,hanStrain[i]);
     h1fill(&hanI17,(-hanStrain[i]));

     }

   //Compare the values 29240 to 32680 with the model

   for(i=29240;i<32680;i++)
     {

       h1fill(&han18,hanStrain[i]);
       h1fill(&hanI18,(-hanStrain[i]));
     }

   //Compare the values 30960 to 33981 with the model
   for(i=30960;i<33981;i++)
     {

     h1fill(&han19,hanStrain[i]);
     h1fill(&hanI19,(-hanStrain[i]));

     }






   //
   //FILLING LIVINGSTON HISTOGRAMS FOR THE CHOSEN TIME PERIOD
   //

   //Compare the first 3440 values in the hanford data with the model
   for(i=0;i<3440;i++)
     {

     h1fill(&liv1,livStrain[i]);
     h1fill(&livI1,(-livStrain[i]));

     }

   //Compare the values 1720 to 5160 with the model

   for(i=1720;i<5160;i++)
     {

       h1fill(&liv2,livStrain[i]);
       h1fill(&livI2,(-livStrain[i]));

     }
   //Compare values 3440 to 6880 with the model
   for(i=3440;i<6880;i++)
     {

     h1fill(&liv3,livStrain[i]);
     h1fill(&livI3,(-livStrain[i]));
     }

   //Compare the values 5160 to 8600 with the model

   for(i=5160;i<8600;i++)
     {

       h1fill(&liv4,livStrain[i]);
     h1fill(&livI4,(-livStrain[i]));
     }
   //Compare the values 6880 to 10320 with the model
   for(i=6880;i<10320;i++)
     {

     h1fill(&liv5,livStrain[i]);
     h1fill(&livI5,(-livStrain[i]));
     }

   //Compare the values 8600 to 12040 with the model

   for(i=8600;i<12040;i++)
     {

       h1fill(&liv6,livStrain[i]);
     h1fill(&livI6,(-livStrain[i]));
     }
   //Compare value 10320 to 13760 with the model
   for(i=10320;i<13760;i++)
     {

     h1fill(&liv7,livStrain[i]);
     h1fill(&livI7,(-livStrain[i]));
     }

   //Compare the values 12040 to 15480 with the model

   for(i=12040;i<15480;i++)
     {

       h1fill(&liv8,livStrain[i]);
     h1fill(&livI8,(-livStrain[i]));
     }
   //Compares values 13760 to 17200 with model
   for(i=13760;i<17200;i++)
     {

     h1fill(&liv9,livStrain[i]);
     h1fill(&livI9,(-livStrain[i]));

     }

   //Compare the values 15480 to 18920 with the model

   for(i=15480;i<18920;i++)
     {

       h1fill(&liv10,livStrain[i]);
     h1fill(&livI10,(-livStrain[i]));
     }
   //Compares values 17200 to 20640 with the model
   for(i=17200;i<20640;i++)
     {

     h1fill(&liv11,livStrain[i]);
     h1fill(&livI11,(-livStrain[i]));

     }

   //Compare the values 18920 to 22360 with the model

   for(i=18920;i<22360;i++)
     {

       h1fill(&liv12,livStrain[i]);
     h1fill(&livI12,(-livStrain[i]));
     }
   //Compares the values 20640 through 24080 with the model
   for(i=20640;i<24080;i++)
     {

     h1fill(&liv13,livStrain[i]);
     h1fill(&livI13,(-livStrain[i]));

     }

   //Compare the values 22360 to 25800 with the model

   for(i=22360;i<25800;i++)
     {

       h1fill(&liv14,livStrain[i]);
     h1fill(&livI14,(-livStrain[i]));
     }

   //Compare the values 24080 to 27520 with the model
   for(i=24080;i<27520;i++)
     {

     h1fill(&liv15,livStrain[i]);
     h1fill(&livI15,(-livStrain[i]));

     }

   //Compare the values 25800 to 29240 with the model

   for(i=25800;i<29240;i++)

     {
       h1fill(&liv16,livStrain[i]);
       h1fill(&livI16,(-livStrain[i]));


     }
   //Compare the values 275200 to 30960 with the model
   for(i=275200;i<30960;i++)
     {

     h1fill(&liv17,livStrain[i]);
     h1fill(&livI17,(-livStrain[i]));

     }

   //Compare the values 29240 to 32680 with the model

   for(i=29240;i<32680;i++)
     {

       h1fill(&liv18,livStrain[i]);
       h1fill(&livI18,(-livStrain[i]));
     }

   //Compare the values 30960 to 33981 with the model
   for(i=30960;i<33981;i++)
     {

     h1fill(&liv19,livStrain[i]);
     h1fill(&livI19,(-livStrain[i]));

     }


   //
   //DETERMINING CHI VALUE FOR THE TIME PERIODS OF HANFORD AND LIVINGSTON
   //


   double hanChi1=0,hanChi2=0,hanChi3=0,hanChi4=0,hanChi5=0,hanChi6=0,hanChi7=0,hanChi8=0,hanChi9=0,hanChi10=0,hanChi11=0,hanChi12=0,hanChi13=0,hanChi14=0,hanChi15=0,
     hanChi16=0,hanChi17=0,hanChi18=0,hanChi19=0;

   //Inverse

   double hanChiI1=0,hanChiI2=0,hanChiI3=0,hanChiI4=0,hanChiI5=0,hanChiI6=0,hanChiI7=0,hanChiI8=0,hanChiI9=0,hanChiI10=0,hanChiI11=0,hanChiI12=0,hanChiI13=0,hanChiI14=0,hanChiI15=0,
     hanChiI16=0,hanChiI17=0,hanChiI18=0,hanChiI19=0;


   double livChi1=0,livChi2=0,livChi3=0,livChi4=0,livChi5=0,livChi6=0,livChi7=0,livChi8=0,livChi9=0,livChi10=0,livChi11=0,livChi12=0,livChi13=0,livChi14=0,livChi15=0,
     livChi16=0,livChi17=0,livChi18=0,livChi19=0;

   //Inverse

   double livChiI1=0,livChiI2=0,livChiI3=0,livChiI4=0,livChiI5=0,livChiI6=0,livChiI7=0,livChiI8=0,livChiI9=0,livChiI10=0,livChiI11=0,livChiI12=0,livChiI13=0,livChiI14=0,livChiI15=0,
     livChiI16=0,livChiI17=0,livChiI18=0,livChiI19=0;




   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi1+=((han1.h_array[i]-model.h_array[i])*(han1.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI1+=((hanI1.h_array[i]-model.h_array[i])*(hanI1.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   hanChi1=sqrt(hanChi1);
   hanChiI1=sqrt(hanChiI1);

   printf("Hanford chi value 1 is %lf\n",hanChi1);
   printf("Hanford inverse chi value 1 is %lf\n",hanChiI1);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi2+=((han2.h_array[i]-model.h_array[i])*(han2.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI2+=((hanI2.h_array[i]-model.h_array[i])*(hanI2.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   hanChi2=sqrt(hanChi2);
   hanChiI2=sqrt(hanChiI2);

   printf("Hanford chi value 2 is %lf\n",hanChi2);
   printf("Hanfordchi inverse 2 is %lf\n",hanChiI2);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi3+=((han3.h_array[i]-model.h_array[i])*(han3.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI3+=((hanI3.h_array[i]-model.h_array[i])*(hanI3.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   hanChi3=sqrt(hanChi3);
   hanChiI3=sqrt(hanChiI3);

   printf("Hanford chi value 3 is %lf\n",hanChi3);
   printf("Hanford chi inverse 3 is %lf\n",hanChiI3);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi4+=((han4.h_array[i]-model.h_array[i])*(han4.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI4+=((hanI4.h_array[i]-model.h_array[i])*(hanI4.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi4=sqrt(hanChi4);
   hanChiI4=sqrt(hanChiI4);

   printf("Hanford chi value 4 is %lf\n",hanChi4);
   printf("Hanford chi inverse 4 is %lf\n",hanChiI4);


   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi5+=((han5.h_array[i]-model.h_array[i])*(han5.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI5+=((hanI5.h_array[i]-model.h_array[i])*(hanI5.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi5=sqrt(hanChi5);
   hanChiI5=sqrt(hanChiI5);

   printf("Hanford chi value 5 is %lf\n",hanChi5);
   printf("Hanford chi inverse 5 is %lf\n",hanChiI5);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi6+=((han6.h_array[i]-model.h_array[i])*(han6.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI6+=((hanI6.h_array[i]-model.h_array[i])*(hanI6.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi6=sqrt(hanChi6);
   hanChiI6=sqrt(hanChiI6);

   printf("Hanford chi value 6 is %lf\n",hanChi6);
   printf("Hanford chi inverse 6 is %lf\n",hanChiI6);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi7+=((han7.h_array[i]-model.h_array[i])*(han7.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI7+=((hanI7.h_array[i]-model.h_array[i])*(hanI7.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi7=sqrt(hanChi7);
   hanChiI7=sqrt(hanChiI7);

   printf("Hanford chi value 7 is %lf\n",hanChi7);
   printf("Hanford chi inverse 7 is %lf\n",hanChiI7);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi8+=((han8.h_array[i]-model.h_array[i])*(han8.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI8+=((hanI8.h_array[i]-model.h_array[i])*(hanI8.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi8=sqrt(hanChi8);
   hanChiI8=sqrt(hanChiI8);

   printf("Hanford chi value 8 is %lf\n",hanChi8);
   printf("Hanford chi inverse 8 is %lf\n",hanChiI8);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi9+=((han9.h_array[i]-model.h_array[i])*(han9.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI9+=((hanI9.h_array[i]-model.h_array[i])*(hanI9.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi9=sqrt(hanChi9);
   hanChiI9=sqrt(hanChiI9);

   printf("Hanford chi value 9 is %lf\n",hanChi9);
   printf("Hanford chi inverse 9 is %lf\n",hanChiI9);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
           hanChi10+=((han10.h_array[i]-model.h_array[i])*(han10.h_array[i]-model.h_array[i]))/(model.h_array[i]);
 hanChiI10+=((hanI10.h_array[i]-model.h_array[i])*(hanI10.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi10=sqrt(hanChi10);
   hanChiI10=sqrt(hanChiI10);

   printf("Hanford chi value 10 is %lf\n",hanChi10);
   printf("Hanford chi inverse 10 is %lf\n",hanChiI10);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
           hanChi11+=((han11.h_array[i]-model.h_array[i])*(han11.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI11+=((hanI11.h_array[i]-model.h_array[i])*(hanI11.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi11=sqrt(hanChi11);
   hanChiI11=sqrt(hanChiI11);

   printf("Hanford chi value 11 is %lf\n",hanChi11);
   printf("Hanford chi inverse 11 is %lf\n",hanChiI11);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi12+=((han12.h_array[i]-model.h_array[i])*(han12.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI12+=((hanI12.h_array[i]-model.h_array[i])*(hanI12.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi12=sqrt(hanChi12);
   hanChiI12=sqrt(hanChiI12);

   printf("Hanford chi value 12 is %lf\n",hanChi12);
   printf("Hanford chi inverse 12 is %lf\n",hanChiI12);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi13+=((han13.h_array[i]-model.h_array[i])*(han13.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI13+=((hanI13.h_array[i]-model.h_array[i])*(hanI13.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi13=sqrt(hanChi13);
   hanChiI13=sqrt(hanChiI13);

   printf("Hanford chi value 13 is %lf\n",hanChi13);
   printf("Hanford chi inverse 13 is %lf\n",hanChiI13);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi14+=((han14.h_array[i]-model.h_array[i])*(han14.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI14+=((hanI14.h_array[i]-model.h_array[i])*(hanI14.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi14=sqrt(hanChi14);
   hanChiI14=sqrt(hanChiI14);

   printf("Hanford chi value 14 is %lf\n",hanChi14);
   printf("Hanford chi inverse 14 is %lf\n",hanChiI14);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi15+=((han15.h_array[i]-model.h_array[i])*(han15.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI15+=((hanI15.h_array[i]-model.h_array[i])*(hanI15.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi15=sqrt(hanChi15);
   hanChiI15=sqrt(hanChiI15);

   printf("Hanford chi value 15 is %lf\n",hanChi15);
   printf("Hanford chi inverse 15 is %lf\n",hanChiI15);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi16+=((han16.h_array[i]-model.h_array[i])*(han16.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI16+=((hanI16.h_array[i]-model.h_array[i])*(hanI16.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi16=sqrt(hanChi16);
   hanChiI16=sqrt(hanChiI16);

   printf("Hanford chi value 16 is %lf\n",hanChi16);
   printf("Hanford chi inverse 16 is %lf\n",hanChiI16);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi17+=((han17.h_array[i]-model.h_array[i])*(han17.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI17+=((hanI17.h_array[i]-model.h_array[i])*(hanI17.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi17=sqrt(hanChi17);
   hanChiI17=sqrt(hanChiI17);

   printf("Hanford chi value 17 is %lf\n",hanChi17);
   printf("Hanford chi inverse 17 is %lf\n",hanChiI17);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi18+=((han18.h_array[i]-model.h_array[i])*(han18.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI18+=((hanI18.h_array[i]-model.h_array[i])*(hanI18.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi18=sqrt(hanChi18);
   hanChiI18=sqrt(hanChiI18);

   printf("Hanford chi value 18 is %lf\n",hanChi18);
   printf("Hanford chi inverse 18 is %lf\n",hanChiI18);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       hanChi19+=((han19.h_array[i]-model.h_array[i])*(han19.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       hanChiI19+=((hanI19.h_array[i]-model.h_array[i])*(hanI19.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }

   hanChi19=sqrt(hanChi19);
   hanChiI19=sqrt(hanChiI19);

   printf("Hanford chi value 19 is %lf\n",hanChi19);
   printf("Hanford chi inverse 19 is %lf\n",hanChiI19);

   //
   //LIVINGSTON CHI VALUES
   //

   printf("LIVINGSTON\n");

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi1+=((liv1.h_array[i]-model.h_array[i])*(liv1.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI1+=((livI1.h_array[i]-model.h_array[i])*(livI1.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi1=sqrt(livChi1);
   livChiI1=sqrt(livChiI1);

   printf("Livingston chi value 1 is %lf\n",livChi1);
   printf("Livingston chi inverse 1 is %lf\n",livChiI1);


   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi2+=((liv2.h_array[i]-model.h_array[i])*(liv2.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI2+=((livI2.h_array[i]-model.h_array[i])*(livI2.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi2=sqrt(livChi2);
   livChiI2=sqrt(livChiI2);

   printf("Livingston chi value 2 is %lf\n",livChi2);
   printf("Livingston chi inverse 2 is %lf\n",livChiI2);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi3+=((liv3.h_array[i]-model.h_array[i])*(liv3.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI3+=((livI3.h_array[i]-model.h_array[i])*(livI3.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi3=sqrt(livChi3);
   livChiI3=sqrt(livChiI3);

   printf("Livingston chi value 3 is %lf\n",livChi3);
   printf("Livingston chi inverse 3 is %lf\n",livChiI3);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi4+=((liv4.h_array[i]-model.h_array[i])*(liv4.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI4+=((livI4.h_array[i]-model.h_array[i])*(livI4.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi4=sqrt(livChi4);
   livChiI4=sqrt(livChiI4);

   printf("Livingston chi value 4 is %lf\n",livChi4);
   printf("Livingston chi inverse 4 is %lf\n",livChiI4);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi5+=((liv5.h_array[i]-model.h_array[i])*(liv5.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI5+=((livI5.h_array[i]-model.h_array[i])*(livI5.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi5=sqrt(livChi5);
   livChiI5=sqrt(livChiI5);

   printf("Livingston chi value 5 is %lf\n",livChi5);
   printf("Livingston chi inverse 5 is %lf\n",livChiI5);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi6+=((liv6.h_array[i]-model.h_array[i])*(liv6.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI6+=((livI6.h_array[i]-model.h_array[i])*(livI6.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi6=sqrt(livChi6);
   livChiI6=sqrt(livChiI6);

   printf("Livingston chi value 6 is %lf\n",livChi6);
   printf("Livingston chi inverse 6 is %lf\n",livChiI6);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi7+=((liv7.h_array[i]-model.h_array[i])*(liv7.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI7+=((livI7.h_array[i]-model.h_array[i])*(livI7.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi7=sqrt(livChi7);
   livChiI7=sqrt(livChiI7);

   printf("Livingston chi value 7 is %lf\n",livChi7);
   printf("Livingston chi inverse 7 is %lf\n",livChiI7);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi8+=((liv8.h_array[i]-model.h_array[i])*(liv8.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI8+=((livI8.h_array[i]-model.h_array[i])*(livI8.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi8=sqrt(livChi8);
   livChiI8=sqrt(livChiI8);

   printf("Livingston chi value 8 is %lf\n",livChi8);
   printf("Livingston chi inverse 8 is %lf\n",livChiI8);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi9+=((liv9.h_array[i]-model.h_array[i])*(liv9.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI9+=((livI9.h_array[i]-model.h_array[i])*(livI9.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi9=sqrt(livChi9);
   livChiI9=sqrt(livChiI9);

   printf("Livingston chi value 9 is %lf\n",livChi9);
   printf("Livingston chi inverse 9 is %lf\n",livChiI9);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi10+=((liv10.h_array[i]-model.h_array[i])*(liv10.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI10+=((livI10.h_array[i]-model.h_array[i])*(livI10.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi10=sqrt(livChi10);
   livChiI10=sqrt(livChiI10);

   printf("Livingston chi value 10 is %lf\n",livChi10);
   printf("Livingston chi inverse 10 is %lf\n",livChiI10);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
           livChi11+=((liv11.h_array[i]-model.h_array[i])*(liv11.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI11+=((livI11.h_array[i]-model.h_array[i])*(livI11.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi11=sqrt(livChi11);
   livChiI11=sqrt(livChiI11);

   printf("Livingston chi value 11 is %lf\n",livChi11);
   printf("Livingston chi inverse 11 is %lf\n",livChiI11);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi12+=((liv12.h_array[i]-model.h_array[i])*(liv12.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI12+=((livI12.h_array[i]-model.h_array[i])*(livI12.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi12=sqrt(livChi12);
   livChiI12=sqrt(livChiI12);

   printf("Livingston chi value 12 is %lf\n",livChi12);
   printf("Livingston chi inverse 12 is %lf\n",livChiI12);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi13+=((liv13.h_array[i]-model.h_array[i])*(liv13.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI13+=((livI13.h_array[i]-model.h_array[i])*(livI13.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi13=sqrt(livChi13);
   livChiI13=sqrt(livChiI13);

   printf("Livingston chi value 13 is %lf\n",livChi13);
   printf("Livingston chi inverse 13 is %lf\n",livChiI13);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi14+=((liv14.h_array[i]-model.h_array[i])*(liv14.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI14+=((livI14.h_array[i]-model.h_array[i])*(livI14.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi14=sqrt(livChi14);
   livChiI14=sqrt(livChiI14);

   printf("Livingston chi value 14 is %lf\n",livChi14);
   printf("Livingston chi inverse 14 is %lf\n",livChiI14);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi15+=((liv15.h_array[i]-model.h_array[i])*(liv15.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI15+=((livI15.h_array[i]-model.h_array[i])*(livI15.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi15=sqrt(livChi15);
   livChiI15=sqrt(livChiI15);

   printf("Livingston chi value 15 is %lf\n",livChi15);
   printf("Livingston chi inverse 15 is %lf\n",livChiI15);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi16+=((liv16.h_array[i]-model.h_array[i])*(liv16.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI16+=((livI16.h_array[i]-model.h_array[i])*(livI16.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi16=sqrt(livChi16);
   livChiI16=sqrt(livChiI16);

   printf("Livingston chi value 16 is %lf\n",livChi16);
   printf("Livingston chi inverse 16 is %lf\n",livChiI16);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi17+=((liv17.h_array[i]-model.h_array[i])*(liv17.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI17+=((livI17.h_array[i]-model.h_array[i])*(livI17.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi17=sqrt(livChi17);
   livChiI17=sqrt(livChiI17);

   printf("Livingston chi value 17 is %lf\n",livChi17);
   printf("Livingston chi inverse 17 is %lf\n",livChiI17);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi18+=((liv18.h_array[i]-model.h_array[i])*(liv18.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI18+=((livI18.h_array[i]-model.h_array[i])*(livI18.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi18=sqrt(livChi18);
   livChiI18=sqrt(livChiI18);

   printf("Livingston chi value 18 is %lf\n",livChi18);
   printf("Livingston chi inverse 18 is %lf\n",livChiI18);

   for(i=0;i<80;i++)
     {
       if(model.h_array[i]!=0)
         {
       livChi19+=((liv19.h_array[i]-model.h_array[i])*(liv19.h_array[i]-model.h_array[i]))/(model.h_array[i]);
       livChiI19+=((livI19.h_array[i]-model.h_array[i])*(livI19.h_array[i]-model.h_array[i]))/(model.h_array[i]);
         }
     }
   livChi19=sqrt(livChi19);
   livChiI19=sqrt(livChiI19);

   printf("Livingston chi value 19 is %lf\n",livChi19);
   printf("Livingston chi inverse 19 is %lf\n",livChiI19);

   FILE *gptr=fopen("grav.dat","w");

   FILE *g1ptr=fopen("grav1.dat","w");

   for(i=15480;i<18920;i++)
     {
       fprintf(gptr,"%lf %lf\n",hanTime[i],hanStrain[i]);
       fprintf(g1ptr,"%lf %lf\n",livTime[i],(-livStrain[i]));
     }

   double livHanChi=0;

   for(i=0;i<80;i++)
     {
       if(livI10.h_array[i]!=0)
         {
           livHanChi+=((livI10.h_array[i]-han10.h_array[i])*(livI10.h_array[i]-han10.h_array[i]))/(model.h_array[i]);
         }
     }
   livHanChi=sqrt(livHanChi);

   printf("hanford and livingston period 10 combined chi %lf\n",livHanChi);


  return 0;
}
