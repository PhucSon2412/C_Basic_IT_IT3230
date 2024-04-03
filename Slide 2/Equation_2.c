#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int M,s[100]={0},T=0;
void printSolution(){
    int i;
    for(i=1;s[i]!=0;i++) printf("%i ",s[i]);
    printf("\n");
}
void Try(int k){
    int v;
    for(v=1;v<=M;v++){
        if(T+v<=M){
            s[k]=v;
            T+=v;
            if(T==M) printSolution();
            else Try(k+1);
            T-=v;
            s[k]=0;
        }
    }
}
int main(){
    scanf("%i",&M);
    Try(1);
}