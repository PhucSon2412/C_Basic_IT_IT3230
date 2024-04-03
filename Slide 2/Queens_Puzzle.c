#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int n,s[100]={0};
void printSolution(){
    int i;
    for(i=1;i<=n;i++) printf("%i ",s[i]);
    printf("\n");
}
int check(int v,int k){
    int i;
    for(i=1;i<k;i++){
        if(v==s[i]) return 0;
        if(v+k==s[i]+i) return 0;
        if(v-k==s[i]-i) return 0;
    } 
    return 1;
}
void Try(int k){
    int v;
    for(v=1;v<=n;v++){
        if(check(v,k)){
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