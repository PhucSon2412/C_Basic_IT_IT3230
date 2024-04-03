//Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
//Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
//Input
//Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
//Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
//Output
//Write the value Q
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main(){
    int n1,n2,i,j,count=0,sum=0;
    scanf("%i %i",&n1,&n2);
    int *a=(int *)calloc(n1,sizeof(int));
    for(i=0;i<n1;i++){
        scanf("%i",&a[i]);
    }
    for(i=0;i<n2;i++){
        sum+=a[i];
    }
    if(sum%2==0) count++;
    for(i=1;i<=n1-n2;i++){
        sum-=a[i-1];
        sum+=a[i+n2-1];
        if(sum%2==0) count++;
    }
    printf("%i",count);
    free(a);
}