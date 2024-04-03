#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int n,M,s[100]={0},T=0;
void printSolution(){
    int i;
    for(i=1;i<=n;i++) printf("%i ",s[i]);
    printf("\n");
}
int check(int v,int k){
    if(k==n) return T+v==M;
    return 1;
}
void Try(int k){
    int v;
    for(v=1;v<=M-T-(n-k);v++){
        if(check(v,k)){
            s[k]=v;
            T+=v;
            if(k==n) printSolution();
            else Try(k+1);
            T-=v;
        }
    }
}
int main(){
    scanf("%i %i",&n,&M);
    Try(1);
}