//// 
// Name:   James Morrissey
// UserId: jpm9rk
// Homework #: 2
// Problem #: 1
// Program Name: jpm9rk_coords
// Pledge Signature: On my honor as a student I have neither given nor received //help on this assignment
//
//
////






#include<stdio.h>
#include<math.h>


int main()
{
  float x,y,r,theta;

  printf("Please enter the distance r, and the angle theta measured counterclockwise with respect to the x axis in radians:\n");

  scanf("%f %f",&r,&theta);

  x=r*cos(theta);
  
  y=r*sin(theta);

  printf("In cartesian coordinates the x coordinate is %5.2f, and the y coordinate is %5.2f",x,y);





	 return 0;
	 }
	 
