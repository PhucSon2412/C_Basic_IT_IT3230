#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
int n,count=0;
char a,b,c;
void move(int n,char a,char b,char c){
    if(n==1){
        count++;
        printf("Step %i: Move a disk from %c to %c.\n",count,a,b);
    } else {
        move(n-1,a,c,b);
        move(1,a,b,c);
        move(n-1,c,b,a);
    }
}
int main(){
    scanf("%i %c %c %c",&n,&a,&b,&c);
    move(n,a,b,c);
}