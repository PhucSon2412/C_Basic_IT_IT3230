#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int k,n,A[100][100]={0};
int C(int k,int n){
    if(A[k][n]==0){
        if(k==0||k==n){
            A[k][n]=1;
            return A[k][n];
        }
        if(k==1||k==n-1){
            A[k][n]=n;
            return A[k][n];
        }
        A[k][n]=C(k-1,n-1)+C(k,n-1);
        return A[k][n];
    } else return A[k][n];
}
int main(){
    scanf("%i %i",&k,&n);
    printf("%i",C(k,n));
}