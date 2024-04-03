//Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
//Input
//Line 1: two positive integers k and n (1 <= k,n <= 999)
//Output
//Write te value C(k,n) modulo 10^9+7.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
long long result,k,n,A[501][1000]={0};
long long Try(int k,int n){
    if(k==n||k==0) return 1;
    if(k==1||k==n-1) return n;
    if(A[k][n]==0){
        return A[k][n]=(Try(k-1,n-1)+Try(k,n-1))%1000000007;
    } else return A[k][n];
}
int main(){
    scanf("%lld %lld",&k,&n);
    printf("%lld",Try(k,n));
}