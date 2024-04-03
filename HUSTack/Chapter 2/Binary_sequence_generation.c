//Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int n,A[100]={0};
void printSolution(){
    int i;
    for(i=1;i<=n;i++) printf("%i",A[i]);
    printf("\n");
}
void Try(int k){
    int v;
    for(v=0;v<=1;v++){
        A[k]=v;
        if(k==n) printSolution();
        else Try(k+1);
    }
}
int main(){
    scanf("%i",&n);
    Try(1);
}