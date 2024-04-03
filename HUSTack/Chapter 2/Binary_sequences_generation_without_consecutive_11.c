//Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
//Input
//Line 1: contains an integer n (1 <= n <= 20)
//Output
//Write binary sequences in a lexicographic order, each sequence in a line
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
        if(A[k-1]+v<2){
            A[k]=v;
            if(k==n) printSolution();
            else Try(k+1);
        }
    }
}
int main(){
    scanf("%i",&n);
    Try(1);
}