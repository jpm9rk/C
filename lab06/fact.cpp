// Program file: fact.cpp
// return n! for any reasonable integer entered into the program
#include <stdio.h>

long factorial(int n);

int main(){
  int n = -1;
  printf("Enter a non-negative integer, floats will be truncated:\n");
  scanf("%i",&n);
  if(n<0){
    printf("%i! is undefined.\n",n);
    return 1;
  } else {
    printf("%i! = %ld\n",n,factorial(n));
  }
  return 0;

}

// recursive implementation of factorial algorithm
long factorial(int n){
  long answer;
  printf("factorial called w/ n = %i\n",n);
  if (n < 2 ) answer = 1;
  else {
    printf("calling factorial(n-1)\n");
    answer = (long)n * factorial(n-1);
  }
  printf("return value %ld from factorial(%i)\n", answer, n);
  return answer;
} 

