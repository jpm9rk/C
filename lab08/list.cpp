#include<stdio.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>


int main(){

srand(time(NULL));

  int randint[15];

  

  for (int i=0;i<=14;i++){



    int  x=rand() % (2+1)-1;

    randint[i]=x;


     printf("%d\n",x);

     

     }

  

  printf("\n");

 


 for (int j=14;j>-1;j--){

      int y=randint[j];

      printf("%d\n",y);











    }

  return 0;
}
