
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 100

int main(){

srand(time(NULL));





 int randNum[SIZE];

 for (int i=0;i<100;i++)

   {

      int random= rand()%30+1;

       randNum[i]=random;
 }

 int j;
 
 int max=0;

 
 int  countArray[SIZE];

  for(int i=0;i<SIZE;i++)
  {
       countArray[i]=0;
       }
 
for(j=0;j<SIZE;j++)

 
   { 
     countArray[randNum[j]]++;
     
   }
    
 for(j=1;j<31;j++){
   
   printf("count of number %d is %d\n",j,countArray[j]);
	  }

  for(j=0;j<SIZE;j++){

     if(countArray[j]>max)
  max=countArray[j];

   }

   for (j=0;j<SIZE+1;j++)
     {

     if(countArray[j]==max)
  printf("Mode(s) is %d\n",j);

    }


	    


 
  return 0;


}
