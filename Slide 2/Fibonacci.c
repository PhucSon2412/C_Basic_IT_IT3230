#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int n,A[100]={0};
int f(int i){
    if(A[i]==0){
        if(i==0||i==1){
            A[i]=1;
            return A[i];
        } else {
            A[i]=f(i-1)+f(i-2);
            return A[i];
        } 
    } else return A[i];
}
int main(){
    int i;
    scanf("%i",&n);
    for(i=0;i<n;i++){
        printf("%i ",f(i));
    }
}