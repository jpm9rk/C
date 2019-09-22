// Name: James Morrissey
// UserId: jpm9rk
// Homework # 1
// Problem # 5
// Program Name: jpm9rk_num5.txt
// On my honor as a student I have neither given nor received help on 
// this assignment
// Problem: Find the area of a triangle given the three sides a,b,c, 
// using the formula s=1/2(a+b+c), and area = (s(s-a)(s-b)(s-c))^(1/2)
// Data Required: input of the length of the three sides of the triangle 
// a,b,c
// Method: Using the input values of a,b,c, calculate s according to 
// s=(1/2)(a+b+c). Then plug this value for s and the corresponding 
// values of abc into the formula area= (s(s-a)(s-b)(s-c))^(1/2). Then 
// output the area
// Algorithim:
// Input values for the sides of the triangle with sides a,b,c
// For each  a,b,c>0
//    while a+b>c,b+c>a,a+c>b
// 	 calculate s by inputting values a,b,c into s=(1/2)(a+b+c)
// 	 s=(1/2)(a+b+c)
// 	 area= (s(s-a)(s-b)(s-c))^(1/2)
//    end while
// end for
// out put area
