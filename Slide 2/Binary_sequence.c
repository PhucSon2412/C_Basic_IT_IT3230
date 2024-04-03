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
        s[k]=v;
        if(k==n) printSolution();
        else Try(k+1);
    }
}
int main(){
    scanf("%i",&n);
    Try(1);
}