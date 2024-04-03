    //Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M
    //Input
    //Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)
    //Output
    //Write in each line X1, X2, ..., Xn separated by a SPACE character
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <malloc.h>
    int n,M,t=0,A[20];
    void printSolution(){
        int i;
        for(i=1;i<=n;i++) printf("%i ",A[i]);
        printf("\n");
    }
    int check(int v,int k){
        if(k==n) return t+v==M;
        return 1;
    }
    void Try(int k){
        int v;
        for(v=1;v<=M-n+1;v++){
            if(check(v,k)){
                A[k]=v;
                t+=v;
                if(k==n) printSolution();
                else Try(k+1);
                t-=v;
            }
        }
    }
    int main(){
        scanf("%i %i",&n,&M);
        Try(1);
    }