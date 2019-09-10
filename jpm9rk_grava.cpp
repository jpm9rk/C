//James Morrissey
//jpm9rk
//hw 7
//prob 3
//jpm9rk_grava.cpp
//On my honor as a student I have neither given nor received help on this assignent



#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
//size of array
#define SIZE 100

const double Grav =0.00000000006754; 

// Creation of structure "body"
struct body
   { 
  double s_vec[3];

  double v_vec[3];

  double f_vec[3];

  double mass;
e   };


// Read Data Function, returns the number of bodys counted
int readData( char* fileName,body *object){

  
FILE *data=fopen(fileName,"r");

 if (data==NULL){

   printf("error:file not found!\n");

   return -1;
 
    }
 int status;

  int count = 0;

 while (count<SIZE){

   //Temporary Variables for calculation

   double temp_x, temp_y, temp_z, tempv_x,tempv_y,tempv_z,tempMass;
   
 status = fscanf(data,"%lf %lf %lf %lf %lf %lf %lf", &temp_x,&temp_y,&temp_z,&tempv_x,&tempv_y,&tempv_z,&tempMass);
 object[count].s_vec[0] =temp_x; 
 object[count].s_vec[1]=temp_y;
 object[count].s_vec[2]=temp_z;
 object[count].v_vec[0]=tempv_x;
 object[count].v_vec[1]=tempv_y;
 object[count].v_vec[2]=tempv_z;
 object[count].mass=tempMass;
 object[count].f_vec[0]=0;
 object[count].f_vec[1]=0;
 object[count].f_vec[2]=0;
   
 
     if (status==EOF || status!=7) break;

     // Check that the right points are being read in

printf("Read from file: (%lf,%lf,%lf,%lf,%lf,%lf,%lf)\n",temp_x,temp_y,temp_z,tempv_x,tempv_y,tempv_z,tempMass);

count++;
  }
 fclose(data);

 // Check number of bodies read in
 printf("%d bodys read from file\n",count);
 return count;
}

//Center of Mass Function, prints the x,y,z coordinates of the center of mass
void  center_of_mass(body array[],int arraysize)

{

double centofMassX=0;
double centofMassY=0;
double centofMassZ=0;
 double massTot=0;
 double xCM=0;
 double yCM=0;
 double zCM=0;
  
 
  for (int h=0;h<arraysize-1;h++)

    {
      printf("Executing loop %d times!\n",h);

      centofMassX+=(array[h].s_vec[0]*(array[h].mass));
      centofMassY+=(array[h].s_vec[1]*(array[h].mass));
      centofMassZ+=(array[h].s_vec[2]*(array[h].mass));
      massTot+=(array[h].mass);

       }
  xCM=(centofMassX)/(massTot);
  yCM=(centofMassY)/(massTot);
  zCM=(centofMassZ)/(massTot);

    printf("center of mass coordinates (x,y,z) = (%lf,%lf,%lf)\n", xCM, yCM, zCM);
}
//calculates distance between points
double distanceFunc(double x,double y,double z,double x1,double y1,double z1){

  double distance=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y)+(z1-z)*(z1-z));

  return distance;
}
int f,a;

//function finds the force on each body, then prints them

void ForceFunction(body array1[],int arraysize1)
{ 
for( f=0;f<arraysize1;f++)
{
   for( a=0;a<arraysize1;a++)
  {
    if(a!=f){
  {
      
      
   double dis=distanceFunc(array1[f].s_vec[0],array1[f].s_vec[1],array1[f].s_vec[2],
    array1[a].s_vec[0],array1[a].s_vec[1],array1[a].s_vec[2]);

  ;
     array1[f].f_vec[0]=array1[f].f_vec[0]+((array1[a].s_vec[0]-array1[f].s_vec[0])*Grav*array1[f].mass*array1[a].mass)/(dis*dis*dis);

   array1[f].f_vec[1]=array1[f].f_vec[1]+((array1[a].s_vec[1]-array1[f].s_vec[1])*Grav*array1[f].mass*array1[a].mass)/(dis*dis*dis);

   array1[f].f_vec[2]=array1[f].f_vec[2]+((array1[a].s_vec[2]-array1[f].s_vec[2])*Grav*array1[f].mass*array1[a].mass)/(dis*dis*dis);

 }

  }



  }
    printf("Body %3d Force = (%8.2lg,%8.2lg,%8.2lg)\n",f+1, array1[f].f_vec[0],
       array1[f].f_vec[1], array1[f].f_vec[2]);

 }

}


//Main Function, accepts a value for an argument
int main(int argc,char *argv[]){



  body object[SIZE];



 
  printf("%s\n",argv[1]);


  int counter=readData( argv[1],object);
  
   printf("counter %d:\n",counter);

  int arrCounter=counter+1;

  center_of_mass(object, arrCounter);

   ForceFunction(object,counter);
  


 return 0;

}




