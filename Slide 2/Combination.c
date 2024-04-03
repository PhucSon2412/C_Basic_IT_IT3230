#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int k,n,s[100]={0};
void printSolution(){
    int i;
    for (i=1;i<=k;i++) printf("%i ",s[i]);
    printf("\n");
}
void Try(int v){
    int w;
    for(w=s[v-1]+1;w<=n;w++){
        s[v]=w;
        if(v==k) printSolution();
        else Try(v+1);
        s[v]=1;
    }
}
int main(){
    scanf("%i %i",&k,&n);
    Try(1);
}