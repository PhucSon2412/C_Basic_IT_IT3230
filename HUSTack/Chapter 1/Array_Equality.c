//Given two sequence. Check if these sequences are equal.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main(){
    int n,i;
    scanf("%i",&n);
    for(i=0;i<n;i++){
        int x,y,j,similar;
        scanf("%i %i",&x,&y);
        int *a=(int *)calloc(x,sizeof(int));
        int *b=(int *)calloc(y,sizeof(int));
        for(j=0;j<x;j++) scanf("%i",&a[j]);
        for(j=0;j<y;j++) scanf("%i",&b[j]);
        if(x!=y){
            printf("0\n");
            free(a);
            free(b);
            continue;
        }
        for(j=0;j<y;j++){
            if(a[j]!=b[j]){
                similar=0;
                break;
            }
            similar=1;
        }
        if(similar==1) printf("1\n");
        else if(similar==0) printf("0\n");
        free(a);
        free(b);
    }

}