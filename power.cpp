#include<stdio.h>
#include<math.h>



double ipow(double x, int n){
  double answer;
  if(n==1){
    answer=x;
    return answer;
  }

  else{

  
  return answer=x*(ipow(x,(n-1)));

		   }
}


int main(){

  double x;

  int n;

  printf("please enter a floating point x and an int n\n");

  scanf("%lf  %d", &x,&n);

  if (n<0 || x<0){
    printf("error: one or more values is negative");

  return 0;
  }

   double number=ipow(x,n);

   printf("base is %lf , exponent is %d, number is %lf\n",x,n,number);




}







