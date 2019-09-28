#include <stdio.h>

int main(){
  
  double a = 99887766.0;
  printf("The size in memory in units of bytes of the variable a is %d\n",sizeof(a));
  printf("The address in memory where a is stored is %p\n",&a);

  return 0;
}
