#include <stdio.h>

float effresistance(float a, float b, float c){

  float res= 1/((1/a)+(1/b)+(1/c));
  return res;
}

float current(float d, float e){

  float cur=d/(e);
  return cur;


}

float cur1individual(float f, float g){

  float cur1=f/(g);
    return cur1;

}

float cur2individual(float h, float i){

  float cur2=h/(i);
  return cur2;
}

float cur3individual(float j, float k){

  float cur3=j/(k);
  return cur3;



}





  int main(){
    
    float voltage;
    float r1,r2,r3;
    


    printf("please enter the voltage of the circuit\n");



    scanf("%f",&voltage);

    printf("please enter the 3 resistances of the parallel circuit\n");

      scanf("%f %f %f",&r1,&r2,&r3);

      float reffective = effresistance(r1,r2,r3);

      printf("The effective resistance is %f\n",reffective);

      float totalcurrent= current(voltage,reffective);

      printf("The total current is %f\n",totalcurrent);

      float cur1= cur1individual(voltage,r1);

      printf("The current through resistor 1 is %f\n",cur1);

      float cur2= cur2individual(voltage,r2);

      printf("The current through resistor 2 is %f\n",cur2);

      float cur3= cur3individual(voltage,r3);

      printf("The current through resistor 3 is %f\n",cur3);























    return 0;
  }
