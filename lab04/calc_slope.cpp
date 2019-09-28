
//Calculates Slope of the Line
// Input Variables: x1,y1-coordinates of point 1, x2,y2-coordinates of point 2




#include <math.h>
#include <stdio.h>

float calcDistance(float a, float b, float c, float d){

  float e= sqrt((c-a)*(c-a)+(d-a)*(d-a));
		return e;


}

float m_to_km(float d_in_m){

  float km= d_in_m/(1000);

  return km;
}


float m_to_feet (float d_in_m){

  float f= d_in_m*0.305;

  return f;
}

float m_to_miles(float d_in_m){

  float miles= d_in_m*0.00062;

  return  miles;
}



int main(){
  float x1,y1,x2,y2;
  double xintercept,yintercept;
  float slope;
  printf("Input two points on the line, starting with the x and y coordinates of the first point, and then the x and y coordinates of the second\n, making sure the coordinates are in meters:\n");
  
  
  scanf("%f %f %f %f", &x1, &y1,&x2,&y2);
  printf("Coordinates of Point1: x1=%5.2f y1= %5.2f\n", x1,y1);
  printf("Coordinates of Point2: x2=%5.2f y2= %5.2f\n", x2,y2);
  if(x1 != x2)
    {
      slope=(y2-y1)/(x2-x1);
      printf("Slope of the Line: %5.2f\n",slope);
      yintercept=(y1)-(slope*x1);
      xintercept=(-yintercept)/slope;
      printf("yintercept when y=%5.2f\n", yintercept);
      printf("xintercept=when x=%5.2f\n", xintercept);
      
      float g = calcDistance(x1,y1,x2,y2);

       printf("The distance between the points is %f\n",g);

       float h= m_to_km(g);
       printf("The distance between the points in km is %f\n",h);

       float j=m_to_feet(g);
       printf("The distance between the points in feet is %f\n",j);

       float k=m_to_miles(g);
       printf("The distance between the points in miles is %f\n",k);




    }
  else
    printf("line is vertical\n");  yintercept=(y1)-(slope*x1);
    


 
   return 0;
}
