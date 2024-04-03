//Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int n,A[100]={0},e[100]={0};
void printSolution(){
    int i;
    for(i=1;i<=n;i++) printf("%i ",A[i]);
    printf("\n");
}
void Try(int k){
    int v,i,j;
    for(v=1;v<=n;v++){
        if(!e[v]){
            A[k]=v;
            e[v]=1;
            if(k==n) printSolution();
            else Try(k+1);
            e[v]=0;
        }
    }
}
int main(){
    scanf("%i",&n);
    Try(1);
}