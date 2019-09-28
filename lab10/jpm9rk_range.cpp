#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include"random.hpp"
#include"hist.hpp"


#define PI 3.14159

#define GRAV 9.81
double rangeFunc(double vZero, double thetaZero)
{

  double thetaRad=thetaZero*(PI/180);
  double  answer=((vZero*vZero)*sin(2*thetaRad))/GRAV;
  return answer;
}

double maxHeight(double vZero,double thetaZero)
{
  double thetaRad=thetaZero*(PI/180);
  double answer=((vZero*vZero)*sin(thetaRad)*sin(thetaRad))/(2*GRAV);
  return answer;

}

double timeFunc(double vZero,double thetaZero)
{
  double thetaRad=thetaZero*(PI/180);
  double answer=((2*vZero)*(sin(thetaRad)))/GRAV;
  return answer;


}
  int main(){

    srand(time(NULL));

    h1 histRange;

    int i;

    histRange(&histRange,10.,30.); 

  double theta,vInit;

  printf("please enter the initial launch angle and initial velocity\n");

  // scanf("%lf %lf",&theta,&vInit);

  // printf("range is %lf , max height is %lf, time is %lf\n",rangeFunc(theta,vInit),maxHeight(theta,vInit),timeFunc(theta,vInit));

  for (i=0;i<10000;i++)
    {
      double u1=randu(44.65,45.35);
      double u2=(13.7,14.3);
    }








  return 0;
}

