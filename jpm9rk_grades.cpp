//James Morrissey
//jpm9rk
//hw08 
//prob 1
//jpm9rk_grades.cpp 
//On my honor as a student I have neither given nor received help on this assignment

#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <ctype.h>



//student structure
struct student
{

  char ID[7];
  char lastName[15];
  char firstName[15];
  double HW[15];
  double lab[15];
  double final;
  double midterm;
  double hwTotal;
  double labTotal;
  double pointTotal;
  double grade;
}stud2660;

int main(){

  double hwPossiblePoint=552;
  double labPossiblePoint=150;
  int otherCounter=0;

  int j,k;

  FILE *gradePtr;
  //I accidentally downloaded the file a couple times and changed things in it
  //grades_2017.csv.4 is unchanged version of the  file downloaded 
  gradePtr=fopen("grades_2017.csv.4","r");
 
  
  if (gradePtr==NULL){

    printf("file not found");
return -1;
  }
 student stud2660[100];

int count=0;
//temporary variables
double HW1,HW2,HW3,HW4,HW5,HW6,HW7,HW8,HW9,HW10,HW11,HW12,HW13,HW14,HW15;
double lab1,lab2,lab3,lab4,lab5,lab6,lab7,lab8,lab9,lab10,lab11,lab12,lab13,lab14,lab15;
 double midterm,final;
 //array for storing first line
char trash[500];

fgets(trash,400,gradePtr);
//temporary strings
char ID[7],firstName[15],lastName[15];

 char tweetstuff[50000];

int status;
//Scans in the values from the file, breaks the loop if EOF reached
 for(count=0;count<100;count++){
  status=fscanf(gradePtr,"%[^,],\"%[^,],%[^\"]\", %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",ID,firstName,lastName,&HW1,&HW2,&HW3,&HW4,&HW5,&HW6,&HW7,&HW8,&HW9,&HW10,&HW11,&HW12,&HW13,&HW14,&HW15,&lab1,&lab2,&lab3,&lab4,&lab5,&lab6,&lab7,&lab8,&lab9,&lab10,&lab11,&lab12,&lab13,&lab14,&lab15,&midterm,&final);
  
   if (status==EOF)
  break;

//structure variables are assigned the corresponding values of the temporary ones
stud2660[count].HW[0]=HW1;
stud2660[count].HW[1]=HW2;
stud2660[count].HW[2]=HW3;
stud2660[count].HW[3]=HW4;
stud2660[count].HW[4]=HW5;
stud2660[count].HW[5]=HW6;
stud2660[count].HW[6]=HW7;
stud2660[count].HW[7]=HW8;
stud2660[count].HW[8]=HW9;
stud2660[count].HW[9]=HW10;
stud2660[count].HW[10]=HW11;
stud2660[count].HW[11]=HW12;
stud2660[count].HW[12]=HW13;
stud2660[count].HW[13]=HW14;
stud2660[count].HW[14]=HW15;
stud2660[count].lab[0]=lab1;
stud2660[count].lab[1]=lab2;
stud2660[count].lab[2]=lab3;
stud2660[count].lab[3]=lab4;
stud2660[count].lab[4]=lab5;
stud2660[count].lab[5]=lab6;
stud2660[count].lab[6]=lab7;
stud2660[count].lab[7]=lab8;
stud2660[count].lab[8]=lab9;
stud2660[count].lab[9]=lab10;
stud2660[count].lab[10]=lab11;
stud2660[count].lab[11]=lab12;
stud2660[count].lab[12]=lab13;
stud2660[count].lab[13]=lab14;
stud2660[count].lab[14]=lab15;
stud2660[count].midterm=midterm;
stud2660[count].final=final;
strcpy(stud2660[count].ID,ID);
strcpy(stud2660[count].firstName,firstName);
strcpy(stud2660[count].lastName,lastName);

 otherCounter++;

 
 }

 for (k=0;k<3;k++)

   {
     //loop to find totals for student k
     for(j=0;j<15;j++)
       {
	stud2660[k].hwTotal+=stud2660[k].HW[j];
        stud2660[k].labTotal+=stud2660[k].lab[j];
	}
     //calculates point total, homework and lab avg, and grade
     stud2660[k].pointTotal=stud2660[k].hwTotal+stud2660[k].labTotal
     +stud2660[k].midterm+stud2660[k].final;
     double hwAvg=(stud2660[k].hwTotal)/hwPossiblePoint;
     double labAvg=(stud2660[k].labTotal)/labPossiblePoint;
     stud2660[k].grade=(hwAvg*0.4)*100+(labAvg*0.15)*100+(stud2660[k].midterm)*0.2
     +(stud2660[k].final)*0.25;
     printf("student %s point total is %lf\n",stud2660[k].firstName,stud2660[k].pointTotal);
     printf("student %s grade is %lf percent\n",stud2660[k].firstName,stud2660[k].grade);
   }

 fclose(gradePtr);
  return 0;
} 




