#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int n,s[50]={0};
void printSolution(){
    int i;
    for (i=1;i<=n;i++) printf("%i",s[i]);
    printf("\n");
}
void Try(int k){
    int v;
    for(v=0;v<=1;v++){
        if(v+s[k-1]<2){
            s[k]=v;
            if(k==n) printSolution();
            else Try(k+1);
        }
    }
}
int main(){
    scanf("%i",&n);
    Try(1);
}