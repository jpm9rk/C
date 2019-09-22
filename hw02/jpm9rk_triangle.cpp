#include<stdio.h>
#include<math.h>

int main()
{

  float  x1,y1,z1;

  float x2,y2,z2;

  float x3,y3,z3;

  float area;
  float scalene;

  float length1,length2,length3;
 

    FILE *inptr;

  inptr=fopen("points.dat","r");

  fscanf(inptr,"%f",&x1);
  printf("x1 coordinate is %f\n",x1);

  fscanf(inptr,"%f",&y1);
  printf("y1 coordinate is %f\n",y1);

  fscanf(inptr,"%f",&z1);
  printf("z1 coordinate is %f\n",z1);

  fscanf(inptr,"%f",&x2);
  printf("x2 coordinate is %f\n",x2);

  fscanf(inptr,"%f",&y2);
  printf("y2 coordinate is %f\n",y2);

  fscanf(inptr,"%f",&z2);
  printf("z2 coordinate is %f\n",z2);

  fscanf(inptr,"%f",&x3);
  printf("x3 coordinate is %f\n",x3);

  fscanf(inptr,"%f",&y3);
  printf("y3 coordinate is %f\n",y3);

  fscanf(inptr,"%f",&z3);
  printf("z3 coordinate is %f\n",z3);

  length1= sqrt((x2-x1)*(x2-1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
  printf("The length of side x1y1z1-->x2y2z2 is %f\n",length1); 

  length2= sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)+(z3-z2)*(z3-z2));
  printf("The length of side x2y2z2-->x3y3z3 is %f\n",length2);

length3= sqrt((x3-x1)*(x3-1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1));
  printf("The length of side x1y1z1-->x3y3z3 is %f\n",length3);

  scalene=(length1+length2+length3)/(2);

  
   area=sqrt((scalene*(scalene-length1)*(scalene-length2)*(scalene-length3)));

 printf("The area of the triangle is %f",area);


  
  


















  return 0;


}
