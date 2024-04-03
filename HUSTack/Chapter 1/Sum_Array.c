//Given a sequence of n integers a1, ..., an. Compute the sum of elements
//Input
//Line 1: contains a positive integer n (1 <= n <= 100000)
//Line 2: contains n integers a1, a2, ..., an (elements are separated by a SPACE character)
//Output
//Write the sum of elements of the given sequence.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main(){
    int n,i,sum=0;
    scanf("%i",&n);
    int *a=(int *)calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        scanf("%i",&a[i]);
        sum+=a[i];
    }
    printf("%i",sum);
    free(a);
}