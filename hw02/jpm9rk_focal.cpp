

//James Morrissey
//jpm9rk
//hw02 #3
//program name:jpm9rk_focal
//On my honor as a student I have neither given nor recieved help on this
//assignment



#include<stdio.h>
#include<math.h>

int main()
{

  float f1,f2,flength;

  printf("Please enter focal length of mirror 1, followed by focal length of mirror 2 \n");

  scanf("%f %f", &f1,&f2);

  flength=(f1*f2)/(f1+f2);

  printf("The length of mirror 1's focal length is %f\n",f1);
  printf("The length of mirror 2's focal length is %f\n",f2);
  printf("The overall focal length is %f",flength);
















  return 0;



}
