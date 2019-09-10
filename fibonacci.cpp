#include<stdio.h>
#include<math.h>





int fib(int n){

  int fibonacci=1;

  if(n==0)
    return 0;

  if (n==1)
    return 1;

  return  fibonacci=(fib(n-1)+fib(n-2));

 
}





int main(){

  int nPosition;


  printf("please enter a positive integer n representing the position in the Fibonacci Series, where 0 is of position 0\n");

  scanf("%d",&nPosition);

  if (nPosition<0){
  printf("error negative number entered");
  return 0;
  }
  if (nPosition<=10){
    for (int i=0;i<=nPosition;i++){
  int fibonaccinumber=fib(i);
  printf("fibonacci of position %d is %d\n",i,fibonaccinumber);
       }
    
  }
  else if (nPosition>=10){
    for(int i=0;i<=10;i++){
      int fibonaccinumber=fib(i);
      printf("fibonacci of position %d is %d\n",i,fibonaccinumber);
    }
    int fibonaccinumber1=fib(nPosition);
    printf(" fibonacci number of position %d is %d",nPosition,fibonaccinumber1);

  









  }

}
