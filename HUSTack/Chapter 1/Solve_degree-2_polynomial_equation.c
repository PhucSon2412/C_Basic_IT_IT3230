//Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
//Input
//Line 1 contains 3 integers a, b, c 
//Output
//Write NO SOLUTION if the given equation has no solution 
//Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
//Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int main(){
    float a,b,c,delta;
    scanf("%f %f %f",&a,&b,&c);
    if(a==0){
        if(b==0) printf("NO SOLUTION\n");
        else printf("%.2f\n",-c/b);
    } else {
        delta=b*b-4*a*c;
        if(delta<0) printf("NO SOLUTION\n");
        if(delta==0) printf("%.2f\n",-b/(2*a));
        if(delta>0) printf("%.2f %.2f\n",(-b-sqrt(delta))/(2*a),(-b+sqrt(delta))/(2*a));
    }
}