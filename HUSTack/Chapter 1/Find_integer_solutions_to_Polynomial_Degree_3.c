//Given 3 integers a, b, c (c != 0). Write a program that find distinct integers solution s1, s2, . . ., sk) such that x3 + ax2 + bx + c can be rewritten under the form (x-s1) m1(x-s2)m2. . . (x-sk)mk   
//in which m1, m2,  . . ., mk are call multipliers.
//Input
//Line 1 contains 3 integers a, b, c (-10000000 <= a, b, c <= 10000000)
//Output
//In case that no solution found, then write NO SOLUTION to stdout. Otherwise, write the solution under the format: 
//s1 m1
//s2 m2
//s3 m3
//. . .
//in which s1, s2, s3, ... are solution sorted in an increasing order and m1, m2, m3, ... are respectively the multipliers of s1, s2, s3, ...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int main(){
    float a,b,c,d,e,f,delta,x1,x2;
    int i;
    scanf("%f %f %f",&a,&b,&c);
    d=0;
    for(i=0;i<10;i++){
        d=d-(pow(d,3)+a*pow(d,2)+b*d+c)/(3*pow(d,2)+2*a*d+b);
    }
    e=d+a;
    f=pow(d,2)+d*a+b;
    delta=e*e-4*f;
    if(delta<0){
        printf("NO SOLUTION");
        return 0;
    } else if(delta==0){
        x1=-e/2;
        if(x1>d){
            printf("%.0f 1\n%.0f 2",d,x1);
        } else if(x1<d){
            printf("%.0f 2\n%.0f 1",x1,d);
        }
    } else if(delta>0){
        x1=(-e-sqrt(delta))/2;
        x2=(-e+sqrt(delta))/2;
        if(d<x1){
            printf("%.0f 1\n%.0f 1\n%.0f 1",d,x1,x2);
        } else if(x1<d&&d<x2){
            printf("%.0f 1\n%.0f 1\n%.0f 1",x1,d,x2);
        } else if(x2<d){
            printf("%.0f 1\n%.0f 1\n%.0f 1",x1,x2,d);
        }
    }
}
