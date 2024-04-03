#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int n,count=0;
char a,b,c,d;
void move(int n,char a,char b,char c,char d){
    if(n==0) return;
    if(n==1){
        count++;
        printf("Step %i: Move a disk from %c to %c.\n",count,a,b);
    } else {
        move(n-2,a,d,b,c);
        move(1,a,c,b,d);
        move(1,a,b,c,d);
        move(1,c,b,a,d);
        move(n-2,d,b,a,c);
    }
}
int main(){
    scanf("%i %c %c %c %c",&n,&a,&b,&c,&d);
    move(n,a,b,c,d);
}