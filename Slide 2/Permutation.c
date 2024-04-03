#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int k,n,s[100],e[100]={0};
void printSolution(){
    int i;
    for (i=1;i<=k;i++) printf("%i ",s[i]);
    printf("\n");
}
void Try(int v){
    int w;
    for(w=1;w<=n;w++){
        if(e[w]==0){
            s[v]=w;
            e[w]=1;
            if(v==k) printSolution();
            else Try(v+1);
            e[w]=0;
        }
    }
}
int main(){
    scanf("%i %i",&k,&n);
    Try(1);
}