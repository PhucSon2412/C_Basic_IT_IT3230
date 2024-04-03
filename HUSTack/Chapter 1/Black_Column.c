//Given a matrix T having n rows and m columns, each element is 0 or 1. A column is called black column if each element on this column is 1. Write a program to compute the number Q of black columns
//Input
//Line 1: contains two positive integers n and m (1 <= n,m <= 1000)
//Line i+1 (i = 1,...,n): contains the ith row of the matrix T
//Output
//Write the value of Q
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int a[1000][1000]={0};
int main(){
    int l1,c1,i,j,count=0,bc=0;
    scanf("%i %i",&l1,&c1);
    for(i=0;i<l1;i++){
        for(j=0;j<c1;j++) scanf("%i",&a[i][j]);
    }
    for(j=0;j<c1;j++){
        for(i=0;i<l1;i++){
            if(a[i][j]==1) bc=1;
            else {
                bc=0;
                break;
            }
        }
        if(bc==1) count++;
    }
    printf("%i",count);
}